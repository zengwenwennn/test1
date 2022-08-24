#include"tongxun.h"
long my_strlen(const char *str)
{
    int num = 0;
    while (*str!='\0') 
    {
        num++;
        str++;
    }
    return num;
}