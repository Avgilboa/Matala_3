#include <stdio.h>
#include <string.h>
#include "my_lib.h"

void formatToAtbaush(char* temp, char* start)
{
    while(*start!='\0')
    {
        if(Transfer(*start)==0)
        {
            *temp =*start;
        }
        else if('A' <=*start && *start <='Z')
        {
            *temp = 'Z'-(*start) +'A';
        }
        else if('a' <=*start && *start <='z')
        {
            char val = 'z' -*start +'a';
            *temp = val;
        }
        temp++;
        start++;    
    }
}


void atbash(int sum_word, char* p_first, char* p_last, char* word)
{
    int first =0;
    int *p= &first;
    int check;
    while (*p_last!='\0')
    {
        if(*p_first == ' ')
        {
            p_first++;
            continue;
        }
        else{
            check = isMinSmaller(sum_word, p_first, p_last);
            // 2 the same sum, 1 first++, 0 last++ 
            if(check==1)
            {
                //printf("case 1");
                p_first++;
                continue;
            }
            if(check==0)
            {
                //printf("case 0");
                p_last++;
                continue;
            }
            if(check==2)
            {
                if(sameWords(word,p_first,p_last)!=0)
                {
                    pprint(p_first,p_last,p);
                }
                p_first++;
                continue;
            }
        }
    }
    if(isMinSmaller(sum_word,p_first,p_last)==2)
    {
         if(sameWords(p_first,p_last, word)!=0)
                {
                    pprint(p_first,p_last,p);
                }
    }
}

int sameWords(char* word, char* start, char* end)
{

    if(ReverseIsThesame(word,start,end)!=0)
    {
        return 1;
    }
    while(start<=end && *word!='\0')
    {
/// need to check that the string start and end withot zeroes values.
            if(*start==' ')
            {
                start++; 
                continue;
            }
            else{
                if(*start!=*word)
                {
                    return 0;
                }
                start++;
                word++;
            }
        }
        if(start-1==end && *word=='\0')
        {
            return 1;
        }
        return 0;
}

int ReverseIsThesame(char *word, char*start, char*end)
{
    while(start<=end && *word!='\0')
    {
/// need to check that the string start and end withot zeroes values.
            if(*end==' ')
            {
                end--; 
                continue;
            }
            else{
                if(*end!=*word)
                {
                    return 0;
                }
                end--;
                word++;
            }
        }
        if(start-1==end && *word=='\0')
        {
            return 1;
        }
        return 0;
}