#include <iostream>
#include <string>
using namespace std;
 
struct mahasiswa{
    string nama;
    string jurusan;
};
 
int main(){
 
    mahasiswa mhs;
 
    mhs.nama = "Valisha Atthalia Naura Irfan";
    mhs.jurusan = "Teknik Informatika";

    
    cout << "DATA MAHASISWA" <<endl;
    cout << "Nama    : " << mhs.nama <<endl;
    cout << "Jurusan : " << mhs.jurusan <<endl;
      
    return 0;
}