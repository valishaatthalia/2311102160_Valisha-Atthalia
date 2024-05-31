#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk memeriksa apakah sebuah karakter adalah vokal
bool isVowel_160(char ch) {
    // Konversi karakter menjadi huruf kecil
    ch = tolower(ch);
    // Periksa apakah karakter adalah salah satu dari 'a', 'e', 'i', 'o', 'u'
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Fungsi untuk menghitung banyaknya huruf vokal dalam sebuah kalimat
int countVowels_160(const string & sentence) {
    int count = 0;
    for (char ch : sentence) {
        if (isVowel_160(ch)) {
            count++;
        }
    }
    return count;
}
int main() {
    string sentence;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, sentence); // Membaca input kalimat dari pengguna

    int vowelCount = countVowels_160(sentence);
    cout << "Banyaknya huruf vokal dalam kalimat adalah: " << vowelCount << endl;

    return 0;
}