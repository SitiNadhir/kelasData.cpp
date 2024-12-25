#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
};

Mahasiswa sikc[30];
int pos = -1;

void tampilkanMenu() {
    system("cls");
    cout << "==============================" << endl;
    cout << "  Aplikasi Pencatatan Data   " << endl;
    cout << "==============================" << endl;
    cout << "1. Masukkan Data" << endl;
    cout << "2. Tampilkan Semua Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Hapus Data" << endl;
    cout << "5. Keluar" << endl;
    cout << "==============================" << endl;
    cout << "Masukkan pilihan: ";
}

void masukkanData() {
    system("cls");
    if (pos >= 29) {
        cout << "Data sudah penuh." << endl;
        cout << "\nTekan Enter untuk kembali...";
        cin.get();
        return;
    }

    pos++;
    cout << "Masukkan Data Mahasiswa\n";
    cout << "------------------------\n";

    cout << "Masukkan NIM: ";
    getline(cin, sikc[pos].nim);
    cout << "Masukkan Nama: ";
    getline(cin, sikc[pos].nama);
    cout << "Masukkan Alamat: ";
    getline(cin, sikc[pos].alamat);

    while (true) {
        cout << "Masukkan IPK (0.0 - 4.0): ";
        cin >> sikc[pos].ipk;
        if (cin.fail() || sikc[pos].ipk < 0.0 || sikc[pos].ipk > 4.0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Coba lagi.\n";
        } else {
            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nData berhasil disimpan!\n";
    cout << "\nTekan Enter untuk kembali...";
    cin.get();
}

void tampilkanSemuaData() {
    system("cls");
    if (pos == -1) {
        cout << "Tidak ada data untuk ditampilkan." << endl;
    } else {
        cout << left
             << setw(5)  << "No"
             << setw(15) << "NIM"
             << setw(20) << "Nama"
             << setw(30) << "Alamat"
             << setw(10) << "IPK" << endl;
        cout << string(80, '-') << endl;

        for (int i = 0; i <= pos; i++) {
            cout << left
                 << setw(5)  << i + 1
                 << setw(15) << sikc[i].nim
                 << setw(20) << sikc[i].nama
                 << setw(30) << sikc[i].alamat
                 << setw(10) << fixed << setprecision(2) << sikc[i].ipk
                 << endl;
        }
    }
    cout << "\nTekan Enter untuk kembali...";
    getch();
}

void updateData() {
    system("cls");
    if (pos == -1) {
        cout << "Tidak ada data untuk diupdate." << endl;
        cout << "\nTekan Enter untuk kembali...";
        cin.get();
        return;
    }

    string cariNIM;
    cout << "Masukkan NIM mahasiswa yang ingin diupdate: ";
    getline(cin, cariNIM);

    bool ditemukan = false;
    for (int i = 0; i <= pos; i++) {
        if (sikc[i].nim == cariNIM) {
            ditemukan = true;

            cout << "\nData ditemukan!" << endl;
            cout << "Masukkan data baru:\n";
            cout << "Masukkan Nama: ";
            getline(cin, sikc[i].nama);
            cout << "Masukkan Alamat: ";
            getline(cin, sikc[i].alamat);

            while (true) {
                cout << "Masukkan IPK (0.0 - 4.0): ";
                cin >> sikc[i].ipk;
                if (cin.fail() || sikc[i].ipk < 0.0 || sikc[i].ipk > 4.0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid. Coba lagi.\n";
                } else {
                    break;
                }
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nData berhasil diperbarui!" << endl;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nData dengan NIM \"" << cariNIM << "\" tidak ditemukan." << endl;
    }

    cout << "\nTekan Enter untuk kembali...";
    cin.get();
}

void hapusData() {
    system("cls");
    if (pos == -1) {
        cout << "Tidak ada data untuk dihapus." << endl;
        cout << "\nTekan Enter untuk kembali...";
        cin.get();
        return;
    }

    string cariNIM;
    cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
    getline(cin, cariNIM);

    bool ditemukan = false;
    for (int i = 0; i <= pos; i++) {
        if (sikc[i].nim == cariNIM) {
            ditemukan = true;

            for (int j = i; j < pos; j++) {
                sikc[j] = sikc[j + 1];
            }
            pos--;
            cout << "\nData berhasil dihapus!" << endl;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nData dengan NIM \"" << cariNIM << "\" tidak ditemukan." << endl;
    }

    cout << "\nTekan Enter untuk kembali...";
    cin.get();
}

int main() {
    char pilihan;
    do {
        tampilkanMenu();
        pilihan = getch();
        switch (pilihan) {
            case '1': masukkanData(); break;
            case '2': tampilkanSemuaData(); break;
            case '3': updateData(); break;
            case '4': hapusData(); break;
            case '5': cout << "\nKeluar dari program.\n"; break;
            default:
                system("cls");
                cout << "Pilihan tidak tersedia. Tekan Enter untuk kembali...";
                cin.get();
                break;
        }
    } while (pilihan != '5');

    return 0;
}
