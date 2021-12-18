#include <stdio.h>
#include <string.h>
#include "my_lib.h"
void getWord(char* p)
{
    char c;
    if(scanf("%c",&c)==1);
    while(c!=' ' && c!='\n' && c!='\t')
    {
        *p =c;
        p++;
        if(scanf("%c",&c)==1);  
    }
    *p ='\0';
}
void getTxt(char* p)
{
    char c;
    scanf("%c",&c);
    while(c!='~')
    {
        *p =c;
        p++;
        if(scanf("%c",&c)==1);
    }
    *p ='\0';
}

int Transfer(char c)
{
    if('A'<=c && c<='Z')
    {
        return (c-'A'+1);
    }
    if('a'<=c && c<='z')
    {
        return (c-'a' +1);
    }
    return 0;
}

int wordValue(char* beg, char* end)
{
    int sum=0;
    while(beg<=end)
    {
        sum += (Transfer(*beg));
        beg++;
    }
    return sum;
}
int wordStrValue(char * w)
{
    int sum=0;
    while(*w!='\0')
    {
        sum += (Transfer(*w));
        w++;
    }
    return sum;
}