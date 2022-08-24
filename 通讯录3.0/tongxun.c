#include"tongxun.h"
#include<unistd.h>
void LinklistTail(linklist *head,linklist *tmp)
{
    linklist *tail =head;
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    tail->next = tmp;
    tmp->next=NULL;
}
void menu()
{
    printf("**************************************************\n");
    printf("      0,退出系统      1,录入信息    \n");
    printf("      2,查看信息      3,搜索信息    \n");
    printf("      4,删除信息      5,修改用户    \n");  
    printf("**************************************************\n");
    printf("input>> ");
}
//将年龄转化为字符串存进文档中
char * my_iota(int i)
{
    static char s[1006];
    int c=i;
    int n=0;
    while(c>0)
    {
        *(s+n)='0'+c%10;
        c=c/10;
        n++;
    }
    *(s+n)='\0';
    for(int v=0;v<n/2;v++)
    {
        char temp=*(s+v);
        *(s+v)=*(s+n-1-v);
        *(s+n-1-v)=temp;
    }
    return s;
}
//创建一个新的链表
linklist *linklistCreate()
{
    linklist *head=(linklist *)malloc(sizeof(linklist));
    head->next=NULL;
    return head;
}
bool LinklistIsEmpty(linklist *head)
{
    return head->next==NULL?1:0;
}
void Fwrite(linklist *head)
{
    linklist *tmp=head->next;
    FILE *fp=fopen("./1.txt","w");
    if(fp==NULL)
    {
        perror("fwrite");
        return;
    }
    while(tmp)
    {
    fwrite(&tmp->name,my_strlen(tmp->name),1,fp);
    fwrite(" ",1,1,fp);
    fwrite(my_iota(tmp->age),my_strlen(my_iota(tmp->age)),1,fp);
    fwrite(" ",1,1,fp);
    fwrite(&tmp->id,my_strlen(tmp->id),1,fp);
    fwrite(" ",1,1,fp);
    fwrite(&tmp->tel,my_strlen(tmp->tel),1,fp);
    fwrite(" ",1,1,fp);
    fwrite("\n",1,1,fp);
    tmp=tmp->next;
    }
    fclose(fp);
}
//添加用户
void LinklistAdd(linklist *head)
{
    char ch;
    int flg=1;
    printf("是否要输入(y/n)\n");
    getchar();
    scanf("%c", &ch);
    while(ch=='y'||ch=='Y')
    {
    // 头插法添加用户
    linklist *tmp=(linklist *)malloc(sizeof(linklist));
    printf("请输入用户的姓名，年龄，ID，电话号码\n");
    scanf("%s%d%s%s",tmp->name,&tmp->age,tmp->id,tmp->tel);
    if(my_strlen(tmp->tel)!=11)
    {
        printf("电话号码格式错误,请重新输入\n");
        flg=1;
        continue;
    }
    linklist *p=head;
    while(p->next!=NULL&&my_strcmp(p->next->name,tmp->name)<0)
    {
        p=p->next;
    }
    tmp->next=p->next;
    p->next=tmp;
    Fwrite(head);
        printf("添加信息成功，是否选择继续添加?(y/n)\n");
        getchar();
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
        {
            continue;
        }
        else if(ch=='n'||ch=='N')
        {
            break;
        }
    }
}
//查看用户
void LinklistPrint(linklist *head)
{
    if(LinklistIsEmpty(head))
    {
        printf("通讯录为空\n");
        return;
    }
    linklist *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
        printf("姓名:%s 年龄:%d ID:%s 电话:%s\n",p->name,p->age,p->id,p->tel);
    }
    #if 0
    linklist *p=head->next;
    while(p!=NULL) 
    {
             printf("姓名:%s 年龄:%d ID:%s 电话:%s\n",p->name,p->age,p->id,p->tel);   
                     p=p->next;
    }
    #endif
    sleep(2);
}
//搜索用户信息
void LinklistSearch(linklist *head)
{
    if(LinklistIsEmpty(head))
    {
        printf("通讯录为空\n");
        return;
    }
    int flg=0;
    char *a;
    a=(char *)malloc(sizeof(char));
    printf("请输入搜索用户的姓名或者ID\n");
    scanf("%s",a);
    // printf("%s\n",a);
    linklist *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    //   printf("%s %s \n",a,p->name);
    //     printf("%d %d\n",my_strcmp(a,p->name),my_strcmp(a,p->id));  
        if(my_strcmp(p->name,a)==0||my_strcmp(p->id,a)==0)
        {
            printf("用户信息如下：\n");
            printf("姓名:%s 年龄:%d ID:%s 电话:%s\n",p->name,p->age,p->id,p->tel);
            flg=1;
        }
    }
    if(flg==1)
    {
        printf("搜索用户成功\n");
    }else
    {
        printf("找不到此用户，搜索失败\n");
    }
    free(a); 
    sleep(1);  
}
//删除用户信息
void LinklistDelete(linklist *head)
{
    if(LinklistIsEmpty(head))
    {
        printf("通讯录为空，无法删除用户\n");
    }
    int flg=0;
    char *a;
    a=(char *)malloc(sizeof(char));
    printf("请输入需要删除用户的姓名或者ID\n");
    scanf("%s",a);
    linklist *q=head;
    linklist *p=head->next;
    while(p!=NULL)
    {
        if(my_strcmp(p->name,a)==0||my_strcmp(p->id,a)==0)
        {
            q->next=p->next;
            free(p);
            flg=1;
            Fwrite(head);
        }
        q=p;
        p=p->next;
    }
    if(flg==1)
    {
        printf("删除用户成功\n");
    }
    else
    {
        printf("找不到此用户，删除失败\n");
    }
    free(a);
    sleep(1);
}
//修改用户信息
void LinklistCorrect(linklist *head)
{
    if(LinklistIsEmpty(head))
    {
        printf("链表为空，无法修改用户\n");
    }
    int flg=0;
    linklist *p=head;
    char tmp_name[20];
    char tmp_id[20];
    char tmp_tel[12];
    int tmp_age; 
    printf("请输入需要修改用户的姓名\n");
    scanf("%s",tmp_name);

    while(p->next!=NULL)
    {
        p=p->next;
        if(my_strcmp(tmp_name,p->name)==0)
        {
            printf("请输入需要修改的信息(姓名，年龄，ID，电话)\n");
            scanf("%s %d %s %s",tmp_name,&tmp_age,tmp_id,tmp_tel);
            if(my_strlen(tmp_tel)!=11)
            {
                printf("电话号码格式错误\n");
                flg=1;
                continue;
            }
            strcpy(p->name,tmp_name);
            p->age=tmp_age;
            strcpy(p->id,tmp_id);
            strcpy(p->tel,tmp_tel);
            flg=1;
            Fwrite(head);
            printf("修改用户信息成功\n");
        }
    }
    if(flg==0)
    {
        printf("找不到此用户，修改失败\n");
    }

}
