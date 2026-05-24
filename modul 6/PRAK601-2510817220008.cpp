#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target){
    vector<int> indices;

    for (auto i = 0; i < nums.size(); i++){
        if (nums[i] == target) indices.push_back(i);
    }
    if (indices.empty()) cout << "angka " << target << " tidak ditemukan pada array" << endl;
    else {
        cout << "Angka " << target << " terdapat pada array sebanyak " << indices.size() << " Kali" << endl;
        cout << "Angka " << target << " ditemukan pada indeks: ";
        for (auto i = 0; i < indices.size(); i++){
            cout << indices[i];
            if (i != indices.size() - 1) cout << ", ";
        }
        cout << "." << endl;
    }
}

void binarySearch(const vector<int> &nums, int target){
    int high = nums.size() - 1;
    int low = 0;
    int index = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;
        if (nums[mid] == target){
            index = mid;
            break;
        }
        if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    if (index == -1) cout << "angka " << target << " tidak ditemukan pada array" << endl;
    else cout << "angka " << target << " ditemukan pada indeks ke " << index << endl; 
}

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void explain(){
    cout << "\nPERBEDAAN SEQUENTIAL/LINEAR SEARCH DENGAN BINARY SEARCH" << endl;
    cout << "SEQUENTIAL SEARCH: " << endl;
    cout << "> Melakukan pengecekan pada array melalui traversal indeks." << endl;
    cout << "> Jika elemen pada array yang dicari sama dengan elemen target, maka cetak nilai indeks." << endl;
    cout << "> Kompleksitas Waktu: O(n), karena penggunaan fungsi loop `for` untuk pencarian target secara traversal." << endl;
    cout << "> Kompleksitas Ruang: O(1), karena penggunaan memori konstan." << endl;
    cout << "LINEAR SEARCH tidak memiliki syarat tertentu." << endl;
    cout << "LINEAR SEARCH dapat diterapkan pada: " << endl;
    cout << "1. Data yang Tidak Terurut" << endl;
    cout << "2. Data berukuran kecil" << endl;
    cout << "3. Pencarian Node Pada Linked List" << endl;
    cout << endl;
    cout << "BINARY SEARCH: " << endl;
    cout << "> Membagi array menjadi dua bagian melalui indeks tengah `mid`." << endl;
    cout << "> Bandingkan elemen tengah dengan elemen target." << endl;
    cout << "> Jika elemen tengah sama dengan elemen target, elemen pada array sudah ditemukan." << endl;
    cout << "> Jika elemen tengah kurang dari elemen target, cari di bagian kanan array." << endl;
    cout << "> Jika elemen tengah lebih dari elemen target, cari di bagian kiri array." << endl;
    cout << "> Ulangi kedua tahap di atas sehingga elemen target ditemukan." << endl;
    cout << "> Kompleksitas Waktu: O(log n), karena pembagian interval waktu pencarian." << endl;
    cout << "> Kompleksitas Ruang: O(1), karena penggunaan memori konstan." << endl;
    cout << "SYARAT BINARY SEARCH: array harus tersortir terlebih dahulu." << endl;
    cout << "BINARY SEARCH dapat diterapkan pada: " << endl;
    cout << "1. Machine Learning" << endl;
    cout << "2. Computer Graphics (algoritma untuk ray tracing atau texture mapping)" << endl;
    cout << "3. Pencarian data pada dataset besar" << endl;
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = dist(rng);
                }
                cout << "Generating 100 numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                sequentialSearch(nums, target);
                break;
            }
            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;
                if (size < 1){
                    cout << "Error: Mohon masukkan bilangan di atas 0" << endl;
                    break;
                }
                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }
                sort(nums.begin(), nums.end());
                cout << "Generating " << size << " numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;
                binarySearch(nums, target);
                break;
            }
            case 3:
                explain();
                break;
            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by NAMIRA HUMAIRA (2510817220008)" << endl;
                break;
            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }
        if (opt != 4) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
            clearScreen();
        }
    } while (opt != 4);
    return 0;
}