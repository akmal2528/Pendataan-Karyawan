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

// Bagian struct
struct tunggu {
    int nip; 
    string namakrywn, tlpon, jbtn, agm, tgl;
};

// Bagian Stack
struct stack {
    int top; 
    struct karyawan krywn[max];
    struct tunggu temp[max];
} S;

// Pointer ke data karyawan yang aktif di stack
struct karyawan* activeKaryawan = NULL;

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

// Bagian Struct & Queue
struct queue {
    int front, rear;
    struct karyawan krywn[max];
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
        Q.krywn[Q.rear] = data;
    }
}

struct karyawan dequeue() {
    struct karyawan data;
    if (isQueueEmpty()) {
        cout << "DATA KOSONG" << endl;
        return data;
    } else {
        data = Q.krywn[Q.front];
        if (Q.front == Q.rear) {
            initQueue();
        } else {
            Q.front++;
        }
        return data;
    }
}

// Fungsi untuk memeriksa apakah karyawan dengan NIP tertentu sudah ada di dalam antrian
bool isExistInQueue(int nip) {
    for (int i = Q.front; i <= Q.rear; i++) {
        if (Q.krywn[i].nip == nip) {
            return true;
        }
    }
    return false;
}

// Masukan Data Karyawan Lama
void masukindata(int nip, string tgl, string agm, string namakrywn, string tlpon, string jbtn) {
    if (isEmpty() == 1) {
        S.top++;
        activeKaryawan = &S.krywn[S.top]; // Set pointer ke data karyawan
        activeKaryawan->nip = nip;
        activeKaryawan->namakrywn = namakrywn;
        activeKaryawan->tgl = tgl;
        activeKaryawan->tlpon = tlpon;
        activeKaryawan->agm = agm;
        activeKaryawan->jbtn = jbtn;
        cout << "DATA KARYAWAN BERHASIL DITAMBAH\n";
        cout << endl;
    } else if (isFull() == 0) {
        S.top++;
        activeKaryawan = &S.krywn[S.top]; // Set pointer ke data karyawan
        activeKaryawan->nip = nip;
        activeKaryawan->namakrywn = namakrywn;
        activeKaryawan->tgl = tgl;
        activeKaryawan->tlpon = tlpon;
        activeKaryawan->agm = agm;
        activeKaryawan->jbtn = jbtn;
        cout << "DATA KARYAWAN TELAH TERDAFTAR\n";
        cout << endl;
    } else {
        cout << "STACK TELAH PENUH";
        cout << endl;
    }
}	

// Bagian Sorting
void sorting() {
    int jmax;
    int u = S.top;
    for (int j = 0; j < S.top; j++) {
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
        S.krywn[u].tlpon = S.krywn[jmax].tlpon;
        S.krywn[u].agm = S.krywn[jmax].agm;
        S.krywn[u].jbtn = S.krywn[jmax].jbtn;

        S.krywn[jmax].nip = S.temp[j].nip;
        S.krywn[jmax].namakrywn = S.temp[j].namakrywn;
        S.krywn[jmax].tgl = S.temp[j].tgl;
        S.krywn[jmax].tlpon = S.temp[j].tlpon;
        S.krywn[jmax].agm = S.temp[j].agm;
        S.krywn[jmax].jbtn = S.temp[j].jbtn;
        u--;
    }
}

// Lihat Daftar Karyawan Baru
void tampil() {
    if (isEmpty() == 0) {
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
void tambahDataAntrian(int nip, string tanggal_lahir, string agama, string namakaryawan, string telepon, string jabatan) {
    // Periksa apakah karyawan sudah ada 
    if (isExistInQueue(nip)) {
        cout << "DATA KARYAWAN SUDAH ADA\n";
        return;
    }

    // Periksa apakah karyawan sudah ada di stack
    int index = cariByNIP(nip);
    if (index != -1) {
        cout << "DATA KARYAWAN SUDAH ADA DI STACK\n";
        return;
    }

    struct karyawan data;
    data.nip = nip;
    data.namakrywn = namakaryawan;
    data.tgl = tanggal_lahir;
    data.tlpon = telepon;
    data.agm = agama;
    data.jbtn = jabatan;

    if (isQueueFull()) {
        cout << "DATA SUDAH PENUH" << endl;
    } else {
        enqueue(data); // Menambahkan data baru ke antrian
        cout << "DATA KARYAWAN TELAH DITAMBAHKAN\n";
    }
}

// Tampilkan Data Karyawan Lama
void tampilkanDataAntrian() {
    if (isQueueEmpty()) {
        cout << "DATA KARYAWAN MASIH KOSONG" << endl;
    } else {
        cout << "\nDaftar Karyawan Lama Amikom:\n";
        while (!isQueueEmpty()) {
            struct karyawan data = dequeue();
            cout << "NIP: " << data.nip << ", Nama: " << data.namakrywn << endl;
        }
        cout << endl;
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
    cout << "|| 6. Exit                                                   ||\n";
    cout << endl;
}

int main() {
    initQueue();  // Inisialisasi antrian
    S.top = 0;    // Inisialisasi stack

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
                masukindata(nip, tgl, agm, namakrywn, tlpon, jbtn);
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
                tambahDataAntrian(nip, tgl, agm, namakrywn, tlpon, jbtn);
                break;

            case '5':
                tampilkanDataAntrian();
                break;

            case '6':
                cout << "\n\tTERIMA KASIH" << endl;
                cout << "\n\tPROGRAM EXIT" << endl;  
                ulang = 0;
                break;
        }
    } while (ulang == 1);

    return 0;
}
