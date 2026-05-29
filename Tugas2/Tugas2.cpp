#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main()
{
    menu :
    cout << "Double Linked List Non Circular (DLLNC) " << endl;
    cout << "======================================= " << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin>>menu;
    system("cls");
    if(menu==1){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil) {
            case 1:
                tambahDepanH();
                break;
            case 2:
                tambahBelakangH();
                break;
            case 3:
                tampilkanH();
                break;
            case 4:
                hapusDepanH();
                break;
            case 5:
                hapusBelakangH();
                break;
            case 6:
                hapusTargetH();
                break;
            case 7:
                clearH();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<8);
    } else if(menu==2){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"======================================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil) {
            case 1:
                tambahDepanHT();
                break;
            case 2:
                tambahBelakangHT();
                break;
            case 3:
                tampilkanHT();
                break;
            case 4:
                hapusDepanHT();
                break;
            case 5:
                hapusBelakangHT();
                break;
            case 6:
                hapusTargetHT();
                break;
            case 7:
                clearHT();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<8);
    } else {
        cout<<"\nTERIMA KASIH"<<endl;
        cout<<"Program was made Namira Humaira (2510817220008)."<<endl;
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if(head == NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if(tail == NULL) return 1;
    else return 0;
}

void tambahDepanH() {
    string temp[100];
    int n = 0;
    string baris, kata;
    cout<<"Masukkan data : ";
    cin.ignore();
    getline(cin, baris);
    baris += ' ';
    kata = "";
    for(int i=0; i<(int)baris.length(); i++){
        if(baris[i]==' '){
            if(kata!="") temp[n++] = kata;
            kata = "";
        } else {
            kata += baris[i];
        }
    }
    for(int i=n-1; i>=0; i--){
        TNode *baru;
        baru = new TNode;
        baru->data = temp[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyH()==1){
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout<<"Data masuk\n";
}

void tambahDepanHT() {
    string temp[100];
    int n = 0;
    string baris, kata;
    cout<<"Masukkan data : ";
    cin.ignore();
    getline(cin, baris);
    baris += ' ';
    kata = "";
    for(int i=0; i<(int)baris.length(); i++){
        if(baris[i]==' '){
            if(kata!="") temp[n++] = kata;
            kata = "";
        } else {
            kata += baris[i];
        }
    }
    for(int i=n-1; i>=0; i--){
        TNode *baru;
        baru = new TNode;
        baru->data = temp[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyHT()==1){
            head = baru;
            tail = baru;
            head->next = NULL;
            head->prev = NULL;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout<<"Data masuk\n";
}

void tambahBelakangH() {
    string baris, kata;
    cout<<"Masukkan data : ";
    cin.ignore();
    getline(cin, baris);
    baris += ' ';
    kata = "";
    for(int i=0; i<(int)baris.length(); i++){
        if(baris[i]==' '){
            if(kata==""){
                continue;
            }
            TNode *baru, *bantu;
            baru = new TNode;
            baru->data = kata;
            baru->next = NULL;
            baru->prev = NULL;
            if(isEmptyH()==1){
                head = baru;
                head->next = NULL;
                head->prev = NULL;
            } else {
                bantu = head;
                while(bantu->next!=NULL){
                    bantu = bantu->next;
                }
                bantu->next = baru;
                baru->prev = bantu;
            }
            kata = "";
        } else {
            kata += baris[i];
        }
    }
    cout<<"Data masuk\n";
}

void tambahBelakangHT() {
    string baris, kata;
    cout<<"Masukkan data : ";
    cin.ignore();
    getline(cin, baris);
    baris += ' ';
    kata = "";
    for(int i=0; i<(int)baris.length(); i++){
        if(baris[i]==' '){
            if(kata==""){
                continue;
            }
            TNode *baru;
            baru = new TNode;
            baru->data = kata;
            baru->next = NULL;
            baru->prev = NULL;
            if(isEmptyHT()==1){
                head = baru;
                tail = baru;
                head->next = NULL;
                head->prev = NULL;
            } else {
                tail->next = baru;
                baru->prev = tail;
                tail = baru;
            }
            kata = "";
        } else {
            kata += baris[i];
        }
    }
    cout<<"Data masuk\n";
}

void tampilkanH() {
    TNode *bantu;
    bantu = head;
    if(isEmptyH() == 0) {
        while(bantu != NULL) {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Masih kosong\n";
}

void tampilkanHT() {
    TNode *bantu;
    bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != tail->next) {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Masih kosong\n";
}

void hapusDepanH() {
    TNode *hapus;
    string d;
    if(isEmptyH() == 0) {
        hapus = head;
        d = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
            delete hapus;
        } else {
            head = NULL;
        }
        cout<<d<<" terhapus\n";
    } else cout<<"Masih kosong\n";
}

void hapusDepanHT() {
    TNode *hapus;
    string d;
    if(isEmptyHT() == 0) {
        hapus = head;
        d = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
            delete hapus;
        } else {
            initHT();
        }
        cout<<d<<" terhapus\n";
    } else cout<<"Masih kosong\n";
}

void hapusBelakangH() {
    TNode *hapus;
    string d;
    if(isEmptyH() == 0) {
        int N, total = 0;
        TNode *bantu;
        bantu = head;
        while(bantu!=NULL){
            total++;
            bantu = bantu->next;
        }
        cout<<"Masukkan N (hapus node ke-N dari belakang) : ";
        cin>>N;
        int target = N % total;
        if(target==0) target = total;
        hapus = head;
        for(int i=1; i<total-target+1; i++)
            hapus = hapus->next;
        d = hapus->data;
        if(hapus->prev != NULL) hapus->prev->next = hapus->next;
        else head = hapus->next;
        if(hapus->next != NULL) hapus->next->prev = hapus->prev;
        delete hapus;
        cout<<d<<" terhapus\n";
    } else cout<<"Masih kosong\n";
}

void hapusBelakangHT() {
    TNode *hapus;
    string d;
    if(isEmptyHT() == 0) {
        int N, total = 0;
        TNode *bantu;
        bantu = head;
        while(bantu!=NULL){
            total++;
            bantu = bantu->next;
        }
        cout<<"Masukkan N (hapus node ke-N dari belakang) : ";
        cin>>N;
        int target = N % total;
        if(target==0) target = total;
        hapus = head;
        for(int i=1; i<total-target+1; i++)
            hapus = hapus->next;
        d = hapus->data;
        if(hapus->prev != NULL) hapus->prev->next = hapus->next;
        else head = hapus->next;
        if(hapus->next != NULL) hapus->next->prev = hapus->prev;
        else tail = hapus->prev;
        delete hapus;
        cout<<d<<" terhapus\n";
    } else cout<<"Masih kosong\n";
}

void hapusTargetH() {
    TNode *hapus, *bantu;
    string target, d;
    int ketemu = 0;
    if(isEmptyH() == 0) {
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>target;
        bantu = head;
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            if(hapus->data == target){
                if(hapus->prev != NULL) hapus->prev->next = hapus->next;
                else head = hapus->next;
                if(hapus->next != NULL) hapus->next->prev = hapus->prev;
                d = hapus->data;
                delete hapus;
                ketemu++;
            }
        }
        if(ketemu==0) cout<<"Data tidak ditemukan\n";
        else cout<<d<<" terhapus sebanyak "<<ketemu<<" node\n";
    } else cout<<"Masih kosong\n";
}

void hapusTargetHT() {
    TNode *hapus, *bantu;
    string target, d;
    int ketemu = 0;
    if(isEmptyHT() == 0) {
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>target;
        bantu = head;
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            if(hapus->data == target){
                if(hapus->prev != NULL) hapus->prev->next = hapus->next;
                else head = hapus->next;
                if(hapus->next != NULL) hapus->next->prev = hapus->prev;
                else tail = hapus->prev;
                d = hapus->data;
                delete hapus;
                ketemu++;
            }
        }
        if(ketemu==0) cout<<"Data tidak ditemukan\n";
        else cout<<d<<" terhapus sebanyak "<<ketemu<<" node\n";
    } else cout<<"Masih kosong\n";
}

void clearH() {
    TNode *hapus;
    string d;
    int urutan = 1;
    if(isEmptyH() == 0) {
        while(head != NULL){
            if(urutan%2 != 0){
                hapus = head;
                d = hapus->data;
                if(head->next != NULL){
                    head = head->next;
                    head->prev = NULL;
                } else {
                    head = NULL;
                }
            } else {
                hapus = head;
                while(hapus->next != NULL) hapus = hapus->next;
                d = hapus->data;
                if(hapus->prev != NULL) hapus->prev->next = NULL;
                else head = NULL;
            }
            delete hapus;
            cout<<"Penghapusan ke-"<<urutan<<" : "<<d<<endl;
            urutan++;
        }
        cout<<"Seluruh data telah dibersihkan\n";
    } else cout<<"Masih kosong\n";
}

void clearHT() {
    TNode *hapus;
    string d;
    int urutan = 1;
    if(isEmptyHT() == 0) {
        while(head != NULL){
            if(urutan%2 != 0){
                hapus = head;
                d = hapus->data;
                if(head->next != NULL){
                    head = head->next;
                    head->prev = NULL;
                } else {
                    head = NULL;
                    tail = NULL;
                }
            } else {
                hapus = tail;
                d = hapus->data;
                if(tail->prev != NULL){
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    head = NULL;
                    tail = NULL;
                }
            }
            delete hapus;
            cout<<"Penghapusan ke-"<<urutan<<" : "<<d<<endl;
            urutan++;
        }
        cout<<"Seluruh data telah dibersihkan\n";
    } else cout<<"Masih kosong\n";
}