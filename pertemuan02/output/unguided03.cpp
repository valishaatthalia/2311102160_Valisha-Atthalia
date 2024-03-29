#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double hitung_maksimum(const vector<double>& arr) {
    double maksimum = arr[0];
    for (double angka : arr) {
        if (angka > maksimum) {
            maksimum = angka;
        }
    }
    return maksimum;
}

double hitung_minimum(const vector<double>& arr) {
    double minimum = arr[0];
    for (double angka : arr) {
        if (angka < minimum) {
            minimum = angka;
        }
    }
    return minimum;
}

double hitung_rata_rata(const vector<double>& arr) {
    double total = 0;
    for (double angka : arr) {
        total += angka;
    }
    return total / arr.size();
}

int main() {
    vector<double> arr;
    int n;

    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> n;

    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < n; ++i) {
        double elemen;
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> elemen;
        arr.push_back(elemen);
    }

    double maksimum = hitung_maksimum(arr);
    double minimum = hitung_minimum(arr);
    double rata_rata = hitung_rata_rata(arr);

    cout << "\nHasil:\n";
    cout << "Nilai Maksimum: " << maksimum << endl;
    cout << "Nilai Minimum: " << minimum << endl;
    cout << "Nilai Rata-rata: " << rata_rata << endl;

    return 0;
}