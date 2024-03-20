#include <iostream>
using namespace std;

// Deklarasi class
class Kotak_160 {
private:
    double panjang_160;
    double lebar_160;
    double tinggi_160;

public:
    // Konstruktor
    Kotak_160 (double p, double l, double t) {
        panjang_160 = p;
        lebar_160 = l;
        tinggi_160 = t;
    }

    // Fungsi untuk menghitung volume kotak
    double hitungVolume_160() {
        return panjang_160 * lebar_160 * tinggi_160;
    }

    // Fungsi untuk menghitung luas permukaan kotak
    double hitungLuasPermukaan_160 () {
        return 2 * (panjang_160 * lebar_160 + panjang_160 * tinggi_160 + lebar_160 * tinggi_160);
    }
};

int main() {
    // Membuat objek kotak
    Kotak_160 kotak1 (3.0, 4.0, 5.0);

    // Menghitung volume dan luas permukaan kotak
    double volume_160 = kotak1.hitungVolume_160 ();
    double luas_permukaan_160 = kotak1.hitungLuasPermukaan_160 ();

    // Menampilkan hasil perhitungan
    cout << "Volume kotak: " << volume_160 << endl;
    cout << "Luas permukaan kotak: " << luas_permukaan_160 << endl;

    return 0;
}