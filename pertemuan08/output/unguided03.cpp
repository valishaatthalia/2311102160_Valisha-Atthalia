#include <iostream>

using namespace std;

int main()
{
    // variable untuk data cari true false nilai dan jumlah angka
    int a = 10;
    int data_160[a] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari_160;
    bool ketemu_160 = false;
    int jumlahAngka_160 = 0;

    // menampilkan dara awall
    cout << "data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Masukkan angka yang ingin Anda cari: ";
    // input cari
    cin >> cari_160;

    // perulangan untuk apakah nilai data sama dengan apa yang di cari
    for (int i = 0; i < a; ++i)
    {
        if (data_160[i] == cari_160)
        {
            ketemu_160 = true;
            jumlahAngka_160++;
        }
    }

    //percabangan ketika data di temukan dan data tidak di temukan
    if (ketemu_160)
    {
        cout << "\nAngka " << cari_160 << " ditemukan sebanyak " << jumlahAngka_160 << endl;
    }
    else
    {
        cout << cari_160 << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}