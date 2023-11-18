#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class ReadWriteLock {
private:
    std::mutex mutex_; // 类的四个成员函数都要实现对这把锁的加锁和解锁操作
    std::condition_variable read_cv_;
    std::condition_variable write_cv_;
    int readers_; // 数据位，表示当前有多少个线程正在读取数据
    bool writing_; // 标志位，表示是否有线程正在进行写操作

public:
    ReadWriteLock() : readers_(0), writing_(false) {}
    // 全部提供默认参数的默认构造函数

    void lockRead() {
        std::unique_lock<std::mutex> lock(mutex_);

        // 如果有线程正在进行写操作或者等待写操作，所以还不能读取，则阻塞等待
        while (writing_) {
            read_cv_.wait(lock);
        }
        
        readers_++;
    }

    void unlockRead() {
        std::unique_lock<std::mutex> lock(mutex_);

        readers_--;
        if (readers_ == 0) {
            write_cv_.notify_one(); // 唤醒等待写操作的线程，写者线程只能一个一个写
        }
    }

    void lockWrite() {
        std::unique_lock<std::mutex> lock(mutex_);

        // 如果有线程正在读或写，则阻塞等待
        while (writing_ || readers_ > 0) {
            write_cv_.wait(lock);
        }

        writing_ = true; // 标记当前有线程正在写
    }

    void unlockWrite() {
        std::unique_lock<std::mutex> lock(mutex_);

        writing_ = false; // 标记当前没有线程正在写
        read_cv_.notify_all();  // 唤醒等待读操作的线程，所有读者线程可同时读取
        write_cv_.notify_one(); // 唤醒等待写操作的线程，写者线程只能一个一个写
    }
};

// 示例用法
ReadWriteLock rwLock;

void readerFunction(int id) {
    while (true) {
        rwLock.lockRead();
        // 执行读取操作
        std::cout << "Reader " << id << " is reading" << std::endl;
        rwLock.unlockRead();
        // 休眠一段时间模拟读取过程
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void writerFunction(int id) {
    while (true) {
        rwLock.lockWrite();
        // 执行写入操作
        std::cout << "Writer " << id << " is writing" << std::endl;
        rwLock.unlockWrite();
        // 休眠一段时间模拟写入过程
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

int main() {
    // 创建多个读者线程和写者线程进行测试
    std::thread readers[3];
    std::thread writers[2];

    for (int i = 0; i < 3; i++) {
        readers[i] = std::thread(readerFunction, i);
    }

    for (int i = 0; i < 2; i++) {
        writers[i] = std::thread(writerFunction, i);
    }

    // 等待所有线程结束
    for (auto& reader : readers) {
        reader.join();
    }

    for (auto& writer : writers) {
        writer.join();
    }

    return 0;
}
