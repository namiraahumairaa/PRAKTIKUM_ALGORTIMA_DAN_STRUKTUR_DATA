#include <iostream>
#include <stdlib.h>
#define n 10
using namespace std;

int PIL, F, R;
char PILIHAN[3], HURUF;
char Q[n];

void Inisialisasi() {
    F = R = -1;
}

void INSERT() {
    if (R == n - 1) {
        cout << "Queue penuh!" << endl;
    } else {
        cout << "Masukkan huruf: ";
        cin >> HURUF;

        if (F == -1) F = 0; 
        R++;
        Q[R] = HURUF;
        cout << "Huruf " << HURUF << " berhasil dimasukkan ke queue.\n";
    }
}

void DELETE() {
    if (F == -1 || F > R) {
        cout << "Queue kosong!\n";
    } else {
        cout << "Huruf " << Q[F] << " dihapus dari queue.\n";
        F++;
    }
}

void CETAKLAYAR() {
    if (F == -1 || F > R) {
        cout << "Queue kosong!\n";
    } else {
        cout << "Isi queue: ";
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

void RESET() {
    Inisialisasi();
    cout << "Queue berhasil direset!\n";
}

int main() {
    Inisialisasi();
    do
    {
        cout << "\nQUEUE" << endl;
        cout << "=====================" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL)
        {
            case 1: 
                INSERT();
                break;
            case 2: 
                DELETE();
                break;
            case 3: 
                CETAKLAYAR();
                break;
            case 4:
                RESET();
                break;
            case 5:
                cout << "TERIMA KASIH" << endl;
                break;
        }

    } while (PIL != 5);

    return 0;
}