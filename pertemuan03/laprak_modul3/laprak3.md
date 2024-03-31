# <h1 align="center">Laporan Praktikum Modul Single and Double Linked List</h1>
<p align="center">Valisha Atthalia Naura Irfan - 2311102160</p>

## Dasar Teori

a. Single Linked List
Linked List merupakan suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas. 

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

```C++
#include <iostream>

using namespace std;

struct Node {
  string nama;
  int usia;
  Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void tambahData() {
  string nama;
  int usia;

  cout << "Masukkan nama: ";
  cin >> nama;

  cout << "Masukkan usia: ";
  cin >> usia;

  Node *baru = new Node;
  baru->nama = nama;
  baru->usia = usia;
  baru->next = NULL;

  if (head == NULL) {
    head = tail = baru;
  } else {
    tail->next = baru;
    tail = baru;
  }
}

void tampilkanData() {
  Node *current = head;

  while (current != NULL) {
    cout << "Nama: " << current->nama << endl;
    cout << "Usia: " << current->usia << endl << endl;
    current = current->next;
  }
}

int main() {
  int pilihan;

  do {
    cout << "1. Tambah Data" << endl;
    cout << "2. Tampilkan Data" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        tambahData();
        break;
      case 2:
        tampilkanData();
        break;
      case 3:
        cout << "Terima kasih!" << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (pilihan != 3);

  return 0;
}
```
#### Output:
![2311102160](<output_unguided01.png>)

Struktur node ini merepresentasikan simpul (node) dalam linked list. Setiap simpul memiliki dua variabel: nama untuk menyimpan nama dan usia untuk menyimpan usia, serta next yang merupakan pointer ke simpul berikutnya dalam linked list. Variabel head dan tail digunakan untuk menandai awal (head) dan akhir (tail) dari linked list. Pada awalnya, keduanya diatur ke NULL karena linked list masih kosong. Pada fungsi tambahData() meminta user untuk memasukkan nama dan usia, kemudian membuat simpul baru dengan data tersebut. Jika linked list masih kosong, simpul baru tersebut akan menjadi head dan tail. Jika tidak, simpul baru akan ditambahkan di belakang (sebagai simpul baru) dan tail akan diperbarui. Di fungsi tampilkanData() digunakan untuk menampilkan seluruh data yang tersimpan dalam linked list. Ini dilakukan dengan menelusuri linked list dari head sampai NULL sambil mencetak setiap elemen. Fungsi utama program yang berisi loop utama adalah untuk menampilkan menu kepada user dan memanggil fungsi sesuai dengan pilihan pengguna. Program akan terus berjalan sampai user memilih untuk keluar.

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.]


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.