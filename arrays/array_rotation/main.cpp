#include<iostream>

using namespace std;

// Euclids formula for gcd
int gcd(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        return gcd(a-b, b);
    }

    return gcd(a, b-a);
}

int main() {
    int arr[] = { 4, 2, 3, 7, 5, 6, 10, 8, 9, 1, 11, 12 };
    int d = 3, n = 12;

    d = d%n;

    int g_c_d = gcd(d, n);
    cout << g_c_d << endl; 

    for (int i = 0; i < g_c_d; i++) {
        int temp = arr[i];
        int j = i;

        while (1) {
            int k = j + d;
            if (k >= n) {
                k = k-n;
            }

            if (k == i) {
                break;
            }

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }

    for (int i=0 ; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}