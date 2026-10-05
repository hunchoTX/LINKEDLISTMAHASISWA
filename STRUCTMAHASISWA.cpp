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

int main() {
    Mahasiswa* head = buatNode("202400001", "Contoh", 100.0f);
    cout << head->nim << " - " << head->nama << "\n";
    delete head;
    return 0;
}