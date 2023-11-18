#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class ReadWriteLock {
private:
    std::mutex mutex_; // ����ĸ���Ա������Ҫʵ�ֶ�������ļ����ͽ�������
    std::condition_variable read_cv_;
    std::condition_variable write_cv_;
    int readers_; // ����λ����ʾ��ǰ�ж��ٸ��߳����ڶ�ȡ����
    bool writing_; // ��־λ����ʾ�Ƿ����߳����ڽ���д����

public:
    ReadWriteLock() : readers_(0), writing_(false) {}
    // ȫ���ṩĬ�ϲ�����Ĭ�Ϲ��캯��

    void lockRead() {
        std::unique_lock<std::mutex> lock(mutex_);

        // ������߳����ڽ���д�������ߵȴ�д���������Ի����ܶ�ȡ���������ȴ�
        while (writing_) {
            read_cv_.wait(lock);
        }
        
        readers_++;
    }

    void unlockRead() {
        std::unique_lock<std::mutex> lock(mutex_);

        readers_--;
        if (readers_ == 0) {
            write_cv_.notify_one(); // ���ѵȴ�д�������̣߳�д���߳�ֻ��һ��һ��д
        }
    }

    void lockWrite() {
        std::unique_lock<std::mutex> lock(mutex_);

        // ������߳����ڶ���д���������ȴ�
        while (writing_ || readers_ > 0) {
            write_cv_.wait(lock);
        }

        writing_ = true; // ��ǵ�ǰ���߳�����д
    }

    void unlockWrite() {
        std::unique_lock<std::mutex> lock(mutex_);

        writing_ = false; // ��ǵ�ǰû���߳�����д
        read_cv_.notify_all();  // ���ѵȴ����������̣߳����ж����߳̿�ͬʱ��ȡ
        write_cv_.notify_one(); // ���ѵȴ�д�������̣߳�д���߳�ֻ��һ��һ��д
    }
};

// ʾ���÷�
ReadWriteLock rwLock;

void readerFunction(int id) {
    while (true) {
        rwLock.lockRead();
        // ִ�ж�ȡ����
        std::cout << "Reader " << id << " is reading" << std::endl;
        rwLock.unlockRead();
        // ����һ��ʱ��ģ���ȡ����
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void writerFunction(int id) {
    while (true) {
        rwLock.lockWrite();
        // ִ��д�����
        std::cout << "Writer " << id << " is writing" << std::endl;
        rwLock.unlockWrite();
        // ����һ��ʱ��ģ��д�����
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

int main() {
    // ������������̺߳�д���߳̽��в���
    std::thread readers[3];
    std::thread writers[2];

    for (int i = 0; i < 3; i++) {
        readers[i] = std::thread(readerFunction, i);
    }

    for (int i = 0; i < 2; i++) {
        writers[i] = std::thread(writerFunction, i);
    }

    // �ȴ������߳̽���
    for (auto& reader : readers) {
        reader.join();
    }

    for (auto& writer : writers) {
        writer.join();
    }

    return 0;
}
