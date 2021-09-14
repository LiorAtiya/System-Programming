#include <stdio.h>
#include "Frequency.h"

int main(int argc, char *argv[])
{
    Node *tree = buildTrie();
    if (argc > 1)
    {
        if (*argv[1] == 'r')
            printWordsRevers(tree);
        else
        {
            printWords(tree);
        }
    }
    else
    {
        printWords(tree);
    }

    return 0;
}