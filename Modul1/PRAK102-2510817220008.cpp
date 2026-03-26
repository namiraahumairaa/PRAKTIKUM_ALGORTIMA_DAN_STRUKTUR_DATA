#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    struct{
        char plat[10], alamat[100];
        string jenis, nama, kota;
    } kendaraan;
    strcpy(kendaraan.plat, "DA1234MK");
    strcpy(kendaraan.alamat, "Jl.Kayu Tangi 1");
    kendaraan.jenis = "RUSH";
    kendaraan.nama = "Andika Hartono";
    kendaraan.kota = "Banjarmasin";
    cout << "Plat Nomor Kendaraan   : "<< kendaraan.plat << "\n";
    cout << "Jenis Kendaraan        : " << kendaraan.jenis << "\n";
    cout << "Nama Pemilik           : " << kendaraan.nama << "\n";
    cout << "Alamat                 : " << kendaraan.alamat << "\n";
    cout << "Kota                   : " << kendaraan.kota << "\n";
    return 0;
}