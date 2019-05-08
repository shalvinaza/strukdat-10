/*
Author   : Shalvina Zahwa Aulia
NPM      : 140810180052
Deskripsi: Program queue circular menggunakan array
Tahun    : 2019
*/
#include<iostream>
#include<windows.h>
using namespace std;

const int maxElmt = 5;

struct Queue{
    char data[maxElmt];
    int head;
    int tail;
};
void createElmt (Queue& q){
    q.head = -1;
    q.tail = -1;
}
void insertElmt (Queue& q, char& elmt){
    int temp;
    if (q.head == -1){
        q.head = 0;
        q.tail = 0;
        q.data[q.tail] = elmt;
    }
    else {
        if (q.tail < maxElmt -1){
            q.tail+=1;
            q.data[q.tail] = elmt;
        }
        else {
            q.tail = 0;
        }
        if (q.tail == q.head){
            cout << "\nANTRIAN SUDAH PENUH!\n";
            q.tail = temp;
        }
        else {
            q.data[q.tail] = elmt;
        }
    }
}
void deleteQueue (Queue& q, char& eDel){
    if (q.head == -1){
        cout << "\nDATA ANTRIAN KOSONG\n";
    }
    else if (q.head == q.tail){
        eDel = q.data[q.head];
        q.data[q.head]= ' ';
        q.head = -1;
        q.tail = -1;
    }
    else {
        eDel = q.data[q.head];
        q.data[q.head] = ' ';
        if (q.head < maxElmt -1){
            q.head+=1;
        }
        else {
            q.head = 0;
        }
    }
}
void display (Queue q){
    if(q.head == -1){
        cout << "\nDATA ANTRIAN KOSONG\n";
    }
    else {
        int i = q.head;
        if(q.head>q.tail){
            while(i < maxElmt){
                cout << q.data[i] << " ";
                if(i!=q.tail){
                    cout << " ";
                }
                i++;
            }
            i=0;
            while(i<=q.tail){
                cout << q.data[i];
                if(i!=q.tail){
                    cout << " ";
                }
                i++;
            }
        }
        else {
            while (i<=q.tail){
                cout << q.data[i];
                if(i!=q.tail){
                    cout << " ";
                }
                i++;
            }
        }
        cout << endl;
    }
}
main (){
    Queue q;
    char e, pilih;
    int n, menu;

    createElmt(q);
    do {
    cout << "1. Insert queue\n";
    cout << "2. Delete queue\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
    cout << "Masukkan pilihan (1/2/3/4) : "; cin >> menu;
    system("cls");
    if (menu <1 || menu >4){
        cout << "\ANDA SALAH MEMASUKKAN ANGKA!\n";
        system("pause");
        exit(0);
    }
    else {
    switch(menu){
    case 1 :
        cout << "Masukkan jumlah data : "; cin >> n;
        for(int i=0; i<n;i++){
            cout << "Masukkan huruf : "; cin >> e;
            insertElmt(q,e);
            }
        system("cls");
        break;
    case 2 :
        deleteQueue(q,e);
        break;
    case 3 :
        display(q);
        break;
    case 4 :
        exit(0);
        break;
        }
    cout << "\nApakah Anda ingin mengulangi program(y/n)? "; cin >> pilih;
    system("cls");
    }
    } while (pilih == 'y' || pilih == 'Y');
}

