# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Valisha Atthalia Naura Irfan - 2311102160</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.]

```C++
#include <iostream>

using namespace std;

int main(){
    int n = 10; //deklarasi variabel n sebagai ukuran array
    int data[10] = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}; //deklarasi array data 
    int cari = 10; //deklarasi variabel cari dengan nilai 10 (angka yang dicari adalah 10)
    bool ketemu = false; //deklarasi variabel boolean ketemu dengan nilai false
    int i; //deklarasi variabel i

    //Sequential Search untuk mencari angka 10
    for(i=0; i < n; i++){
        if(data[i] == cari){ //jika nilai pada array data index ke i adalah 10, maka 
            ketemu = true; //ubah variabel boolean ketemu menjadi true
            break; //perulangan berhenti
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "Data = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}" << endl; //menampilkan isi array data

    if(ketemu){ //jika angka 10 ditemukan, maka tampilkan
        cout << "\nAngka " << cari << " ditemukan pada indeks ke " << i << endl; 
    } else { //jika angka 10 tidak ditemukan, maka tampilkan
        cout << "Data tidak ditemukan!" << endl;
    }

    return 0;
}
```
1. Deklarasi Variabel:
- n: Variabel integer yang diinisialisasi ke 10, mewakili ukuran array.
- data: Array integer berukuran 10, diinisialisasi dengan nilai {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}.
- cari: Variabel integer yang diinisialisasi ke 10, mewakili nilai yang akan dicari.
- ketemu: Variabel boolean yang diinisialisasi ke false, menunjukkan apakah nilai pencarian telah ditemukan.
- i: Variabel integer yang digunakan sebagai penghitung loop.

2. Loop Pencarian Sekuensial:
- Loop for mengiterasi array data dari indeks 0 ke n - 1.
- Di dalam loop:
  Kondisi data[i] == cari memeriksa apakah elemen saat ini (data[i]) sama dengan nilai pencarian (cari).
Jika kondisinya benar:
  a. Variabel ketemu diatur ke true, menunjukkan bahwa nilai pencarian telah ditemukan.
  b. Pernyataan break digunakan untuk keluar dari loop segera.
Jika kondisinya salah, loop berlanjut ke iterasi berikutnya.

3. Output:
- Pesan "Program Pencarian Sekuensial" dicetak ke konsol.
- Array data dicetak ke konsol menggunakan format "Data = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}".

4. Pemeriksaan Hasil Pencarian:
- Pernyataan kondisional if (ketemu) memeriksa apakah variabel ketemu benar (artinya nilai pencarian telah ditemukan).
Jika ketemu benar:
  a. Pesan "Angka 10 ditemukan pada indeks ke 2" dicetak ke konsol, menunjukkan bahwa nilai 10 ditemukan pada indeks 2 array.
Jika ketemu salah:
Pesan "Data tidak ditemukan!" dicetak ke konsol, menunjukkan bahwa nilai 10 tidak ditemukan dalam array.

### 2. [Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.]

```C++
#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7}; //deklarasi array dataArray beserta isinya
int cari; //deklarasi variabel cari

//prosedur Selection_Sort untuk mengurutkan data secara ascending
void Selection_Sort(){
    int temp, min, i, j; 
    for(i = 0; i < 7; i++){ //perulangan for untuk memeriksa setiap data 
        min = i; //nilai min adalah 0
        for(j = i + 1; j < 7; j++){ //nilai j adalah 1
            if(dataArray[j] < dataArray[min]){ //jika nilai pada dataArray index ke j (1) kurang dari nilai pada dataArray index ke i (0), maka 
                min = j; //nilai min adalah j
            }
        }
        temp = dataArray[i]; //masukkan nilai pada dataArray index ke i kedalam temp
        dataArray[i] = dataArray[min]; //isi dataArray index ke i dengan dataArray index min (j)
        dataArray[min] = temp; //isi dataArray index min (j) dengan nilai temp
    }
}

//prosedur BinarySearch untuk mencari data
void BinarySearch(){
    int awal, akhir, tengah; //deklarasi variabel awal, akhir, tengah
    bool b_flag = false; //deklarasi variabel boolean b_flag dengan nilai false 
    awal = 0; //nilai awal adalah 0
    akhir = 6; //nilai akhir adalah 6
    while(!b_flag && awal <= akhir){
        tengah = (awal + akhir)/2; //menghitung nilai tengah
        if(dataArray[tengah] == cari){ //jika data yang dicari berada di tengah, maka
            b_flag = true; //ubah b_flag menjadi true
        } else if(dataArray[tengah] < cari){  //jika data yang dicari lebih besar dari data yang ditengah (data berada di kanan), maka
            awal = tengah + 1; //nilai awal adalah tengah + 1
        } else { //jika data yang dicari lebih kecil dari data yang ditengah (data berada di kiri), maka
            akhir = tengah - 1; //nilai akhir adalah tengah - 1
        }
    }
    if(b_flag){ //jika data ditemukan, maka tampilkan 
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    } else { //jika data tidak ditemukan, maka tampilkan
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main(){
    cout << "BINARY SEARCH" << endl;
    cout << "\nData : ";
    //Perulangan untuk menampilkan data
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    //user menginputkan data yang ingin dicari
    cout << "Masukkan data yang ingin dicari : ";
    cin >> cari;
    
    cout << "\nData diurutkan : ";
    Selection_Sort(); //pemanggilan prosedur Selection_Sort() untuk mengurutkan data secara ascending

    //Perulangan untuk menampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    BinarySearch(); //pemanggilan prosedur BinarySearch() untuk mencari data yang ingin dicari
    _getche();
    return 0;
}
```


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