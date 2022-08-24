#ifndef _TONGXUNLU_
#define _TONGXUNLU_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef int DataType;
typedef struct node
{
    int age;
    char name[20];
    char id[20];
    char tel[12];
    struct node *next;
}linklist;
//主菜单
void menu();
char * my_iota(int i);
//创建空链表
linklist* linklistCreate();
//判断链表是否为空
bool LinklistIsEmpty(linklist *head);
//添加用户
void LinklistAdd(linklist *head);
//冒泡排序
void my_bubble(linklist *head);
//查看用户
void LinklistPrint(linklist *head);
//搜索用户信息
void LinklistSearch(linklist *head);
//删除用户信息
void LinklistDelete(linklist *head);
//修改用户信息
void LinklistCorrect(linklist *head);
int my_strcmp( char*s1,  char *s2);
char *my_strcpy(char *dest,char *src);
long my_strlen(const char *str);
char * my_iota(int i);
void Fwrite(linklist *head);
void LinklistTail(linklist *head,linklist *tmp);
void My_Read(linklist *head);
#endif 