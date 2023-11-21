#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> svec;

    // vector不支持push_front()，但可以插入到begin()之前
    svec.insert(svec.begin(), "Hello");
    // 将3个元素插入到svec的末尾，并将所有元素都初始化为 string "Anna"
    svec.insert(svec.end(), 3, "Anna");
    svec.insert(svec.begin(), {"wuyan", "WUYAN"});
    svec.insert(svec.begin(), svec.begin(), svec.end());
    // svec.insert(svec.end(), svec.begin(), svec.end()); //为什么这条语句不起作用？？？
    
    for (const auto &s : svec)
        cout << s << " ";
    cout << endl;

    vector<int> ivec = {1, 2, 3, 4, 5};

    // ivec.insert(ivec.end(), ivec.begin(), ivec.end());
    // ivec.insert(ivec.begin(), ivec.begin(), ivec.end());
    // ivec.emplace(ivec.end(), 10);

    // 可以通过迭代器的加减操作到达指定位置
    // 例如想要在容器的第三个元素前面插入一个元素10
    ivec.insert(ivec.begin() + 2, 10);

    for (const auto &i : ivec)
        cout << i << " "; 
    cout << endl;

    return 0;
}