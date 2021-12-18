#include <stdio.h>
#include <string.h>
#include "my_lib.h"

void makeArr(int arr[], char* w)
{
    while (*w !='\0')
    {
        if(*w==' ')
        {
            w++;
            continue;
        }
        else{
            arr[(int)*w]++;
            w++;
        }
    }

}
int SmaeLettr(char* start, char* end, int* arr)
{
    while(start<=end)
    {
        if(*start==' ')
        {
            start++;
            continue;
        }
        if(arr[(int)*start]<0)
        {
            return 0;
        }
        arr[(int)*start]--;
        start++;
    }
    for (int i=33; i<256; i++)
    {
        if(arr[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

void Anagram(int sum_word, char* p_first, char* p_last, int* arr)
{
    int first =0; 
    int * p= &first;
    int check;
    int temp [256]={0};
    while(*p_last!='\0')
    {
        if(*p_first==' ' ||*p_first=='\n' || *p_first=='\t')
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
                for (int i=0; i<256;i++)
                {
                    temp[i] = arr[i];
                }
                if(SmaeLettr(p_first,p_last,temp) !=0)
                {pprint(p_first,p_last,p);}
                p_first++;
                continue;
            }
        }
    }
    if(isMinSmaller(sum_word, p_first,p_last)==2)
    {
        if(SmaeLettr(p_first,p_last,temp)!=0){
                    pprint(p_first,p_last,p);}
    }
}