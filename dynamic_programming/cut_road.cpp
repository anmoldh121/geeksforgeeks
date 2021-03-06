#include <iostream>
#include <climits>
 
using namespace std;

int cut_road(int price[], int n) {
    if (n <= 0) 
        return 0;
    int max_val = INT_MIN;

    for (int i=0; i<n; i++) {
        max_val = max(max_val, price[i] + cut_road(price, n-i-1));
    }
    return max_val;
}   

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    cout << cut_road << endl;
    return 0;
}