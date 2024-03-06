#include <iostream>

using namespace std;

// Fungsi untuk menjumlahkan dua bilangan
int tambah(int a, int b) {
    return a + b;
}

// Fungsi untuk mengalikan dua bilangan
int kali(int a, int b) {
    return a * b;
}

// Fungsi utama
int main() {
    // Deklarasi variabel
    int bilangan1, bilangan2;

    // Input dua bilangan dari pengguna
    cout << "Masukkan bilangan pertama: ";
    cin >> bilangan1;
    cout << "Masukkan bilangan kedua: ";
    cin >> bilangan2;

    // Menampilkan hasil penjumlahan
    int hasil_tambah = tambah(bilangan1, bilangan2);
    cout << "Hasil penjumlahan: " << hasil_tambah << endl;

    // Menampilkan hasil perkalian
    int hasil_kali = kali(bilangan1, bilangan2);
    cout << "Hasil perkalian: " << hasil_kali << endl;

    return 0;
}