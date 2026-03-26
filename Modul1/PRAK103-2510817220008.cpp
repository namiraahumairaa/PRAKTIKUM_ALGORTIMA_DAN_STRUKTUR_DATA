#include <iostream>
using namespace std;
struct masukkan{
    char huruf;
    string kata;
    int angka;
};
int main(){
    masukkan msk;
    cout << "Masukkan sebuah huruf      = ";
    cin >> msk.huruf;
    cout << "Masukkan sebuah kata       = ";
    cin >> msk.kata;
    cout << "Masukkan Angka             = ";
    cin >> msk.angka;

    cout << "\nHuruf yang Anda masukkan adalah " << msk.huruf << endl;
    cout << "Kata yang Anda masukkan adalah " << msk.kata << endl;
    cout << "Angka yang Anda masukkan adalah " << msk.angka << endl;
return 0;
}