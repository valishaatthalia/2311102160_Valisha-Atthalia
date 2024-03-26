#include <iostream>
using namespace std;

int main() {
    int size_x, size_y, size_z;

    // Meminta pengguna untuk memasukkan ukuran array tiga dimensi
    cout << "Masukkan jumlah elemen untuk dimensi X: ";
    cin >> size_x;
    cout << "Masukkan jumlah elemen untuk dimensi Y: ";
    cin >> size_y;
    cout << "Masukkan jumlah elemen untuk dimensi Z: ";
    cin >> size_z;

    // Membuat array tiga dimensi dengan ukuran yang dimasukkan pengguna
    int array_3d[size_x][size_y][size_z];

    // Meminta pengguna untuk memasukkan nilai-nilai elemen
    for (int i = 0; i < size_x; ++i) {
        for (int j = 0; j < size_y; ++j) {
            for (int k = 0; k < size_z; ++k) {
                cout << "Masukkan nilai untuk elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array_3d[i][j][k];
            }
        }
    }

    // Mencetak array tiga dimensi yang dibuat
    cout << "Array tiga dimensi yang dibuat:" << endl;
    for (int i = 0; i < size_x; ++i) {
        for (int j = 0; j < size_y; ++j) {
            for (int k = 0; k < size_z; ++k) {
                cout << array_3d[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}