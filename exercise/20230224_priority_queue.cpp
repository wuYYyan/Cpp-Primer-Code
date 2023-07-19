#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    priority_queue<int> heap1; //���ȶ���Ĭ�϶����Ǵ���ѣ����Ѷ�Ԫ�����������Ԫ��
    priority_queue<int, vector<int>, greater<int>> heap2;
    // ͨ�����������ģ�����������ʵ��С���ѣ����Ѷ�Ԫ����������СԪ��

    //����в���Ԫ��
    heap1.push(1);
    heap1.push(4);
    heap1.push(2);
    heap1.push(3);

    cout << "heap1�ĶѶ�Ԫ��Ϊ: " << heap1.top() << endl; //���ضѶ�Ԫ��
    heap1.pop();
    cout << "heap1�ĶѶ�Ԫ��Ϊ: " << heap1.top() << endl; //���ضѶ�Ԫ��

    heap2.push(1);
    heap2.push(4);
    heap2.push(2);
    heap2.push(3);

    cout << "heap2�ĶѶ�Ԫ��Ϊ: " << heap2.top() << endl; //���ضѶ�Ԫ��
    heap2.pop();
    cout << "heap2�ĶѶ�Ԫ��Ϊ: " << heap2.top() << endl; //���ضѶ�Ԫ��

    cout << heap2.size() << endl;
    if (heap2.empty())
        puts("��ʱ���ȶ���heap2Ϊ��");
    else
        puts("��ʱ���ȶ���heap2��Ϊ��");

    return 0;
}