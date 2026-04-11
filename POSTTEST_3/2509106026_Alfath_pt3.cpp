#include <iostream>
#include <string>
using namespace std;

#define MAX 80

struct Kereta{
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Tiket{
    string namaPenumpang;
    string namaKereta;
    string asal;
    string tujuan;
};

Tiket antrian[MAX];
Tiket riwayat[MAX];

int front=-1;
int rear=-1;
int top=-1;

void lihatKereta(Kereta *arr,int n){

    cout<<"=== DATA KERETA ==="<<endl;

    for(int i=0;i<n;i++){
        cout<<"Nomor  : "<<(arr+i)->nomor<<endl;
        cout<<"Nama   : "<<(arr+i)->nama<<endl;
        cout<<"Rute   : "<<(arr+i)->asal<<" - "<<(arr+i)->tujuan<<endl;
        cout<<"Harga  : "<<(arr+i)->harga<<endl;
        cout<<"-----------------------"<<endl;
    }
}

void enqueue(){

    if(rear==MAX-1){
        cout<<"Antrian penuh!"<<endl;
        return;
    }

    Tiket t;

    cout<<"Nama Penumpang : ";
    cin>>t.namaPenumpang;

    cout<<"Nama Kereta : ";
    cin>>t.namaKereta;

    cout<<"Kota Asal : ";
    cin>>t.asal;

    cout<<"Kota Tujuan : ";
    cin>>t.tujuan;

    if(front==-1)
        front=0;

    rear++;
    antrian[rear]=t;

    cout<<"Penumpang berhasil masuk antrian"<<endl;
}

void pushRiwayat(Tiket t){

    if(top==MAX-1){
        cout<<"Stack riwayat penuh"<<endl;
        return;
    }

    top++;
    riwayat[top]=t;
}

void dequeue(){

    if(front==-1 || front>rear){
        cout<<"Tidak ada antrian"<<endl;
        return;
    }

    Tiket t=antrian[front];

    cout<<"=== MEMPROSES TIKET ==="<<endl;
    cout<<"Penumpang : "<<t.namaPenumpang<<endl;
    cout<<"Kereta    : "<<t.namaKereta<<endl;
    cout<<"Rute      : "<<t.asal<<" - "<<t.tujuan<<endl;

    pushRiwayat(t);

    for(int i=front;i<rear;i++){
        *(antrian+i)=*(antrian+i+1);
    }

    rear--;

    if(rear<front){
        front=-1;
        rear=-1;
    }

    cout<<"Tiket berhasil diproses"<<endl;
}

void lihatAntrian(){

    if(front==-1){
        cout<<"Antrian kosong"<<endl;
        return;
    }

    cout<<"=== DAFTAR ANTRIAN ==="<<endl;

    for(int i=front;i<=rear;i++){
        cout<<"Penumpang : "<<(antrian+i)->namaPenumpang<<endl;
        cout<<"Kereta    : "<<(antrian+i)->namaKereta<<endl;
        cout<<"Rute      : "<<(antrian+i)->asal<<" - "<<(antrian+i)->tujuan<<endl;
        cout<<"--------------------------"<<endl;
    }
}

void lihatRiwayat(){

    if(top==-1){
        cout<<"Belum ada transaksi"<<endl;
        return;
    }

    cout<<"=== RIWAYAT TRANSAKSI ==="<<endl;

    for(int i=top;i>=0;i--){
        cout<<"Penumpang : "<<(riwayat+i)->namaPenumpang<<endl;
        cout<<"Kereta    : "<<(riwayat+i)->namaKereta<<endl;
        cout<<"Rute      : "<<(riwayat+i)->asal<<" - "<<(riwayat+i)->tujuan<<endl;
        cout<<"----------------------------"<<endl;
    }
}

void popRiwayat(){

    if(top==-1){
        cout<<"Riwayat kosong"<<endl;
        return;
    }

    cout<<"Transaksi terakhir dibatalkan"<<endl;
    top--;
}

void peekData(){

    cout<<"=== CEK DATA ==="<<endl;

    if(front!=-1)
        cout<<"Antrian terdepan : "<<antrian[front].namaPenumpang<<endl;
    else
        cout<<"Antrian kosong"<<endl;

    if(top!=-1)
        cout<<"Transaksi terakhir : "<<riwayat[top].namaPenumpang<<endl;
    else
        cout<<"Riwayat kosong"<<endl;
}
void pause(){
    cout<<"\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}
int main(){

    Kereta dataKereta[100]={
        {11,"Nozomi","Jakarta","Bandung",120000},
        {12,"Hikari","Surabaya","Yogyakarta",150000},
        {13,"Kodama","Bandung","Jakarta",100000},
        {14,"Hayabusa","Semarang","Surabaya",130000},
        {15,"Sakura","Yogyakarta","Malang",140000}
    };

    int jumlah=5;
    int pilih;

    do{

        cout<<endl;
        cout<<"===== SISTEM KERETA API NASIONAL ====="<<endl;
        cout<<"1. Lihat Data Kereta"<<endl;
        cout<<"2. Pesan Tiket (Masuk Antrian)"<<endl;
        cout<<"3. Proses Pembelian Tiket"<<endl;
        cout<<"4. Lihat Antrian Penumpang"<<endl;
        cout<<"5. Lihat Riwayat Transaksi"<<endl;
        cout<<"6. Hapus Transaksi Terakhir"<<endl;
        cout<<"7. Cek Antrian & Riwayat"<<endl;
        cout<<"0. Keluar"<<endl;
        cout<<"===================================="<<endl;

        cout<<"Pilih menu : ";
        cin>>pilih;

     if(pilih==1){
        lihatKereta(dataKereta,jumlah);
        pause();
    }

    else if(pilih==2){
        enqueue();
        pause();
    }

    else if(pilih==3){
        dequeue();
        pause();
    }

    else if(pilih==4){
        lihatAntrian();
        pause();
    }

    else if(pilih==5){
        lihatRiwayat();
        pause();
    }

    else if(pilih==6){
        popRiwayat();
        pause();
    }

    else if(pilih==7){
        peekData();
        pause();
    }

     else if(pilih==0){
          cout<<"Program selesai"<<endl;
      }

    else{
          cout<<"Menu tidak tersedia"<<endl;
   }

    }while(pilih!=0);

}