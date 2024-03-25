#include <iostream>
using namespace std;

int main() {
    int Arr_160; // Ukuran Array yang dimasukkan oleh pengguna
    cout << "> Masukkan ukuran Array: ";
    cin >> Arr_160;

    // Alokasi dinamis array
    int *Valisha_160 = new int[Arr_160]; // Array untuk menyimpan angka genap
    int *Amelia_160 = new int[Arr_160]; // Array untuk menyimpan angka ganjil
    int Genap_160 = 0; // Jumlah angka genap
    int Ganjil_160 = 0; // Jumlah angka ganjil

    // Meminta pengguna memasukkan angka
    cout << "> Masukkan " << Arr_160 << " angka (dipisah pake spasi):\n";
    for (int i = 0; i < Arr_160; ++i) {
        if (!(cin >> Valisha_160[i])) {
            cout << "Input tidak mencukupi atau tidak valid." << endl;
            return 1;
        }
        // Memisahkan angka genap dan ganjil
        if (Valisha_160[i] % 2 == 0) {
            Genap_160++;
        } else {
            Amelia_160 [Ganjil_160] = Valisha_160[i];
            Ganjil_160++;
        }
    }

    cout << "\n<<<<< HASIL >>>>>" << endl;

    // Menampilkan data array yang sudah diinput oleh user
    cout << "Data Array   : ";
    for (int i = 0; i < Arr_160; ++i) // Melakukan perulangan untuk menampilkan data array
        cout << Valisha_160[i] << " ";
    cout << endl;

    // Menampilkan angka genap
    cout << "Nomor Genap  : ";
    for (int i = 0; i < Arr_160; ++i) {
        if (Valisha_160[i] % 2 == 0)
            cout << Valisha_160[i] << ", ";
    }
    cout << endl;

    // Menampilkan angka ganjil
    cout << "Nomor Ganjil : ";
    for (int i = 0; i < Ganjil_160; ++i) { 
        cout << Amelia_160[i] << ", ";
    }
    cout << endl;

    // Dealokasi memori setelah selesai digunakan
    delete[] Valisha_160;
    delete[] Amelia_160;

    return 0;
}