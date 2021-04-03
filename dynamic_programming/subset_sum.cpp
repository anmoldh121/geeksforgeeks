#include <iostream>
#include <map>

using namespace std;

int subset_sum(int arr[], int n, int sum) { 
    map<int, int> m;
    int count = 0;
    for (int i=0; i<n; i++) {
        if (m[sum-arr[i]]) {
            count++;
        } else {
            m[arr[i]] = sum - arr[i];
        }
    }
    return count;
}

int main() {
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subset_sum(arr, n, sum);
    return 0;
}