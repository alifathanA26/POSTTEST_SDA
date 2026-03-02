#include <iostream>
using namespace std;

int FindMin(int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }
    return min;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int indexMin;

    int min = FindMin(A, 8, indexMin);

    cout << "Nilai minimum: " << min << endl;
    cout << "Indeks minimum: " << indexMin << endl;

    return 0;
}

/*
Analisis Kompleksitas FindMin
Pseudocode + Cost:

1  min ← A[0]                → c1
2  for i ← 1 to n-1          → c2 (n-1 kali)
3     if A[i] < min          → c3 (n-1 kali)
4        min ← A[i]          → c4 (tergantung kondisi)
5  return min                → c5

BEST CASE (nah untuk array sudah minimum di awal, maka nya tak pernah masuk if):
Tmin(n) = c1 + c2(n-1) + c3(n-1) + c5
        = a(n-1) + b
        = O(n)

WORST CASE (pada bagian ini array menurun, hingga selalu masuk if):
Tmax(n) = c1 + c2(n-1) + c3(n-1) + c4(n-1) + c5
        = a(n-1) + b
        = O(n)

Jadi untuk kesimpulan:
Best Case  = O(n)
Worst Case = O(n)
*/
