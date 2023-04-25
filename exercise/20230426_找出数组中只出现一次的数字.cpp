#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findSingleNumber(vector<int> v);

int main()
{
    vector<int> v = {1, 2, 3, 4, 3, 6, 7, 6, 1, 2, 4};
    

    printf("The number in array appears only once is: ");
    printf("%d\n", findSingleNumber(v));

    return 0;
}

int findSingleNumber(vector<int> v)
{
    sort(v.begin(), v.end());
    /*
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;
    */

    int n = v.size();
    int i, j;
    for(i = 0, j = 0; j < n; i = j)
    {
        int num = 0;
        while(v[i] == v[j])
        {
            j++;
            num ++;
        }
        if(num == 1)
            return v[i];
    }
    return v[i];
}