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


#include <iostream>
using namespace std;
 
class mahasiswa {
public:
    int nim = 1;
    string nama = "default name"; 
    float nilai=0; 
 
    void setterNilai (float Nilai) {
        nilai=aNilai;
    }
    void printData(){
        cout << "NIM   \t= " << nim << endl;
        cout << "Nama  \t= " << nama << endl;
        cout << "Nilai \t= " << nilai << endl;
    }
};
 
int main() {
    mahasiswa anton,budi;
    cout<<"Anton" << endl;
    anton.printData();
    cout<<"==Budi==="<<endl;
    budi.printData();
 
    return 0;
}