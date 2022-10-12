// (C)ode by Rizky Azmi Swandy

#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define nmax 5 // banyak data yang dapat ditampung
using namespace std;

int n = 0; // variable n sebagai banyak data yang telah tersimpan
struct data
{ // struktur data mahasiswa yg akan diinput

    int nim;
    char nama[20];
    char kom;
};
struct data maba[nmax]; // deklarasi variabel bertipe struct
void tambah_data();     // prototype fungsi void
void hapus_data();
void tampilkan_data();
void sunting_data();
main()
{
    int pil;
    menu:
    cout << "+---------------------------+" << endl;
    cout << "|           MENU            |" << endl;
    cout << "| 1. Tambah data            |" << endl; 
    cout << "| 2. Hapus data             |" << endl;
    cout << "| 3. Sunting data           |" << endl;
    cout << "| 4. Tampilkan data         |" << endl;
    cout << "| 5. Keluar                 |" << endl;
    cout << "+---------------------------+" << endl;
    cout << "| Pilih menu (1/2/3/4/5) ? : ";
    cin >> pil;
    cout << "+---------------------------+" << endl;
    if (pil == 1)
        tambah_data();
    else if (pil == 2)
        hapus_data();
    else if (pil == 3)
        sunting_data();
    else if (pil == 4)
        tampilkan_data();
    else if (pil == 5)
        exit(1); // atau bisa pakai return(0)
    else
    {
        cout << "pilihan tak tersedia...!!!\n";
    }
    goto menu;
    getch();
}

void tambah_data()
{
    system("CLS");
    cout << "+-------------------------------------------+" << endl;
    cout << "| Insert Your Data Here !    (1 s.d. 5)     |" << endl;
    cout << "+-------------------------------------------+" << endl;
    if (n < nmax)
    {
        cout << "+---------+" << endl;
        cout << "| Nama : ";
        cin >> maba[n].nama;
        cout << "| NIM  : ";
        cin >> maba[n].nim;
        cout << "| KOM  : ";
        cin >> maba[n].kom;
        cout << "+-------------------------+" << endl;
        n++;
    }
    else
        cout << "\n data telah melebihi...!!!\n maksimal data = " << nmax;
}

void hapus_data()
{
    system("CLS");
    int x;
    cout << "+-------------------------------------------+" << endl;
    cout << "| Delete Your Data Here !    (1 s.d. 5)     |" << endl;
    cout << "+-------------------------------------------+" << endl;
    cout << "| Pilih data yang akan dihapus (1 s.d. 5): ";
    cin >> x;
    cout << "+-------------------------------------------+" << endl;
    
    if (x < n && x > 0)
    {
        for (int i = x; i < n; i++)
        {
            strcpy(maba[i - 1].nama, maba[x].nama);
            maba[i - 1].nim = maba[x].nim;
            maba[i - 1].kom = maba[x].kom;
            n--;
        }
    }
    else if (x == n)
        n--;
    else
        cout << "\n data yang ingin dihapus tidak ada...!!!\n";
}

void sunting_data(){
    system("CLS");
    int pos, temp_nim;
    char temp_nama[20];
    char temp_kom;

    if (n == 0)
        cout << "Tidak ada data yang disimpan...!!!\n";
    else{
    cout << "+-------------------------------------------+" << endl;
    cout << "| Edit Your Data Here !    (1 s.d. 5)       |" << endl;
    cout << "+-------------------------------------------+" << endl;
    cout << "| Posisi yang diubah    : "; cin >> pos;
    cout << "| Masukkan Update Nama  : "; cin >> temp_nama;
    cout << "| Masukkan Update NIM   : "; cin >> temp_nim;
    cout << "| Masukkan Update KOM   : "; cin >> temp_kom;
    cout << "+-------------------------------------------+" << endl;
        
        strcpy(maba[pos-1].nama, temp_nama);
        maba[pos].nim = temp_nim;
        maba[pos].kom = temp_kom;

    }

}

void tampilkan_data()
{
    system("CLS");
    if (n == 0)
        cout << "Tidak ada data yang disimpan...!!!\n";
    else
    {
        cout << "+-------------------------------------------+" << endl;
        cout << "|       Your Data Will Showed up here       |" << endl;
        cout << "+-------------------------------------------+" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "+---------------+" << endl;
            cout << "|   Siswa " << i+1 << "       |" << endl;
            cout << "+---------------+" << endl;
            cout << "| Nama : " << maba[i].nama<< endl;
            cout << "| NIM  : " << maba[i].nim << endl;
            cout << "| KOM  : " << maba[i].kom << endl; 
            cout << "+---------------+" << endl;
            cout << endl;
        }
    }
}