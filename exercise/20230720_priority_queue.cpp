#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    priority_queue<int> heap1; //Ĭ���Ǵ���ѣ��ײ�Ĭ��ʹ��vector��Ϊ����
    priority_queue<int, deque<int>> heap2; //ʹ��deque��Ϊ�ײ�ʵ�ֽṹ�������Ǵ����

    priority_queue<int, vector<int>, greater<int>> heap3;
    // ��һ��ģ�������ʾpriority_queue�д�ŵ�Ԫ������
    // �ڶ���ģ�������ʾpriority_queue�ĵײ��������ͣ�������vector��deque
    // priority_queue��STL�е�������������������һ�����е��������ͣ���ʹ�������Ϊ����������һ����������
    // priority_queueĬ��ʹ��vector��Ϊ�ײ���������ȻҲ����ʹ��deque��Ϊ�ײ�����
    // ������������ʾpriority_queue��Ԫ�صıȽϷ�ʽ��������һ������ֵ��bool���͵Ŀɵ��ö���
    // �ÿɵ��ö��������������������ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    // ���õĿɵ��ö����У���׼�ⶨ��ĺ�������less<T>��greater<T>���Լ��Զ���ĺ�������
    // ��lambda���ʽ������ָ�롢�����˺������������operator()�����

    heap3.push(13);
    heap3.push(97);
    heap3.push(51);
    // ����heap3�ײ���ʹ��vectorʵ�ֵģ��������ͬ�ڶ�����������Ҫ�洢ָ�����������ӽڵ㣬����ͨ���±�ķ�ʽ����������
    // ������vector�е��±�Ϊi�Ľڵ㣬�����ӽڵ��±�Ϊ2i+1�����ӽڵ��±�Ϊ2i+2

    // priority_queue�����÷�Χfor���
    // for (const auto &i : h)
    //     cout << i << " ";
    // cout << endl;

    unordered_map<int, int> m;

    return 0;
}