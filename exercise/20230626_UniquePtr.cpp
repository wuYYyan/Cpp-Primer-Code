#include <iostream>
#include <utility>

using namespace std;

template<typename T>
class UniquePtr
{
    private:
        T *ptr_resource = nullptr;

    public:
        // 禁止隐式类型转换的转换构造函数
        explicit UniquePtr(T *raw_resource) noexcept : ptr_resource(std::move(raw_resource)) { }
        UniquePtr(std::nullptr_t) : ptr_resource(nullptr) { }

        UniquePtr() noexcept : ptr_resource(nullptr) {}
        ~UniquePtr() noexcept
        {
            delete ptr_resource;
        }

        // 禁用拷贝构造函数与拷贝赋值运算符
        UniquePtr(const UniquePtr<T>&) noexcept = delete;
        UniquePtr& operator=(const UniquePtr&) noexcept = delete;

        // 移动构造函数
        UniquePtr(UniquePtr&& move) noexcept
        {
            std::cout << "construct for UniquePtr&&" << std::endl;
            move.swap(*this);
        }

        // 移动赋值运算符
        UniquePtr& operator=(UniquePtr&& move) noexcept
        {
            std::cout << "operator= for UniquePtr&&" << std::endl;
            move.swap(*this);
            return *this;
        }

        explicit operator bool() const noexcept
        {
            return this->ptr_resource;
        }

        T* release() noexcept
        {
            return std::exchange(ptr_resource, nullptr); //使得移后源对象可析构
        }

        T* get() const noexcept
        {
            return ptr_resource;
        }

        void swap(UniquePtr<T>& resource_ptr) noexcept
        {
            std::swap(ptr_resource, resource_ptr.ptr_resource);
        }

        void reset(T* resource_ptr) noexcept(false)
        {
            if (resource_ptr == nullptr)
                throw std::invalid_argument("An invalid pointer was passed, resources will not be swapped");

            delete ptr_resource;
            ptr_resource = nullptr; //显式地讲指针置为空
            std::swap(ptr_resource, resource_ptr);
        }

        // 重载成员访问运算符，返回模板类型的指针
        T* operator->() const noexcept
        {
            return this->ptr_resource; //这里相当于有个二级指针
        }

        // 重载成员访问运算符，返回模板类型的引用
        T& operator*() const noexcept
        {
            return *this->ptr_resource;
        }
};

// 用于实例化智能指针模板类
class Test {
public:
	Test() {
		std::cout << "Test class construct" << std::endl;
	}
	~Test() {
		std::cout << "Test class destruct" << std::endl;
	}

	void printSomething() {
		std::cout << "Test printSomething " << std::endl;
	}

    void printResource() {
		std::cout << "Test printResource " << a << std::endl;
	}

    int getResource() {
        return a;
    }

private:
    int a = 10;
};

// 使用UniquePtr的类
class PUser {
public:
	PUser() {
        //初始化pTest
        pTest.reset(new Test());
		std::cout << "PUser construct " << std::endl;
	}
	~PUser() {
		std::cout << "PUser destruct" << std::endl;
	}

    //可以在类的各种函数，使用pTest，
	void userTest() {
		std::cout << "userTest " << pTest->getResource() << std::endl;
	}

private:
    //典型用法，在一个类中，作为一个类成员变量
    UniquePtr<Test> pTest;
};

// 主程序入口
int main(int argc, char* argv[]) {
    UniquePtr<Test> tPtr1(new Test());
    // 以下这两句话，编译就不通过，因为已经定义 UniquePtr& operator=(const UniquePtr&) noexcept = delete;
    // UniquePtr<Test> tPtr2 = tPtr1;
    // UniquePtr<Test> tPtr3(tPtr1);
    
    // 以下两句话就允许，因为pPtr1做了控制权转移
    UniquePtr<Test> tPtr2(std::move(tPtr1));
    UniquePtr<Test> tPtr3 = std::move(tPtr2);

    // tPtr1->printResource();//这一句就崩溃，因为tPtr1非空，只不过资源完全不能用了
    tPtr1->printSomething(); //这一句不崩溃，tPtr1虽然资源不能用，但是代码段可以调用，只要代码段没有使用到资源


    PUser* pUser = new PUser();
    pUser->userTest();

    return 0;
}
