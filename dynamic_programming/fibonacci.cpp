#include <iostream>

using namespace std;

int fibonacci_number(int n) {
    int dp[n];
    
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n = 9;
    cout << fibonacci_number(n);
}