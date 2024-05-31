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