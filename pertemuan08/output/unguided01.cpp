#include <iostream>
#include <string>

using namespace std;
// Fungsi untuk mengurutkan karakter atau huruf kedalam string menggunakan Bubble Sort
void bubbleSort_160(string & Kalimat_160)
{
    int n = Kalimat_160.size();
    // Perulangan untuk semua elemen dalam string
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (Kalimat_160[j] > Kalimat_160[j + 1])
            {
                swap(Kalimat_160[j], Kalimat_160[j + 1]);
            }
        }
    }
}

// Fungsi untuk mencari karakter atau huruf dalam string yang sudah diurutkan menggunakan Binary Search
void binarySearch_160(const string & Kalimat_160, char cari_160)
{
    bool ditemukan = false;
    cout << " Kata setelah diurutkan: " << Kalimat_160 << endl;
    cout << " Huruf '" << cari_160 << "' ditemukan pada indeks ke : ";
    // Perulangan untuk mencari huruf dalam string
    for (size_t i = 0; i < Kalimat_160.size(); ++i)
    {
        if (Kalimat_160[i] == cari_160)
        {
            ditemukan = true;
            cout << i << " ";
        }
    }
    cout << endl;
    // percabangan apabila huruf tidak ditemukan dalam kata atau huruf
    if (!ditemukan)
    {
        cout << " Huruf '" << cari_160 << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main()
{
    // variable kalimat dan cari
    string Kalimat_160;
    char cari_160;
    
    cout << " Masukkan kalimat : ";
    getline(cin, Kalimat_160);

    // Urutkan kalimat menggunakan bubble sort
    bubbleSort_160(Kalimat_160);
    cout << " Kalimat setelah Anda urutkan : " << Kalimat_160 << endl;

    cout << " Masukkan huruf yang ingin Anda cari : ";
    cin >> cari_160;

    // Cari huruf dalam kalimat menggunakan binary search
    binarySearch_160(Kalimat_160, cari_160);

    return 0;
}