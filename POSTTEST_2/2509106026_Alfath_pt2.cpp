#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Kereta{
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

void swapKereta(Kereta *a, Kereta *b){
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n){

    cout<<"===== DATA JADWAL KERETA ====="<<endl;

    for(int i=0;i<n;i++){

        cout<<"Nomor Kereta : "<<(arr+i)->nomor<<endl;
        cout<<"Nama Kereta  : "<<(arr+i)->nama<<endl;
        cout<<"Asal         : "<<(arr+i)->asal<<endl;
        cout<<"Tujuan       : "<<(arr+i)->tujuan<<endl;
        cout<<"Harga Tiket  : "<<(arr+i)->harga<<endl;
        cout<<"-----------------------------"<<endl;
    }
}

void tambah(Kereta *arr, int &n){

    cout<<"Masukkan Nomor Kereta : ";
    cin>>(arr+n)->nomor;

    cout<<"Masukkan Nama Kereta : ";
    cin>>(arr+n)->nama;

    cout<<"Masukkan Kota Asal : ";
    cin>>(arr+n)->asal;

    cout<<"Masukkan Kota Tujuan : ";
    cin>>(arr+n)->tujuan;

    cout<<"Masukkan Harga Tiket : ";
    cin>>(arr+n)->harga;

    n++;
}

void linearSearch(Kereta *arr,int n,string asal,string tujuan){

    bool ditemukan=false;

    cout<<"Proses pencarian..."<<endl;

    for(int i=0;i<n;i++){

        cout<<"Iterasi ke "<<i+1<<endl;

        if((arr+i)->asal==asal && (arr+i)->tujuan==tujuan){

            cout<<"Data ditemukan"<<endl;
            cout<<"Nama Kereta : "<<(arr+i)->nama<<endl;
            cout<<"Harga : "<<(arr+i)->harga<<endl;

            ditemukan=true;
        }
    }

    if(!ditemukan)
    cout<<"Data tidak ditemukan"<<endl;
}
int jumpSearch(Kereta *arr,int n,int key){

    int step=sqrt(n);
    int prev=0;
    while((arr+(min(step,n)-1))->nomor < key){
        prev=step;
        step+=sqrt(n);

        if(prev>=n)
        return -1;
    }
    for(int i=prev;i<min(step,n);i++){

        if((arr+i)->nomor==key)
        return i;
    }
    return -1;
}
void merge(Kereta *arr,int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    Kereta L[50],R[50];

    for(int i=0;i<n1;i++)
    L[i]=arr[l+i];

    for(int j=0;j<n2;j++)
    R[j]=arr[m+1+j];
    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(L[i].nama <= R[j].nama){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }

        k++;
    }

    while(i<n1){
        arr[k]=L[i];
        i++; k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++; k++;
    }
}

void mergeSort(Kereta *arr,int l,int r){
    if(l<r){

        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void selectionSort(Kereta *arr,int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;

        for(int j=i+1;j<n;j++){

            if((arr+j)->harga < (arr+minIndex)->harga)
            minIndex=j;
        }
        swapKereta(arr+i,arr+minIndex);
    }
}
int main(){

    Kereta data[100]={
        {11,"Nozomi","Jakarta","Bandung",120000},
        {12,"Hikari","Surabaya","Yogyakarta",150000},
        {13,"Kodama","Bandung","Jakarta",100000},
        {14,"Hayabusa","Semarang","Surabaya",130000},
        {15,"Sakura","Yogyakarta","Malang",140000}
    };

    int n=5;
    int pilih;

    do{
        cout<<endl;
        cout<<"=== SISTEM INFORMASI KERETA NASIONAL ==="<<endl;
        cout<<"1. Tampil Jadwal Kereta"<<endl;
        cout<<"2. Tambah Data Kereta"<<endl;
        cout<<"3. Cari Rute (Linear Search)"<<endl;
        cout<<"4. Cari Nomor Kereta (Jump Search)"<<endl;
        cout<<"5. Urutkan Nama Kereta (Merge Sort)"<<endl;
        cout<<"6. Urutkan Harga Termurah (Selection Sort)"<<endl;
        cout<<"0. Keluar"<<endl;

        cout<<"Pilih Menu : ";
        cin>>pilih;

        if(pilih==1){

            tampil(data,n);
        }

        else if(pilih==2){

            tambah(data,n);
        }
        else if(pilih==3){
            string asal,tujuan;
            cout<<"Masukkan Kota Asal : ";
            cin>>asal;

            cout<<"Masukkan Kota Tujuan : ";
            cin>>tujuan;

            linearSearch(data,n,asal,tujuan);
        }
        else if(pilih==4){
            int nomor;
            cout<<"Masukkan Nomor Kereta : ";
            cin>>nomor;

            int index=jumpSearch(data,n,nomor);

            if(index!=-1){
                cout<<"Data ditemukan"<<endl;
                cout<<"Nama Kereta : "<<data[index].nama<<endl;
                cout<<"Asal : "<<data[index].asal<<endl;
                cout<<"Tujuan : "<<data[index].tujuan<<endl;
                cout<<"Harga : "<<data[index].harga<<endl;
            }
            else
            cout<<"Data tidak ditemukan"<<endl;
        }
        else if(pilih==5){

            mergeSort(data,0,n-1);
            cout<<"Data berhasil diurutkan berdasarkan nama kereta"<<endl;
        }
        else if(pilih==6){
            selectionSort(data,n);
            cout<<"Data berhasil diurutkan berdasarkan harga termurah"<<endl;
        }
    }while(pilih!=0);
}