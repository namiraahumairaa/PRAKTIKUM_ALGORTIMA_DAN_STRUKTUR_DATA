#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct TNode{
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataHapus;

void init();
int isEmpty();
int hitungNode();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    init();
    do {
        cout<<"Single Linked List Circular (SLLC)"<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua Elemen"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        pil = atoi(pilihan);

        switch(pil) {
        case 1: tambahDepan(); break;
        case 2: tambahBelakang(); break;
        case 3:
            hapusDepan();
            break;
        case 4:
            hapusBelakang();
            break;
        case 5: tampilkan(); break;
        case 6: reset(); break;
        case 7: cariData(); break;
        case 8: hapusData(); break;
        case 9: sisipkanSebelum(); break;
        case 10: sisipkanSetelah(); break;
        default:
            cout<<"\nTERIMA KASIH"<<endl;
            cout<<"Program was made by Namira Humaira (2510817220008)."<<endl;
        }

        cout<<"\nPress any key to continue!"<<endl;
        getch();
        system("cls");

    } while(pil < 11);
}

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

int hitungNode() {
    if(isEmpty()) return 0;
    int hitung = 1;
    TNode *bantu = head;
    while(bantu->next != head) {
        hitung++;
        bantu = bantu->next;
    }
    return hitung;
}

void tambahDepan() {
    cin.ignore();
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;
    string arr[100];
    int n = 0;

    while(ss >> token) arr[n++] = token;

    for(int i = n - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = baru;

        if(isEmpty()) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }
    cout<<"Data berhasil dimasukkan di bagian depan."<<endl;
}

void tambahBelakang() {
    cout<<"Masukkan data : ";
    TNode *baru = new TNode;
    cin>>dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty()) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout<<"Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian belakang."<<endl;
}

void hapusDepan() {
    if(isEmpty() == 0) {
        int n, total = hitungNode();
        cout<<"Hapus node ke-N dari depan, masukkan N : ";
        cin>>n;

        if(n > total) n = total; 

        TNode *bantu = head;
        for(int i = 1; i < n; i++) bantu = bantu->next;

        dataHapus = bantu->data;

        if(head == tail) {
            delete bantu;
            init();
        } else if(bantu == head) {
            head = head->next;
            tail->next = head;
            delete bantu;
        } else if(bantu == tail) {
            TNode *prev = head;
            while(prev->next != tail) prev = prev->next;
            tail = prev;
            tail->next = head;
            delete bantu;
        } else {
            TNode *prev = head;
            while(prev->next != bantu) prev = prev->next;
            prev->next = bantu->next;
            delete bantu;
        }
        cout<<"Node ke-"<<n<<" dengan data \""<<dataHapus<<"\" berhasil dihapus dari depan."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusBelakang() {
    if(isEmpty() == 0) {
        int n, total = hitungNode();
        cout<<"Hapus node ke-N dari belakang, masukkan N : ";
        cin>>n;

        if(n > total) n = total; 
        
        int posDepan = total - n + 1;
        TNode *bantu = head;
        for(int i = 1; i < posDepan; i++) bantu = bantu->next;

        dataHapus = bantu->data;

        if(head == tail) {
            delete bantu;
            init();
        } else if(bantu == head) {
            head = head->next;
            tail->next = head;
            delete bantu;
        } else if(bantu == tail) {
            TNode *prev = head;
            while(prev->next != tail) prev = prev->next;
            tail = prev;
            tail->next = head;
            delete bantu;
        } else {
            TNode *prev = head;
            while(prev->next != bantu) prev = prev->next;
            prev->next = bantu->next;
            delete bantu;
        }
        cout<<"Node ke-"<<n<<" dari belakang dengan data \""<<dataHapus<<"\" berhasil dihapus."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void tampilkan() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        do {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        } while(bantu != head);
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void reset() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        int ke = 1;
        do {
            TNode *hapus = bantu;
            cout<<"Menghapus node ke-"<<ke<<" dengan data \""<<hapus->data<<"\"."<<endl;
            bantu = bantu->next;
            delete hapus;
            ke++;
        } while(bantu != head);

        init();
        cout<<"Seluruh elemen pada Linked List telah dibersihkan."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void cariData() {
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dicari : ";
        cin>>cari;

        TNode *bantu = head, *bantuTampilkan;
        bool apaDitemukan = false;

        do {
            if(cari == bantu->data) {
                cout<<"Data yang dicari ditandai dengan [...]"<<endl;
                cout<<"Linked List : ";
                bantuTampilkan = head;
                do {
                    if(cari == bantuTampilkan->data) cout<<"["<<bantuTampilkan->data<<"] ";
                    else cout<<bantuTampilkan->data<<' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while(bantuTampilkan != head);
                apaDitemukan = true;
                cout<<endl;
                break;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(!apaDitemukan)
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusData() {
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>cari;

        TNode *bantu, *sebelum, *hapus[255], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;

        bantu = head;
        do {
            bantu2 = bantu;
            if(cari == bantu->data) {
                hapus[hitung++] = bantu;
                apaDitemukan = true;
                if(bantu != head && bantu != tail) {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan) {
            for(int i = 0; i < hitung; i++) {
                if(hapus[i] == head) {
                    head = head->next;
                    tail->next = head;
                    delete hapus[i];
                } else if(hapus[i] == tail) {
                    TNode *prev = head;
                    while(prev->next != tail) prev = prev->next;
                    tail = prev;
                    tail->next = head;
                    delete hapus[i];
                } else {
                    delete hapus[i];
                }
            }
            cout<<"Setiap data \""<<cari<<"\" telah dihapus dari Linked List."<<endl;
        } else cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void sisipkanSebelum() {
    if(isEmpty() == 0) {
        TNode *bantu = head, *sebelum = tail;
        string nextData;
        bool apaAda = false;

        cout<<"Sisipkan data baru sebelum data : ";
        cin>>nextData;

        do {
            if(nextData == bantu->data) { apaAda = true; break; }
            else { sebelum = bantu; bantu = bantu->next; }
        } while(bantu != head);

        if(apaAda) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;
            if(bantu == head) head = baru;
            cout<<"Data \""<<dataBaru<<"\" berhasil disisipkan sebelum \""<<nextData<<"\"."<<endl;
        } else cout<<"Data \""<<nextData<<"\" tidak ditemukan."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void sisipkanSetelah() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        string prevData;
        bool apaAda = false;

        cout<<"Sisipkan data baru setelah data : ";
        cin>>prevData;

        do {
            if(prevData == bantu->data) { apaAda = true; break; }
            else bantu = bantu->next;
        } while(bantu != head);

        if(apaAda) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;
            if(bantu == tail) tail = baru;
            cout<<"Data \""<<dataBaru<<"\" berhasil disisipkan setelah \""<<prevData<<"\"."<<endl;
        } else cout<<"Data \""<<prevData<<"\" tidak ditemukan."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}