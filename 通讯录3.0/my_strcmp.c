#include"tongxun.h"
int my_strcmp( char*s1,  char *s2)
{
    if((s1==NULL)&&(s2 ==NULL))
    {
        return 0;
    }
    if((s1==NULL)&&(s2!=NULL))
    {
        return -1;
    }
    if((s1!=NULL)&&(s2==NULL))
    {
        return 1;
    }
    while(*s1!='\0'&&*s1!='\0')
    {
        if(*s1>*s2)
        {
            return 1;
        }
        if(*s1<*s2)
        {
            return -1;
        }
        s1++;
        s2++;
    }
    if(*s1=='\0'&&*s1=='\0')
    {
        return 0;
    }
    if(*s1!='\0'&&*s1=='\0')
    {
        return 1;
    }
    if(*s1=='\0'&&*s2!='\0')
    {
        return -1;
    }
}