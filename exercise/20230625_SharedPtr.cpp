#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// 基于类模板实现的智能指针类
template<class T>
class SharedPtr
{
    public:
        // 默认构造函数
        SharedPtr(T *ptr = nullptr) : _pPtr(ptr), _pRefCount(new int(1)), _pMutex(new mutex) 
        {
            std::cout << "SharedPtr construct ..., origin init" << std::endl;
        }

        // 析构函数
        ~SharedPtr()
        {
            std::cout << "SharedPtr destruct ..." << std::endl;
            release();
        }
        
        // 拷贝构造函数
        SharedPtr(const SharedPtr<T>& sp) : _pPtr(sp._pPtr), _pRefCount(sp._pRefCount), _pMutex(sp._pMutex)
        {
            std::cout << "SharedPtr construct ..., copy other SharedPtr" << std::endl;
        }

        // 拷贝赋值运算符
        SharedPtr<T>& operator=(const SharedPtr<T>& sp)
        {
            std::cout << "operator=" << std::endl;

            if (_pPtr != sp._pPtr) //防止自赋值
            {
                std::cout << "operator= will call release" << std::endl;
                release(); //释放赋值运算符左侧的智能指针管理的旧内存资源
                _pPtr = sp._pPtr;
                _pRefCount = sp._pRefCount;
                _pMutex = sp._pMutex;
                addRefCount();
            }
            return *this;
        }

        // 重载成员访问运算符，返回模板类型的引用
        T& operator*()
        {
            return *_pPtr;
        }

        // 重载成员访问运算符，返回模板类型的指针
        T* operator->()
        {
            std::cout << "operator ->" << std::endl;
            return _pPtr;
        }

        T* Get()
        {
            return _pPtr;
        }

    private:
        void addRefCount() //计数器加1
        {
            _pMutex->lock();
            ++(*_pRefCount);
            std::cout << "addRefCount, now ref count " << (*_pRefCount) << std::endl;
            _pMutex->unlock(); 
        }

        void release() //计数器减1，为0时释放资源
        {
            std::cout << "release, current _RefCount " << *_pRefCount << std::endl;

            bool deleteFlag = false;
            _pMutex->lock();
            if (--(*_pRefCount) == 0)
            {
                std::cout << "will delete _pPtr " << std::endl;
                delete _pRefCount;
                delete _pPtr;
                deleteFlag = true;
            }
            _pMutex->unlock();
            if (deleteFlag = true)
                delete _pMutex;
        }

    private:
        int *_pRefCount; //引用计数
        T *_pPtr; //指向被管理对象的指针
        mutex *_pMutex; //锁，用于计数加减或释放对象等关键操作时加锁
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
		std::cout << "Test printSomething" << std::endl;
	}
};

void doSomeTest(SharedPtr<Test> pTest);

int main(int argc, char* argv[]) {

	std::cout << "main start, will init SharedPtr" << std::endl;

	SharedPtr<Test> originPtr(new Test());
    // new运算符：构造对象(调用构造函数)、分配内存(返回指向对象的指针)
    // 然后再将该指向对象的指针按值传递给智能指针模板类的构造函数，实例化模板类对象(第二次分配内存)

	std::cout << "will call doSomeTest" << std::endl;

	doSomeTest(originPtr); //按值传递参数，调用拷贝构造函数
    // shared_ptr 类型允许拷贝构造与拷贝赋值，但是拷贝后的所有对象都指向同一块内存，这样会导致引用计数的错误

	std::cout << "main end" << std::endl;

	return 0;
}

void doSomeTest(SharedPtr<Test> pTest) {
	std::cout << "doSomeTest call" << std::endl;
	SharedPtr<Test> pInnerTest = pTest; //拷贝构造函数执行初始化
    // 作用相当于SharePtr<Test> pInnerTest(pTest)
	
	std::cout << "will make an emptyPtr" << std::endl;
	SharedPtr<Test> pInnerTest2; //默认构造函数
	std::cout << "will set pInnerTest2" << std::endl;
	pInnerTest2 = pTest;
    //这种先创建变量再赋值的写法才会用到拷贝赋值运算符=

	pInnerTest->printSomething();//当doSomeTest函数执行结束，pTest和pInnerTest的生命周期就会结束，会调用析构
    // 等价写法：pInnerTest.operator->()->printSomething();

	std::cout << "will make one test" << std::endl;
	Test test; //默认构造函数
	test.printSomething();

}