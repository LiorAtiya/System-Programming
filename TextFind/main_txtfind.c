#include <stdio.h>
#include "TextFind.h"

int main(){
    //Scan word
    char word[30];
    scanf(" %s", word);
    char option;
    //Scan option
    scanf(" %c", &option);

    //Scan text
    int i=0;
    while(scanf("%c", &text[i]) != EOF){
        i++;
    }

    if(option == 'a'){
        print_lines(word);
    }else if(option == 'b'){
        print_similar_words(word);
    }else{
        printf("%d",0);
    }
    return 0;
}
