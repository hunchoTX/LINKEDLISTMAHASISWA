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

int main() {
    Mahasiswa* head = nullptr;
    insertLast(head, "202400001", "Andi", 90.0f);
    insertLast(head, "202400002", "Budi", 85.0f);
    insertHead(head, "202400000", "Citra", 100.0f);
    for (Mahasiswa* p = head; p != nullptr; p = p->next)
        cout << p->nim << " - " << p->nama << "\n";
    deleteHead(head);
    deleteLast(head);
    for (Mahasiswa* p = head; p != nullptr; p = p->next)
        cout << p->nim << " - " << p->nama << "\n";
    return 0;
}