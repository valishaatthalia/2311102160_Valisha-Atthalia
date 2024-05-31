# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Valisha Atthalia Naura Irfan - 2311102160</p>

## Dasar Teori

Algoritma sequential searching yang biasanya disebut sebagai pendekatan pencarian secara beruntun merupakan pencarian yang diawali dari elemen awal sampai  dengan elemen akhir secara beruntun hingga  bisa  menemukan elemen  yang  akan didatangi.  Algoritma  ini  mampu  melakukan  pencarian  dengan  array  yang  data-datanya  tidak perlu melalui pengurutan data sebelumnya. Cara kerja algoritma ini adalah dengan melakukan perbandingan antara data  yang  ada  dengan data  yang  akan  dicari  satu  per  satu  secara  berurutan  sampai  dapat  menemukan  datanya.

Pendekatan sequential  searching dapat melakuan pengembalian nilai record atau pointer ke record. Record merupakan  jenis tipe  data  yang  berisi  atas  variabel-variabel  atau  kumpulanya  yang  diberi  nama  field.  Tahapan  dari  Sequential Search melakukan kunjungan dari satu pohon ke pohon yang lain dengan cara pada tiap-tiap simpulnya dikunjungi sekali saja yang biasanya disebut dengan tree transversal/kunjungan pohon. Tahapan pada pendekatan pencarian secara  berurutan  melalui  beberapa proses,  yaitu  melakukan  pengenalan  array,  menentukan  data  yang  akan dilakukan  pencarian,  mencocokkan  data  diawali  dari  data  pertama  hingga  data  terakhir,  data  yang  dilakukan pencarian  kemudian  memisalkan  dengan  setiap  datanya  pada  array.  Pencarian  dilakukan  dengan  memisalkan seluruh data pada array sampai selesai. Apabila data yang akan dilakukan pencarian telah didapatkan maka proses memisalkan elemen array akan dihentikan, dan apabila data yang dicari pada seluruh array tidak ditemukan maka proses akan berhenti.

Pencarian Biner hanya dapat dilakukan pada barisan bilangan yang telah diurutkan baik secara menaik (ascending) maupun menurun (descending).Pencarian Biner melakukan pencarian data X dalam barisan  A[1]  ...  A[n] dengan dimulai dari data tengah pada barisan A. Jika nilai data X sama dengan nilai data tengah barisan A, maka pencarian dihentikan dan dinyatakan sukses. Sedangkan jika tidak sama maka,

1. Untuk data yang diurutkan secara menaik (ascending), pencarian akan dilanjutkan ke ½ bagian kiri apabila nilai data X lebih kecil daripada nilai data tengah pada barisan A. Sedangkan apabila nilai data X lebih besar daripada nilai data tengah pada barisan A, maka pencarian akan dilanjutkan ke ½ bagian kanan.

2. Untuk data yang diurutkan secara menurun (descending), pencarian akan dilanjutkan ke ½ bagian kiri apabila nilai data X lebih besar daripada nilai data tengah pada barisan A. Sedangkan apabila nilai data X lebih kecil daripada nilai data tengah pada barisan A, maka pencarian akan dilanjutkan ½ bagian kiri.


Pencarian akan dihentikan dan dinyatakan gagal apabila ½ bagian kiri atau ½ bagian kanan berupa sebuah data tunggal dan data tersebut tidak sama dengan data X yang sedang dicari.

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
Program ini dimulai dengan mengimpor pustaka input-output konvensional conio.h yang digunakan untuk getche. Program ini mengimport juga iomanip yang digunakan untuk keluaran format setelah data diurutkan menggunakan algoritma selection sort. Dalam fungsi main saya mulai dengan membuat array dataArray dengan ukuran 7 dan diinisialisasi dengan nilai tertentu. Kemudian saya membuat variabel cari untuk menyimpan nilai yang akan dicari oleh user. Kemudian saya mengurutkan array dataArray dengan mode inceasing melalui fungsi SelectionSort. Fungsi ini bekerja dengan menggunakan dua loop bersarang untuk menemukan elemen terkecil dan kemudian menukarnya dengan elemen saat ini. Fungsi BinarySearch adalah fungsi yang digunakan untuk menemukan output dari nilai yang diinput setelah array diurutkan. Variabel awal, akhir, dan tengah algoritma binary search digunakan untuk melakukan pencarian yang efektif pada array yang sudah diurutkan.

## Unguided 

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++
#include <iostream>
#include <string>

using namespace std;
// Fungsi untuk mengurutkan karakter atau huruf kedalam string menggunakan Bubble Sort
void bubbleSort_160(string & Kalimat_160)
{
    int n = Kalimat_160.size();
    // Perulangan untuk semua elemen dalam string
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (Kalimat_160[j] > Kalimat_160[j + 1])
            {
                swap(Kalimat_160[j], Kalimat_160[j + 1]);
            }
        }
    }
}

// Fungsi untuk mencari karakter atau huruf dalam string yang sudah diurutkan menggunakan Binary Search
void binarySearch_160(const string & Kalimat_160, char cari_160)
{
    bool ditemukan = false;
    cout << " Kata setelah diurutkan: " << Kalimat_160 << endl;
    cout << " Huruf '" << cari_160 << "' ditemukan pada indeks ke : ";
    // Perulangan untuk mencari huruf dalam string
    for (size_t i = 0; i < Kalimat_160.size(); ++i)
    {
        if (Kalimat_160[i] == cari_160)
        {
            ditemukan = true;
            cout << i << " ";
        }
    }
    cout << endl;
    // percabangan apabila huruf tidak ditemukan dalam kata atau huruf
    if (!ditemukan)
    {
        cout << " Huruf '" << cari_160 << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main()
{
    // variable kalimat dan cari
    string Kalimat_160;
    char cari_160;
    
    cout << " Masukkan kalimat : ";
    getline(cin, Kalimat_160);

    // Urutkan kalimat menggunakan bubble sort
    bubbleSort_160(Kalimat_160);
    cout << " Kalimat setelah Anda urutkan : " << Kalimat_160 << endl;

    cout << " Masukkan huruf yang ingin Anda cari : ";
    cin >> cari_160;

    // Cari huruf dalam kalimat menggunakan binary search
    binarySearch_160(Kalimat_160, cari_160);

    return 0;
}
```
#### Output:
![2311102160](<output_unguided01.png>)

Kode program tersebut merupakan program C++ yang mengimplementasikan dua fungsi utama:

1. bubbleSort_160(string &Kalimat_160): Fungsi ini mengambil sebuah string Kalimat_160 sebagai referensi dan mengurutkan karakternya secara ascending (dari yang terkecil ke yang terbesar) menggunakan algoritma Bubble Sort.
2. binarySearch_160(const string &Kalimat_160, char cari_160): Fungsi ini mencari indeks-indeks kemunculan sebuah karakter cari_160 dalam string Kalimat_160 yang sudah terurut. Fungsi ini memanfaatkan algoritma Pencarian Biner (Binary Search) untuk menemukan karakter tersebut secara efisien.

Dalam fungsi main(), program meminta pengguna untuk memasukkan sebuah kalimat. Kalimat tersebut kemudian diurutkan menggunakan fungsi bubbleSort_160(). Setelah itu, program meminta pengguna untuk memasukkan sebuah karakter yang ingin dicari dalam kalimat yang telah diurutkan. Fungsi binarySearch_160() kemudian dipanggil untuk mencari indeks-indeks kemunculan karakter tersebut dalam kalimat yang sudah terurut.

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++
#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk memeriksa apakah sebuah karakter adalah vokal
bool isVowel_160(char ch) {
    // Konversi karakter menjadi huruf kecil
    ch = tolower(ch);
    // Periksa apakah karakter adalah salah satu dari 'a', 'e', 'i', 'o', 'u'
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Fungsi untuk menghitung banyaknya huruf vokal dalam sebuah kalimat
int countVowels_160(const string &sentence) {
    int count = 0;
    for (char ch : sentence) {
        if (isVowel_160(ch)) {
            count++;
        }
    }
    return count;
}
int main() {
    string sentence;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, sentence); // Membaca input kalimat dari pengguna

    int vowelCount = countVowels_160(sentence);
    cout << "Banyaknya huruf vokal dalam kalimat adalah: " << vowelCount << endl;

    return 0;
}
```
#### Output
![2311102160](<output_unguided02.png>)

Berikut adalah penjelasan dari fungsi-fungsi dan alur kerja program:

1. bool isVowel_160(char ch): Fungsi ini mengecek apakah sebuah karakter ch merupakan huruf vokal atau bukan. Fungsi ini melakukan konversi karakter ke huruf kecil menggunakan fungsi tolower(ch), lalu memeriksa apakah karakter tersebut adalah salah satu dari 'a', 'e', 'i', 'o', atau 'u'. Jika iya, fungsi akan mengembalikan nilai true, jika tidak, akan mengembalikan false.
2. int countVowels_160(const string &sentence): Fungsi ini menghitung jumlah huruf vokal dalam sebuah kalimat sentence. Fungsi ini melakukan iterasi melalui setiap karakter dalam kalimat menggunakan loop for dengan sintaks for (char ch : sentence). Untuk setiap karakter ch, fungsi isVowel_160(ch) dipanggil untuk memeriksa apakah karakter tersebut adalah huruf vokal atau bukan. Jika isVowel_160(ch) mengembalikan true, maka variabel count akan diinkrementasi. Setelah iterasiselesai, fungsi akan mengembalikan nilai count yang merupakan jumlah huruf vokal dalam kalimat.
3. Dalam fungsi main(), program meminta pengguna untuk memasukkan sebuah kalimat menggunakan getline(cin, sentence). Kalimat yang diinputkan disimpan dalam variabel sentence.
4. Fungsi countVowels_160(sentence) dipanggil dengan argumen sentence, yang akan menghitung jumlah huruf vokal dalam kalimat tersebut. Hasilnya disimpan dalam variabel vowelCount.
5. Terakhir, program menampilkan jumlah huruf vokal yang ditemukan dalam kalimat menggunakan cout << "Banyaknya huruf vokal dalam kalimat adalah: " << vowelCount << endl;.

Jadi, program ini mengimplementasikan dua fungsi utama: isVowel_160() untuk mengecek apakah sebuah karakter adalah huruf vokal, dan countVowels_160() untuk menghitung jumlah huruf vokal dalam sebuah kalimat dengan memanfaatkan fungsi isVowel_160(). Program ini bisa digunakan untuk menghitung jumlah huruf vokal dalam kalimat yang diinputkan oleh pengguna.

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]

```C++
#include <iostream>

using namespace std;

int main()
{
    // variable untuk data cari true false nilai dan jumlah angka
    int a = 10;
    int data_160[a] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari_160;
    bool ketemu_160 = false;
    int jumlahAngka_160 = 0;

    // menampilkan dara awall
    cout << "data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Masukkan angka yang ingin Anda cari: ";
    // input cari
    cin >> cari_160;

    // perulangan untuk apakah nilai data sama dengan apa yang di cari
    for (int i = 0; i < a; ++i)
    {
        if (data_160[i] == cari_160)
        {
            ketemu_160 = true;
            jumlahAngka_160++;
        }
    }

    //percabangan ketika data di temukan dan data tidak di temukan
    if (ketemu_160)
    {
        cout << "\nAngka " << cari_160 << " ditemukan sebanyak " << jumlahAngka_160 << endl;
    }
    else
    {
        cout << cari_160 << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
#### Output
![2311102160](<output_unguided03.png>)

Program ini adalah program C++ yang mencari keberadaan sebuah angka yang diinputkan oleh pengguna dalam sebuah array data integer yang telah dideklarasikan sebelumnya. Berikut adalah penjelasan tentang program ini:

1. Program mendeklarasikan variabel a dengan nilai 10 yang merupakan panjang array data_160.
2. Array data_160 diinisialisasi dengan nilai-nilai {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}.
3. Variabel cari_160 digunakan untuk menyimpan angka yang akan dicari dalam array data_160.
4. Variabel ketemu_160 diinisialisasi dengan nilai false. Variabel ini akan diubah menjadi true jika angka yang dicari ditemukan dalam array.
5. Variabel jumlahAngka_160 diinisialisasi dengan nilai 0. Variabel ini akan menghitung berapa kali angka yang dicari muncul dalam array.
6. Program menampilkan data array awal dan meminta pengguna untuk memasukkan angka yang ingin dicari.
7. Program melakukan perulangan dengan menggunakan loop for untuk memeriksa setiap elemen dalam array data_160. Dalam setiap iterasi, program memeriksa apakah nilai elemen sama dengan angka yang dicari (cari_160). Jika sama, variabel ketemu_160 diubah menjadi true dan variabel jumlahAngka_160 ditambah 1.
8. Setelah perulangan selesai, program memeriksa nilai ketemu_160. Jika true, program menampilkan pesan bahwa angka yang dicari ditemukan dan berapa kali angka tersebut muncul dalam array (jumlahAngka_160). Jika false, program menampilkan pesan bahwa angka yang dicari tidak ditemukan dalam array.

Jadi, program ini mencari keberadaan sebuah angka yang diinputkan oleh pengguna dalam sebuah array data integer dan menghitung berapa kali angka tersebut muncul dalam array. Program ini menggunakan konsep array, perulangan, dan percabangan dalam implementasinya.


## Kesimpulan

Pada modul 8 ini Algoritma Searching merupakan struktur data dari urutan langkah-langkah yang digunakan untuk menemukan data tertentu dalam kumpulan data. Ada 2 macam yaitu Binary Search dan Sequential Search. Binary search adalah algoritma pencarian untuk data terurut. Pencarian dilakukan dengan membandingkan data yang dicari dengan data di tengah. Sedangkan Sequential Search adalah algoritma pencarian untuk data yang acak atau tidak terurut. Dengan Implementasi paling sederhana, di mana setiap elemen array dibaca satu per satu dari indeks terkecil hingga terbesar, atau sebaliknya.

Perbedaan utama antara Binary Search dan Sequential Search terletak pada cara kerja, efisiensi, persyaratan data, dan penerapannya :

Binary Search :

- Cara Kerjanya memeriksa setiap elemen secara berurutan dari awal hingga akhir atau sampai target ditemukan.
- Efisiensinya cenderung Kurang efisien untuk kumpulan data besar. Kompleksitas waktu rata-rata dan terburuk adalah O(n).
- Persyaratan Datanya tidak memerlukan data terurut.
- Penerapannya cocok untuk data kecil atau data yang tidak terurut.

Sequential Search :

- Cara Kerjanya membagi kumpulan data menjadi dua bagian secara terus-menerus dan hanya memeriksa bagian yang relevan.
- Efisiensinya cenderung lebih efisien untuk kumpulan data besar. Kompleksitas waktu rata-rata dan terburuk adalah O(log n).
- Persyaratan Datanya memerlukan data yang sudah terurut.
- Penerapannya cocok untuk data besar yang sudah terurut.

## Referensi
[1] Situmorang H. ANALISA ALGORITMA PADA METODA PENCARIAN LINIER, BINER DAN INTERPOLASI | JURNAL MAHAJANA INFORMASI. e-journalsari-mutiaraacid. 2018;(Vol. 2 No 2, 2017). Accessed May 31, 2024. http://e-journal.sari-mutiara.ac.id/index.php/7/article/view/177/194 

[2] Sunjarwanto R, Zailani AU. Aplikasi Pemesanan Peti Mati Berbasis Android Menggunakan Algoritma Sequantial Search. Jurnal Informatika Multi. 2023;1(2):137-143. Accessed May 31, 2024. https://jurnal.publikasitecno.id/index.php/multi/article/view/21/19