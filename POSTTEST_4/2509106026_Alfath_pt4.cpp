#include <iostream>
#include <string>
using namespace std;

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
    Tiket *next;
};
Tiket *front = NULL;
Tiket *rear = NULL;
Tiket *top = NULL;

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
    Tiket *baru = new Tiket;

    cout<<"Nama Penumpang : ";
    cin>>baru->namaPenumpang;

    cout<<"Nama Kereta : ";
    cin>>baru->namaKereta;

    cout<<"Kota Asal : ";
    cin>>baru->asal;

    cout<<"Kota Tujuan : ";
    cin>>baru->tujuan;

    baru->next=NULL;

    if(front==NULL){
        front=rear=baru;
    }else{
        rear->next=baru;
        rear=baru;
    }

    cout<<"Penumpang berhasil masuk antrian"<<endl;
}

void pushRiwayat(string nama,string kereta,string asal,string tujuan){
    Tiket *baru = new Tiket;
    baru->namaPenumpang = nama;
    baru->namaKereta = kereta;
    baru->asal = asal;
    baru->tujuan = tujuan;

    baru->next = top;
    top = baru;
}

void dequeue(){
    if(front==NULL){
        cout<<"Tidak ada antrian"<<endl;
        return;
    }

    Tiket *hapus = front;

    cout<<"=== MEMPROSES TIKET ==="<<endl;
    cout<<"Penumpang : "<<hapus->namaPenumpang<<endl;
    cout<<"Kereta    : "<<hapus->namaKereta<<endl;
    cout<<"Rute      : "<<hapus->asal<<" - "<<hapus->tujuan<<endl;

    pushRiwayat(hapus->namaPenumpang,hapus->namaKereta,hapus->asal,hapus->tujuan);

    front=front->next;

    if(front==NULL)
        rear=NULL;

    delete hapus;

    cout<<"Tiket berhasil diproses"<<endl;
}
void lihatAntrian(){

    if(front==NULL){
        cout<<"Antrian kosong"<<endl;
        return;
    }

    Tiket *temp=front;

    cout<<"=== DAFTAR ANTRIAN ==="<<endl;

    while(temp!=NULL){

        cout<<"Penumpang : "<<temp->namaPenumpang<<endl;
        cout<<"Kereta    : "<<temp->namaKereta<<endl;
        cout<<"Rute      : "<<temp->asal<<" - "<<temp->tujuan<<endl;
        cout<<"--------------------------"<<endl;

        temp=temp->next;
    }
}
void lihatRiwayat(){
    if(top==NULL){
        cout<<"Belum ada transaksi"<<endl;
        return;
    }

    Tiket *temp=top;

    cout<<"=== RIWAYAT TRANSAKSI ==="<<endl;

    while(temp!=NULL){

        cout<<"Penumpang : "<<temp->namaPenumpang<<endl;
        cout<<"Kereta    : "<<temp->namaKereta<<endl;
        cout<<"Rute      : "<<temp->asal<<" - "<<temp->tujuan<<endl;
        cout<<"----------------------------"<<endl;

        temp=temp->next;
    }
}

void popRiwayat(){
    if(top==NULL){
        cout<<"Riwayat kosong"<<endl;
        return;
    }

    Tiket *hapus=top;
    top=top->next;

    delete hapus;

    cout<<"Transaksi terakhir dibatalkan"<<endl;
}

void peekData(){
    cout<<"=== CEK DATA ==="<<endl;

    if(front!=NULL)
        cout<<"Antrian terdepan : "<<front->namaPenumpang<<endl;
    else
        cout<<"Antrian kosong"<<endl;

    if(top!=NULL)
        cout<<"Transaksi terakhir : "<<top->namaPenumpang<<endl;
    else
        cout<<"Riwayat kosong"<<endl;
}

void pause(){
    cout<<"\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

int main(){
    Kereta dataKereta[5]={
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
        cout<<"2. Pesan Tiket"<<endl;
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