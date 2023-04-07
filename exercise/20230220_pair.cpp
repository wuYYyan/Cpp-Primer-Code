#include <vector>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<string, string> Author;

int main()
{
    //创建空对象
    pair<string, string> anon;         // 两个元素类型都是 string
    pair<int, string> word_count1;     // 两个元素类型分别是 string 和 int
    pair<int, string> word_count2;     // 两个元素类型分别是 string 和 int
    pair<int, pair<int, int>> line;    // 两个元素类型分别是 int 和 pair(容器嵌套)

    //定义的同时初始化
    pair<string, string> author("James","Joy"); // 创建一个author对象，两个元素类型分别为string类型，并默认初始值为James和Joy。
    pair<string, int> name_age("Tom", 18);
    pair<string, int> name_age2(name_age); // 拷贝构造初始化

    //使用typedef简化声明
    Author proust("March", "Proust");
    Author joy("James", "Joy");

    //first 和 second 的调用不加()，分别用于返回第一关键字和第二关键字
    cout << name_age.first << " is " << name_age.second << " years old." << endl;

    //生成新对象
    anon = {"Hello", "World!"};
    word_count1 = make_pair(5, "Hello");
    word_count2 = make_pair(6, "World!");

    //支持比较运算(字典序比较原理或自定义关键字比较方式)，first为第一关键字，second为第二关键字
    if (word_count1 < word_count2)
        puts("word_count1 < word_count2");

    return 0;
}