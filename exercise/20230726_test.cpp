#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int a = 0;
    int j = 0;
    int m = 0;
    while ( m <= n ){
        a = a + 1; 
        for (int b = 1 ; b <= a ; b++){
             j = j + a;
             m = m + 1;
        }
    }
        if (m != n)
            j = j - ( m - n ) * a;
    cout << j;
    return 0;

    int sum = 0;
    int k = 1;
    while (n >= 0)
    {
        n -= k; // n = n - k;
        k += 1; // k = k + 1;
        sum = sum;
    }
}