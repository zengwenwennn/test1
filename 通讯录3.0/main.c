#include"tongxun.h"

void My_Read(linklist *head)
{
    FILE *fp=fopen("./1.txt","r");
    if(NULL==fp)
    {
        perror("fopen");
    }
    fseek(fp,0,SEEK_SET);
        while(1)
        {
            char ch=fgetc(fp);
            if(ch==EOF)
            {
                break;
            }
            linklist *tmp=(linklist*)malloc(sizeof(linklist));
            char buf;
            int i=0;
            while(1)
            {
                fread(&buf,1,1,fp);
                if(buf==' ')
                {
                    tmp->name[i]='\0';
                    break;
                }
                tmp->name[i]=buf;
                i++;
            }
                        printf("--------------------------------\n");
            i=0;
            char buf1;
            while(1)
            {
                fread(&buf1,1,1,fp);
                if(buf1==' ')
                    break;
                tmp->age=tmp->age*10+(buf1-'0');
            }
            if(tmp->age==0)
                break;
            i=0;
            char buf2;
            while(1)
            {
                fread(&buf2,1,1,fp);
                if(buf2==' ')
                    break;
                tmp->id[i]=buf2;
                i++;
            }
            i=0;
            char buf3;
            while(1)
            {
                fread(&buf3,1,1,fp);
                if(buf3=='\n')
                    break;
                tmp->tel[i]=buf3;
                i++;
            } 
            LinklistTail(head,tmp); 
            if(feof(fp))
            {
                break;
            }
    }
    fclose(fp);
}
int main(int argc, char const *argv[])
{
    linklist *head=linklistCreate();
    My_Read(head);
    int choice;
    while(1)
    {
        menu();
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
            exit(0);
            break;
            case 1:
            LinklistAdd(head);
            break;
            case 2:
            LinklistPrint(head);
            break;
            case 3:
            LinklistSearch(head);
            break;
            case 4:
            LinklistDelete(head);
            break;
            case 5:
            LinklistCorrect(head);
            break;
            default:
            printf("Unknown choice\n");
            getchar();
            break;
        }
    }
    return 0;
}
