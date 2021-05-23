#include <iostream>
#include <map>

using namespace std;

int newman_conway(int n, map<int, int> &memo) {
    if (n == 1 || n == 2)
        return 1;
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    memo[n] = newman_conway(newman_conway(n-1, memo), memo) + newman_conway(n - newman_conway(n-1, memo), memo);
    return memo[n];
}

int main() {
    int n = 10;
    map<int, int> memo;
    cout << newman_conway(n, memo);
    return 0;
}