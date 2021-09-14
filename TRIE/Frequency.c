#include "Frequency.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *initTrie()
{
    Node *n = (Node *)calloc(1,sizeof(Node));
    if (n)
    {
        n->count = 0;
        n->letter = 0;
        n->endWord = FALSE;
        n->prev = (char *)malloc(1);
        n->prev[0] = 0;
        for (int i = 0; i < NUM_LETTERS; i++)
        {
            n->children[i] = NULL;
        }
    }
    return n;
}

Node *newNode(Node *current, char c)
{
    Node *n = (Node *)calloc(1,sizeof(Node));

    if (n)
    {
        n->count = 0;
        n->letter = c;
        n->endWord = FALSE;
        if (current)
        {
            n->prev = (char *)malloc(sizeof(strlen(current->prev) + 2));
            if (n->prev)
            {
                strcpy(n->prev, current->prev);
                char str[1];
                str[0] = c;
                strcat(n->prev,str);
                for (int i = 0; i < NUM_LETTERS; i++)
                {
                    n->children[i] = NULL;
                }
            }
        }
    }
    return n;
}

int charToIndex(char c)
{
    if (c >= 'A' && c <= 'Z')
        c = c + 32;
    return ((int)c - (int)'a');
}

void insert(Node *root)
{
    Node *current = root;
    char letter;
    while (scanf("%c", &letter) != EOF && letter != '\0')
    {
        if (letter != ' ' && letter != '\n' && letter != '\t' && letter != '\r')
        {
            if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
            {
                int index = charToIndex(letter);
                if (current->children[index] == NULL)
                {
                    current->children[index] = newNode(current, letter);
                    
                }
                current = current->children[index];
            }
            else
            {
                current->endWord = TRUE;
                current->count += 1;
                current = root;
            }
        }
        else
        {
            current->endWord = TRUE;
            current->count += 1;
            current = root;
        }
    }
    root->count = 0;
}

void printWords(Node *root)
{
    if (!root)
        return;

    for (int i = 0; i < NUM_LETTERS; i++)
    {
        printWords(root->children[i]);
    }
    if (root->endWord && root->count != 0)
    {
        printf("%s %ld\n", root->prev, root->count);
    }

    free(root->prev);
    free(root);
}

void printWordsRevers(Node *root){
    if(root == NULL) return;

    for (int i = 25; i >= 0; i--){
        printWordsRevers(root->children[i]);
    }

    if (root->endWord && root->count != 0){
        printf("%s %ld\n",root->prev,root->count);
    }
    free(root->prev);
    free(root);
}

Node *buildTrie()
{
    Node *root = initTrie();
    insert(root);
    return root;
}

