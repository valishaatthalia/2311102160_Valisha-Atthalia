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


## Guided 1

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

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.