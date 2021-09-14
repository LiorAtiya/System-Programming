#include <string.h>
#include <stdio.h>
#include "TextFind.h"


int get_line(int i){
    memset(s, '\0', sizeof s);
    int count = 0;
    while(text[i] != '\r' && text[i] != '\n' && text[i] != '\0' && text[i] != '\t'){
        s[count] = text[i];
        count++;
        i++;
    }
    return i;
}

int get_word(int i){
    memset(w, '\0', sizeof s);
    int count = 0;
    while(text[i] != ' ' && text[i] != '\n' && text[i] != '\r' && text[i] != '\0' && text[i] != '\t'){
        w[count] = text[i];
        count++;
        i++;
    }
    return i;
}

int substring(char *str1, char *str2) {
    if (strstr(str1, str2) != NULL) {
        return 1;
    }
    return 0;
}

int similar(char *s, char *t, int n){
    int len_s = strlen(s);
    int j = 0;
    
    char copy[len_s];
    strcpy(copy,s);

    for(int i = 0 ; i < len_s && n > 0 ; i++){
        if(s[i] != t[j]){
            n--;
            memmove(&copy[j], &copy[j + 1], strlen(copy) - j);
        }else{
            j++;
        }
    }

    if(strcmp(copy,t) == 0) return 1;
    return 0;
}

void print_lines(char * str){
    int i = 0;
    // printf("%d", 12);
    while(i < strlen(text) && text[i] != '\0'){
        i = get_line(i)+1;
        if(substring(s, str)){
            printf("%s\n", s);
        }
    }
}

void print_similar_words(char * str){
    int i = 0;
    while(i < strlen(text) && text[i] != '\0'){
        i = get_word(i)+1;
        if(similar(w,str,1)){
            printf("%s\n", w);
        }
    }
}
