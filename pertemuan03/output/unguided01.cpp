#include <iostream>

using namespace std;

struct Node {
  string nama;
  int usia;
  Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void tambahData() {
  string nama;
  int usia;

  cout << "Masukkan nama: ";
  cin >> nama;

  cout << "Masukkan usia: ";
  cin >> usia;

  Node *baru = new Node;
  baru->nama = nama;
  baru->usia = usia;
  baru->next = NULL;

  if (head == NULL) {
    head = tail = baru;
  } else {
    tail->next = baru;
    tail = baru;
  }
}

void tampilkanData() {
  Node *current = head;

  while (current != NULL) {
    cout << "Nama: " << current->nama << endl;
    cout << "Usia: " << current->usia << endl << endl;
    current = current->next;
  }
}

int main() {
  int pilihan;

  do {
    cout << "1. Tambah Data" << endl;
    cout << "2. Tampilkan Data" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        tambahData();
        break;
      case 2:
        tampilkanData();
        break;
      case 3:
        cout << "Terima kasih!" << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (pilihan != 3);

  return 0;
}