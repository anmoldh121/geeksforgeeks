#include <iostream>

using namespace std;

int newman_shanks(int n) {
    int sn_1 = 1, sn_2 = 1;
    int sn;

    for (int i=2; i<=n; i++) {
        sn = 2*sn_1 + sn_2;
        sn_2 = sn_1;
        sn_1 = sn;
    }

    return sn;
}

int main() {

    cout << newman_shanks(3);
    return 0;
}