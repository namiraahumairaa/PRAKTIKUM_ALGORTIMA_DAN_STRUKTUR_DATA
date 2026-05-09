#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream> 

using namespace std;

struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataHapus;

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (head == NULL) return 1;
    else return 0;
}

void tambahDepan() {
    string line;
    cout << "Masukkan data (pisahkan dengan spasi): ";
    cin.ignore(); 
    getline(cin, line);
    
    stringstream ss(line);
    string kata;
    TNode *lastAdded = NULL;
    TNode *firstAdded = NULL;

    while (ss >> kata) {
        TNode *baru = new TNode;
        baru->data = kata;
        
        if (firstAdded == NULL) {
            firstAdded = baru;
        }

        if (lastAdded != NULL) {
            lastAdded->next = baru;
        }
        lastAdded = baru;
    }

    if (firstAdded != NULL) {
        if (isEmpty() == 1) {
            head = firstAdded;
            tail = lastAdded;
            tail->next = head;
        } else {
            lastAdded->next = head;
            head = firstAdded;
            tail->next = head;
        }
        cout << "Data berhasil dimasukkan ke depan." << endl;
    }
}

void tambahBelakang() {
    cout << "Masukkan data : ";
    TNode *baru = new TNode;
    cin >> dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if (isEmpty() == 1) {
        head = baru;
        tail = baru;
        tail->next = head;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di belakang." << endl;
}

void hapusDepan() {
    if (isEmpty() == 0) {
        int n, hitung = 1;
        cout << "Hapus node ke-N dari depan, N = ";
        cin >> n;

        TNode *hapus = head;
        TNode *sebelum = tail;

        while (hitung < n && hapus->next != head) {
            sebelum = hapus;
            hapus = hapus->next;
            hitung++;
        }

        dataHapus = hapus->data;
        
        if (hapus == head) {
            if (head == tail) {
                init();
            } else {
                head = head->next;
                tail->next = head;
            }
        } else if (hapus == tail) {
            tail = sebelum;
            tail->next = head;
        } else {
            sebelum->next = hapus->next;
        }
        
        delete hapus;
        cout << "Data \"" << dataHapus << "\" pada posisi " << hitung << " berhasil dihapus." << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void hapusBelakang() {
    if (isEmpty() == 0) {
        int n, total = 0;
        TNode *bantu = head;
  
        do {
            total++;
            bantu = bantu->next;
        } while (bantu != head);

        cout << "Hapus node ke-N dari belakang, N = ";
        cin >> n;

        if (n >= total) {
            TNode *hapus = head;
            dataHapus = hapus->data;
            if (head == tail) {
                init();
            } else {
                head = head->next;
                tail->next = head;
            }
            delete hapus;
            cout << "N melebihi jumlah node, head dihapus." << endl;
        } else {
            int target = total - n + 1;
            int current = 1;
            TNode *hapus = head;
            TNode *sebelum = tail;

            while (current < target) {
                sebelum = hapus;
                hapus = hapus->next;
                current++;
            }

            dataHapus = hapus->data;
            sebelum->next = hapus->next;
            if (hapus == tail) tail = sebelum;
            
            delete hapus;
            cout << "Data \"" << dataHapus << "\" berhasil dihapus." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void tampilkan() {
    if (isEmpty() == 0) {
        TNode *bantu = head;
        do {
            cout << bantu->data << " ";
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    } else {
        cout << "Linked List kosong." << endl;
    }
}

void reset() {
    if (isEmpty() == 0) {
        int i = 1;
        while (head != NULL) {
            TNode *hapus = head;
            cout << "Menghapus node ke-" << i << " berisi: " << hapus->data << endl;
            
            if (head == tail) {
                delete hapus;
                head = NULL;
                tail = NULL;
            } else {
                head = head->next;
                tail->next = head;
                delete hapus;
            }
            i++;
        }
        cout << "Seluruh elemen telah dibersihkan." << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

int main() {
    init();
    do {
        cout << "\nSingle Linked List Circular (SLLC)" << endl;
        cout << "==================================" << endl;
        cout << "1. Tambah Depan (Bisa banyak data)" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Posisi ke-N (Depan)" << endl;
        cout << "4. Hapus Posisi ke-N (Belakang)" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Reset (Hapus Satu per Satu)" << endl;
        cout << "11. Quit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch (pil) {
            case 1: tambahDepan(); break;
            case 2: tambahBelakang(); break;
            case 3: hapusDepan(); break;
            case 4: hapusBelakang(); break;
            case 5: tampilkan(); break;
            case 6: reset(); break;
            case 11: cout << "Keluar..." << endl; break;
            default: cout << "Pilihan tidak ada!" << endl;
        }
        if (pil != 11) {
            cout << "\nPress any key to continue!";
            getch();
            system("cls");
        }
    } while (pil != 11);
    return 0;
}