#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    // ���ȶ�����һ�����������������ṩ�˳���ʱ��Ļ�ȡ���ֵ����Сֵ�Ĳ��������ǲ�֧�ֱ�������
    priority_queue<int> heap1; //Ĭ���Ǵ���ѣ��ײ�Ĭ��ʹ��vector��Ϊ����
    priority_queue<int, deque<int>> heap2; //ʹ��deque��Ϊ�ײ�ʵ�ֽṹ�������Ǵ����

    priority_queue<int, vector<int>, greater<int>> heap3;
    // ��һ��ģ�������ʾpriority_queue�д�ŵ�Ԫ������
    // �ڶ���ģ�������ʾpriority_queue�ĵײ��������ͣ�������vector��deque
    // priority_queue��STL�е�������������������һ�����е��������ͣ���ʹ�������Ϊ����������һ����������
    // priority_queueĬ��ʹ��vector��Ϊ�ײ���������ȻҲ����ʹ��deque��Ϊ�ײ�����
    // ������������ʾpriority_queue��Ԫ�صıȽϷ�ʽ��������һ������ֵ��bool���͵Ŀɵ��ö���
    // �ɵ��ö��󷵻�ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ��������������ȶ����У����ȼ��ϸߵ�Ԫ���³������ȼ��ϵ͵�Ԫ���ϸ�
    // �ÿɵ��ö��������������������ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    // ���õĿɵ��ö����У���׼�ⶨ��ĺ�������less<T>��greater<T>���Լ��Զ���ĺ�������
    // ��lambda���ʽ������ָ�롢�����ˡ��������������operator()�������

    heap3.push(13);
    heap3.push(97);
    heap3.push(51);
    // ����heap3�ײ���ʹ��vectorʵ�ֵģ��������ͬ�ڶ�����������Ҫ�洢ָ�����������ӽڵ㣬����ͨ���±�ķ�ʽ����������
    // ������vector�е��±�Ϊi�Ľڵ㣬�����ӽڵ��±�Ϊ2i+1�����ӽڵ��±�Ϊ2i+2

    // priority_queue�����÷�Χfor���
    // for (const auto &i : h)
    //     cout << i << " ";
    // cout << endl;

    while (heap3.size()) {
        cout << heap3.top() << endl;
        heap3.pop();
    } // heap3��С���ѣ��������˳��Ӧ����13 51 97

    unordered_map<int, int> m;

    return 0;
}