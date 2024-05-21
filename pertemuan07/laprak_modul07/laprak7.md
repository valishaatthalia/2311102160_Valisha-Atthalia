# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Valisha Atthalia Naura Irfan - 2311102160</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Queue]

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;  // Maksimal antrian
int front = 0;                // Penanda antrian
int back = 0;                 // Penanda
string queueTeller[5];        // Fungsi pengecekan

bool isFull() {               // Pengecekan antrian penuh atau tidak
  if (back == maksimalQueue) {
    return true;  // =1
  } else {
    return false;
  }
}

bool isEmpty() {  // Antriannya kosong atau tidak
  if (back == 0) {
    return true;
  } else {
    return false;
  }
}

void enqueueAntrian(string data) {  // Fungsi menambahkan antrian
  if (isFull()) {
    cout << "Antrian penuh" << endl;
  } else {
    if (isEmpty()) {  // Kondisi ketika queue kosong
      queueTeller[0] = data;
      front++;
      back++;
    } else {  // Antrianya ada isi
      queueTeller[back] = data;
      back++;
    }
  }
}

void dequeueAntrian() {  // Fungsi mengurangi antrian
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    for (int i = 0; i < back; i++) {
      queueTeller[i] = queueTeller[i + 1];
    }
    back--;
  }
}

int countQueue() {  // Fungsi menghitung banyak antrian
  return back;
}

void clearQueue() {  // Fungsi menghapus semua antrian
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    for (int i = 0; i < back; i++) {
      queueTeller[i] = "";
    }
    back = 0;
    front = 0;
  }
}

void viewQueue() {  // Fungsi melihat antrian
  cout << "Data antrian teller:" << endl;
  for (int i = 0; i < maksimalQueue; i++) {
    if (queueTeller[i] != "") {
      cout << i + 1 << ". " << queueTeller[i] << endl;
    } else {
      cout << i + 1 << ". (kosong)" << endl;
    }
  }
}

int main() {
  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  return 0;
}
```
Kode ini berfungsi untuk mengelola antrian dengan beberapa operasi dasar seperti menambah elemen ke antrian (enqueue) menghapus elemen dari antrian (dequeue), mengecek apakah antrian penuh atau kosong, menghitung jumlah elemen dalam antrian, menghapus semua elemen dari antrian, dan menampilkan isi antrian.

## Unguided 

### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]

```C++
#include<iostream>

using namespace std;

//Deklarasi struct node
struct node{ 
    string data_160;
    node *next;
};
    node *front; 
    node *back; 

//Prosedur inisialisasi node front dan back sebagai NULL
void Inisialisasi_160(){ 
    front = NULL;
    back = NULL;
}

//Fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty_160(){
    if (front == 0){
        return true; 
    } else {
        return false; 
    }
}

//Prosedur untuk menambahkan data pada antrian
void TambahData_160(string data_160){
    node *baru = new node; 
    baru->data_160 = data_160; 
    baru->next = NULL; 
    if(isEmpty_160() == true){ 
        front = back = baru; 
        back->next = NULL; 
    } else if(isEmpty_160() == false){ 
        back->next = baru; 
        back = baru; 
    }
}

//Prosedur untuk mengurangi antrian (lanjut ke antrian selanjutnya)
void KurangiAntrian_160(){
    node *hapus; 
    if(isEmpty_160() == true){ 
        cout << "Antrian masih kosong!" << endl;
    } else if(isEmpty_160() == false){ 
        if(front->next != NULL){ 
            hapus = front; 
            front = front->next; 
            delete hapus; 
        } else { 
            front = back = NULL; 
        }
    }
}

//Fungsi untuk menghitung jumlah antrian
int HitungAntrian_160(){
    node * hitung; 
    hitung = front; 
    int jumlah_160 = 0; 
    while(hitung != NULL){ 
        hitung = hitung->next; 
        jumlah_160++; 
    }
    return jumlah_160; 
}

//Prosedur untuk menghapus seluruh antrian
void HapusAntrian_160(){
    node * hapus, * bantu; 
    bantu = front; 
    while(bantu != NULL){ 
        hapus = bantu; 
        bantu = bantu->next; 
        delete hapus; 
    }
    front = back = NULL; 
}

//Prosedur untuk menampilkan antrian
void LihatAntrian_160(){
    node * bantu; 
    bantu = front; 
    if(isEmpty_160() == true){ 
        cout << "Antrian kosong!" << endl; 
    } else if(isEmpty_160() == false){ 
        cout << "===== Data Antrian =====" << endl;  
        int NomorAntrian_160 = 1; 
        while(bantu != NULL){ 
            cout << NomorAntrian_160 << ". " << bantu->data_160 << endl; 
            bantu = bantu->next; 
            NomorAntrian_160++; 
        }
    }
    cout << endl;
}

int main(){
    //Menambah 3 data nama kedalam antrian
    TambahData_160("Alya");
    TambahData_160("Kiki");
    TambahData_160("Artika");

    //Menampilkan data yang sudah ditambahkan
    LihatAntrian_160();

    //Mengurangi data
    KurangiAntrian_160();

    //menampilkan data setelah dikurangi
    LihatAntrian_160();

    //Menghapus seluruh antrian
    HapusAntrian_160();

    //menampilkan data setelah dihapus
    LihatAntrian_160();
    
    return 0;
}
```
#### Output:
![2311102160](<unguided01.png>)

Program ini mengimplementasikan antrian menggunakan linked list di C++. Dengan operasi dasar enqueue, dequeue, pengecekan antrian kosong, menghitung jumlah elemen, menghapus semua elemen, dan menampilkan isi antrian, program ini menyediakan cara yang efisien dan dinamis untuk mengelola data dalam bentuk antrian.

### 2. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]

```C++
#include <iostream>

using namespace std;

// Deklarasi struct node
struct node {
    string nama_160;
    string nim_160;
    node *next;
};

node *front; // node depan
node *back;  // node belakang

// Prosedur Inisialisasi node front dan back sebagai NULL
void Inisialisasi_160() {
    front = NULL;
    back = NULL;
}

// Fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty_160() {
    return front == NULL;
}

// Prosedur tuntuk menambahkan data pada antrian
void TambahData_160(string name_160, string nim_160) {
    node *baru = new node;
    baru->nama_160 = name_160;
    baru->nim_160 = nim_160;
    baru->next = NULL;
    if (isEmpty_160()) {
        front = back = baru;
    } else {
        back->next = baru;
        back = baru;
    }
}

// Prosedur untuk mngurangi data dari antrian (lanjut ke antrian selanjutnya)
void KurangiAntrian_160() {
    if (isEmpty_160()) {
        cout << "Antrian masih kosong!" << endl;
    } else {
        node *hapus = front;
        front = front->next;
        delete hapus;
        if (front == NULL) {
            back = NULL;
        }
    }
}

// Fungsi untuk menghitung jumlah antrian
int HitungAntrian_160() {
    int jumlah_160 = 0;
    node *hitung = front;
    while (hitung != NULL) {
        hitung = hitung->next;
        jumlah_160++;
    }
    return jumlah_160;
}

// Prosedur untu menghapus semua antrian
void HapusAntrian_160() {
    node *hapus, *bantu = front;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    front = back = NULL;
}

// Prosedur untuk mampilkan antrian
void LihatAntrian_160() {
    if (isEmpty_160()) {
        cout << "Antrian kosong!" << endl;
    } else {
        cout << "===== Data antrian =====" << endl;
        node *bantu = front;
        int NomorAntrian_160 = 1;
        while (bantu != NULL) {
            cout << NomorAntrian_160 << ". Nama: " << bantu->nama_160 << ", NIM: " << bantu->nim_160 << endl;
            bantu = bantu->next;
            NomorAntrian_160++;
        }
    }
    cout << endl;
}

int main() {
    Inisialisasi_160();
    
    // Tambah 3 data mahasiswa ke antrian
    TambahData_160("Alya", "2311102122");
    TambahData_160("Kiki", "2311102123");
    TambahData_160("Artika", "2311102124");
    TambahData_160("Nadhila Amalia","2311102125");
    TambahData_160("Golda Khairunnisa","2311102126");

    // Menampilkan data yang sudah ditambah
    LihatAntrian_160();

    // Mengurangi data
    KurangiAntrian_160();

    // Menampilkan data setelah dikurangi
    LihatAntrian_160();

    // Menghapus semua antrian
    HapusAntrian_160();

    // Menampilkan data setelah dihapus
    LihatAntrian_160();

    return 0;
}
```
#### Output:
![2311102160](<unguided02.png>)

Kode program tersebut adalah implementasi struktur data Queue (Antrian) menggunakan Linked List dalam bahasa C++. Berikut adalah penjelasan dari kode program tersebut:

Program dimulai dengan deklarasi struct node yang berisi data nama_160, nim_160, dan pointer next yang menunjuk ke node berikutnya Dideklarasikan dua pointer front dan back yang masing-masing akan menunjuk ke node depan dan node belakang dari queue. Terdapat beberapa fungsi dan prosedur yang didefinisikan:

- Inisialisasi_160() untuk menginisialisasi front dan back sebagai NULL.
- isEmpty_160() untuk mengecek apakah queue kosong atau tidak.
- TambahData_160() untuk menambahkan data baru ke queue.
- KurangiAntrian_160() untuk menghapus data dari depan queue.
- HitungAntrian_160() untuk menghitung jumlah data dalam queue.
- HapusAntrian_160() untuk menghapus semua data dalam queue.
- LihatAntrian_160() untuk menampilkan semua data dalam queue.
- Inisialisasi queue dengan memanggil Inisialisasi_160().
- Menambahkan 5 data mahasiswa ke dalam queue dengan memanggil TambahData_160().
- Data dalam queue ditampilkan dengan memanggil LihatAntrian_160().
- Data di depan queue dihapus dengan memanggil KurangiAntrian_160().
- Data dalam queue setelah penghapusan ditampilkan kembali dengan memanggil LihatAntrian_160().
- Semua data dalam queue dihapus dengan memanggil HapusAntrian_160().
- Data dalam queue (yang seharusnya sudah kosong) ditampilkan kembali dengan memanggil LihatAntrian_160().

Kode program ini mengimplementasikan operasi-operasi dasar pada struktur data Queue seperti enqueue (menambahkan data), dequeue (menghapus data dari depan), menghitung jumlah data, dan menghapus semua data dari queue.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.