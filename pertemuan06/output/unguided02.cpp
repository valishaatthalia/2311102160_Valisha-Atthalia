#include <iostream>
#include <stack>
#include <string>

using namespace std;

string BalikkanKata_160(string kalimat_160) {
    stack<char> karakterStack_160;

    // Operasi PUSH
    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (char karakterKata : kalimat_160) {
        karakterStack_160.push(karakterKata);
    }

    string BalikkanKata_160 = " ";

    // Operasi POP
    // Mengeluarkan setiap karakter dari stack untuk membentuk kalimat terbalik
    
    while (!karakterStack_160.empty()) {
        BalikkanKata_160 += karakterStack_160.top();
        karakterStack_160.pop();
    }

    return BalikkanKata_160;
}

int main() {
    string kalimat_160;

    cout << "Masukkan Kata ";
    getline(cin, kalimat_160);

    string kalimatTerbalik = BalikkanKata_160(kalimat_160);
    cout << "DataStack Array : " <<  endl;
    cout << "Data : " << kalimatTerbalik << endl;

    return 0;
}