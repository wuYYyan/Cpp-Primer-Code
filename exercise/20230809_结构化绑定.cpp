#include <iostream>

using namespace std;

struct MyStruct {
    int id;
    std::string name;
};

int main()
{
    // ����ʱ���������ѡ�-std=c++17
    int arr[] = {1, 2};
    auto [x, y] = arr;
    std::cout << "x: " << x << ", y: " << y << std::endl;

    MyStruct s = {1, "example"};
    auto [id, name] = s;
    std::cout << "id: " << id << ", name: " << name << std::endl;
    
    return 0;
}