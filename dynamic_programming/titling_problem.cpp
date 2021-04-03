#include <iostream>

using namespace std;

int tiling_(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return tiling_(n-1) + tiling_(n-2); 
}

int main() {
    cout << tiling_(4) << endl;
    return 0;
}