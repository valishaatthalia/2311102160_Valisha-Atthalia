# <h1 align="center">Laporan Praktikum Modul Single and Double Linked List</h1>
<p align="center">Valisha Atthalia Naura Irfan - 2311102160</p>

## Dasar Teori

a. Single Linked List

Linked List merupakan suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas. Umumnya "linked list" berarti single linked list. Single linked list adalah daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya. Single linked list terdiri dari sejumlah node dimana setiap node memiliki pointer yang merujuk ke elemen berikut (*next). Pointer next pada node terakhir akan menunjuk ke NULL. Ini menandakan akhir dari list. Berikut meupakan ilustrasi dari sebuah single linked list.

b. Double Linked List

Berbeda dengan single linked list, double linked list adalah linked list yang memiliki dua rantai(link); yaitu satu link atau pointer yang merujuk ke node berikutnya (*next) dan satu link atau pointer yang merujuk ke node sebelumnya (*prev) Keuntungan dari double linked list adalah bahwa dengan adanya 2 buah pointer, programmer dapat melakukan operasi penghapusan dan penambahan pada simpul mana saja secara efisien. Berikut merupakan ilustrasi dari double linked list.

Secara garis besar, linked list memiliki kelebihan dan kekurangan. Kelebihan dari linked list antara lain :
- Memiliki ukuran yang dinamis, sehingga ukurannya dapat disesuaikan dengan kebutuhan
- Penambahan dan penghapusan elemen di tengah linked list bisa dilakukan dengan mudah dan efisien, tanpa memerlukan penggeseran elemen-elemen lainnya.
- Dapat digunakan sebagai dasar untuk struktur data lainnya seperti stack, queue, dan hash table.

Kekurangan dan linked list antara lain :
- Penggunaan Memori Tambahan untuk Pointer (*next dan *prev)
- Data didalam list tidak terurut

## Guided 

### 1. [Single Linked List]
```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
//Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
            cout << "List kosong!" << endl;
        }
    }
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Linked list tersebut menyimpan data dalam simpul-simpul yang saling terhubung. Fungsi dari program ini untuk menambahkan, menghapus, mengubah, dan menampilkan data dalam linked list. Setiap simpul memiliki data dan pointer yang menunjuk ke simpul berikutnya. Program ini menggunakan operasi-operasi dasar pada linked list seperti tambah depan, tambah belakang, tambah tengah, hapus depan, hapus belakang, hapus tengah, ubah depan, ubah belakang, ubah tengah, dan tampilkan isi linked list.

### 2. [Double Linked List]
```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};  

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Dalam program ini, dua kelas utama didefinisikan: kelas Node, yang merepresentasikan simpul dalam Doubly Linked List, dan kelas DoublyLinkedList, yang menyediakan operasi-operasi dasar untuk mengelola Doubly Linked List. Kelas Node memiliki tiga anggota data yaitu data, prev, dan next. Data digunakan untuk menyimpan nilai integer dalam simpul, sedangkan prev dan next adalah pointer yang menunjuk ke simpul sebelumnya dan berikutnya secara berturut-turut. Kelas DoublyLinkedList memiliki dua pointer utama yaitu head dan tail, yang masing-masing menunjuk ke simpul pertama dan terakhir dalam daftar. Konstruktor kelas ini menginisialisasi pointer-head dan pointer-tail ke nullptr, menandakan bahwa daftar saat ini kosong.

## Unguided 

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user]
![2311102160](<soal_no1.png>)
```C++
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Mendeklarasikan struct Node
struct Node {
    string nama_160;
    int umur_160;
    Node *next;
};
    Node *head; // deklarasi node sebagai head
    Node *tail; // deklarasi node sebagai tail

// Menginisialisasi Node
void inisialisasi_160(){
    head = NULL;
    tail = NULL;
}

// Pengecekan NULL
bool isEmpty_160(){
    if (head == NULL){
        return true;
    }else {
        return false;
    }
}

// Prosedure untuk memasukkan data 
// Prosedure untuk memasukkan insert depan
void insertDepan_160(string nama_160, int umur_160)
{
    Node *baru = new Node; // tambah node baru
    baru->nama_160 = nama_160; // isi node baru
    baru->umur_160 = umur_160; // isi node baru
    baru->next = NULL; // next node nya NULL
    if (isEmpty_160() == true){
        head = tail = baru;    
    }else {
        baru->next = head;
        head = baru;
    }
}

// Prosedure untuk insert belakang
void insertBelakang_160(string nama_160, int umur_160)
{
    Node *baru = new Node; // tambah node baru
    baru->nama_160 = nama_160; // isi node baru
    baru->umur_160 = umur_160; // isi node baru
    baru->next = NULL;
    if (isEmpty_160() == true){
        head = tail = baru;
    }else {
        tail->next = baru;
        tail = baru;
    }
}

// Prosedure untuk insert tengah
void insertTengah_160(string nama_160, int umur_160, int posisi_160)
{
    Node *baru = new Node;
    baru->nama_160 = nama_160;
    baru->umur_160 = umur_160;
    baru->next = NULL;
    if (isEmpty_160() == true){
        head = tail = baru;
    }else {
        Node *bantu = head;
        int nomor = 1; // deklarasi variabel nomor
        while (nomor < posisi_160 - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Fungsi Hitung Node
int hitungNode_160(){
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL){ // perulangan while
        jumlah++; // deklarasi variabel jumlah
        hitung = hitung->next;
    }
    return jumlah;
}

// Untuk menghapus data
// Prosedure untuk hapus depan
void hapusDepan_160(){
    if (isEmpty_160() == false){
        if (head->next != NULL){
            Node *hapus = head;
            head = head->next;
            delete hapus;
        }else {
            head = tail = NULL;
        }
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Prosedure untuk hapus belakang
void hapusBelakang_160(){
    if (isEmpty_160() == false){
        if (head->next != NULL){
            Node *hapus = tail;
            Node *bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next; // node bantu berlanjut ke next dari bantu
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus; // delete node hapus
        }else {
            head = tail = NULL;
        }
    }else {
        cout << "List masih kosong!" << endl;
    }
}
// Prosedure untuk hapus tengah
void hapusTengah_160(int posisi_160){
    if (posisi_160 < 1 || posisi_160 > hitungNode_160()){
        cout << "Posisi node yang akan dihapus diluar jangkauan" << endl;
    }else if (posisi_160 == 1){
        cout << "Posisi nodeyang ingin dihapus bukan posisi tengah" << endl;
    }else {
        Node *hapus = head;
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi_160 - 1){
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } 
}

// Untuk ubah data
// Prosedure untuk mengubah depan
void ubahDepan_160(string nama_160, int umur_160){
    if (isEmpty_160() == false){
        head->nama_160 = nama_160;
        head->umur_160 = umur_160;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Prosedure untuk mengubah belakang
void ubahBelakang_160(string nama_160, int umur_160){
    if (isEmpty_160() == false){
        tail->nama_160 = nama_160;
        tail->umur_160 = umur_160;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Prosedure untuk mengubah tengah
void ubahTengah_160(string nama_160, int umur_160, int posisi_160){
    if (posisi_160 < 1 || posisi_160 > hitungNode_160()){
        cout << "Posisi diluar jangkauan" << endl;
    }else if (posisi_160 == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }else {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi_160){
            bantu = bantu->next;
            nomor++;
        }
        bantu->nama_160 = nama_160;
        bantu->umur_160 = umur_160;    
    } 
}

// Prosedure untuk menghapus semua data
void hapusSemua_160(){
    if (isEmpty_160() == false){
        Node *bantu = head;
        while (bantu != NULL){
            Node *hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = tail = NULL;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Prosedure untuk menampilkan display
void display_160(){
    Node *bantu = head;
    if (!isEmpty_160()){
        cout << "|    Nama    |    Umur    |" << endl;
        while (bantu != NULL){
            cout << "| " << setw(10) << left << bantu->nama_160 << " | " << setw(10) << left << bantu->umur_160 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|-------------------------|" << endl;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    
    //Untuk inisialisasi
    inisialisasi_160();
    //Untuk menambahkan data diawali
    insertDepan_160("Karin", 18);
    insertDepan_160("Hoshino", 18);
    insertDepan_160("Akechi", 20);
    insertDepan_160("Yusuke", 19);
    insertDepan_160("Michael", 18);
    insertDepan_160("Jane", 20);
    insertDepan_160("John", 19);

    //Untuk menampilkan data diawali
    cout << "Data Mahasiswa : " << endl;
    display_160();
    cout << endl;

    //Pilihan Menu
    int pilihan_160;
    string nama_160;
    int umur_160;
    int posisi_160;
    do{
        cout << "Data Mahasiswa" << endl;
        cout << "1. Tambahkan Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Update Data Mahasiswa" << endl;
        cout << "4. Tambahkan Data Mahasiswa Urutan Tertentu" << endl;
        cout << "5. Hapus Data Mahasiswa Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data Mahasiswa" << endl;
        cout << "7. Tampilkan Data Mahasiswa" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan_160;

        switch(pilihan_160){
            //Menambahkan data
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama_160;
                cout << "Masukkan Umur: ";
                cin >> umur_160;
                insertDepan_160(nama_160, umur_160);
                break;
            //Menghapus data    
            case 2:
                hapusDepan_160();
                break;
            //Mengubah data    
            case 3:
                cout << "Masukkan Nama: "; cin >> nama_160;
                cout << "Masukkan Umur: "; cin >> umur_160;
                cout << "Masukkan Posisi: "; cin >> posisi_160;
                ubahTengah_160 (nama_160, umur_160, posisi_160);
                break;
            //Menambahkan data di posisi antara   
            case 4:
                cout << "Masukkan Nama: "; cin >> nama_160;
                cout << "Masukkan Umur: "; cin >> umur_160;
                cout << "Masukkan Posisi: "; cin >> posisi_160;
                insertTengah_160 (nama_160, umur_160, posisi_160);
                break;
            //Menghapus data di posisi antara    
            case 5:
                cout << "Masukkan Posisi: ";
                cin >> posisi_160;
                cout << "Masukkan Nama Mahasiswa yang akan dihapus: ";
                cin >> nama_160;
                cout << "Masukkan Umur Mahsiswa yang akan dihapus: ";
                cin >> umur_160;
                hapusTengah_160 (posisi_160);
                break;
            //Menghapus semua data    
            case 6:
                hapusSemua_160();
                break;
            //Menampilkan semua data    
            case 7:
                cout << "Tampilan Seluruh Data Mahasiswa" << endl;
                display_160();
                break;
            //Program selesai    
            case 8:
                cout << "Anda keluar dari program. Program selesai!" << endl;
                break;
            default:
                cout << "Pilihan yang anda masukkan tidak tersedia" << endl;
                break;
        }
    }
    while(pilihan_160 != 8);
    return 0;   
}
```
#### Output:

![2311102160](<output_unguided01.png>)
![2311102160](<Screenshot (299).png>)

Untuk menyimpan data siswa, seperti nama dan umur, program ini menggunakan struktur data daftar terhubung. Program mendeklarasikan sebuah node dengan dua atribut, yaitu nama dan umur, dan sebuah pointer next yang menunjuk ke node berikutnya. Selain itu, program mendeklarasikan dua variabel pointer head dan tail sebagai penanda awal dan akhir dari daftar terhubung, dan kemudian menetapkan berbagai cara untuk melakukan operasi pada daftar terhubung, seperti memulai, memeriksa apakah daftar terhubung kosong, menambah, menghapus, dan mengubah data di depan, belakang, dan tengah, menghitung jumlah node, dan menampilkan data. Fungsi utama program adalah mengaktifkan daftar terhubung dan menambahkan sejumlah data siswa ke dalam daftar terhubung. Selanjutnya, program memberikan menu interaktif kepada pengguna yang memungkinkan mereka melakukan berbagai hal dengan data siswa, seperti menambahkan, menghapus, mengubah, menambahkan data ke posisi tertentu, menghapus data ke posisi tertentu, menghapus semua data, dan menampilkan semua data. Switch case akan menjalankan setiap operasi yang dipilih pengguna dan memanggil prosedur yang sesuai yang telah didefinisikan sebelumnya. Hal ini memungkinkan pengguna mengelola data siswa sesuai kebutuhan mereka melalui menu yang tersedia. Program akan terus berjalan sampai pengguna memilih untuk keluar.

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.]
![2311102160](<soal_no2.png>)
![2311102160](<soalno2.png>)

```C++
#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

class Node {
public:
    string namaProduk_160;
    double harga_160;
    Node* prev;
    Node* next;

    Node(string nama, double harga_160) : namaProduk_160(nama), harga_160(harga_160), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void add_data_160 (string namaProduk_160, double harga_160) {
        Node* newNode = new Node(namaProduk_160, harga_160);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void tambahDataUrutanTertentu(string namaProduk_160, double harga_160, int posisi) {
        if (posisi < 1) {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        Node* newNode = new Node(namaProduk_160, harga_160);
        if (posisi == 1 || head == nullptr) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* current = head;
            int pos = 1;
            while (current != nullptr && pos < posisi - 1) {
                current = current->next;
                pos++;
            }
            if (current == nullptr) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }

    void hapusData(string namaProduk_160) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk_160 == namaProduk_160) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                if (current == head) {
                    head = current->next;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan" << endl;
    }

    void updateData(string namaProduk_160, string new_namaProduk_160, double newHarga_160) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk_160 == namaProduk_160) {
                current->namaProduk_160 = new_namaProduk_160;
                current->harga_160 = newHarga_160;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan" << endl;
    }

    void hapusSeluruhData() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    void hapusDataUrutanTertentu(int posisi) {
        if (posisi < 1) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        Node* current = head;
        int pos = 1;
        while (current != nullptr && pos < posisi) {
            current = current->next;
            pos++;
        }
        if (current == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        if (current == head) {
            head = current->next;
        }
        delete current;
    }

    void tampilkanData() {
        if (head == nullptr) {
            cout << "Tidak ada data yang tersedia" << endl;
            return;
        }
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << left << setw(20) << current->namaProduk_160 << current->harga_160 << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    // add data awal penjualan skincare purwokerto
    cout << "Daftar Produk" << endl;
    list.add_data_160("Originote", 60000);
    list.add_data_160("Somethinc", 150000);
    list.add_data_160("Skintific", 100000);
    list.add_data_160("Wardah", 50000);
    list.add_data_160("Hanasui", 30000);

    int pilihan;
    do {
        cout << "Toko Skincare" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Hapus Produk" << endl;
        cout << "3. Update Produk" << endl;
        cout << "4. Tambah produk berdasarkan urutan" << endl;
        cout << "5. Hapus produk berdasarkan urutan" << endl;
        cout << "6. Hapus Seluruh produk" << endl;
        cout << "7. Tampilkan Produk" << endl;
        cout << "8. Exit" << endl;

        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        string namaProduk_160, new_namaProduk_160;
        double harga_160, newHarga_160;
        int posisi;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Produk: ";
                cin >> namaProduk_160;
                cout << "Masukkan Harga: ";
                cin >> harga_160;
                list.add_data_160 (namaProduk_160, harga_160);
                break;
            case 2:
                cout << "Masukkan Nama Produk yang akan dihapus: ";
                cin >> namaProduk_160;
                list.hapusData(namaProduk_160);
                break;
            case 3:
                cout << "Masukkan Nama Produk yang akan diupdate: ";
                cin >> namaProduk_160;
                cout << "Masukkan Nama Produk baru: ";
                cin >> new_namaProduk_160;
                cout << "Masukkan Harga baru: ";
                cin >> newHarga_160;
                list.updateData(namaProduk_160, new_namaProduk_160, newHarga_160);
                break;
            case 4:
                cout << "Masukkan Nama Produk baru: ";
                cin >> namaProduk_160;
                cout << "Masukkan Harga: ";
                cin >> harga_160;
                cout << "Masukkan Urutan: ";
                cin >> posisi;
                list.tambahDataUrutanTertentu(namaProduk_160, harga_160, posisi);
                break;
            case 5:
                cout << "Masukkan Urutan produk yang akan dihapus: ";
                cin >> posisi;
                list.hapusDataUrutanTertentu(posisi);
                break;
            case 6:
                list.hapusSeluruhData();
                cout << "Produk pada posisi" << posisi << "berhasil dihapus" << endl;
                break;
            case 7:
                list.tampilkanData();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali!." << endl;
        }
    } while (pilihan != 8);

    return 0;
}
```
#### Output:
![2311102160](<output_unguided02.png>)
![2311102160](<outputunguided02.png>)

Struktur data ini digunakan untuk menyimpan informasi tentang produk skincare, seperti nama produk dan harganya. Program ini menyediakan berbagai fungsi dasar untuk operasi-operasi pada linked list, termasuk penambahan data, penghapusan data, pembaruan data, dan penampilan data.

## Kesimpulan
Linked list adalah struktur data yang terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. terdapat 2 jenis linked list, yaitu single linked list dan double linked list. Pada single linked list, setiap nodenya terdiri dari 2 bagian, yaitu nilai yang ditampung dan pointer next. Sedangkan pada double linked list, setiap nodenya terdiri dari 3 bagian, yaitu nilai yang ditampung, pointer prev, dan pointer next. Masing-masing jenis Linked List ini memiliki kelebihan dalam hal penyisipan dan penghapusan elemen yang lebih efisien dibandingkan array. Namun, Linked List juga membutuhkan lebih banyak memori karena setiap nodenya memakai lebih dari 1 blok memori dan umumnya memiliki akses data yang lebih lambat.

## Referensi
[1] Harihayati Mardzuki, Tati. (2020). Double Linked List. [Teaching Resource]. http://repository.unikom.ac.id/id/eprint/64221.
