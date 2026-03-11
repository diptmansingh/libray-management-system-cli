#include<stdio.h>
#include<string.h>
int main(){
    int ch,no,pos,mch,mod,enr,n,i,j,k,l,m;
    i=0;
    struct book
    {
        char auth[100];
        char title[100];
        char code[100];
    };
    struct date
    {
        int dd;
        int mm;
        int yyyy;
    };
    struct library
    {
        int en;
        char name[100];
        char course[100];
        struct date id;
        struct date rd[10];
        struct book bk[10];

    };
    struct library lib[100];
    while(1){
        printf("\nEnter your role:");
        printf("\n1. Librarian\n2. Faculty\n3. Student\nPress any other key to exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nWhat do you want to do\n1. Issue Books\n2. Return Book\n3. See Records\n4. Modify Record\n5. Delete Record");
                printf("\nEnter your choice : ");
                scanf("%d",&m);
                getchar();
                if(m==1)
                {
                    printf("\nIssue book for\n1. Faculty\n2. Student");
                    printf("\nEnter your choice : ");
                    scanf("%d",&l);
                    if(l!=1&l!=2)
                    {
                        printf("\nWrong Choice...Try Again!!\n");
                        break;
                    }
                    if(l==1)
                    {
                        printf("\nEnter number of faculty to issue book : ");
                        scanf("%d",&n);
                        getchar();
                    }
                    else if(l==2)
                    {
                        printf("\nEnter number of student to issue book : ");
                        scanf("%d",&n);
                        getchar();
                    }
                    int y=0;
                    int a=i;
                    for(;i<a+n;i++)
                    {
                        int z=0;
                        printf("\nEnter date(DD/MM/YYYY)    : ");
                        scanf("%d/%d/%d",&lib[i].id.dd,&lib[i].id.mm,&lib[i].id.yyyy);
                        if(l==1)
                            printf("Enter faculty %d ID number : ",y+1);
                        else if(l==2)
                            printf("Enter student %d enrollment number : ",y+1);
                        scanf("%d",&lib[i].en);
                        getchar();
                        if(l==1)
                            printf("Enter faculty %d name      : ",y+1);
                        else if(l==2)
                            printf("Enter student %d name      : ",y+1);
                        fgets(lib[i].name,sizeof(lib[i].name),stdin);
                        if(l==1)
                            strcpy(lib[i].course,"FACULTY");
                        else if(l==2)
                        {
                            printf("Enter student %d course    : ",y+1);
                            fgets(lib[i].course,sizeof(lib[i].course),stdin);
                        }
                        if(l==1)
                            printf("\nEnter faculty %d number of book to issue : ",y+1);
                        else if(l==2)
                            printf("\nEnter student %d number of book to issue : ",y+1);
                        scanf("%d",&j);
                        getchar();
                        for(k=0;k<j;k++)
                        {
                            if(l==1)
                                printf("\nEnter faculty %d book %d title  : ",y+1,z+1);
                            else if(l==2)
                                printf("\nEnter student %d book %d title  : ",y+1,z+1);
                            fgets(lib[i].bk[k].title,sizeof(lib[i].bk[k].title),stdin);
                            if(l==1)
                                printf("Enter faculty %d book %d author : ",y+1,z+1);
                            else if(l==2)
                                printf("Enter student %d book %d author : ",y+1,z+1);
                            fgets(lib[i].bk[k].auth,sizeof(lib[i].bk[k].auth),stdin);
                            if(l==1)
                                printf("Enter faculty %d book %d code   : ",y+1,z+1);
                            else if(l==2)
                                printf("Enter student %d book %d code   : ",y+1,z+1);
                            fgets(lib[i].bk[k].code,sizeof(lib[i].bk[k].code),stdin);
                            z++;
                        }
                        y++;
                    }
                    printf("\nRecord Saved Successfully!!\n");

                }
                else if(m==2)
                {
                    int ret;
                    char code[100];
                    printf("\nEnter ID/Enrollment Number : ");
                    scanf("%d",&ret);
                    getchar();
                    printf("\nEnter the code of the book : ");
                    fgets(code,sizeof(code),stdin);
                    int p=0;
                    for(;p<i;p++)
                    {
                        if(lib[p].en==ret)
                        {
                            int b;
                            for(b=0;b<10;b++)
                            {
                                if(!strcmp(lib[p].bk[b].code,code))
                                    break;
                            }
                            if(b==10&p==i-1)
                            {
                                printf("\nNo Record Found!!\n");
                                break;
                            }
                            if(b==10)
                                continue;
                            else
                            {
                                printf("Enter Return Date : ");
                                scanf("%d/%d/%d",&lib[p].rd[b].dd,&lib[p].rd[b].mm,&lib[p].rd[b].yyyy);
                                printf("\nBook Returned Successfully!!\n");
                                break;
                            }
                            break;
                        }
                    }
                    if(p==i)
                            printf("\nNo Record Found!!\n");
                }
                else if(m==3)
                {
                    if(i==0)
                    {
                        printf("\nNo Record Found!!\n");
                        break;
                    }
                    for(int a=0;a<i;a++)
                    {
                        if(strcmp(lib[a].course,"FACULTY"))
                            printf("\n\nEnrollment No. : %d",lib[a].en);
                        else
                            printf("\n\nID             : %d",lib[a].en);
                        printf("\nName           : %s",lib[a].name);
                        printf("Issue Date     : %d/%d/%d",lib[a].id.dd,lib[a].id.mm,lib[a].id.yyyy);
                        if(strcmp(lib[a].course,"FACULTY"))
                            printf("\nDesignation    : STUDENT\n");
                        else
                            printf("\nDesignation    : FACULTY");
                        if(strcmp(lib[a].course,"FACULTY"))
                        {
                            printf("Course         : %s",lib[a].course);
                            printf("Serial Number  : %d",a+1);
                        }
                        else
                            printf("\nSerial Number  : %d",a+1);
                        printf("\n-----------------------\n");
                        for(int b=0;b<10;b++)
                        {
                            if(!strcmp(lib[a].bk[b].title,""))
                                break;
                            printf("Book %d Title   : %s",b+1,lib[a].bk[b].title);
                            printf("Book %d Author  : %s",b+1,lib[a].bk[b].auth);
                            printf("Book %d Code    : %s",b+1,lib[a].bk[b].code);
                            if(!(lib[a].rd[b].dd==0&lib[a].rd[b].mm==0&lib[a].rd[b].yyyy==0))
                                printf("Return Date    : %d/%d/%d\n",lib[a].rd[b].dd,lib[a].rd[b].mm,lib[a].rd[b].yyyy);
                            printf("- - - - - - - - - - - - \n");
                        }

                    }
                }
                else if(m==4)
                {
                    printf("\nModify record with\n1. ID/Enrollment Number\n2. Serial Number");
                    printf("\nEnter your choice : ");
                    scanf("%d",&mch);
                    if(mch==1)
                    {
                        printf("\nEnter ID/Enrollment Number : ");
                        scanf("%d",&enr);
                        int p=0;
                        for(;p<i;p++)
                        {
                            if(lib[p].en==enr)
                            {
                                printf("\nModify\n1. Name\n2. Course(only for students)\n3. Issue Date\n4. Book Details");
                                printf("\nEnter your choice : ");
                                scanf("%d",&mod);
                                getchar();
                                if(mod==1)
                                {
                                    printf("\nEnter name : ");
                                    fgets(lib[p].name,sizeof(lib[p].name),stdin);
                                    printf("Record Updated Successfully!!\n");
                                }
                                else if(mod==2)
                                {
                                    printf("\nEnter course(only for students) : ");
                                    fgets(lib[p].course,sizeof(lib[p].course),stdin);
                                    printf("Record Updated Successfully!!\n");
                                }
                                else if(mod==3)
                                {
                                    printf("\nEnter date(DD/MM/YYYY) : ");
                                    scanf("%d/%d/%d",&lib[i].id.dd,&lib[i].id.mm,&lib[i].id.yyyy);
                                    printf("Record Updated Successfully!!\n");
                                }
                                else if(mod==4)
                                {
                                    for(int b=0;b<10;b++)
                                    {
                                        if(!strcmp(lib[p].bk[b].title,""))
                                            break;
                                        printf("\nTitle of book %d : %s",b+1,lib[p].bk[b].title);
                                        printf("Author of book %d : %s",b+1,lib[p].bk[b].auth);
                                        printf("Code of book %d : %s",b+1,lib[p].bk[b].code);
                                        printf("- - - - - - - - - - - - - - - - -");
                                    }
                                    char auth[100];
                                    char title[100];
                                    char code[100];
                                    printf("\n\nEnter code of the book : ");
                                    fgets(code,sizeof(code),stdin);
                                    int b;
                                    for(b=0;b<10;b++)
                                    {
                                        if(!strcmp(lib[p].bk[b].code,code))
                                            break;
                                    }
                                    if(b==10)
                                        printf("\nNo Record Found!!\n");
                                    else
                                    {
                                        printf("\nEnter book %d title : ",b+1);
                                        fgets(title,sizeof(title),stdin);
                                        strcpy(lib[p].bk[b].title,title);
                                        printf("Enter book %d author : ",b+1);
                                        fgets(auth,sizeof(auth),stdin);
                                        strcpy(lib[p].bk[b].auth,auth);
                                        printf("Enter book %d code : ",b+1);
                                        fgets(code,sizeof(code),stdin);
                                        strcpy(lib[p].bk[b].code,code);
                                        printf("Record Updated Successfully!!\n");
                                    }
                                }
                                else
                                    printf("\nWrong Choice...Try Again!!\n");
                                break;
                            }
                        }
                        if(p==i)
                            printf("\nNo Record Found!!\n");
                    }
                    else if(mch==2)
                    {
                        int p;
                        printf("\nSerial Number : ");
                        scanf("%d",&p);
                        if(p>i||p<1)
                        {
                            printf("\nNo Record Found!!\n");
                            break;
                        }
                        printf("\nModify\n1. ID/Enrollment Number\n2. Name\n3. Course(only for students)\n4. Issue Date\n5. Book Details");
                        printf("\nEnter your choice : ");
                        scanf("%d",&mod);
                        getchar();
                        if(mod==1)
                        {
                            printf("\nEnter ID/Enrollment Number : ");
                            scanf("%d",lib[p].en);
                            printf("Record Updated Successfully!!\n");
                        }
                        else if(mod==2)
                        {
                            printf("\nEnter name : ");
                            fgets(lib[p].name,sizeof(lib[p].name),stdin);
                            printf("Record Updated Successfully!!\n");
                        }
                        else if(mod==3)
                        {
                            printf("\nEnter course(only for students) : ");
                            fgets(lib[p].course,sizeof(lib[p].course),stdin);
                            printf("Record Updated Successfully!!\n");
                        }
                        else if(mod==4)
                        {
                            printf("\nEnter date(DD/MM/YYYY) : ");
                            scanf("%d/%d/%d",&lib[i].id.dd,&lib[i].id.mm,&lib[i].id.yyyy);
                            printf("Record Updated Successfully!!\n");
                        }
                        else if(mod==5)
                        {
                            for(int b=0;b<10;b++)
                            {
                                if(!strcmp(lib[p].bk[b].title,""))
                                    break;
                                printf("\nTitle of book %d : %s",b+1,lib[p].bk[b].title);
                                printf("Author of book %d : %s",b+1,lib[p].bk[b].auth);
                                printf("Code of book %d : %s",b+1,lib[p].bk[b].code);
                                printf("- - - - - - - - - - - - - - - - -");
                            }
                            char auth[100];
                            char title[100];
                            char code[100];
                            printf("\n\nEnter code of the book : ");
                            fgets(code,sizeof(code),stdin);
                            int b;
                            for(b=0;b<10;b++)
                            {
                                if(!strcmp(lib[p].bk[b].code,code))
                                    break;
                            }
                            if(b==10)
                                printf("\nNo Record Found!!\n");
                            else
                            {
                                printf("\nEnter book %d title : ",b+1);
                                fgets(title,sizeof(title),stdin);
                                strcpy(lib[p].bk[b].title,title);
                                printf("Enter book %d author : ",b+1);
                                fgets(auth,sizeof(auth),stdin);
                                strcpy(lib[p].bk[b].auth,auth);
                                printf("Enter book %d code : ",b+1);
                                fgets(code,sizeof(code),stdin);
                                strcpy(lib[p].bk[b].code,code);
                                printf("Record Updated Successfully!!\n");
                            }
                        }
                        else
                            printf("\nWrong Choice...Try Again!!\n");
                    }
                    else
                        printf("\nWrong Choice...Try Again!!\n");
                }
                else if(m==5)
                {
                    if(i==0)
                        printf("\nNo Record Found!!\n");
                    else
                    {
                        printf("\nEnter Serial Number to delete record : ");
                        scanf("%d",&pos);
                        if(pos>i||pos<1)
                        {
                            printf("\nNo Record Found!!\n");
                            break;
                        }
                        for(int c=pos-1;c<i;c++)
                        {
                            lib[c]=lib[c+1];

                        }
                        i--;
                        printf("\nRecord Deleted Successfully!!\n");
                    }
                }
                else
                    printf("\nWrong Choice...Try Again!!\n");
                break;
            case 2:
                printf("\nWhat do you want to do\n1. Issue Books\n2. Return Book");
                printf("\nEnter your choice : ");
                scanf("%d",&m);
                getchar();
                if(m==1)
                {
                    printf("\nEnter your ID number : ");
                    scanf("%d",&lib[i].en);
                    getchar();
                    printf("Enter your name      : ");
                    fgets(lib[i].name,sizeof(lib[i].name),stdin);
                    strcpy(lib[i].course,"FACULTY");
                    printf("\nEnter date(DD/MM/YYYY) : ");
                    scanf("%d/%d/%d",&lib[i].id.dd,&lib[i].id.mm,&lib[i].id.yyyy);
                    getchar();
                    printf("\nEnter number of book to issue : ");
                    scanf("%d",&j);
                    getchar();
                    int z=0;
                    for(k=0;k<j;k++,z++)
                    {
                        printf("\nEnter book %d title  : ",z+1);
                        fgets(lib[i].bk[k].title,sizeof(lib[i].bk[k].title),stdin);
                        printf("Enter book %d author : ",z+1);
                        fgets(lib[i].bk[k].auth,sizeof(lib[i].bk[k].auth),stdin);
                        printf("Enter book %d code   : ",z+1);
                        fgets(lib[i].bk[k].code,sizeof(lib[i].bk[k].code),stdin);
                    }
                    i++;
                    printf("\nBook Issued Successfully!!\n");
                }
                else if(m==2)
                {
                    int ret;
                    char code[100];
                    printf("\nEnter your ID number       : ");
                    scanf("%d",&ret);
                    getchar();
                    printf("\nEnter the code of the book : ");
                    fgets(code,sizeof(code),stdin);
                    int p=0;
                    for(;p<i;p++)
                    {
                        if(lib[p].en==ret)
                        {
                            int b;
                            for(b=0;b<10;b++)
                            {
                                if(!strcmp(lib[p].bk[b].code,code))
                                    break;
                            }
                            if(b==10&p==i-1)
                            {
                                printf("\nNo Record Found!!\n");
                                break;
                            }
                            if(b==10)
                                continue;
                            else
                            {
                                printf("Enter Return Date : ");
                                scanf("%d/%d/%d",&lib[p].rd[b].dd,&lib[p].rd[b].mm,&lib[p].rd[b].yyyy);
                                printf("\nBook Returned Successfully!!\n");
                                break;
                            }

                        }
                    }
                    if(p==i)
                            printf("\nNo Record Found!!\n");
                }
                else
                    printf("\nWrong Choice...Try Again!!\n");
                break;
            case 3:
                printf("\nWhat do you want to do\n1. Issue Books\n2. Return Book");
                printf("\nEnter your choice : ");
                scanf("%d",&m);
                getchar();
                if(m==1)
                {
                    printf("\nEnter your enrollment number : ");
                    scanf("%d",&lib[i].en);
                    getchar();
                    printf("Enter your name   : ");
                    fgets(lib[i].name,sizeof(lib[i].name),stdin);
                    printf("Enter your course : ");
                    fgets(lib[i].course,sizeof(lib[i].course),stdin);
                    printf("\nEnter date(DD/MM/YYYY) : ");
                    scanf("%d/%d/%d",&lib[i].id.dd,&lib[i].id.mm,&lib[i].id.yyyy);
                    getchar();
                    printf("\nEnter number of book to issue : ");
                    scanf("%d",&j);
                    getchar();
                    int z=0;
                    for(k=0;k<j;k++,z++)
                    {
                        printf("\nEnter book %d title  : ",z+1);
                        fgets(lib[i].bk[k].title,sizeof(lib[i].bk[k].title),stdin);
                        printf("Enter book %d author : ",z+1);
                        fgets(lib[i].bk[k].auth,sizeof(lib[i].bk[k].auth),stdin);
                        printf("Enter book %d code   : ",z+1);
                        fgets(lib[i].bk[k].code,sizeof(lib[i].bk[k].code),stdin);
                    }
                    i++;
                    printf("\nBook Issued Successfully!!\n");
                }
                else if(m==2)
                {
                    int ret;
                    char code[100];
                    printf("\nEnter your enrollment number : ");
                    scanf("%d",&ret);
                    getchar();
                    printf("\nEnter the code of the book   : ");
                    fgets(code,sizeof(code),stdin);
                    int p=0;
                    for(;p<i;p++)
                    {
                        if(lib[p].en==ret)
                        {
                            int b;
                            for(b=0;b<10;b++)
                            {
                                if(!strcmp(lib[p].bk[b].code,code))
                                    break;
                            }
                            if(b==10&p==i-1)
                            {
                                printf("\nNo Record Found!!\n");
                                break;
                            }
                            if(b==10)
                                continue;
                            else
                            {
                                printf("Enter Return Date : ");
                                scanf("%d/%d/%d",&lib[p].rd[b].dd,&lib[p].rd[b].mm,&lib[p].rd[b].yyyy);
                                printf("\nBook Returned Successfully!!\n");
                                break;
                            }

                        }
                    }
                    if(p==i)
                            printf("\nNo Record Found!!\n");
                }
                else
                    printf("\nWrong Choice...Try Again!!\n");
                break;
            default:
                printf("\nExiting...\nPress Enter\n");
                return 0;
        }
    }
}
