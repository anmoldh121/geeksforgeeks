#include <iostream>
#include <vector>

using namespace std;

int find_num_ways(int n, int k) {
    long total = k;
    int mod = 1000000007;

    int same = 0, diff = k;
    
    for (int i = 3; i <= n; i++) {
        same = diff;
        diff = total*(k-1);
        diff = diff % mod;
        total = (same + diff) % mod;
    }
    return total;
}

int main() {
    int n = 2, k = 3;
    cout << find_num_ways(n, k);
    return 0;
}