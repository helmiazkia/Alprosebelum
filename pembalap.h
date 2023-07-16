#ifndef PEMBALAP_H
#define PEMBALAP_H
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// konstanta untuk nama file
const string FILENAME = "pembalap.txt";

// class untuk menyimpan data Pembalap
class Waktu {
    public:
    int jam;
    int menit;
    int detik;
};

class Sirkuit{
    public:
    string namaSirkuit;
    int lap;
};

class Pembalap {
public:
    string nama;
    int nomor;
    int namtim;
    Waktu waktu;
    Sirkuit sirkuit;

    void nama_tim() {
        cout << "=============================" << endl;
        cout << "   Pilihan nama tim: " << endl;
        cout << "=============================" << endl;
        cout << "1. Oracle Red Bull Racing" << endl;
        cout << "2. Scuderia Ferrari" << endl;
        cout << "3. Mercedes-AMG Petronas" << endl;
        cout << "4. BWT Alpine" << endl;
        cout << "5. McLaren" << endl;
        cout << "6. Alfa Romeo" << endl;
        cout << "7. Aston Martin" << endl;
        cout << "8. Moneygram Haas" << endl;
        cout << "9. Scuderia AlphaTauri" << endl;
        cout << "10. Williams Racing" << endl;
    }

    void tambahPembalap() {
        ulang:
        nama_tim();
        int namtim;
        cout << "Pilih tim (1-10):  ";
        cin >> namtim;

        switch (namtim) {
            case 1:
                cout << "Oracle Red Bull Racing" << endl;
                break;
            case 2:
                cout << "Scuderia Ferrari" << endl;
                break;
            case 3:
                cout << "Mercedes-AMG Petronas" << endl;
                break;
            case 4:
                cout << "BWT Alpine" << endl;
                break;
            case 5:
                cout << "McLaren" << endl;
                break;
            case 6:
                cout << "Alfa Romeo" << endl;
                break;
            case 7:
                cout << "Aston Martin" << endl;
                break;
            case 8:
                cout << "Moneygram Haas" << endl;
                break;
            case 9:
                cout << "Scuderia AlphaTauri" << endl;
                break;
            case 10:
                cout << "Williams Racing" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                goto ulang;
                break;
        }

        string nama;
        cout << "Masukkan Nama pembalap: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan Nomor pembalap: ";
        cin >> nomor;
        cout << "Masukkan Lokasi Sirkuit: ";
        cin.ignore();
        getline(cin, sirkuit.namaSirkuit);
        cout << "Masukkan Jumlah Lap : ";
        cin >> sirkuit.lap;
        cout << "Masukkan Waktu yang ditempuh: " << endl;
        cout << "Masukkan jam: ";
        cin >> waktu.jam;
        if (waktu.jam > 23 || waktu.jam < 0) {
            cout << "Inputan tidak valid" << endl;
            goto ulang;
        }
        cout << "Masukkan menit: ";
        cin >> waktu.menit;
        if (waktu.menit > 59 || waktu.menit < 0) {
            cout << "Inputan tidak valid" << endl;
            goto ulang;
        }
        cout << "Masukkan detik: ";
        cin >> waktu.detik;
        if (waktu.detik > 59 || waktu.detik < 0) {
            cout << "Inputan tidak valid" << endl;
            goto ulang;
        }

        ofstream fout(FILENAME, ios::app);
        if (fout.is_open()) {
            fout << namtim << " " << nama << " " << nomor << " " << sirkuit.namaSirkuit << " " << sirkuit.lap << " " << waktu.jam << " " << waktu.menit << " " << waktu.detik << endl;
            fout.close();
            cout << "Data pembalap berhasil ditambahkan." << endl;
        } else {
            cout << "Gagal membuka file untuk menambahkan data." << endl;
        }
    }

    void lihatTim() {
        ifstream fin;
        fin.open(FILENAME);

        system("cls"); // Clear the console screen

        cout << "\nData Tim:\n";
        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "| No. | Nama Tim               | Nama Pembalap        | No. Pembalap |     Nama Sirkuit    | Lap      |   Waktu     |" << endl;
        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;

        int no = 1;
        string line;
        while (getline(fin, line)) {
            istringstream iss(line);
            string namatim, nama;
            Waktu waktu;
            Sirkuit sirkuit;

            iss >> namatim >> nama >> nomor >> sirkuit.namaSirkuit >> sirkuit.lap >> waktu.jam >> waktu.menit >> waktu.detik;

            cout << "| " << setw(3) << no << " | ";
            if (namatim == "1") {
                cout << setw(23) << "Oracle Red Bull Racing";
            } else if (namatim == "2") {
                cout << setw(23) << "Scuderia Ferrari";
            } else if (namatim == "3") {
                cout << setw(23) << "Mercedes-AMG Petronas";
            } else if (namatim == "4") {
                cout << setw(23) << "BWT Alpine";
            } else if (namatim == "5") {
                cout << setw(23) << "McLaren";
            } else if (namatim == "6") {
                cout << setw(23) << "Alfa Romeo";
            } else if (namatim == "7") {
                cout << setw(23) << "Aston Martin";
            } else if (namatim == "8") {
                cout << setw(23) << "Moneygram Haas";
            } else if (namatim == "9") {
                cout << setw(23) << "Scuderia AlphaTauri";
            } else if (namatim == "10") {
                cout << setw(23) << "Williams Racing";
            } else {
                cout << setw(23) << "Pilihan tidak valid";
            }

            cout << " | " << setw(18) << nama << " | ";
            cout << setw(15) << nomor << " | ";
            cout << setw(15) << sirkuit.namaSirkuit << " | ";
            cout << setw(12) << sirkuit.lap << " | ";
            cout << setw(2) << waktu.jam << ":" << setw(2) << waktu.menit << ":" << setw(2) << waktu.detik << " |" << endl;
            no++;
        }

        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
        fin.close();
    }

    void editPembalap() {
    lihatTim();
    int nomorPembalap;
    cout << "Masukkan Nomor Pembalap yang ingin diubah: ";
    cin >> nomorPembalap;

    ifstream fin(FILENAME);
    ofstream fout("temp.txt", ios::app);
    if (fin.is_open() && fout.is_open()) {
        string namatim, nama;

        bool found = false;

        while (fin >> namatim >> nama >> nomor >> waktu.jam >> waktu.menit >> waktu.detik) {
            if (nomor == nomorPembalap) {
                found = true;

                cout << "Nama Tim: ";
                if (namatim == "1") {
                    cout << "Oracle Red Bull Racing" << endl;
                } else if (namatim == "2") {
                    cout << "Scuderia Ferrari" << endl;
                } else if (namatim == "3") {
                    cout << "Mercedes-AMG Petronas" << endl;
                } else if (namatim == "4") {
                    cout << "BWT Alpine" << endl;
                } else if (namatim == "5") {
                    cout << "McLaren" << endl;
                } else if (namatim == "6") {
                    cout << "Alfa Romeo" << endl;
                } else if (namatim == "7") {
                    cout << "Aston Martin" << endl;
                } else if (namatim == "8") {
                    cout << "Moneygram Haas" << endl;
                } else if (namatim == "9") {
                    cout << "Scuderia AlphaTauri" << endl;
                } else if (namatim == "10") {
                    cout << "Williams Racing" << endl;
                } else {
                    cout << "Pilihan tidak valid" << endl;
                }

                string newNama;
                int newNomor, newJam, newMenit, newDetik;
                cout << "Masukkan Nama Pembalap baru: ";
                cin.ignore();
                getline(cin, newNama);
                cout << "Masukkan Nomor Pembalap baru: ";
                cin >> newNomor;
                cout << "Masukkan Waktu yang ditempuh baru: " << endl;
                cout << "Masukkan jam: ";
                cin >> newJam;
                if (newJam > 23 || newJam < 0) {
                    cout << "Inputan tidak valid" << endl;
                    continue;
                }
                cout << "Masukkan menit: ";
                cin >> newMenit;
                if (newMenit > 59 || newMenit < 0) {
                    cout << "Inputan tidak valid" << endl;
                    continue;
                }
                cout << "Masukkan detik: ";
                cin >> newDetik;
                if (newDetik > 59 || newDetik < 0) {
                    cout << "Inputan tidak valid" << endl;
                    continue;
                }

                fout << namatim << " " << newNama << " " << newNomor << " " << waktu.jam << " " << waktu.menit << " " << waktu.detik << endl;

                cout << "Data pembalap berhasil diubah." << endl;
            } else {
                fout << namatim << " " << nama << " " << nomor << " " << waktu.jam << " " << waktu.menit << " " << waktu.detik << endl;
            }
        }

        fin.close();
        fout.close();

        remove(FILENAME.c_str());
        rename("temp.txt", FILENAME.c_str());

        if (!found) {
            cout << "Nomor Pembalap tidak ditemukan." << endl;
        }
    } else {
        cout << "Gagal membuka file." << endl;
    }
}


    void hapusPembalap() {
        lihatTim();
        int nomorPembalap;
        cout << "Masukkan Nomor Pembalap yang ingin dihapus: ";
        cin >> nomorPembalap;

        ifstream fin(FILENAME);
        ofstream fout("temp.txt", ios::app);
        if (fin.is_open() && fout.is_open()) {
            string namtim, nama;
            Sirkuit sirkuit;
            Waktu waktu;

            bool found = false;

            while (fin >> namtim >> nama >> nomor >> sirkuit.namaSirkuit >> sirkuit.lap >> waktu.jam >> waktu.menit >> waktu.detik) {
                if (nomor == nomorPembalap) {
                    found = true;
                    cout << "Data pembalap berhasil dihapus." << endl;
                } else {
                    fout << namtim << " " << nama << " " << nomor << " " << sirkuit.namaSirkuit << " " << sirkuit.lap << " " << waktu.jam << " " << waktu.menit << " " << waktu.detik << endl;
                }
            }

            fin.close();
            fout.close();

            remove(FILENAME.c_str());
            rename("temp.txt", FILENAME.c_str());

            if (!found) {
                cout << "Nomor Pembalap tidak ditemukan." << endl;
            }
        } else {
            cout << "Gagal membuka file." << endl;
        }
    }

    const int MAX_RACERS = 100;

    void SortPembalap() {
        ifstream fin;
        fin.open(FILENAME);

        system("cls");

        cout << "\nData Tim:\n";
        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "| No. | Nama Tim               | Nama Pembalap        | No. Pembalap |     Nama Sirkuit    | Lap      |   Waktu     |" << endl;
        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;

        int no = 1;
        string line;
        string pembalap[MAX_RACERS];
        int jumlahPembalap = 0;

        while (getline(fin, line)) {
            pembalap[jumlahPembalap] = line;
            jumlahPembalap++;

            if (jumlahPembalap >= MAX_RACERS) {
                cout << "Jumlah pembalap melebihi batas maksimum." << endl;
                break;
            }
        }

        bool ditukar = true;
        int i = 0;

        while (ditukar) {
            ditukar = false;
            int j = 0;

            while (j < jumlahPembalap - i - 1) {
                istringstream iss1(pembalap[j]);
                istringstream iss2(pembalap[j + 1]);
                string namatim1, nama1, waktu1;
                string namatim2, nama2, waktu2;
                int nomor1, jam1, menit1, detik1;
                int nomor2, jam2, menit2, detik2;
                Sirkuit sirkuit;

                iss1 >> namatim1 >> nama1 >> nomor1 >> sirkuit.namaSirkuit >> sirkuit.lap >> jam1 >> menit1 >> detik1;
                iss2 >> namatim2 >> nama2 >> nomor2 >> sirkuit.namaSirkuit >> sirkuit.lap >> jam2 >> menit2 >> detik2;

                int totalDetik1 = jam1 * 3600 + menit1 * 60 + detik1;
                int totalDetik2 = jam2 * 3600 + menit2 * 60 + detik2;

                if (totalDetik1 > totalDetik2) {
                    swap(pembalap[j], pembalap[j + 1]);
                    ditukar = true;
                }

                j++;
            }

            i++;
        }

        int indeks = 0;
        while (indeks < jumlahPembalap) {
            istringstream iss(pembalap[indeks]);
            string namatim, nama, waktu, namaTim;
            int nomor, jam, menit, detik;

            iss >> namatim >> nama >> nomor >> sirkuit.namaSirkuit >> sirkuit.lap >> jam >> menit >> detik;

    if (namatim == "1") {
                       namaTim = "Oracle Red Bull Racing";
                    } else if (namatim == "2") {
                        namaTim = "Scuderia Ferrari";
                    } else if (namatim == "3") {
                        namaTim = "Mercedes-AMG Petronas";
                    } else if (namatim == "4") {
                        namaTim = "BWT Alpine";
                    } else if (namatim == "5") {
                        namaTim = "McLaren";
                    } else if (namatim == "6") {
                        namaTim = "Alfa Romeo" ;
                    } else if (namatim == "7") {
                        namaTim = "Aston Martin";
                    } else if (namatim == "8") {
                        namaTim = "Moneygram Haas" ;
                    } else if (namatim == "9") {
                        namaTim = "Scuderia AlphaTauri";
                    } else if (namatim == "10") {
                        namaTim ="Williams Racing";
                    } else {
                        namaTim = "Pilihan tidak valid";
                    }

            cout << "| " << setw(3) << no << " | ";
            cout << setw(23) << namaTim << " | ";
            cout << setw(15) << nama << " | ";
            cout << setw(15) << nomor << " | ";
            cout << setw(15) << sirkuit.namaSirkuit << " | ";
            cout << setw(15) << sirkuit.lap << " | ";
            cout << setw(2) << jam << ":" << setw(2) << menit << ":" << setw(2) << detik << " |" << endl;
            no++;

            indeks++;
        }

        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
        fin.close();
    }

    void cariPembalap() {
        ifstream fin;
        fin.open(FILENAME);
        dat:
        int data;
        cout << "Data mana yang ingin di sorting" << endl << endl;
        cout << "1. Sebelum di sorting" << endl;
        cout << "2. Sesudah di sort" << endl;
        cout << "1 atau 2: ";
        cin >> data;
        if (data == 1) {
            lihatTim();
        } else if (data == 2) {
            SortPembalap();
        } else {
            cout << "Data tidak ditemukan" << endl;
            goto dat;
        }
        string namaPembalap;
        cout << "Masukkan Nama Pembalap yang ingin dicari: ";
        cin >> namaPembalap;

        system("cls");

        cout << "\nHasil Pencarian:\n";
        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "| No. | Nama Tim               | Nama Pembalap        | No. Pembalap |     Nama Sirkuit    | Lap      |   Waktu     |" << endl;
        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
        int no = 1;
        string line;
        bool ditemukan = false;

        while (getline(fin, line)) {
            istringstream iss(line);
            string namatim, nama, waktu;
            int nomor, jam, menit, detik;
            Sirkuit sirkuit;
            iss >> namatim >> nama >> nomor >> sirkuit.namaSirkuit >> sirkuit.lap >> jam >> menit >> detik;

            if (nama == namaPembalap) {
                ditemukan = true;

                cout << "| " << setw(3) << no << " | ";
                if (namatim == "1") {
                    cout << setw(21) << "Oracle Red Bull Racing" << " | ";
                } else if (namatim == "2") {
                    cout << setw(21) << "Scuderia Ferrari" << " | ";
                } else if (namatim == "3") {
                    cout << setw(21) << "Mercedes-AMG Petronas" << " | ";
                } else if (namatim == "4") {
                    cout << setw(21) << "BWT Alpine" << " | ";
                } else if (namatim == "5") {
                    cout << setw(21) << "McLaren" << " | ";
                } else if (namatim == "6") {
                    cout << setw(21) << "Alfa Romeo" << " | ";
                } else if (namatim == "7") {
                    cout << setw(21) << "Aston Martin" << " | ";
                } else if (namatim == "8") {
                    cout << setw(21) << "Moneygram Haas" << " | ";
                } else if (namatim == "9") {
                    cout << setw(21) << "Scuderia AlphaTauri" << " | ";
                } else if (namatim == "10") {
                    cout << setw(21) << "Williams Racing" << " | ";
                } else {
                    cout << setw(21) << "Pilihan tidak valid" << " | ";
                }

                cout << setw(17) << nama << " | ";
                cout << setw(15) << nomor << " | ";
                cout << setw(15) << sirkuit.namaSirkuit << " | ";
                cout << setw(15) << sirkuit.lap << " | ";
                cout << setw(2) << jam << ":" << setw(2) << menit << ":" << setw(2) << detik << " |" << endl;
                no++;
            }
        }

        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
        fin.close();

        if (!ditemukan) {
            cout << "Pembalap dengan nama " << namaPembalap << " tidak ditemukan." << endl;
        }
    }
};

void createFile() {
    ifstream fin;
    fin.open(FILENAME);

    // mengecek apakah file sudah ada atau tidak
    if (fin.fail()) {
        fin.close();
        ofstream fout;
        fout.open(FILENAME);
        fout.close();
    } else {
        fin.close();
    }
}

#endif // PEMBALAP_H


