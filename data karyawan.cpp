#include <iostream>
#include <iomanip>
#include <string>
#define max 30

using namespace std;

// Bagian struct
struct karyawan {
    int nip;
    string namakrywn, tlpon, jbtn, agm, tgl;
};

// Bagian Stack
struct stack {
    int top;
    struct karyawan krywn[max];
} S;

// Bagian Struct & Queue
struct queue {
    int front, rear;
    struct karyawan baru[max];
} Q;

void initQueue() {
    Q.front = -1;
    Q.rear = -1;
}

int isQueueEmpty() {
    return (Q.front == -1 && Q.rear == -1);
}

int isQueueFull() {
    return (Q.rear == max - 1);
}

void enqueue(struct karyawan data) {
    if (isQueueFull()) {
        cout << "DATA SUDAH PENUH" << endl;
    } else {
        if (isQueueEmpty()) {
            Q.front = Q.rear = 0;
        } else {
            Q.rear++;
        }
        Q.baru[Q.rear] = data;
    }
}

struct karyawan dequeue() {
    struct karyawan data;
    if (isQueueEmpty()) {
        cout << "DATA KOSONG" << endl;
        return data;
    } else {
        data = Q.baru[Q.front];
        if (Q.front == Q.rear) {
            initQueue();
        } else {
            Q.front++;
        }
        return data;
    }
}

int isEmpty() {
    return (S.top == 0);
}

int isFull() {
    return (S.top == max - 1);
}

// Masukan Data Karyawan Baru
void masukindatakaryawanbaru(int nip, string tgl, string agm, string namakrywn, string tlpon, string jbtn) {
    if (isEmpty() || !isFull()) {
        S.top++;
        S.krywn[S.top].nip = nip;
        S.krywn[S.top].namakrywn = namakrywn;
        S.krywn[S.top].tgl = tgl;
        S.krywn[S.top].tlpon = tlpon;
        S.krywn[S.top].agm = agm;
        S.krywn[S.top].jbtn = jbtn;
        cout << "DATA KARYAWAN BERHASIL DITAMBAH\n";
        cout << endl;
    } else {
        cout << "STACK TELAH PENUH" << endl;
        cout << endl;
    }
}

// Bagian Sorting
void sorting() {
    for (int i = 1; i <= S.top; i++) {
        for (int j = i + 1; j <= S.top; j++) {
            if (S.krywn[j].nip > S.krywn[i].nip) {
                swap(S.krywn[j], S.krywn[i]);
            }
        }
    }
}

// Lihat Daftar Karyawan Baru
void tampil() {
    if (!isEmpty()) {
        sorting();
        cout << "\n";
        cout << "===================================================================" << endl;
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
        cout << "____________________________________________________________________" << endl;
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
        cout << "====================================================================" << endl;
        cout << endl;
    } else {
        cout << "STACK MASIH KOSONG" << endl
             << endl;
    }
}

// Bagian Pencarian Data karyawan Baru
int cariByNIP(int nip) {
    for (int i = 1; i <= S.top; i++) {
        if (S.krywn[i].nip == nip) {
            return i;
        }
    }
    return -1;
}

// Tambah Data Karyawan Lama
void tambahDataKaryawanlama(int nip, string tanggal_lahir, string agama, string namakaryawan, string telepon, string jabatan) {
    struct karyawan data;
    data.nip = nip;
    data.namakrywn = namakaryawan;
    data.tgl = tanggal_lahir;
    data.tlpon = telepon;
    data.agm = agama;
    data.jbtn = jabatan;

    if (!isQueueFull()) {
        enqueue(data); // Menambahkan data baru ke antrian tunggu
        cout << "DATA KARYAWAN TELAH DITAMBAHKAN\n";
    } else {
        cout << "DATA SUDAH PENUH" << endl;
    }
}

// Tampilkan Data Karyawan Lama
void tampilkanDataKaryawanlama() {
    if (!isQueueEmpty()) {
        cout << "\nDaftar Karyawan Lama Amikom:\n";
        while (!isQueueEmpty()) {
            struct karyawan data = dequeue();
            cout << "NIP: " << data.nip << ", Nama: " << data.namakrywn << endl;
        }
        cout << endl;
    } else {
        cout << "DATA KARYAWAN MASIH KOSONG" << endl;
    }
}

//Hapus Data Karyawan
void hapusDataKaryawan(int nip) {
    int index = cariByNIP(nip);
    if (index != -1) {
        // Geser data ke atas untuk menutup celah
        for (int i = index; i < S.top; i++) {
            S.krywn[i] = S.krywn[i + 1];
        }
        S.top--;

        cout << "DATA KARYAWAN BERHASIL DIHAPUS\n";

        // Tambahkan data ke dalam antrian tunggu
        struct karyawan data = dequeue();
        enqueue(data);
    } else {
        cout << "DATA TIDAK DITEMUKAN\n";
    }
}

void menu() {
    cout << endl;
    cout << "||                PILIHAN MENU DIBAWAH INI                   ||\n";
    cout << "||                                                           ||\n";
    cout << "|| 1. Masukan Data Karyawan Baru Amikom Yogyakarta           ||\n";
    cout << "|| 2. Lihat Daftar Karyawan Baru Amikom Yogyakarta           ||\n";
    cout << "|| 3. Cari Data Karyawan Baru Amikom Yogyakarta              ||\n";
    cout << "|| 4. Masukkan Data Karyawan Lama                            ||\n";
    cout << "|| 5. Tampilkan Data Karyawan Lama                           ||\n";
    cout << "|| 6. Hapus Data Karyawan Amikom Yogyakarta                  ||\n";
    cout << "|| 7. Exit                                                   ||\n";
    cout << endl;
}

int main() {
    initQueue(); // Inisialisasi antrian
    S.top = 0;   // Inisialisasi stack

    char pilihMenu;
    int ulang = 1;
    int nip;
    string namakrywn, tlpon, jbtn, agm, tgl;
    int index;

    do {
        menu();
        cout << "Input Menu  : ";
        cin >> pilihMenu;
        switch (pilihMenu) {
        case '1':
            cout << "\nMasukkan NIP \t\t= ";
            cin >> nip;
            cout << "Masukan Nama Karyawan \t= ";
            cin >> namakrywn;
            cout << "Masukan Tanggal Lahir \t= ";
            cin >> tgl;
            cout << "Masukan Telepon \t= ";
            cin >> tlpon;
            cout << "Masukan Agama \t\t= ";
            cin >> agm;
            cout << "Masukan Jabatan \t= ";
            cin >> jbtn;
            masukindatakaryawanbaru(nip, tgl, agm, namakrywn, tlpon, jbtn);
            break;

        case '2':
            tampil();
            break;

        case '3':
            cout << "\nMasukkan NIP Yang Dicari: ";
            cin >> nip;
            index = cariByNIP(nip);
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
            break;

        case '4':
            cout << "\nMasukkan NIP \t\t= ";
            cin >> nip;
            cout << "Masukan Nama Karyawan \t= ";
            cin >> namakrywn;
            cout << "Masukan Tanggal Lahir \t= ";
            cin >> tgl;
            cout << "Masukan Telepon \t= ";
            cin >> tlpon;
            cout << "Masukan Agama \t\t= ";
            cin >> agm;
            cout << "Masukan Jabatan \t= ";
            cin >> jbtn;
            tambahDataKaryawanlama(nip, tgl, agm, namakrywn, tlpon, jbtn);
            break;

        case '5':
            tampilkanDataKaryawanlama();
            break;

        case '6':
            cout << "\nMasukkan NIP yang akan dihapus: ";
            cin >> nip;
            hapusDataKaryawan(nip);
            break;

        case '7':
            cout << "\n\tTERIMA KASIH" << endl;
            cout << "\n\tPROGRAM EXIT" << endl;
            ulang = 0;
            break;
        }
    } while (ulang == 1);

    return 0;
}
