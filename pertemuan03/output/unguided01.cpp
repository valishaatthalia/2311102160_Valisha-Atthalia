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