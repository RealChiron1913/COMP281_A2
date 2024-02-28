#include <stdio.h>


void encode(){
    char input, previous;
    int count = 1;//initialize the counter
    while (scanf("%c", &input) != EOF) {
        if (previous == input){
            count ++;//count the number of the same characters
        } else {
            if (count >= 3){
                printf("%d*", count);
            }//if the number of the same characters is more than 3, output the number of the same characters and a '*'
            count = 1;//reset the counter
        }
        previous = input;//update the previous character
        if (count <= 3){
            printf("%c", input);//output the character
        }
    }
    if (count >= 3){
        printf("%d*", count);//deal with the last character
    }
}

void decode(){
    char input, previous;
    int count = 1;
    int num = 0;
    int flag = 1, flag2 = 0;
    while (scanf("%c", &input) != EOF) {
        if (flag == 1){//deal with the first character
            printf("%c", input);
            flag = 0;
            previous = input;//update the previous character
        }
        else if (previous == input && count < 3){//output the character, update the counter and the previous character
            printf("%c", input);
            count ++;
            previous = input;
        }
        else if (previous != input && count < 3){//output the character, reset the counter and update the previous character
            printf("%c", input);
            count = 1;
            previous = input;
        }
        else if (count == 3){
                char repeat;//store the character to be repeated
                if (flag2 == 0){//previous character is the repeated character
                    repeat = previous;
                    flag2 = 1;
                }
                if (input != '*'){//count the number of the repeated characters
                    num = num * 10 + (input - '0');
                }
                else if (num >= 3){//output the repeated characters
                    for (int i = 3; i < num; i++) {
                        printf("%c", repeat);
                    }
                    //reset the counter,the previous character and the flag2
                    count = 1;
                    num = 0;
                    flag2 = 0;
                }
        }
    }
}
int main() {
    char choice;
    scanf("%c", &choice);//input the choice
    if (choice == 'C'){
        getchar();//clear the buffer
        encode();
    }
    else if (choice == 'E'){
        getchar();
        decode();
    }
//    decode();
    return 0;
}
