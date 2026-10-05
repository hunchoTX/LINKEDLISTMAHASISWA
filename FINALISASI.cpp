#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float persentaseKehadiran;
    Mahasiswa* next;
};

Mahasiswa* buatNode(const string& nim, const string& nama, float hadir) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nim = nim;
    baru->nama = nama;
    baru->persentaseKehadiran = hadir;
    baru->next = nullptr;
    return baru;
}

void insertHead(Mahasiswa*& head, const string& nim, const string& nama, float hadir) {
    Mahasiswa* baru = buatNode(nim, nama, hadir);
    baru->next = head;
    head = baru;
}

void insertLast(Mahasiswa*& head, const string& nim, const string& nama, float hadir) {
    Mahasiswa* baru = buatNode(nim, nama, hadir);
    if (head == nullptr) {
        head = baru;
        return;
    }
    Mahasiswa* bantu = head;
    while (bantu->next != nullptr) {
        bantu = bantu->next;
    }
    bantu->next = baru;
}

void deleteHead(Mahasiswa*& head) {
    if (head == nullptr) {
        cout << "Daftar kosong, tidak ada yang dihapus.\n";
        return;
    }
    Mahasiswa* hapus = head;
    head = head->next;
    cout << "Data dihapus: " << hapus->nim << " - " << hapus->nama << "\n";
    delete hapus;
}

void deleteLast(Mahasiswa*& head) {
    if (head == nullptr) {
        cout << "Daftar kosong, tidak ada yang dihapus.\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Data dihapus: " << head->nim << " - " << head->nama << "\n";
        delete head;
        head = nullptr;
        return;
    }
    Mahasiswa* bantu = head;
    while (bantu->next->next != nullptr) {
        bantu = bantu->next;
    }
    Mahasiswa* hapus = bantu->next;
    bantu->next = nullptr;
    cout << "Data dihapus: " << hapus->nim << " - " << hapus->nama << "\n";
    delete hapus;
}

void cetakDaftar(const Mahasiswa* head) {
    if (head == nullptr) {
        cout << "Daftar kosong.\n";
        return;
    }
    cout << "\n" << left << setw(5) << "No" << setw(15) << "NIM"
         << setw(30) << "Nama" << "Kehadiran (%)\n";
    cout << string(65, '-') << "\n";
    int no = 1;
    for (const Mahasiswa* p = head; p != nullptr; p = p->next) {
        cout << left << setw(5) << no++ << setw(15) << p->nim
             << setw(30) << p->nama << fixed << setprecision(1)
             << p->persentaseKehadiran << "\n";
    }
    cout << "Total: " << no - 1 << " mahasiswa\n";
}

void hapusSemua(Mahasiswa*& head) {
    while (head != nullptr) {
        Mahasiswa* hapus = head;
        head = head->next;
        delete hapus;
    }
}

void inputData(string& nim, string& nama, float& hadir) {
    cout << "NIM                : ";
    getline(cin, nim);
    cout << "Nama               : ";
    getline(cin, nama);
    cout << "Persentase hadir(%): ";
    while (!(cin >> hadir)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid, ulangi: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Mahasiswa* head = nullptr;

    for (int i = 1; i <= 16; i++) {
        string nim = "2024000" + string(i < 10 ? "0" : "") + to_string(i);
        string nama = "Mahasiswa " + to_string(i);
        float hadir = 100.0f - (i % 5) * 6.25f;
        insertLast(head, nim, nama, hadir);
    }

    int pilihan;
    do {
        cout << "\n=== MENU KEHADIRAN MAHASISWA ===\n"
             << "1. Insert Head\n"
             << "2. Insert Last\n"
             << "3. Delete Head\n"
             << "4. Delete Last\n"
             << "5. Cetak Daftar\n"
             << "0. Keluar\n"
             << "Pilihan: ";
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihan = -1;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string nim, nama;
        float hadir;
        switch (pilihan) {
            case 1:
                inputData(nim, nama, hadir);
                insertHead(head, nim, nama, hadir);
                cout << "Berhasil ditambahkan di depan.\n";
                break;
            case 2:
                inputData(nim, nama, hadir);
                insertLast(head, nim, nama, hadir);
                cout << "Berhasil ditambahkan di belakang.\n";
                break;
            case 3:
                deleteHead(head);
                break;
            case 4:
                deleteLast(head);
                break;
            case 5:
                cetakDaftar(head);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    hapusSemua(head);
    return 0;
}