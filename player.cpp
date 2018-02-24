#include "player.h"
#include <ctime>

int randomInt(int  max_int) {
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L) {
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */

    address Q = first(L);
    do {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    } while(Q!=first(L));
    cout<<"==============================================="<<endl;
}


void playMusic(address P) {
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L) {
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //-------------your code here-------------
        /*address Q=NULL;
        int x=0;
        for(int i=1; i<=10; i++){
            x=randomInt(5);
            Q=first(L);
            for(int j=1; i<=x; i++){
                Q=next(Q);
            }
            deleteAfter(L,Q,P);
            insertFirst(L,P);
        }*/
    //----------------------------------------
}

void sortListByID(List &L) {
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan ID
    * FS : isi (elemen) dari list L terurut
    */
    //-------------your code here-------------

    //----------------------------------------

}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //-------------your code here-------------
        int cnt=0;
        address P=first(L);
        while(cnt<=n){
            while(next(P)!=first(L)){
                playMusic(P);
                P=next(P);
            }
            cnt++;
        }
    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x) {
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //-------------your code here-------------
        address Q=first(L);
        address R=NULL;
        while(next(Q)!=first(L)){
            if(info(Q).ID==x.ID){
                R=Q;
            }
            Q=next(Q);
        }
        if(R!=NULL){
            Q=first(L);
            while(Q!=R){
                Q=next(Q);
            }
            deleteAfter(L,Q,R);
        }
    //----------------------------------------

}
