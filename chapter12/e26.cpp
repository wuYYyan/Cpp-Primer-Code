#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    allocator<string> alloc;
    auto const p = alloc.allocate(100); //开辟内存

    string s;
    string *q = p;
    while(cin >> s && q != p + 100)
        alloc.construct(q++, s); //构造对象

    const size_t size = q - p;
    for (int i = 0; i < size; i ++)
        cout << p[i] << " ";
    cout << endl;

    while(q != p)
        alloc.destroy(--q); //销毁对象
    alloc.deallocate(p, 100); //释放内存

    return 0;
}