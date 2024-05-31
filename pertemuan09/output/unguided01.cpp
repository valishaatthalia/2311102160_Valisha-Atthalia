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
