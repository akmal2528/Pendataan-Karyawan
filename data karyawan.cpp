#include <iostream>
#include <iomanip>
#include <string> 
#define max 50

using namespace std;

struct karyawan {
    int nip;
    string namakrywn, tlpon, jbtn, agm, tgl;
};

struct tunggu {
    int nip;
    string namakrywn, tlpon, jbtn, agm, tgl;
};

struct stack {
    int top;
    struct karyawan krywn[max];
    struct tunggu temp[max];
} S;

int isEmpty() {
    if (S.top == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    if (S.top == max - 1) {
        return 1;
    } else {
        return 0;
    }
}

void masukindata(int nip, string tgl, string agm, string namakrywn, string tlpon, string jbtn) {
    if (isEmpty() == 1) {
        S.top++;
        S.krywn[S.top].nip = nip;
        S.krywn[S.top].namakrywn = namakrywn;
        S.krywn[S.top].tgl = tgl;
        S.krywn[S.top].tlpon = tlpon;
        S.krywn[S.top].agm = agm;
        S.krywn[S.top].jbtn = jbtn;
        cout << "DATA KARYAWAN BERHASIL DITAMBAH\n";
        cout << endl;
    } else if (isFull() == 0) {
        S.top++;
        S.krywn[S.top].nip = nip;
        S.krywn[S.top].namakrywn = namakrywn;
        S.krywn[S.top].tgl = tgl;
        S.krywn[S.top].tlpon = tlpon;
        S.krywn[S.top].agm = agm;
        S.krywn[S.top].jbtn = jbtn;
        cout << "DATA KARYAWAN TELAH DITAMBAHKAN KE DAFTAR\n";
        cout << endl;
    } else {
        cout << "STACK TELAH PENUH";
        cout << endl;
    }
}

void sorting() {
    int jmax;
    int u = S.top;
    for (int j = 0; j < S.top + 1; j++) {
        jmax = 0;
        for (int k = 1; k <= u; k++) {
            if (S.krywn[k].nip > S.krywn[jmax].nip) {
                jmax = k;
            }
        }
        S.temp[j].nip = S.krywn[u].nip;
        S.temp[j].namakrywn = S.krywn[u].namakrywn;
        S.temp[j].tgl = S.krywn[u].tgl;
        S.temp[j].tlpon = S.krywn[u].tlpon;
        S.temp[j].agm = S.krywn[u].agm;
        S.temp[j].jbtn = S.krywn[u].jbtn;

        S.krywn[u].nip = S.krywn[jmax].nip;
        S.krywn[u].namakrywn = S.krywn[jmax].namakrywn;
        S.krywn[u].tgl = S.krywn[jmax].tgl;
        S.krywn[u].agm = S.krywn[jmax].agm;
        S.temp[j].jbtn = S.krywn[u].jbtn;

        S.krywn[jmax].nip = S.temp[j].nip;
        S.krywn[jmax].namakrywn = S.temp[j].namakrywn;
        S.krywn[jmax].tgl = S.temp[j].tgl;
        S.krywn[jmax].tlpon = S.temp[j].tlpon;
        S.krywn[jmax].agm = S.temp[j].agm;
        S.temp[j].jbtn = S.krywn[u].jbtn;
        u--;
    }
}

void tampil() {
    if (isEmpty() == 0) {
        sorting();
        cout << "\n";
        cout << "========================================================================================================================" << endl;
        cout << "\n";
        cout << "NIP \t \t";
        cout << " | ";
        cout << "Nama karyawan";
        cout << " | ";
        cout << "Tanggal Lahir      ";
        cout << " | ";
        cout << "Nomor Telepon    ";
        cout << " | ";
        cout << "Agama             ";
        cout << " | ";
        cout << "Jabatan             ";
        cout << " | " << endl;
        cout << "______________________________________________________________________________________________________________________" << endl;
        for (int i = 1; i <= S.top; i++) {
            cout << setiosflags(ios::left) << setw(16) << S.krywn[i].nip;
            cout << " | ";
            cout << setiosflags(ios::left) << setw(13) << S.krywn[i].namakrywn;
            cout << " | ";
            cout << setiosflags(ios::left) << setw(19) << S.krywn[i].tgl;
            cout << " | ";
            cout << setiosflags(ios::left) << setw(17) << S.krywn[i].tlpon;
            cout << " | ";
            cout << setiosflags(ios::left) << setw(18) << S.krywn[i].agm;
            cout << " | ";
            cout << setiosflags(ios::left) << setw(20) << S.krywn[i].jbtn;
            cout << " | " << endl;
        }
        cout << "========================================================================================================================" << endl;
        cout << endl;
    } else {
        cout << "STUCK MASIH KOSONG" << endl
             << endl;
    }
}

int cariByNIP(int nip) {
    for (int i = 1; i <= S.top; i++) {
        if (S.krywn[i].nip == nip) {
            return i;
        }
    }
    return -1;
}

void menu() {
    cout << "||-----------------------------------------------------------||\n";
    cout << "||                PILIHAN MENU DIBAWAH INI                   ||\n";
    cout << "||                                                           ||\n";
    cout << "|| 1. Masukan Data Karyawan Amikom Yogyakarta                ||\n";
    cout << "|| 2. Lihat Daftar Karyawan Amikom Yogyakarta                ||\n";
    cout << "|| 3. Cari Data Karyawan                                     ||\n";
    cout << "|| 4. Exit                                                   ||\n";
    cout << "||-----------------------------------------------------------||\n";
    cout << endl;
}

int main() {
    char pilihMenu;
    int ulang = 1;
    int nip;
    string namakrywn, tlpon, jbtn, agm, tgl;

    do {
        menu();
        cout << "Input Menu  : ";
        cin >> pilihMenu;
        switch (pilihMenu) {
        case '1':
            cout << "\nMasukkan NIP \t		= ";
            cin >> nip;
            cout << "Masukan Nama Karyawan \t\t= ";
            cin >> namakrywn;
            cout << "Masukan Tanggal Lahir \t	= ";
            cin >> tgl;
            cout << "Masukan Telepon \t	= ";
            cin >> tlpon;
            cout << "Masukan Agama \t		= ";
            cin >> agm;
            cout << "Masukan Jabatan \t	= ";
            cin >> jbtn;
            masukindata(nip, tgl, agm, namakrywn, tlpon, jbtn);
            break;

        case '2':{
		
            tampil();
        }
            break;

        case '3':{
		
            cout << "\nMasukkan NIP Yang Dicari: ";
            cin >> nip;
            int index = cariByNIP(nip);
            if (index != -1) {
                cout << "DATA DITEMUKAN PADA INDEKS " << index << endl;
                cout << "NIP		: " << S.krywn[index].nip << endl;
                cout << "Nama Karyawan	: " << S.krywn[index].namakrywn << endl;
                cout << "Tanggal Lahir	: " << S.krywn[index].tgl << endl;
                cout << "Nomor Telepon	: " << S.krywn[index].tlpon << endl;
                cout << "Agama		: " << S.krywn[index].agm << endl;
                cout << "Jabatan		: " << S.krywn[index].jbtn << endl;
            } else {
                cout << "DATA TIDAK DITEMUKAN\n";
            }
        }
            break;

        case '4':{
            cout << "\n\tTERIMA KASIH" << endl;
            cout << "\n\tPROGRAM EXIT" << endl;
            ulang = 0;}
            break;
        }
    } while (ulang == 1);

    return 0;
}
