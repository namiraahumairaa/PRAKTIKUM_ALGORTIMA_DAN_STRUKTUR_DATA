#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <iomanip>
#include <conio.h>
#include <algorithm>

using namespace std;

string namaMhs = "Namira Humaira";
string nimMhs = "2510817220008";

void ukurWaktu(const function<void()> &fungsiSort, const string &namaAlgoritma) {
    auto mulai = chrono::high_resolution_clock::now();
    fungsiSort();
    auto selesai = chrono::high_resolution_clock::now();
    chrono::duration<double> durasi = selesai - mulai;

    cout << fixed << setprecision(10);
    cout << ">> " << namaAlgoritma << " memerlukan waktu: " << durasi.count() << " detik\n";
}

void insertionSort(string &teks) {
    int n = teks.size();
    for (int i = 1; i < n; i++) {
        char sisip = teks[i];
        int j = i - 1;
        while (j >= 0 && teks[j] > sisip) {
            teks[j + 1] = teks[j];
            j--;
        }
        teks[j + 1] = sisip;
    }
}

void gabung(string &teks, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    string stringL = teks.substr(kiri, n1);
    string stringR = teks.substr(tengah + 1, n2);

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (stringL[i] <= stringR[j])
            teks[k++] = stringL[i++];
        else
            teks[k++] = stringR[j++];
    }
    while (i < n1) teks[k++] = stringL[i++];
    while (j < n2) teks[k++] = stringR[j++];
}

void mergeSort(string &teks, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeSort(teks, kiri, tengah);
        mergeSort(teks, tengah + 1, kanan);
        gabung(teks, kiri, tengah, kanan);
    }
}

void shellSort(string &teks, int n) {
    for (int jarak = n / 2; jarak > 0; jarak /= 2) {
        for (int i = jarak; i < n; i++) {
            char temp = teks[i];
            int j = i;
            while (j >= jarak && teks[j - jarak] > temp) {
                teks[j] = teks[j - jarak];
                j -= jarak;
            }
            teks[j] = temp;
        }
    }
}

void bubbleSort(string &teks) {
    int n = teks.size();
    for (int i = 0; i < n - 1; i++) {
        bool tukar = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (teks[j] > teks[j + 1]) {
                swap(teks[j], teks[j + 1]);
                tukar = true;
            }
        }
        if (!tukar) break;
    }
}

int partisi(string &teks, int rendah, int tinggi) {
    char poros = teks[tinggi];
    int i = rendah - 1;
    for (int j = rendah; j < tinggi; j++) {
        if (teks[j] <= poros)
            swap(teks[++i], teks[j]);
    }
    swap(teks[i + 1], teks[tinggi]);
    return i + 1;
}

void quickSort(string &teks, int rendah, int tinggi) {
    if (rendah < tinggi) {
        int idxPartisi = partisi(teks, rendah, tinggi);
        quickSort(teks, rendah, idxPartisi - 1);
        quickSort(teks, idxPartisi + 1, tinggi);
    }
}

void selectionSort(string &teks) {
    int n = teks.size();
    for (int i = 0; i < n - 1; i++) {
        int idxMin = i;
        for (int j = i + 1; j < n; j++) {
            if (teks[j] < teks[idxMin])
                idxMin = j;
        }
        if (idxMin != i)
            swap(teks[i], teks[idxMin]);
    }
}

int main() {
    int pilihan;
    string olahData;

    do {
        cout << "+====================================================+" << endl;
        cout << "|                PROGRAM SORTING MODUL 5             |" << endl;
        cout << "+====================================================+" << endl;
        cout << "| Pilih Algoritma:                                   |" << endl;
        cout << "| 1. Insertion Sort (Nama)                           |" << endl;
        cout << "| 2. Merge Sort (Nama)                               |" << endl;
        cout << "| 3. Shell Sort (Nama)                               |" << endl;
        cout << "| 4. Bubble Sort (NIM)                               |" << endl;
        cout << "| 5. Quick Sort (NIM)                                |" << endl;
        cout << "| 6. Selection Sort (NIM)                            |" << endl;
        cout << "| 7. Keluar                                          |" << endl;
        cout << "+====================================================+" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            pilihan = -1;
        }

        switch (pilihan) {
        case 1: case 2: case 3:
            olahData.clear();
            for (char c : namaMhs) if (isalpha(c)) olahData += c;
            cout << "\nData Nama Awal: " << namaMhs << endl;
            if (pilihan == 1)
                ukurWaktu([&]() { insertionSort(olahData); }, "Insertion Sort");
            else if (pilihan == 2)
                ukurWaktu([&]() { mergeSort(olahData, 0, olahData.size() - 1); }, "Merge Sort");
            else
                ukurWaktu([&]() { shellSort(olahData, olahData.size()); }, "Shell Sort");
            cout << "Hasil Pengurutan: " << olahData << endl;
            break;

        case 4: case 5: case 6:
            olahData = nimMhs;
            cout << "\nData NIM Awal: " << nimMhs << endl;
            if (pilihan == 4)
                ukurWaktu([&]() { bubbleSort(olahData); }, "Bubble Sort");
            else if (pilihan == 5)
                ukurWaktu([&]() { quickSort(olahData, 0, olahData.size() - 1); }, "Quick Sort");
            else
                ukurWaktu([&]() { selectionSort(olahData); }, "Selection Sort");
            cout << "Hasil Pengurutan: " << olahData << endl;
            break;

        case 7:
            cout << "\nProgram Selesai." << endl;
            cout << "Oleh: " << namaMhs << " (" << nimMhs << ")" << endl;
            break;

        default:
            cout << "Pilihan tidak tersedia!" << endl;
        }

        if (pilihan != 7) {
            cout << "\nTekan sembarang tombol untuk lanjut...";
            getch();
            system("cls");
        }

    } while (pilihan != 7);

    return 0;
}