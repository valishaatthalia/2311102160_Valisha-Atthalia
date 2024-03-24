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

a. Array adalah struktur data statis yang menyimpan elemen-elemen dengan tipe data yang sama. Elemen-elemen tersebut dapat diakses dengan menggunakan indeks. Array memiliki ukuran tetap yang ditentukan saat deklarasi.

b. Vector adalah Standard Template Library (STL) jika di dalam C/C++ memiliki bentuk std::vector. Umumnya, vector mirip seperti array yang memiliki kemampuan untuk menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan otomatis dan bersebelahan.

c. Map terasa mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer. Pada map, indeks tersebut diberi nama “key”. Pada std::map digunakan Self-Balancing Tree khususnya Red-Black Tree.


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
a. Menggunakan Struct
```C++
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
1. Program dimulai dengan mendefinisikan struktur mahasiswa_160, yang memiliki dua anggota: nama_160 untuk menyimpan nama mahasiswa dan jurusan_160 untuk menyimpan jurusan mahasiswa.
2. Di dalam fungsi main(), program membuat sebuah objek mhs_160 dari tipe mahasiswa_160.
3. Program kemudian menginisialisasi anggota-anggota dari objek mhs_160 dengan nama dan jurusan mahasiswa.
4. Program mencetak data mahasiswa yang telah diinisialisasi ke layar dengan menggunakan perintah cout.

#### Output:
![2311102160_Valisha Atthalia](<outputclass_unguided02.png>)

b. Menggunakan Class
```C++
#include <iostream>
using namespace std;

// Deklarasi class
class Kotak_160 {
private:
    double panjang_160;
    double lebar_160;
    double tinggi_160;

public:
    // Konstruktor
    Kotak_160 (double p, double l, double t) {
        panjang_160 = p;
        lebar_160 = l;
        tinggi_160 = t;
    }

    // Fungsi untuk menghitung volume kotak
    double hitungVolume_160() {
        return panjang_160 * lebar_160 * tinggi_160;
    }

    // Fungsi untuk menghitung luas permukaan kotak
    double hitungLuasPermukaan_160 () {
        return 2 * (panjang_160 * lebar_160 + panjang_160 * tinggi_160 + lebar_160 * tinggi_160);
    }
};

int main() {
    // Membuat objek kotak
    Kotak_160 kotak1 (3.0, 4.0, 5.0);

    // Menghitung volume dan luas permukaan kotak
    double volume_160 = kotak1.hitungVolume_160 ();
    double luas_permukaan_160 = kotak1.hitungLuasPermukaan_160 ();

    // Menampilkan hasil perhitungan
    cout << "Volume kotak: " << volume_160 << endl;
    cout << "Luas permukaan kotak: " << luas_permukaan_160 << endl;

    return 0;
}
```
1. Deklarasikan sebuah kelas bernama Kotak_160 yang memiliki atribut panjang_160, lebar_160, dan tinggi_160 yang merepresentasikan panjang, lebar, dan tinggi kotak.
2. Deklarasikan Kotak_160 yang akan digunakan untuk inisialisasi nilai-nilai awal panjang, lebar, dan tinggi kotak saat objek Kotak_160 dibuat.
3. Deklarasikan hitungVolume_160() dan hitungLuasPermukaan_160() yang digunakan untuk menghitung volume dan luas permukaan kotak berdasarkan nilai-nilai panjang, lebar, dan tinggi yang telah diinisialisasi.
4. Di dalam fungsi main(), sebuah objek Kotak_160 dengan nilai panjang 3.0, lebar 4.0, dan tinggi 5.0 dibuat.
Volume dan luas permukaan dari objek kotak tersebut dihitung menggunakan metode yang telah didefinisikan.
5. Hasil perhitungan kemudian ditampilkan menggunakan cout.

A. Fungsi dari Class
Class adalah struktur data yang mendefinisikan tipe data baru yang memiliki data (variabel anggota) dan fungsi (metode) yang terkait dengannya. Dalam class, data dan fungsi tersebut bersifat terkait dan dapat diakses melalui objek dari class tersebut. Class memungkinkan untuk menggabungkan data dan perilaku dalam satu kesatuan.

B. Fungsi dari Struct
Struct adalah struktur data yang mirip dengan class, tetapi secara default semua anggotanya adalah public (dalam class, secara default anggotanya adalah private). Struct biasanya digunakan untuk menyimpan sekumpulan data yang terkait, tetapi tidak memiliki fungsi yang terkait.

!![2311102160_Valisha Atthalia](<outputclass_unguided02.png>)

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.]
```C++
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string input_string;
    cout << "Masukkan string: ";
    getline(cin, input_string);

    map <char, int> char_frequency;

    // Menghitung frekuensi kemunculan setiap karakter
    for (char c : input_string) {
        if (isalpha(c)) {  // Memeriksa apakah karakter adalah huruf
            char_frequency[c]++;
        }
    }

    // Menampilkan frekuensi kemunculan setiap karakter
    cout << "Frekuensi kemunculan setiap karakter:\n";
    for (const auto& pair : char_frequency) {
        cout << "'" << pair.first << "' : " << pair.second << endl;
    }

    return 0;
}
```
![2311102160_Valisha Atthalia](<output_unguided03.png>)

1. string input_string; mendeklarasikan variabel input_string yang akan digunakan untuk menyimpan string yang dimasukkan oleh pengguna.
2. cout << "Masukkan string: "; menampilkan pesan untuk meminta pengguna untuk memasukkan sebuah string.
3. getline(cin, input_string); mengambil string yang dimasukkan oleh pengguna dan menyimpannya dalam variabel input_string.
4. map <char, int> char_frequency; mendeklarasikan sebuah objek dari tipe map yang menggunakan karakter sebagai kunci (key) dan bilangan bulat sebagai nilainya. Ini akan digunakan untuk menyimpan frekuensi kemunculan setiap karakter.
5. Loop for pertama digunakan untuk menghitung frekuensi kemunculan setiap karakter dalam string yang dimasukkan oleh pengguna. Jika karakter tersebut adalah huruf, maka frekuensi kemunculannya akan diinkremen.
6. Loop for kedua digunakan untuk menampilkan frekuensi kemunculan setiap karakter yang telah dihitung sebelumnya.

Perbedaan Map dan Array:
Array merupakan struktur data yang digunakan untuk menyimpan sekumpulan data dalam satu tempat. Sedangkan mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer.

## Kesimpulan
Programer harus memahami dan menguasai tipe data c++ dengan baik.Ketika Anda membuat variabel, tipe data harus ada agar variabel memiliki nilai yang jelas dan spesifik ketika digunakan. Terdapat tiga kategori tipe data: tipe data primitif atau tipe data dasar, yang mencakup integer, char, float, dan boolen; tipe data abstrak atau tipe data yang dapat dibentuk sendiri, yang mencakup struct dan class; dan tipe data koleksi atau tipe data yang digunakan untuk pengelompokan, yang mencakup array, map, dan vector. Agar program yang dibuat dapat berjalan dengan benar, efisien, dan terhindar dari kesalahan (error).

## Referensi
[1] Muharajul Zani (2019). Penjelasan Struktur Data Majemuk. Lampung : Universitas Mitra Indonesia.
[2] Hermawan T. “Buku Ajar Panduan Praktikum STRUKTUR DATA.” Text-Id.123dok.com, 2014, text-id.123dok.com/document/zkxv02ey-buku-ajar-panduan-praktikum-struktur-data.html. 