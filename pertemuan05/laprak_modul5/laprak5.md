# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Valisha Atthalia Naura Irfan - 2311102160</p>

## Dasar Teori

Hashing adalah teknik untuk melakukan penambahan, penghapusan dan pencarian dengan constant average time Untuk menambahkan data atau pencarian, ditentukan key dari data tersebut dan digunakan sebuah fungsi hash untuk menetapkan lokasi untuk key tersebut. Hash tables adalah array dengan sel-sel yang ukurannya telah ditentukan dan dapat berisi data atau key yang berkesesuaian dengan data. Untuk setiap key, digunakan fungsi hash untuk memetakan key pada bilangan dalam rentang 0 hingga H-size-1.
Fungsi hash harus memiliki sifat berikut:
a. Mudah dihitung.
b. Dua key yang berbeda akan dipetakan pada dua sel yang berbeda
pada array.
c. Membagi key secara rata pada seluruh sel.
Sebuah fungsi hash sederhana adalah menggunakan fungsi mod (sisa bagi) dengan bilangan prima. Dapat menggunakan manipulasi digit dengan kompleksitas rendah dan distribusi key yang rata.

## Guided 

### 1. [Hash Table Sederhana]

```C++
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

// Fungsi Hash Sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// Struktur Data Untuk Setiap Node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class Hash Table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << " : " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```
Program ini adalah hash table sederhana yang digunakan untuk menyimpan pasangan kunci dan nilainya. Dengan menggunakan library iostream, program ini memiliki tabel hash dengan ukuran 10 dan MAX_SIZE. Fungsi hash_func digunakan untuk membuat indeks hash dari kunci yang diberikan. Hash table memiliki setiap node yang dapat menyimpan data dan memiliki pointer untuk menunjukkan ke node berikutnya. Untuk mengatur data dalam hash table, class HashTable memiliki fungsi insert, get, remove, dan traverse. Dalam bagian inti, program membuat objek ht dari class HashTable untuk melakukan berbagai operasi tersebut. Berikut merupakan hasil output dari program di atas adalah:
Get key 1: 10
Get key 4: -1
3 : 30
2 : 20
1 : 10

### 2. [Hash Table dengan Node]

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap
{
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
        }
    }
};

int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}
```
Program tersebut menjalankan struktur data hash table, yang digunakan untuk menyimpan dan mengakses pasangan nomor dan nama. Dalam program ini, ada dua kelas, "HashNode" dan "HashMap". Kelas pertama menunjukkan setiap node dalam tabel hash dan memiliki dua variabel anggota, name dan phone_number, yang digunakan untuk menyimpan nama dan nomor telepon. Kelas kedua menampilkan tabel hash sebagai array dinamis dari vektor atau vector yang berisi pointer ke objek HashNode untuk mengelola tabel hash. Tiga pasangan nama dan nomor telepon dimasukkan ke dalam tabel hash, kemudian dilakukan pencarian untuk mencari nomor telepon berdasarkan nama yang ada, dan kemudian satu pasangan nama dan nomor telepon dihapus dari tabel hash. Setelah operasi-operasi ini selesai, isi tabel hash secara keseluruhan dicetak untuk ditampilkan.

## Unguided

### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai.]

Dengan ketentuan : 

a. Setiap mahasiswa memiliki NIM dan nilai.

b. Program memiliki tampilan pilihan menu berisi poin C.

c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
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
```
#### Output:
![2311102160](<output_ke1.png>)
![2311102160](<output_ke2.png>)
![2311102160](<output_ke3.png>)
![2311102160](<output_ke4.png>)

 Struktur data ini memungkinkan untuk menambah, menghapus, mencari, dan menampilkan data siswa berdasarkan nama atau NIM serta mencari data siswa berdasarkan rentang nilai. Untuk mengelola data siswa, program ini menggunakan kelas HashMap, yang memungkinkan beberapa operasi utama seperti memasukkan, menghapus, mencariByNIM, mencariRentangNilai, dan menulis. Setiap siswa diwakili oleh objek HashNode yang menyimpan informasi nama, NIM, dan nilai. Kelas HashMap memiliki tabel hashing yang digambarkan sebagai array vektor dinamis dengan ukuran tabel diubah menjadi bilangan prima untuk meningkatkan efisiensi hashing. Fungsi hashing digunakan untuk mengonversi nama siswa dalam tabel hashing menjadi indeks.
Sebuah menu interaktif di fungsi main memungkinkan pengguna melakukan hal-hal berikut:
1. Menambah data mahasiswa dengan memasukkan nama, NIM, dan nilai.
2. Menghapus data mahasiswa berdasarkan nama.
3. Mencari data mahasiswa berdasarkan NIM.
4. Mencari data mahasiswa berdasarkan rentang nilai.
5. Menampilkan seluruh data mahasiswa yang tersimpan.
6. Keluar dari program.
7. Setelah pengguna memilih opsi, program akan menjalankan operasi yang sesuai dan mengulangi menu hingga pengguna memilih untuk keluar.


## Kesimpulan
Hash table adalah struktur data yang memungkinkan penyimpanan dan akses data dengan efisiensi tinggi. Kelebihannya meliputi efisiensi waktu operasi seperti insert, delete, dan search yang cepat dengan waktu rata-rata O(1). Selain itu, hash table ideal untuk data dengan frekuensi operasi yang tinggi dan menggunakan algoritma hashing untuk mempercepat pencarian data. Selain efisien dalam penggunaan memori, hash table juga memiliki teknik-teknik seperti open hashing, separate chaining, dan closed hashing untuk mengurangi kemungkinan collision dalam penyimpanan data.

## Referensi
[1] Manurung R, Azurat A. Hash Table. Hash Table. Published online 2008:4-5. http://aren.cs.ui.ac.id/sda/resources/sda2010/15_hashtable.pdf

[2] Hussain Anwar," Cara Jitu Mahir C++ untuk Pemula". Jakarta: Elex media, 2020.