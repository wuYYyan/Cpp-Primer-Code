#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

struct Foo
{
    Foo(int i):i_(i){}
    void print() {std::cout << i_ << std::endl;}
    int i_;
};

int main(int argc, char const *argv[])
{
    {
        auto ptr = std::make_shared<Foo>(42);
        std::thread([&ptr](){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            ptr->print();
        }).detach(); //�̷߳���ʱlambda���ʽ������Ҫ��������
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}
// g++ test.cpp -o test -lpthread
// ./test 
// Segmentation fault