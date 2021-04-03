#include <iostream>

using namespace std;

int findUglyNumber(int n) {
    int arr[n];
    arr[0] = 1;

    int i1 = 0 , i2 = 0, i3 = 0;

    int next_multiple_of_2 = arr[i1]*2;
    int next_multiple_of_3 = arr[i2]*3;
    int next_multiple_of_5 = arr[i3]*5;
    int next_ugly_number = 1;
    
    for (int i=1; i< n; i++) {
        next_ugly_number = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        arr[i] = next_ugly_number;
        if (next_ugly_number == next_multiple_of_2) {
            i1 = i1 + 1;
            next_multiple_of_2 = arr[i1]*2;
        }    
        if (next_ugly_number == next_multiple_of_3) {
            i2 = i2 + 1;
            next_multiple_of_3 = arr[i2]*3;
        }    
        if (next_ugly_number == next_multiple_of_5) {
            i3 = i3 + 1;
            next_multiple_of_5 = arr[i3]*5;
        }    
    } 
    return next_ugly_number;
}

int main() {
    int n = 150;
    cout << findUglyNumber(n) << endl;
    return 0;
}