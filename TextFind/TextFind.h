#ifndef TEXTFIND_H
#define TEXTFIND_H

#define SIZETEXT 250*256
#define LINE 256
#define WORD 30

char s[LINE];
char text[SIZETEXT];
char w[WORD];

int get_line(int i);
int get_word(int i);
int substring( char * str1, char * str2);
int similar (char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);

#endif