#include <stdio.h>
#include <string.h>
#include "my_lib.h"

#define WORD 30
#define TXT 1024 


int main()
{
    char w [WORD] = {'0'};
    char st[TXT] ={'0'};
    getWord(w);
    getTxt(st);
    int sum_word = wordStrValue(w);
    printf("Gematria Sequences: ");
    Gematria(sum_word,st,st);
    printf("\n");
    char at [WORD] = {'\0'};
    formatToAtbaush(at,w);
    printf("Atbash Sequences: ");
    sum_word = wordStrValue(at);
    atbash(sum_word,st,st,at);
    printf("\n");
    int arr[256] ={'0'};
    makeArr(arr,w);
    sum_word = wordStrValue(w);
    printf("Anagram Sequences: ");
    Anagram(sum_word,st,st,arr);
    return 0;
}
   