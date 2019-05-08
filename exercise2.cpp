/*
Author   : Shalvina Zahwa Aulia
NPM      : 140810180052
Deskripsi: Program queue circular menggunakan linked list
Tahun    : 2019
*/
#include<iostream>
#include<windows.h>
using namespace std;

struct elemenQueue{
    char info;
    elemenQueue* next;
};
typedef elemenQueue* pointer;

struct Queue {
    pointer head;
    pointer tail;
};
void createQueue(Queue& q){
    q.head = NULL;
    q.tail = NULL;
}
void createElmt(pointer& pBaru){
    pBaru = new elemenQueue;
    cout << "Masukkan huruf : "; cin >> pBaru->info;
    pBaru->next = NULL;
}
void insertQueue(Queue& q, pointer pBaru ){
    if (q.head == NULL && q.tail == NULL){
        q.head = pBaru;
        q.tail = pBaru;
    }
    else {
        q.tail->next = pBaru;
        q.tail = pBaru;
    }
}
void deleteQueue(Queue& q, pointer pHapus){
    if(q.head == NULL && q.tail == NULL){
        pHapus = NULL;
        cout << "\nDATA ANTRIAN KOSONG\n";
    }
    else if (q.head->next == NULL){
        pHapus = q.head;
        q.head = NULL;
        q.tail = NULL;
    }
    else {
        pHapus = q.head;
        q.head = q.head->next;
        pHapus->next = NULL;
    }
}
void traversal (Queue q){
    pointer pBantu;
    pBantu = q.head;
    while(pBantu!=NULL){
        cout << pBantu->info << " ";
        pBantu =  pBantu->next;
    }
}
main(){
    Queue q;
    pointer p;
    int n, menu;
    char pilih;
    createQueue(q);
    do {
    cout << "1. Insert queue\n";
    cout << "2. Delete queue\n";
    cout << "3. Display\n";
    cout << "4. Keluar\n";
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
        cout << "Masukkan banyak data : "; cin >> n;
        for(int i=0; i<n; i++){
            createElmt(p);
            insertQueue(q,p);
        }
        break;
        system("cls");
    case 2 :
        deleteQueue(q,p);
        break;
    case 3 :
        traversal(q);
        break;
        system("cls");
    case 4 :
        exit(0);
        break;
            }
        cout << "\nApakah anda ingin mengulangi program (y/n)? "; cin >> pilih;
        system("cls");
        }
    }while(pilih == 'y' || pilih == 'Y');
}
