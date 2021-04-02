#include <iostream>

using namespace std;

int find_max_sum(int arr[]) {
    int sum_arr = 0;
    int sum_with_index = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    n = 4;
    cout << n << endl;
    for (int i=0; i<n; i++) {
        sum_arr += arr[i];
        sum_with_index += i*arr[i];
    }

    int max_val = sum_with_index;

    for (int j=1; j<n; j++) {
        sum_with_index = sum_with_index + sum_arr-(n*arr[n-j]);
        if (max_val < sum_with_index) {
            max_val = sum_with_index;
        }
    }
    return max_val;
}

int main() {
    int arr[] = {1, 20, 2, 10};
    int result = find_max_sum(arr);
    cout << result << endl;
    return 0;
}