//
// Created by Yinuo Chen on 2023/3/1.
//


#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct{
    char word[30];
    int count;
}Dictionary;

int main(){

    char input[100] = "";
    int number = 30;
    int countWord = 0;
    int found = 0;
    int i = 0;

    Dictionary dictionary[200];


    while (scanf("%s", input) != EOF){
        if(input[0] >= 'A' && input[0] <= 'Z'){
            input[0] += 32;
        }
        if(!(input[strlen(input) - 1] >= 'a' && input[strlen(input) - 1] <= 'z')){
            input[strlen(input) - 1] = '\0';
        }



        for (i = 0; i < countWord; i++) {
            if(strcmp(input, (dictionary+i)->word) == 0){
                (dictionary+i)->count++;
                found = 1;
            }
        }
        if(found == 0){
            countWord++;
            strcpy((dictionary+i)->word, input);
            (dictionary+i)->count = 1;

        }
        found = 0;


    }

    char temp_str[30];
    int temp_int;
    for (int j = 0; j < countWord; j++) {
        for (int k = 0; k < countWord; k++) {
            if(strcmp((dictionary+j)->word,(dictionary+k)->word) < 0){
                strcpy(temp_str, (dictionary + j)->word);
                strcpy((dictionary+j)->word, (dictionary+k)->word);
                strcpy((dictionary+k)->word, temp_str);
                temp_int = (dictionary+j)->count;
                (dictionary+j)->count = (dictionary+k)->count;
                (dictionary+k)->count = temp_int;
            }
        }
    }
    for (int j = 0; j < countWord; j++) {
//        fprintf(fp, "%s => %d\n", (dictionary+j)->word, (dictionary+j)->count);
        printf("%s => %d\n", (dictionary+j)->word, (dictionary+j)->count);
    }

    return 0;
}