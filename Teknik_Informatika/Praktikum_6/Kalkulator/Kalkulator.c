#include "Kalkulator.h"
#include "boolean.h"
#include <stdio.h>

void BuatKalkulator (Kalkulator *K){
    K->NEffOperan=0;
    K->NEffOperator=0;
    K->Ans=0;
}
/* Membuat kalkulator kosong
 I.S. K sembarang
 F.S. Terbentuk kalkulator K kosong */

boolean CekError (Kalkulator K){
	if(K.NEffOperan == 0 & K.NEffOperator == 0) return false;
    if(K.NEffOperan!=K.NEffOperator+1) return true;
    boolean e=false;
    for(int i=1; i<K.NEffOperan; ++i){
        if(K.Operan[i]==0 && K.Operator[i-1]=='/'){
            e=true;
            break;
        }
    }
    return e;
}
/* Mengembalikan nilai true jika kalkulator akan mengeluarkan error dan false jika tidak ada error */

void ResetKalkulator (Kalkulator *K){
    K->NEffOperan=0;
    K->NEffOperator=0;
    K->Ans=0;
}
/* Menghapus keseluruhan data pada kalkulator K */

void InputOperasi (Kalkulator *K, int oprn[], int n_oprn, char oprtor[], int n_oprtor){
    ResetKalkulator(K);
    for(int i=0; i<n_oprn; ++i){
        K->Operan[i]=oprn[i];
    }
    for(int i=0; i<n_oprtor; ++i){
        K->Operator[i]=oprtor[i];
    }
    K->NEffOperan=n_oprn;
    K->NEffOperator=n_oprtor;
}
/* Menerima sekumpulan array operan dan operator sekaligus beserta panjangnya,
   lalu menyimpannya ke dalam kalkulator K
   Pastikan untuk mengosongkan kalkulator K dulu sebelum memasukkan input baru */

void TambahOperator (Kalkulator *K, char oprtor){
    if(K->NEffOperator<MAX_OPERATOR){
        K->Operator[K->NEffOperator]=oprtor;
        K->NEffOperator++;
    }
}
/* Menambahkan operator di akhir list */

void HapusOperator (Kalkulator *K){
    if(K->NEffOperator > 0) K->NEffOperator--;
}
/* Menghapus operator di akhir list */

void UbahOperator (Kalkulator *K, int idx, char oprtor){
    if(0<=idx && idx<=K->NEffOperator-1){
        K->Operator[idx]=oprtor;
    }
}
/* Mengubah operator pada posisi idx */

void TambahOperan (Kalkulator *K, int oprn){
    if(K->NEffOperan<MAX_OPERAND){
        K->Operan[K->NEffOperan]=oprn;
        K->NEffOperan++;
    }
}
/* Menambahkan operan di akhir list */

void HapusOperan (Kalkulator *K){
    if(K->NEffOperan > 0) K->NEffOperan--;
}
/* Menghapus operan di akhir list */

void UbahOperan (Kalkulator *K, int idx, int oprn){
    if(0<=idx && idx<=K->NEffOperan-1){
        K->Operan[idx]=oprn;
    }
}
/* Mengubah operan pada posisi idx */

boolean JalankanKalkulasi (Kalkulator *K){
    if(CekError(*K) || K->NEffOperan == 0) return false;

    int ans=K->Operan[0];
    for(int i=1; i<K->NEffOperan; ++i){
        if(K->Operator[i-1]=='+'){
            ans+=K->Operan[i];
        }else if(K->Operator[i-1]=='-'){
            ans-=K->Operan[i];
        }else if(K->Operator[i-1]=='/'){
            ans/=K->Operan[i];
        }else if(K->Operator[i-1]=='*'){
            ans*=K->Operan[i];
        }
    }
    K->Ans=ans;
    return true;
}
/* Jika kalkulasi valid dan berhasil:
   - Hasil kalkulasi disimpan ke Ans dan fungsi akan mengembalikan true.
   Jika kalkulasi tidak valid dan gagal:
   - Hasil kalkulasi tidak disimpan ke Ans dan fungsi akan mengembalikan false
   Note: Abaikan presedensi operator, cukup ikuti urutan pada list */

void CetakHasil (Kalkulator K){
    if(K.NEffOperan==0){
        printf("KALKULATOR MASIH KOSONG\n");
        return;
    }
    printf("%d", K.Operan[0]);
    for(int i=0; i<K.NEffOperator; ++i){
	    printf("%c", K.Operator[i]);
	    if(i+1<K.NEffOperan) printf("%d", K.Operan[i+1]);
    }
    printf("\nHasil Kalkulasi: ");
    if(JalankanKalkulasi(&K)){
        printf("%d\n", K.Ans);
    }else{
        printf("ERROR\n");
    }
}
/* Mencetak operan dan operasi yang terlibat serta menampilkan hasil kalkulasi
Contoh 1:
4+2*5-7
Hasil Kalkulasi: 7

Contoh 2:
4+2*5-
Hasil Kalkulasi: ERROR

Contoh 3 (Kalkulator Kosong):
KALKULATOR MASIH KOSONG
Jangan lupa akhiri dengan newline ('\n') */
