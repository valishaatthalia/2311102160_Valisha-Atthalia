# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Valisha Atthalia Naura Irfan - 2311102160</p>

## Dasar Teori

#### Pengertian Graph dan Pohon

1. Pengertian Graph

Graph atau Graf atau lintasan adalah struktur data non-linier yang terdiri dari node atau verteks yang terhubung oleh edge. Setiap node dapat memiliki beberapa edge yang menghubungkannya dengan node lain, dan setiap edge dapat memiliki bobot atau label yang terkait dengannya. Graf dapat digunakan untuk merepresentasikan hubungan antara objek, seperti jaringan sosial, halaman web, atau struktur molekul. Secara matematis, Graph dinyatakan dengan : G = (V, E)

Graf G didefinisikan sebagai graph atau pasangan himpunan (V, E), ditulis dengannotasi G=(V, E), yang dalam hal ini V adalah himpunan tidak-kosong dari simpul-simpul(vertices atau node) dan E adalah himpunan sisi (edges atau arcs) yang menghubungkan sepasang simpul.

Simpul pada graf dapat dinomori dengan huruf seperti a, b, c, d, dst atau bisa dengan bilangan asli 1, 2, 3, dst atau gabungan keduanya. Sedangkan sisi yang menghubungkan simpul a dan b dinyatakan dalam sepasang (a,b) atau dinyatakan dalam lambang e1, e2, e3, dst.

2. Pengertian Pohon

Tree atau Pohon adalah jenis graf yang khusus, yang terhubung, tak berarah, dan tidak memiliki siklus. Ini terdiri dari satu set node tertaut yang terurut dalam grafik yang terhubung, dimana setiap node memiliki paling banyak satu simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. Tree atau Pohon digunakan untuk merepresentasikan hubungan hirarkis antara objek, seperti sistem file atau struktur organisasi.

Istilah Tree(Pohon) :

- Root (akar) adalah node dengan hirarki tertinggi.
- Parent adalah node yang berada satu level di atas node yang ditinjau (parent adalah node yang memiliki child).
- Sibling adalah node-node yang memiliki parent yang sama dengan node yang ditinjau.
- Child adalah node yang berada dibawah node parent.
- Leaf adalah node yang tidak memiliki child.
- Subtree adalah pohon yang terdiri dari sebuah simpul (node) dalam pohon utama beserta semua turunannya (descendants).
- Level atau aras adalah posisi atau kedalaman suatu simpul (node) dalam pohon, dimulai dari level 0 pada node root.
- Size adalah banyaknya node dalam suatu tree.
- Height adalah banyaknya tingkatan atau level dalam suatu tree.
- Degree adalah banyaknya child dalam suatu node.
- Descendant adalah seluruh node yang terletak setelah node tertentu dan terletak pada jalur yang sama.

Operasi pada Tree(Pohon) :

- Create; digunakan untuk membuat tree baru.
- Clear; digunakan untuk menghapus tree.
- isEmpty; digunakan untuk memeriksa apaah tree kosong atau tidak.
- insert (left or right); digunakan untuk menambah node child (kanan maupun kiri).
- Find; digunakan untuk mencari root, parent, left child, atau right child dari suatu node.
- Update; digunakan untuk mengubah isi dari node yang ditunjuk.
- Retrieve; digunakan untuk mengetahui isi dari node yang ditujuk.
- Charasteristic; digunakan untuk mengetahui karakteristik dari suatu tree, yakni size, height, dan average length-nya
- Traverse; digunakan untuk mengunjungi seluruh node dengan cara traversal. Terdapat 3 metode traverse, yaitu PreOrder (mencetak root - child kiri - child kanan), InOrder (mencetak child kiri - root - kanan), dan PostOrder (mencetak child kiri - child kanan - root).

## Guided 

### 1. [Program Graph ]

```C++
#include <iostream>
#include <iomanip>

using namespace std;
string simpul [7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur [7] [7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph () {
    for (int baris = 0; baris < 7; baris++) {
        cout << "" << setiosflags (ios::left) << setw (15) << simpul [baris] << " : ";
        for ( int kolom = 0; kolom < 7; kolom++) {
            if (busur [baris] [kolom] !=0) {
                cout << "" << simpul [kolom] << "(" << busur [baris] [kolom] << ")";
            }
        } cout << endl; 
    }
}

int main () {
    tampilGraph ();
    return 0;
}
```
Program diatas merupakan implementasi dasar dari algoritma pencarian linier (sequential search) dalam bahasa pemrograman C++. Program ini dimulai dengan mendeklarasikan dan menginisialisasi beberapa variabel penting: n yang mewakili ukuran array, data yang merupakan array berisi sepuluh elemen integer, cari yang merupakan nilai yang ingin dicari dalam array, serta ketemu, sebuah variabel boolean yang digunakan untuk melacak apakah nilai yang dicari ditemukan dalam array. Nilai awal ketemu adalah false, menandakan bahwa nilai belum ditemukan. Variabel i digunakan sebagai indeks untuk iterasi. Dalam loop for, program melakukan iterasi melalui setiap elemen array dari indeks 0 hingga n-1. Pada setiap iterasi, program memeriksa apakah elemen saat ini (data[i]) sama dengan nilai cari. Jika ditemukan kesamaan, ketemu diubah menjadi true dan loop dihentikan menggunakan pernyataan break untuk menghindari iterasi yang tidak perlu. Setelah loop selesai, program mencetak pesan pembuka "Program Sequential Search" dan menampilkan isi array. Kemudian, program memeriksa nilai ketemu untuk menentukan hasil pencarian. Jika ketemu bernilai true, program mencetak bahwa angka yang dicari ditemukan pada indeks tertentu. Jika tidak, program mencetak bahwa angka tersebut tidak ditemukan dalam array. Program ini menggambarkan cara kerja pencarian linier yang sederhana namun efektif untuk dataset kecil, meskipun kurang efisien untuk dataset yang lebih besar karena memiliki kompleksitas waktu O(n).

### 2. [Program Tree]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat sebagai root." << endl;
    } else {
        cout << "\nTree sudah ada!" << endl;
    }
}

Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon* insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent) {
                cout << "Parent : (tidak punya parent)" << endl;
            } else {
                cout << "Parent : " << node->parent->data << endl;
            }
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) {
                cout << "Sibling : " << node->parent->left->data << endl;
            } else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) {
                cout << "Sibling : " << node->parent->right->data << endl;
            } else {
                cout << "Sibling : (tidak punya sibling)" << endl;
            }
            if (!node->left) {
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            } else {
                cout << "Child Kiri : " << node->left->data << endl;
            }
            if (!node->right) {
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            } else {
                cout << "Child Kanan : " << node->right->data << endl;
            }
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            if (node != root) {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    cout << "\nSize Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}

int main() {
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);

    retrieve(nodeC);
 
    find(nodeC);

    cout << "\nSize Tree: " << size() << endl;
    cout << "Height Tree: " << height() << endl;
    cout << "Average Node of Tree: " << size() / height() << endl;

    cout << "\nPreOrder: ";
    preOrder();
    cout << "\nInOrder: ";
    inOrder();
    cout << "\nPostOrder: ";
    postOrder();
    cout << endl;

    return 0;
}
```
Program ini mengimplementasikan struktur data pohon biner dalam C++. Program ini mencakup berbagai fungsi untuk memanipulasi pohon biner, seperti membuat node, menambahkan node ke kiri atau kanan, memperbarui nilai node, menampilkan data node, dan mencari node tertentu. Selain itu, program ini juga menyediakan metode untuk menelusuri pohon dengan tiga cara (pre-order, in-order, dan post-order) serta menghitung ukuran dan tinggi pohon. Fungsi lain termasuk menghapus seluruh pohon atau subpohon tertentu, serta menampilkan karakteristik pohon seperti ukuran dan rata-rata node per level. Pada bagian akhir program, terdapat demonstrasi penggunaan berbagai fungsi ini dengan membangun sebuah pohon, melakukan beberapa operasi pada node, dan menampilkan hasil penelusuran serta karakteristik pohon.

## Unguided 

### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.]

```C++
#include <iostream> 
#include <vector>   
#include <string>   

using namespace std; 

int main()
{
    int JumlahSimpul_160; 
    // Menampilkan judul program
    cout << "\n>>>>>>> Program graph menghitung jarak dari sebuah kota <<<<<<<" << endl;
    // Meminta pengguna memasukkan jumlah simpul
    cout << "\nSilakan masukan jumlah simpul : ";
    cin >> JumlahSimpul_160; // Membaca input jumlah simpul dari pengguna

    vector<string> NamaSimpul_160(JumlahSimpul_160);
    // Mendeklarasikan matriks untuk menyimpan bobot (jarak) antar simpul
    vector<vector<int>> bobot_160(JumlahSimpul_160, vector<int>(JumlahSimpul_160));

    // Meminta pengguna memasukkan nama-nama simpul
    cout << "Silakan masukan nama simpul" << endl;
    for (int i_160 = 0; i_160 < JumlahSimpul_160; ++i_160)
    {
        // Meminta input nama simpul dari pengguna
        cout << "Simpul " << i_160 + 1 << " : ";
        cin >> NamaSimpul_160[i_160]; // Membaca input nama simpul dan menyimpannya ke dalam vektor
    }

    // Meminta pengguna memasukkan bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i_160 = 0; i_160 < JumlahSimpul_160; ++i_160)
    {
        for (int j_160 = 0; j_160 < JumlahSimpul_160; ++j_160)
        {
            // Meminta input bobot (jarak) dari simpul i ke simpul j
            cout << NamaSimpul_160[i_160] << "--> " << NamaSimpul_160[j_160] << " = ";
            cin >> bobot_160[i_160][j_160]; // Membaca input bobot dan menyimpannya ke dalam matriks
        }
    }

    cout << endl; 
    cout << "     "; 
    for (const string &Nama_160 : NamaSimpul_160)
    {
        cout << Nama_160 << "  "; 
    }
    cout << endl;

    for (int i_160 = 0; i_160 < JumlahSimpul_160; ++i_160)
    {
        cout << NamaSimpul_160[i_160] << "     "; 
        for (int j_160 = 0; j_160 < JumlahSimpul_160; ++j_160)
        {
            cout << bobot_160[i_160][j_160] << "  "; 
        }
        cout << endl;
    }

    return 0; 
}
```
#### Output:
![231112160](<output_unguided01.png>)

Kode di atas digunakan untuk implementasi program penerapan Graph sederhana dalam C++. Dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya. Berikut rincian programnya:

- int JumlahSimpul_160;: Variabel untuk menyimpan jumlah simpul yang akan dimasukkan oleh pengguna.
- NamaSimpul_160 adalah vektor yang berisi nama-nama simpul.
- bobot_160 adalah matriks yang berisi bobot (jarak) antar simpul.
- vector <string> NamaSimpul_160(JumlahSimpul_160);: Vektor untuk menyimpan nama-nama simpul.
- vector<vector<int>> bobot(JumlahSimpul_160, vector<int>(JumlahSimpul_160));: Matriks untuk menyimpan bobot (jarak) antar simpul.

Contoh Programnya user memasukkan input sendiri, dan itu sesuai yang diperintah pada modul. Lebih jelasnya yang hasil programnya seperti gambar output diatas.

### 2. [Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!]

```C++
#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent; // pointer
};
Pohon *root;

void init() {
    root = NULL;
}
bool isEmpty() {
    return root == NULL;
}
Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}
void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat pohonnya dulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat pohonnya dulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada di child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}
void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat pohonya dulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang mau diganti gak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat pohonnya dulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk gak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}
void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat Pohonnya dulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk gak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}
void showChild(Pohon *node) {
    if (isEmpty()) {
        cout << "\n Buat treenya dulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk gak ada!" << endl;
        } else {
            cout << "\nNode " << node->data << " Child: " << endl;
            if (node->left)
                cout << " Child Kiri : " << node->left->data << endl;
            else
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            if (node->right)
                cout << "Child Kanan : " << node->right->data << endl;
            else
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
        }
    }
}
void preOrder(Pohon *node) {
    if (node != NULL) {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void showDescendants(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat pohonnya dulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk gak ada!" << endl;
        } else {
            cout << "\nKeturunan dari node " << node->data << " : ";
            preOrder(node);
            cout << endl;
        }
    }
}
void inOrder(Pohon *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
    }
}
void postOrder(Pohon *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
    }
}
void deleteTree(Pohon *node) {
    if (node != NULL) {
        if (node != root) {
            if (node->parent->left == node)
                node->parent->left = NULL;
            else if (node->parent->right == node)
                node->parent->right = NULL;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        if (node == root) {
            delete root;
            root = NULL;
        } else {
            delete node;
        }
    }
}
void deleteSub(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat pohonnya dulu!" << endl;
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode cabang pohon " << node->data << " berhasil dihapus." << endl;
    }
}
void clear() {
    if (isEmpty()) {
        cout << "\nBuat pohon dulu!!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}
int size(Pohon *node) {
    if (!node) {
        return 0;
    } else {
        return 1 + size(node->left) + size(node->right);
    }
}
int height(Pohon *node) {
    if (!node) {
        return 0;
    } else {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        if (heightKiri >= heightKanan) {
            return heightKiri + 1;
        } else {
            return heightKanan + 1;
        }
    }
}
void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nUkuran Pohon : " << s << endl;
    cout << "Berat Pohon : " << h << endl;
    if (h != 0)
        cout << "Rata-rata simpul pohon : " << s / h << endl;
    else
        cout << "Rata-rata simpul pohon : 0" << endl;
}

int main() {
    int choice;
    char Valisha_2311102160, parentData, direction;
    Pohon *parentNode, *tempNode;
    
    do {
        cout << "   Program Binary Tree  \n";
        cout << "1. Buat Node\n";
        cout << "2. Insert Left\n";
        cout << "3. Insert Right\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. Show Child\n";
        cout << "8. Show Descendants\n";
        cout << "9. Clear Tree\n";
        cout << "10. Tree Characteristics\n";
        cout << "11. Exit\n";
        cout << "=================================\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data: ";
                cin >> Valisha_2311102160;
                buatNode(Valisha_2311102160);
                break;
            case 2:
                cout << "Masukkan data: ";
                cin >> Valisha_2311102160;
                cout << "Masukkan parent data: ";
                cin >> parentData;
                parentNode = root;
                while (parentNode && parentNode->data != parentData) {
                    cout << "Arahkan ke kiri (l) atau kanan (r) dari " << parentNode->data << "?: ";
                    cin >> direction;
                    if (direction == 'l')
                        parentNode = parentNode->left;
                    else
                        parentNode = parentNode->right;
                }
                insertLeft(Valisha_2311102160, parentNode);
                break;
            case 3:
                cout << "Masukkan data: ";
                cin >> Valisha_2311102160;
                cout << "Masukkan parent data: ";
                cin >> parentData;
                parentNode = root;
                while (parentNode && parentNode->data != parentData) {
                    cout << "Arahkan ke kiri (l) atau kanan (r) dari " << parentNode->data << "?: ";
                    cin >> direction;
                    if (direction == 'l')
                        parentNode = parentNode->left;
                    else
                        parentNode = parentNode->right;
                }
                insertRight(Valisha_2311102160, parentNode);
                break;
            case 4:
                cout << "Masukkan data baru: ";
                cin >> Valisha_2311102160;
                cout << "Masukkan data node yang ingin di-update: ";
                cin >> parentData;
                tempNode = root;
                while (tempNode && tempNode->data != parentData) {
                    cout << "Arahkan ke kiri (l) atau kanan (r) dari " << tempNode->data << "?: ";
                    cin >> direction;
                    if (direction == 'l')
                        tempNode = tempNode->left;
                    else
                        tempNode = tempNode->right;
                }
                update(Valisha_2311102160, tempNode);
                break;
            case 5:
                cout << "Masukkan data node yang ingin di-retrieve: ";
                cin >> Valisha_2311102160;
                tempNode = root;
                while (tempNode && tempNode->data != Valisha_2311102160) {
                    cout << "Arahkan ke kiri (l) atau kanan (r) dari " << tempNode->data << "?: ";
                    cin >> direction;
                    if (direction == 'l')
                        tempNode = tempNode->left;
                    else
                        tempNode = tempNode->right;
                }
                retrieve(tempNode);
                break;
            case 6:
                cout << "Masukkan data node yang ingin di-find: ";
                cin >> Valisha_2311102160;
                tempNode = root;
                while (tempNode && tempNode->data != Valisha_2311102160) {
                    cout << "Arahkan ke kiri (l) atau kanan (r) dari " << tempNode->data << "?: ";
                    cin >> direction;
                    if (direction == 'l')
                        tempNode = tempNode->left;
                    else
                        tempNode = tempNode->right;
                }
                find(tempNode);
                break;
            case 7:
                cout << "Masukkan data node yang ingin di-show child: ";
                cin >> Valisha_2311102160;
                tempNode = root;
                while (tempNode && tempNode->data != Valisha_2311102160) {
                    cout << "Arahkan ke kiri (l) atau kanan (r) dari " << tempNode->data << "?: ";
                    cin >> direction;
                    if (direction == 'l')
                        tempNode = tempNode->left;
                    else
                        tempNode = tempNode->right;
                }
                showChild(tempNode);
                break;
            case 8:
                cout << "Masukkan data node yang ingin di-show descendants: ";
                cin >> Valisha_2311102160;
                tempNode = root;
                while (tempNode && tempNode->data != Valisha_2311102160) {
                    cout << "Arahkan ke kiri (l) atau kanan (r) dari " << tempNode->data << "?: ";
                    cin >> direction;
                    if (direction == 'l')
                        tempNode = tempNode->left;
                    else
                        tempNode = tempNode->right;
                }
                showDescendants(tempNode);
                break;
            case 9:
                clear();
                break;
            case 10:
                characteristic();
                break;
            case 11:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 11);

    return 0;
}
```
#### Output:
![231112160](<output_unguided02.png>)
![2311102160](<output_unguided02-2.png>)
![2311102160](<output_unguided02-3.png>)
![2311102160](<output_unguided02-4.png>)
![2311102160](<output_unguided02-5.png>)
![2311102160](<output_unguided02-6.png>)
![2311102160](<output_unguided02-7.png>)

Program ini mengimplementasikan struktur data pohon biner dengan berbagai operasi seperti membuat node, menyisipkan node di kiri dan kanan, memperbarui node, mengambil data node, mencari node dan menampilkan informasi, menampilkan anak dan keturunan dari node, serta menghapus pohon atau sub pohon. Program ini menyediakan menu interaktif yang memungkinkan pengguna untuk memilih operasi yang diinginkan, dengan validasi sederhana untuk memastikan operasi dilakukan pada node yang ada. Operasi traversal seperti pre-order, in-order, dan post-order juga disertakan, bersama dengan fungsi untuk menghitung ukuran, tinggi, dan menampilkan karakteristik pohon.

## Kesimpulan
Secara umum, graf dan pohon adalah struktur data yang sangat berguna dalam berbagai aplikasi dan algoritma. Graf digunakan untuk merepresentasikan hubungan antara objek-objek, sedangkan pohon adalah bentuk khusus dari graf yang tidak memiliki siklus dan digunakan dalam berbagai aplikasi seperti struktur data, pengindeksan, kompresi data, dan pengambilan keputusan.

## Referensi
[1] Muhammad Nugraha. Dasar Pemrograman Dengan C++ Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta. 2021.

[2] Meidyan Permata Putri, et al., Algoritma dan Struktur Data. Bandung: Widina Bhakti Persada Bandung, 2022.