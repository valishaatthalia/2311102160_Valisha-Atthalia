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