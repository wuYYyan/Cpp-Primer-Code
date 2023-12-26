#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout << left;
    cout << setw(20) << "default format: " << 100 * sqrt(2.0) << endl;
    cout << setw(20) << "scientific: " << scientific << 100 * sqrt(2.0) << endl;
    cout << setw(20) << "fixed decimal: " << fixed << 100 * sqrt(2.0) << endl; 
    return 0;
}