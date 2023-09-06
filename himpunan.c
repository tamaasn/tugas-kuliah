#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define array_max 5

int main(){
    int array1[array_max];
    int array2[array_max];
    srand(time(NULL));

    // Menambahkan angka random pada array 1 (angka < 15)
    for(int i=0;i<array_max;i++){
        array1[i] = rand()%15;
    }

    // Menambahkan angka random pada array 2 (angka < 15)

    for(int i=0;i<array_max;i++){
        array2[i] = rand()%15;
    }
    
    // Mencetak output array 1 dan array 2
    printf("Array 1 : {");
    for(int i=0;i<array_max;i++){
        printf("%d," , array1[i]);
    }
    printf("}");

    printf("\nArray 2 : {");
    for(int i=0;i<array_max;i++){
        printf("%d," , array2[i]);
    }
    printf("}");
    
    // Deklarasi array untuk union
    int array_union[array_max*2];

    // Menghitung array union
    for(int i=0;i<array_max*2;i++){
        if (i > 4){
            array_union[i] = array2[i-5];
        }
        else{
            array_union[i] = array1[i];
        }
    }

    printf("\nArray himpunan : {");
    for(int i=0;i<array_max*2;i++){
        printf("%d," , array_union[i]);
    }
    printf("}\n");

    int count=0;
    int array_irisan[20];
    int angka_ditemukan;
    for(int i=0;i<array_max;i++){
        for(int j=0;j<array_max;j++){
            if (array1[i] == array2[j] && array1[i] != angka_ditemukan){
                array_irisan[count] = array1[i];
                count++;
                angka_ditemukan=array2[j];
            }
        }
    }
    printf("\nArray irisan : {");
    for(int i=0;i<count;i++){
        printf("%d,",array_irisan[i]);
    }
    printf("}\n");
    
    count=0;
    int array_complement[20];
    for(int i=0;i<array_max;i++){
        bool found=false;
        for(int j=0;j<array_max;j++){
            printf("%d = %d\n" , array1[i] , array2[j]);
            if (array1[i] == array2[j]){
                found=true;
            }
        }
        if(!found){
            array_complement[count] = array1[i];
            count++;
        }
    }

    printf("Complement dari himpunan array1 :{");
    for(int i=0;i<count;i++){
        printf("%d," , array_complement[i]);
    }
    printf("}\n");
}

