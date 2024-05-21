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