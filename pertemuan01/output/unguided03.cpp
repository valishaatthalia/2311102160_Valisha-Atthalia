#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string input_string;
    cout << "Masukkan string: ";
    getline(cin, input_string);

    map <char, int> char_frequency;

    // Menghitung frekuensi kemunculan setiap karakter
    for (char c : input_string) {
        if (isalpha(c)) {  // Memeriksa apakah karakter adalah huruf
            char_frequency[c]++;
        }
    }

    // Menampilkan frekuensi kemunculan setiap karakter
    cout << "Frekuensi kemunculan setiap karakter:\n";
    for (const auto& pair : char_frequency) {
        cout << "'" << pair.first << "' : " << pair.second << endl;
    }

    return 0;
}