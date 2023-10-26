#ifndef RECORD_H
#define RECORD_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void setHighScore(int records[10]){

    int i;
    FILE *recordtxt;
    if((recordtxt = fopen("record.txt","r")) == NULL){
        printf("corrupted or deleted file!\n");
    }

    for(i = 0; i <10; i++){
        fscanf(recordtxt,"%d\n",&records[i]);
    }
    fclose(recordtxt);
}
int getNewHighScore(int score, int records[10]){
    int i, j, aux;
    FILE* recordtxt;
    int newHigh=0;

    for(i=0;i < 10;i++){
        if(records[i] < score){
            for(j=9;j > i;j--){
                aux = records[j];
                records[j]= records[j-1];
                records[j-1]= aux;
            }
            records[i] = score;
            newHigh = i+1;
            break;
        }
    }


    if((recordtxt = fopen("record.txt","w")) == NULL){
    printf("corrupted or deleted file!\n");
    }

    for(i=0;i<10;i++ ){
       fprintf(recordtxt, "%d\n",records[i]);
    }  

    fclose(recordtxt);
    return newHigh;
}
#endif