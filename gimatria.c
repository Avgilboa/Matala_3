#include <stdio.h>
#include <string.h>
#include "my_lib.h"

void pprint(char* start, char* end, int* first)
{
    if(*first!=0)
    {
        printf("%c",'~');
    }
    while(start<=end)
    {
        printf("%c", *start);
        start++;
    }
    *first =1;
}
int isMinSmaller(int word, char* start, char* end)
{
    int value = wordValue(start,end);
    if(value < word)
    {
        return 0; //the string smaller than our value, so plast++
    }
    if(value==word)
    {
        return 2;
    }
    return 1;   /// 1 means first++;
}
void Gematria( int sum_word,char* p_first, char* p_last)
{
    int first =0; 
    int * p= &first;
    int check;
    while(*p_last!='\0')
    {
        if(Transfer(*p_first)==0)
        {
            p_first++;
            continue;
        }
        else{
            check = isMinSmaller(sum_word, p_first,p_last);
            if(check==0)
            {
                p_last++;
                continue;
            }
            if(check==1)
            {
                p_first++;
                continue;
            }
            if(check==2)
            {
                pprint(p_first,p_last,p);
                p_first++;
                continue;
            }
        }
    }
    if(isMinSmaller(sum_word, p_first,p_last)==2)
    {
        pprint(p_first,p_last,p);
    }
}