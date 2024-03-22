# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Valisha Atthalia Naura Irfan - 2311102160</p>

## Dasar Teori

Tipe data adalah sebuah pengklasifikasi data berdasarkan jenis data tesebut. Tipe data dibutuhkan agar kompiler dapat mengetahui bagaimana sebuah data akan digunakan.
1. Tipe Data Primitif

Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem, tipe ini disediakan oleh berbagai macam pemrogramman, perbedaannya terletak pada jumlah bit yang dialokasikan untuk setiap bit pada tipe data primitif tergantung pada bahasa pemrogramman, compiler dan sistem operasinya. 

2. Tipe data Abstrak

Tipe data abstrak atau Abstrak Data Tipe (ADT) adalah tipe data yang dibentuk oleh programer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data. Fitur Class adalah fitur Object Oriented Program(OOP) pada bahasa C++ yang mirip dengan fitur data structures Struct pada bahasa C. Keduanya berfungsi untuk membungkus tipe data di dalamnya sebagai anggota. Menurut learn microsoft.com perbedaan antara Sturct dan Class adalah pada akses defaultnya diman Struct bersifat public dan Class bersifat private.

3. Tipe Data Koleksi

Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. Ada beberapa tipe data koleksi yang umum digunakan dalam pemrograman, dan di antaranya adalah:

a. Array

Array adalah struktur data statis yang menyimpan elemen-elemen dengan tipe data yang sama. Elemen-elemen tersebut dapat diakses dengan menggunakan indeks. Array memiliki ukuran tetap yang ditentukan saat deklarasi.

b. Vector

Vector adalah Standard Template Library (STL) jika di dalam C/C++ memiliki bentuk std::vector. Umumnya, vector mirip seperti array yang memiliki kemampuan untuk menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan otomatis dan bersebelahan.

c. Map

Map terasa mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer. Pada map, indeks tersebut diberi nama “key”. Pada std::map digunakan Self-Balancing Tree khususnya Red-Black Tree.


## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    char op;
    float num1, num2;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter two operands: ";
    cin >> num1 >> num2;
    switch (op) {
        case '+':
            cout << "Result: " << num1 + num2;
        break;
        case '-':
            cout << "Result: " << num1 - num2;
        break;
        case '*':
            cout << "Result: " << num1 * num2;
        break;
        case '/':
        if (num2 != 0) {
            cout << "Result: " << fixed << setprecision(2) << 
            num1 / num2;
        } else {
            cout << "Error! Division by zero is not allowed.";
        }
        break;
            cout << "Error! Operator is not correct";
    }
return 0;
}
```
1. Fungsi main() dimulai dengan mendeklarasikan variabel op (untuk menyimpan operator), num1, dan num2 (untuk menyimpan dua bilangan yang akan dioperasikan).
2. Pengguna diminta untuk memasukkan operator matematika (+, -, *, /) dan dua bilangan.
3. Program menggunakan switch-case untuk mengevaluasi operator yang dimasukkan oleh pengguna. Setiap case mengimplementasikan operasi matematika yang sesuai terhadap dua bilangan dan menampilkan hasilnya.
4. Jika operator yang dimasukkan adalah '/' (pembagian), program memeriksa apakah bilangan kedua tidak sama dengan nol. Jika iya, itu akan melakukan pembagian dan menampilkan hasil dengan menggunakan presisi dua angka desimal. Jika tidak, program akan menampilkan pesan kesalahan karena pembagian dengan nol tidak diperbolehkan.
5. Jika operator yang dimasukkan tidak cocok dengan operator yang diharapkan, program akan menampilkan pesan kesalahan.
6. Setelah melakukan operasi yang sesuai, program mengembalikan nilai 0, menandakan bahwa program telah berjalan dengan sukses.


### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>
#include <string.h>

//Struct
struct Mahasiswa{

    char name[50];
    char address[100];
    int age;
};

int main(){
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;
    
    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf ("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
Kode di atas digunakan untuk memberikan sebuah informasi data mahasiswa dan mencetak informasi ke layar.

### 3. [Tipe Data Koleksi]

```C++
#include <iostream>
#include <array>

using namespace std;
int main() {
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    
    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
return 0;
}
```
Kode di atas digunakan untuk memberikan sebuah informasi data mahasiswa dan mencetak informasi ke layar.

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!] 

```C++
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
```
Dua fungsi didefinisikan
a. tambah(int a, int b): Fungsi ini mengambil dua parameter integer dan mengembalikan hasil penjumlahan dari kedua parameter tersebut.
b. kali(int a, int b): Fungsi ini mengambil dua parameter integer dan mengembalikan hasil perkalian dari kedua parameter tersebut.

#### Output:
![2311102160_valisha output 1](<output_unguided01.png>)

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]
```C++
// 1. Menggunakan Struct
#include <iostream>
#include <string>
using namespace std;
 
struct mahasiswa_160 {
    string nama_160;
    string jurusan_160;
};
 
int main(){
 
    mahasiswa mhs_160;
 
    mhs.nama_160 = "Valisha Atthalia Naura Irfan";
    mhs.jurusan_160 = "Teknik Informatika";
    
    cout << "DATA MAHASISWA" << endl;
    cout << "Nama    : " << mhs.nama_160 << endl;
    cout << "Jurusan : "<< mhs.jurusan_160 << endl;
      
    return 0;
}
```

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Output:
!![2311102160_Valisha Atthalia](<output_unguided02.png>)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.