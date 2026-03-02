#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {

    Mahasiswa mhs[5] = {
        {"ali", "026", 3.2},
        {"manda", "011", 3.6},
        {"azmi", "033", 3.1},
        {"syadid", "046", 3.7},
        {"dapa", "003", 3.8}
    };

    #//cari ipk tinggi
    int idxMax = 0;
    for(int i = 1; i < 5; i++) {
        if(mhs[i].ipk > mhs[idxMax].ipk) {
            idxMax = i;
        }
    }

    cout << "Data Mahasiswa:\n";
    for(int i = 0; i < 5; i++) {
        cout << mhs[i].nama << " | "
             << mhs[i].nim << " | "
             << mhs[i].ipk << endl;
    }

    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[idxMax].nama << endl;
    cout << "NIM  : " << mhs[idxMax].nim << endl;
    cout << "IPK  : " << mhs[idxMax].ipk << endl;

    return 0;
}