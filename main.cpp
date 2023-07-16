#include <iostream>
#include <string>
#include <fstream>
#include "pembalap.h"
#include "menu.h"

using namespace std;

int pilihan;
Pembalap Pembalap;
int main()
{
    // createFile(); /

    do {
        tampilMenu();
        cout << "Masukan Pilihan (1-7): ";
        cin >> pilihan;


        switch (pilihan) {
            case 1:
                // jika pilihan 1, memanggil fungsi tambahpembalap
                system("cls");
                cout << "=======================================" << endl;
                cout << "           Tambah Pembalap             " << endl;
                cout << "=======================================" << endl;
                Pembalap.tambahPembalap();
                break;
            case 2:
                // jika pilihan 2, memanggil fungsi lihatTabungan
                system("cls");
                cout << "=======================================" << endl;
                cout << "           Lihat Daftar Pembalap       " << endl;
                cout << "=======================================" << endl;
                Pembalap.lihatTim();
                break;
            case 3:
                // jika pilihan 3, memanggil fungsi editTabungan
                system("cls");
                cout << "=======================================" << endl;
                cout << "            Edit data Pembalap         " << endl;
                cout << "=======================================" << endl;
                Pembalap.editPembalap();
                break;
            case 4:
                // jika pilihan 4, memanggil fungsi hapusTabungan
                system("cls");
                cout << "=======================================" << endl;
                cout << "              Hapus data Pembalap      " << endl;
                cout << "=======================================" << endl;
                Pembalap.hapusPembalap();
                break;
            case 5:
                // jika pilihan 5, memanggil fungsi cariTabungan
                system("cls");
                cout << "=======================================" << endl;
                cout << "              Sorting pembalap         " << endl;
                cout << "=======================================" << endl;
                Pembalap.SortPembalap();
                break;
            case 6:
                system("cls");
                int nomorPembalap;
                cout << "=======================================" << endl;
                cout << "              Cari Pembalap            " << endl;
                cout << "=======================================" << endl;
                Pembalap.cariPembalap();
                break;
            case 7:
                break;
            default:
                // jika pilihan tidak valid, menampilkan pesan error
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

        cout << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        system("cls");

    } while (pilihan != 7); // mengulang selama pilihan tidak sama dengan 7

    return 0;
}
