#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
        first(L)=NULL;
        last(L)=NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //-------------your code here-------------
        P=(address)malloc(sizeof(elmlist));
        info(P)=x;
        next(P)=NULL;
        prev(P)=NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
        delete(P);
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
        if(first(L)!=NULL){
            next(P)=first(L);
            prev(P)=prev(first(L));
            prev(first(L))=P;
            first(L)=P;
            next(last(L))=first(L);
        }
        else{
            first(L)=P;
            last(L)=P;
            next(P)=first(L);
            prev(P)=last(L);
        }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
        if(first(L)!=NULL){
            prev(P)=last(L);
            next(P)=first(L);
            next(last(L))=P;
            last(L)=P;
            prev(first(L))=last(L);
        }
        else{
            insertFirst(L,P);
        }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
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
            return R;
        }
    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
        address Q=first(L);
        address R=NULL;
        while(next(Q)!=first(L)){
            if(info(Q).name==x.name){
               R=Q;
            }
            Q=next(Q);
        }
        if(R!=NULL){
            return R;
        }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        if(first(L)!=NULL){
            if(first(L)!=last(L)){
                P=first(L);
                prev(next(P))=last(L);
                next(last(L))=next(P);
                first(L)=next(P);
                prev(P)=NULL;
                next(P)=NULL;
            }
            else{
                P=first(L);
                first(L)=NULL;
                last(L)=NULL;
            }
        }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        if(first(L)!=NULL){
            if(first(L)!=last(L)){
                P=last(L);
                prev(first(L))=prev(P);
                next(prev(P))=first(L);
                last(L)=prev(P);
                next(P)=NULL;
                prev(P)=NULL;
            }
            else{
                P=first(L);
                first(L)=NULL;
                last(L)=NULL;
            }
        }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
        if((Prec!=NULL)&&(P!=NULL)){
            if(Prec!=last(L)){
                next(P)=next(Prec);
                prev(P)=Prec;
                prev(next(Prec))=P;
                next(Prec)=P;
            }
            else{
                next(P)=first(L);
                prev(first(L))=P;
                prev(P)=Prec;
                next(Prec)=P;
                last(L)=P;
            }
        }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        if(Prec!=NULL){
            if(Prec!=last(L)){
               P=next(Prec);
               prev(next(P))=Prec;
               next(Prec)=next(P);
               next(P)=NULL;
               prev(P)=NULL;
            }
            else{
               P=first(L);
               deleteFirst(L,P);
            }
        }
    //----------------------------------------
}

