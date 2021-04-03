#include <iostream>

using namespace std;

int coin_change_ways(int arr[], int N, int d) {
    if (d == 0)
        return 1;
    if (d < 0) 
        return 0;
    if (N <= 0 && d >= 1) {
        return 0;
    } 
    return coin_change_ways(arr, N-1, d) + coin_change_ways(arr, N, d-arr[N-1]);
}

int main() {
    int d = 4;
    int arr[] = { 1, 2, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << coin_change_ways(arr, N, d) << endl;
    return 0;
}   