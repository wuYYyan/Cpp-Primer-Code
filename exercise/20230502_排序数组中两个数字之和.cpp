#include <iostream>

using namespace std;

const int SIZE = 5;

pair<int, int> func(int arr[], int n, int target);

int main()
{
    int arr[SIZE] = {1, 2, 4, 6, 10};
    int sum = 0;

    cout << "Please enter a number you want to find: ";
    cin >> sum;

    pair<int, int> p = func(arr, SIZE, sum);

    cout << "The index of two numbers are: " << p.first << " and " << p.second << endl;

    return 0;
}

pair<int, int> func(int arr[], int n, int target)
{
    int i = 0, j = n - 1;
    while(i < j && arr[i] + arr[j] != target)
    {
        if(arr[i] + arr[j] > target)
            j--; //只能递减右指针，而不能递增左指针，因为原数组是递增数组
        else
            i++;
    }

    return pair<int, int>(i, j);
}