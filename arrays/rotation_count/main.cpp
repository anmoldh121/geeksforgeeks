#include <iostream>

using namespace std;

int find_Start_point(int arr[], int n) {
    int i;
    for (i=1; i<n; i++) {
        if (arr[n-1] > arr[n]) {
            break;
        }
    }
    return i;
}

int find_rotation_count(int arr[], int n) {
    int pivot = find_Start_point(arr, n);
    return pivot + 1;
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = find_rotation_count(arr, n);
    cout << result << endl;
}