#include <iostream>

using namespace std;

int num_edit(string str1, string str2, int n, int m) {
    if (m == 0)
        return n;

    if (n == 0)
        return m;
    
    if (str1[m-1] == str2[n-1]) {
        return num_edit(str1, str2, m - 1, n - 1);
    }

    return 1 + min(
        num_edit(str1, str2, m, n-1), //Insert
        num_edit(str1, str2, m-1, n), //Remove
        num_edit(str1, str2, m-1, n-1) //Replace
    );
}       

int main() {
    string str1 = "geek";
    string str2 = "gesek";
    int n = str1.size();
    int m = str2.size();

    cout << num_edit(str1, str2, n, m);

    return 0;
}