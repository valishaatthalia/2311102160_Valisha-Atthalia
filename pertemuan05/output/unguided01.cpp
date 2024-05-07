#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int TABLE_SIZE = 100; // Ukuran tabel diubah menjadi bilangan prima untuk meningkatkan efisiensi hashing

// Struktur data mahasiswa
struct Mahasiswa {
    string nama_160;
    string nim_160;
    int nilai_160;
};

// Struktur data untuk setiap node
class HashNode {
public:
    string name_160;
    string nim_160;
    int nilai_160;

    HashNode(string name_160, string nim_160, int nilai_160) : name_160(name_160), nim_160(nim_160), nilai_160(nilai_160) {}
};

// Class HashMap
class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name_160, string nim_160, int nilai_160) {
        int hash_val = hashFunc(name_160);
        for (auto node : table[hash_val]) {
            if (node->name_160 == name_160) {
                node->nim_160 = nim_160;
                node->nilai_160 = nilai_160;
                cout << "Data Mahasiswa dengan Nama " << name_160 << " berhasil ditambahkan." << endl;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name_160, nim_160, nilai_160));
    }

    void remove(string name_160) {
        int hash_val = hashFunc(name_160);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); ++it) {
            if ((*it)->name_160 == name_160) {
                delete *it;
                table[hash_val].erase(it);
                cout << "Data Mahasiswa dengan nama " << name_160 << " berhasil dihapus." << endl;
                return;
            }
        }
    }

    void searchByNIM(string nim_160) {
        bool found = false;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto node : table[i]) {
                if (node->nim_160 == nim_160) {
                    cout << "\n CARI DATA MAHASISWA (NIM)" << endl;
                    cout << " ---------------------------------------------------" << endl;
                    cout << left << "| " << setw(15) << "Nama"
                         << "| " << setw(20) << "NIM"
                         << "| " << setw(10) << "Nilai"
                         << " |" << endl;
                    cout << " ---------------------------------------------------" << endl;
                    cout << "| " << left << setw(15) << node->name_160
                         << "| " << left << setw(20) << node->nim_160
                         << "| " << left << setw(10) << node->nilai_160 << " |" << endl;
                    cout << " ---------------------------------------------------" << endl;
                    found = true;
                    return;
                }
            }
        }
        if (!found) {
            cout << "Mahasiswa dengan NIM " << nim_160 << " tidak ditemukan." << endl;
        }
    }

    void CariRentangNilai(int NilaiMin, int NilaiMax) {
        bool found = false;
        cout << "\n CARI DATA MAHASISWA (RENTANG NILAI)" << endl;
        cout << " ---------------------------------------------------" << endl;
        cout << left << "| " << setw(15) << "Nama"
             << "| " << setw(20) << "NIM"
             << "| " << setw(10) << "Nilai"
             << " |" << endl;
        cout << " ---------------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto node : table[i]) {
                if (node->nilai_160 >= NilaiMin && node->nilai_160 <= NilaiMax) {
                    cout << "| " << left << setw(15) << node->name_160
                         << "| " << left << setw(20) << node->nim_160
                         << "| " << left << setw(10) << node->nilai_160 << " |" << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "Tidak ada data Mahasiswa dengan nilai antara " << NilaiMin << " dan " << NilaiMax << "." << endl;
        }
        cout << " ---------------------------------------------------" << endl;
    }

    void print() {
        cout << "\n DATA MAHASISWA" << endl;
        cout << " ---------------------------------------------------" << endl;
        cout << left << "| " << setw(15) << "Nama"
             << "| " << setw(20) << "NIM"
             << "| " << setw(10) << "Nilai"
             << " |" << endl;
        cout << " ---------------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto pair : table[i]) {
                cout << "| " << left << setw(15) << pair->name_160
                     << "| " << left << setw(20) << pair->nim_160
                     << "| " << left << setw(10) << pair->nilai_160 << " |" << endl;
            }
        }
        cout << " ---------------------------------------------------" << endl;
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto node : table[i]) {
                delete node;
            }
        }
    }
};

int main() {
    HashMap map;
    int choice;
    string name_160;
    string nim_160;
    int nilai_160;
    int search1, search2;
    do {
        cout << "\n MENU LIST NILAI MAHASISWA" << endl;
        cout << "1. Tambah data Mahasiswa" << endl;
        cout << "2. Hapus data Mahasiswa" << endl;
        cout << "3. Cari data Mahasiswa (NIM)" << endl;
        cout << "4. Cari data Mahasiswa (Rentang Nilai)" << endl;
        cout << "5. Tampilkan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nTAMBAH DATA MAHASISWA" << endl;
                cout << "Masukkan Nama: ";
                cin >> name_160;
                cout << "Masukkan NIM: ";
                cin >> nim_160;
                cout << "Masukkan Nilai: ";
                cin >> nilai_160;
                map.insert(name_160, nim_160, nilai_160);
                break;
            case 2:
                cout << "\nHAPUS DATA MAHASISWA (Nama)" << endl;
                cout << "Masukkan Nama: ";
                cin >> name_160;
                map.remove(name_160);
                break;
            case 3:
                cout << "\nCARI DATA MAHASISWA (NIM)" << endl;
                cout << "Masukkan NIM: ";
                cin >> nim_160;
                map.searchByNIM(nim_160);
                break;
            case 4:
                cout << "\nCARI DATA MAHASISWA (RENTANG NILAI)" << endl;
                cout << "Masukkan Nilai minimum: ";
                cin >> search1;
                cout << "Masukkan Nilai maksimum: ";
                cin >> search2;
                map.CariRentangNilai(search1, search2);
                break;
            case 5:
                map.print();
                break;
            case 6:
                break;
            default:
                cout << "Pilihan tidak tersedia!" << endl;
        }
    } while (choice != 6);
    return 0;
}