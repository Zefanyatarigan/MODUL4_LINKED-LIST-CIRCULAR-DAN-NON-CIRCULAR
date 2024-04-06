#include <iostream>
#include <iomanip>
using namespace std;
// Deklarasi Struct Node
struct Node
{
    string nama;
    string nim;
    Node *next;
};
Node *head = NULL;
// Buat Node Baru
Node *buatNode(string nama, string nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    return baru;
}
// Pengecekan List Kosong
bool isEmpty()
{
    return head == NULL;
}
// Tambah Depan
void tambahDepan(string nama, string nim)
{
    Node *baru = buatNode(nama, nim);
    baru->next = head;
    head = baru;
}
// Tambah Belakang
void tambahBelakang(string nama, string nim)
{
    Node *baru = buatNode(nama, nim);
    if (isEmpty())
    {
        head = baru;
    }
    else
    {
        Node *bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}
// Tambah Tengah
void tambahTengah(string nama, string nim, int posisi)
{
    if (posisi <= 1 || isEmpty())
    {
        tambahDepan(nama, nim);
    }
    else
    {
        Node *baru = buatNode(nama, nim);
        Node *bantu = head;
        for (int i = 1; i < posisi - 1 && bantu->next != NULL; i++)
        {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Ubah Depan
void ubahDepan(string nama, string nim)
{
    if (!isEmpty())
    {
        head->nama = nama;
        head->nim = nim;
    }
}
// Ubah Belakang
void ubahBelakang(string nama, string nim)
{
    if (!isEmpty())
    {
        Node *bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->nama = nama;
        bantu->nim = nim;
    }
}
// Ubah Tengah
void ubahTengah(string nama, string nim, int posisi)
{
    if (!isEmpty())
    {
        Node *bantu = head;
        for (int i = 1; i < posisi && bantu != NULL; i++)
        {
            bantu = bantu->next;
        }
        if (bantu != NULL)
        {
            bantu->nama = nama;
            bantu->nim = nim;
        }
    }
}
// Hapus Depan
void hapusDepan()
{
    if (!isEmpty())
    {
        Node *hapus = head;
        head = head->next;
        delete hapus;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    if (!isEmpty())
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *bantu = head;
            while (bantu->next->next != NULL)
            {
                bantu = bantu->next;
            }
            delete bantu->next;
            bantu->next = NULL;
        }
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    if (!isEmpty())
    {
        if (posisi <= 1)
        {
            hapusDepan();
        }
        else
        {
            Node *bantu = head;
            for (int i = 1; i < posisi - 1 && bantu->next != NULL; i++)
            {
                bantu = bantu->next;
            }
            if (bantu->next != NULL)
            {
                Node *hapus = bantu->next;
                bantu->next = bantu->next->next;
                delete hapus;
            }
        }
    }
}
// Hapus List
void hapusList()
{
    while (!isEmpty())
    {
        hapusDepan();
    }
}
// Tampilkan Data
void tampilkanData()
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
    }
    else
    {
        Node *bantu = head;
        cout << "====================================================" << endl;
        cout << "| DATA MAHASISWA |" << endl;
        cout << "====================================================" << endl;
        cout << "| " << setw(25) << left << "NAMA"
             << " | " << setw(20) << left
             << "NIM"
             << " |" << endl;
        cout << "======================================================" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(25) << left << bantu->nama << " | " << setw(20)
                 << left << bantu->nim << " |" << endl;
            bantu = bantu->next;
        }
        cout << "======================================================" << endl;
    }
}
// Menu Utama
void menu()
{
    system("cls");
    cout << "\033[1mMade by : Zefanya Brana Tertius Tarigan\033[0m" << endl;
    cout << "\033[1mNim : 2311102028\033[0m" << endl;
    cout << endl;
    cout << "==============================================="
         << endl;
    cout << "| PROGRAM SINGLE LINKED LIST NON-CIRCULAR |" << endl;
    cout << "==============================================="
         << endl;
    cout << "01. Tambah Depan" << endl;
    cout << "02. Tambah Belakang" << endl;
    cout << "03. Tambah Tengah" << endl;
    cout << "04. Ubah Depan" << endl;
    cout << "05. Ubah Belakang" << endl;
    cout << "06. Ubah Tengah" << endl;
    cout << "07. Hapus Depan" << endl;
    cout << "08. Hapus Belakang" << endl;
    cout << "09. Hapus Tengah" << endl;
    cout << "10. Hapus List" << endl;
    cout << "11. TAMPILKAN" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "0. KELUAR" << endl;
    cout << "==============================================="
         << endl;
}
int main()
{
    system("cls");
    int pilihan, posisi;
    string nama, nim;
    do
    {
        menu();
        cout << "Pilih Operasi : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            system("cls");
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            tambahDepan(nama, nim);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            tambahBelakang(nama, nim);
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            tambahTengah(nama, nim, posisi);
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahDepan(nama, nim);
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahBelakang(nama, nim);
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            ubahTengah(nama, nim, posisi);
            system("pause");
            break;
        case 7:
            system("cls");
            hapusDepan();
            system("pause");
            break;
        case 8:
            system("cls");
            hapusBelakang();
            system("pause");
            break;
        case 9:
            system("cls");
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            hapusTengah(posisi);
            system("pause");
            break;
        case 10:
            hapusList();
            break;
        case 11:
            system("cls");
            tampilkanData();
            system("pause");
            break;
        case 0:
            cout << "Terima kasih!" << endl;
            break;
            system("pause");
        default:
            cout << "Pilihan tidak valid!" << endl;
            system("pause");
        }
    } while (pilihan != 0);
    return 0;
}