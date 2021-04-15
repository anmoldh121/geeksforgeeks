/*
    Base Case

    T(1) = Entry time Line 1 + Time spent in station S(1,1) = e1 + a(1,1)
    T(2) = Entry time Line 2 + Time spent in station S(2,1) = e2 + a(2,1)

    Recursive Case

    Case 1
    T1(j) = Minimum Time taken to leave S(1,j-1) + Time spent in station S(1, j) = T1(j-1) + a(1,j)

    Case 2 
    T1(j) = Minimum time taken to leave S(2,j-1) + Extra Cost + Time spent in station S(1, j) = T2(j-1) + a(1,j) + t2

    T1(j) = min((T1(j-1) + a(1,j)), T2(j-1) + a(1,j) + t(2,j))

    T2(j) = min((T2(j-1) + a(2,j)), T1(j-1) + a(2,j) + t(1,j))


    Tmin = minimum time taken to leave station S(i,n) + Time taken to exit the car factory
    Tmin = min (T1(n)+x1, T2(n) + x2)  
*/

#include <iostream>

using namespace std;

#define NUM_STATION 4

int carAssembly(int a[][NUM_STATION], int t[][NUM_STATION], int e[], int x[]) {
    int T1[NUM_STATION], T2[NUM_STATION];
    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];

    for (int i=1; i<NUM_STATION; i++) {
        T1[i] = min(
            (T1[i-1] + a[0][i]),
            (T2[i-1] + a[0][i] + t[1][i])
            );
        T2[i] = min(
            (T2[i-1] + a[1][i]),
            (T1[i-1] + a[1][i] + t[0][i])
        );
    }

    return min(T1[NUM_STATION-1] + x[0], T2[NUM_STATION-1] +x[1]);
}

int main() {
    int a[][NUM_STATION] = {
        {4, 5, 3, 2},
        {2, 10, 1, 4}
    };
    int t[][NUM_STATION] = {
        {0, 7, 4, 5},
        {0, 9, 2, 8}
    };
    int e[] = {10 , 12}, x[] = {18, 7}; 
    cout << carAssembly(a, t, e, x);
    return 0;
}

