#ifndef FREQUENCY_H
#define FREQUENCY_H
#define NUM_LETTERS ((int)26)

typedef enum {FALSE=0, TRUE=1} boolean;
char word[100];

typedef struct node {
    char letter;
    long unsigned int count;
    boolean endWord;
    struct node* children[NUM_LETTERS];
    char *prev;
} Node;

Node *newNode(Node *root, char c);
void insert(Node *root);
void printWords(Node *root);
void printWordsRevers(Node *root);
Node* buildTrie();

// int search(Node *root, const char *key);

#endif
