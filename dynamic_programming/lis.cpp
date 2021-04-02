#include <iostream>
#include <algorithm>

using namespace std;

int lis(int arr[], int n) {
    int dp[n];
    dp[0] = 1;

    for (int i=0; i<n; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] += 1;
            }
        }
    }
    return *max_element(dp, dp + n);
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << lis(arr, n);
    return 0;
}