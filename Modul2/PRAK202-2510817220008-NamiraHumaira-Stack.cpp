#include <iostream>
using namespace std;

const int maks = 5; 

struct Stack {
    int data[maks];
    int atas;
} Tumpuk;

void inisialisasi() {
 Tumpuk.atas = -1;
}

int kosong() { 
    if (Tumpuk.atas == -1) {
        return 1; 
    } else {
        return 0; 
    }
}

int penuh() {
    if (Tumpuk.atas == maks - 1) {
        return 1; 
    } else {
        return 0; 
    }
}

void input(int data) {
    if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk ke Stack\n";
    } else {
        cout << "Tumpukan penuh\n";
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Keluar dari Stack\n";
        Tumpuk.atas--;
    } else {
        cout << "Tumpukan kosong\n";
    }
}

void tampil() {
    if (kosong() == 0) {
        cout << "\nIsi Stack:\n";
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
        cout << endl;
    } else {
        cout << "Tumpukan kosong\n";
    }
}

int main() {
    inisialisasi(); 

    input(10);
    input(20);
    input(30);

    tampil();

    hapus(); 

    tampil(); 

    input(40);
    input(50);
    
    tampil();

    return 0;
}