/*某班有最多不超过30人（具体人数由键盘输入）参加期末考试， 
最多不超过 6 门（具体门数由键盘输入）。用二维数组作函数参数，
实现学生成绩管理系统*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20
#define STUD_N 30
#define COURSE_N 6

void ReadScore(float score[][COURSE_N],long num[],char name[][MAX_LEN],float score1[][COURSE_N],long num1[],char name1[][MAX_LEN],int *pstud,int *pcourse);         
void PrintScore(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course);
void Course_Total_Aver(float score[][COURSE_N],float course_sum[],float course_aver[],int stud,int course);
void Stud_Total_Aver(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course);
void ScoreUp(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course);
void ScoreDown(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course);
void NumberUp(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course);
void NameSort(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course);
void SearchByID(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course,long Num);
void SearchByName(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course,char Name[]);
void Statistics(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course);
int main ()
{
    printf("Number:200110806\n");
    printf("subject No.7 - program No.1\n\n");

    int stud,course,input,temp;
    long num[STUD_N],num1[STUD_N],Num;
    char name[STUD_N][MAX_LEN],name1[STUD_N][MAX_LEN],Name[MAX_LEN];
    float score[STUD_N][COURSE_N],score1[STUD_N][COURSE_N],stud_sum[STUD_N],stud_sum1[STUD_N],stud_aver[STUD_N],stud_aver1[STUD_N],course_sum[COURSE_N],course_aver[COURSE_N];
    
    printf("1. Input record\n");
    printf("2. List record\n");
    printf("3. Calculate total and average score of every course\n");
    printf("4. Calculate total and average score of every student\n");
    printf("5. Sort in descending order by total score of every student\n");
    printf("6. Sort in ascending order by total score of every student\n");
    printf("7. Sort in ascending order by StudentID\n");
    printf("8. Sort in dictionary order by name\n");   
    printf("9. Search by StudentID\n");
    printf("10.Search by name\n");
    printf("11.Statistic analysis for every course\n");
    printf("0.Exit\n");
    printf("Please enter your choice:\n");     
    temp=scanf("%d",&input);
    while (temp!=1)
    {
        fflush(stdin);
        printf("Input error!\n");
        printf("Please enter your choice:");     
        temp=scanf("%d",&input);
    }
    if(input==0)
    {
        printf("This program will be closed.");
        exit(0);  
    }
    while(input!=1&&input!=0)
    {
        printf("You must input a sort of records first!\n");
        printf("Please enter your choice:");     
        temp=scanf("%d",&input);
    }
    ReadScore(score,num,name,score1,num1,name1,&stud,&course);

    begin:
    printf("Please enter your choice:");     
    temp=scanf("%d",&input);
    while (temp!=1)
    {
        fflush(stdin);
        printf("Input error!\n");
        printf("Please enter your choice:");     
        temp=scanf("%d",&input);
    }
    switch (input)
    {
    case 0:
        printf("This program will be closed.");
        break;
    case 1:
        ReadScore(score,num,name,score1,num1,name1,&stud,&course);   
        goto begin;    
    case 2:
        Stud_Total_Aver(score1,stud_sum1,stud_aver1,num1,name1,stud,course);
        PrintScore(score1,stud_sum1,stud_aver1,num1,name1,stud,course);
        goto begin;
    case 3:
        Course_Total_Aver(score,course_sum,course_aver,stud,course);
        goto begin;
    case 4:
        Stud_Total_Aver(score,stud_sum,stud_aver,num,name,stud,course);
        for(int i=0;i<stud;i++)
        {
            printf("%-2d.%-15s %ld  sum=%.1f aver=%.2f\n",i+1,name[i],num[i],stud_sum[i],stud_aver[i]);
        }
        goto begin;
    case 5:
        ScoreDown(score,stud_sum,stud_aver,num,name,stud,course);
        for(int j=0;j<stud;j++)
        {
            printf("%2d.%-15s %ld  sum=%.1f\n",j+1,name[j],num[j],stud_sum[j]);
        }
        goto begin; 
    case 6:
        ScoreUp(score,stud_sum,stud_aver,num,name,stud,course); 
        for(int j=0;j<stud;j++)
        {
            printf("%2d.%-15s %ld  sum=%.1f\n",stud-j,name[j],num[j],stud_sum[j]);
        } 
        goto begin; 
    case 7:
        NumberUp(score,stud_sum,stud_aver,num,name,stud,course); 
        PrintScore(score,stud_sum,stud_aver,num,name,stud,course); 
        goto begin;
    case 8:
        NameSort(score,stud_sum,stud_aver,num,name,stud,course);
        PrintScore(score,stud_sum,stud_aver,num,name,stud,course);
        goto begin;
    case 9:
        printf("Please input the ID you wanted:");
        scanf("%ld",&Num);
        SearchByID(score,stud_sum,stud_aver,num,name,stud,course,Num);
        goto begin;
    case 10:
        fflush(stdin);
        printf("Please input the name you wanted:");
        gets(Name);
        SearchByName(score,stud_sum,stud_aver,num,name,stud,course,Name);
        goto begin;
    case 11:
        Statistics(score,stud_sum,stud_aver,num,name,stud,course);
        goto begin;
    default:
        printf("Input error!\n");
        goto begin;
    }
    return 0;
}

//1.函数功能:输入学生各科成绩与学生的学号。
void ReadScore(float score[][COURSE_N],long num[],char name[][MAX_LEN],float score1[][COURSE_N],long num1[],char name1[][MAX_LEN],int *pstud,int *pcourse)
{
    int stud,course,i,j;
    do
    {
        printf("Please input the number of students (<=30):"); //输入人数。
        scanf("%d",&stud);
        if(stud>30||stud<=0)
        { 
            printf("Input error!\n");
        }   
    } while (stud>30||stud<=0);
    do
    {
        printf("Please input the number of courses (<=6):"); //输入课程数。
        scanf("%d",&course);
        if(course>6||course<=0)
        { 
            printf("Input error!\n");
        }   
    } while (course>6||course<=0);
    for(i=0;i<stud;i++)                              //输入姓名及各科成绩。
    {
        fflush(stdin);
        printf("Please input name %d:",i+1);
        gets(name[i]);
        printf("Please input ID %d:",i+1);
        scanf("%ld",&num[i]);
        for(j=0;j<course;j++)
        {
            printf("course%d:",j+1);
            scanf("%f",&score[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<stud;i++)                                //将输入的学号,姓名及成绩按输入的顺序储存到另一对数组中。
    {
        strcpy(name1[i],name[i]);
        for(j=0;j<course;j++)
        {
            score1[i][j]=score[i][j];
        }
        num1[i]=num[i];
    } 
    *pstud=stud;
    *pcourse=course;
}
//2.函数功能:按次序输出n个学生的学号、姓名、各科成绩、总分和平均分。(有序号)
void PrintScore(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course) 
{
    int i,j;
    for(i=0;i<stud;i++)
    {
        printf("%-2d.%-15s %ld  sum=%.1f aver=%.2f ",i+1,name[i],num[i],stud_sum[i],stud_aver[i]);
        for(j=0;j<course;j++)
        {
            printf("%.1f ",score[i][j]);
        }
        printf("\n");
    } 
}
//3.函数功能:计算并输出每门课程的总分和平均分,分别以两个一维数组储存。
void Course_Total_Aver(float score[][COURSE_N],float course_sum[],float course_aver[],int stud,int course)
{
    int i,j;
    for(j=0;j<course;j++)
    {
        course_sum[j]=0;
        for(i=0;i<stud;i++)
        {
            course_sum[j]=course_sum[j]+score[i][j];
        }
        course_aver[j]=course_sum[j]/stud;
    }
     printf("course sum     aver\n");
    for(j=0;j<course;j++)
    {
        printf("  %d    %.1f   %.1f\n",j+1,course_sum[j],course_aver[j]);
    }
}
//4.函数功能:计算每个学生的总分和平均分,分别以两个一维数组储存。
void Stud_Total_Aver(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course)
{
    int i,j;
    for(i=0;i<stud;i++)
    {
        stud_sum[i]=0;
        for(j=0;j<course;j++)
        {
            stud_sum[i]=stud_sum[i]+score[i][j];
        }
        stud_aver[i]=stud_sum[i]/course;
    }
}
//5.函数功能:按每个学生的总分由高到低排出名次表。使用交换法。
void ScoreDown(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course)
{
    int i,j,k;
    float temp1;
    long temp2;
    char temp3[MAX_LEN];
    for(i=0;i<stud-1;i++)
    {
        for(j=i+1;j<stud;j++)
        {
            if(stud_sum[j]>stud_sum[i])
            {    
                temp1=stud_sum[i];
                stud_sum[i]=stud_sum[j];
                stud_sum[j]=temp1;
                temp1=stud_aver[i];
                stud_aver[i]=stud_aver[j];
                stud_aver[j]=temp1;
                temp2=num[i];
                num[i]=num[j];
                num[j]=temp2;
                strcpy(temp3,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp3);
                for(k=0;k<COURSE_N;k++)
                {
                    temp1=score[i][k];
                    score[i][k]=score[j][k];
                    score[j][k]=temp1;                    
                }
            }
        }
    }
}
//6.函数功能:按成绩由低到高排出名次表。使用交换法,运用有指针变量的函数进行数据的交换。
void ScoreUp(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course)
{
    int i,j,k;
    float temp1;
    long temp2;
    char temp3[MAX_LEN];
    for(i=0;i<stud-1;i++)
    {
        for(j=i+1;j<stud;j++)
        {
            if(stud_sum[j]<stud_sum[i])
            {    
                temp1=stud_sum[i];
                stud_sum[i]=stud_sum[j];
                stud_sum[j]=temp1;
                temp1=stud_aver[i];
                stud_aver[i]=stud_aver[j];
                stud_aver[j]=temp1;
                temp2=num[i];
                num[i]=num[j];
                num[j]=temp2;
                strcpy(temp3,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp3);
                for(k=0;k<COURSE_N;k++)
                {
                    temp1=score[i][k];
                    score[i][k]=score[j][k];
                    score[j][k]=temp1;                    
                }
            }
        }
    }
}
//7.函数功能:按学号由小到大排出成绩表。使用交换法。
void NumberUp(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course)
{
    int i,j,k;
    float temp1;
    long temp2;
    char temp3[MAX_LEN];
    for(i=0;i<stud-1;i++)
    {
        for(j=i+1;j<stud;j++)
        {
            if(num[j]<num[i])
            {    
                temp1=stud_sum[i];
                stud_sum[i]=stud_sum[j];
                stud_sum[j]=temp1;
                temp1=stud_aver[i];
                stud_aver[i]=stud_aver[j];
                stud_aver[j]=temp1;
                temp2=num[i];
                num[i]=num[j];
                num[j]=temp2;
                strcpy(temp3,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp3);
                for(k=0;k<COURSE_N;k++)
                {
                    temp1=score[i][k];
                    score[i][k]=score[j][k];
                    score[j][k]=temp1;
                }   
            }
        }
    }   
}
//8.函数功能:按姓名的字典顺序排出成绩表
void NameSort(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course)
{
    int i,j,k;
    float temp1;
    long temp2;
    char temp3[MAX_LEN];
    for(i=0;i<stud-1;i++)
    {
        for(j=i+1;j<stud;j++)
        {
            if(strcmp(name[j],name[i])<0)
            {    
                temp1=stud_sum[i];
                stud_sum[i]=stud_sum[j];
                stud_sum[j]=temp1;
                temp1=stud_aver[i];
                stud_aver[i]=stud_aver[j];
                stud_aver[j]=temp1;
                temp2=num[i];
                num[i]=num[j];
                num[j]=temp2;
                strcpy(temp3,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp3);
                for(k=0;k<COURSE_N;k++)
                {
                    temp1=score[i][k];
                    score[i][k]=score[j][k];
                    score[j][k]=temp1;
                }   
            }
        }
    }
}
//9.函数功能:按学号查询学生排名及成绩。
void SearchByID(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course,long Num)
{
    ScoreDown(score,stud_sum,stud_aver,num,name,stud,course);
    int i,j,flag=0;
    for(i=0;i<stud;i++)
    {
        if(num[i]==Num)
        {
            printf("The ranking is %d,the score is ",i+1);
            for(j=0;j<course;j++)
            {
                printf("%.1f ",score[i][j]);
            }
            printf("\n");
            flag=1;
            break;
        } 
    }
    if(flag==0)
    {
        printf("This student doesn't exist!\n");          
    }
}
//10.函数功能:按姓名查询学生排名及其考试成绩。
void SearchByName(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course,char Name[])
{
    ScoreDown(score,stud_sum,stud_aver,num,name,stud,course);
    int i,j,flag=0;
    for(i=0;i<stud;i++)
    {
        if(strcmp(Name,name[i])==0)
        {
            printf("The ranking is %d,the score is ",i+1);
            for(j=0;j<course;j++)
            {
                printf("%.1f ",score[i][j]);
            }
            printf("\n");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("This student doesn't exist!\n");
    }
}
//11.函数功能:按优秀(90-100)、良好(80-89)、中等(70-79)、及格(60-69)、不及格(0-59)5个类别，统计每个类别的人数以及所占的百分比。
void Statistics(float score[][COURSE_N],float stud_sum[],float stud_aver[],long num[],char name[][MAX_LEN],int stud,int course)
{
    int i,j;  
    int flag,count1,count2,count3,count4,count5;
    float rate1,rate2,rate3,rate4,rate5;
    for(j=0;j<course;j++)
    { 
        flag=0,count1=0,count2=0,count3=0,count4=0,count5=0;
        rate1=0,rate2=0,rate3=0,rate4=0,rate5=0;
        ScoreDown(score,stud_sum,stud_aver,num,name,stud,course);
        for(i=0;i<stud;i++)
        {
            if(score[i][j]>=90)                    flag=1;
            if(score[i][j]>=80&&score[i][j]<90)    flag=2;
            if(score[i][j]>=70&&score[i][j]<80)    flag=3;
            if(score[i][j]>=60&&score[i][j]<70)    flag=4;
            if(score[i][j]>=0&&score[i][j]<60)     flag=5;
            switch (flag)
            {
            case 1:
                count1++;
                break;
            case 2:
                count2++;
                break;
            case 3:
                count3++;
                break;
            case 4:
                count4++;
                break;
            case 5:
            count5++;
                break;
            }
        }
        rate1=100*count1/(float)stud;
        rate2=100*count2/(float)stud;
        rate3=100*count3/(float)stud;
        rate4=100*count4/(float)stud;
        rate5=100*count5/(float)stud;
        printf("course %d:\n",j);
        printf("Level 1(90-100)   %d    %.2f%%\n",count1,rate1);
        printf("Level 2(80-89)    %d    %.2f%%\n",count2,rate2);
        printf("Level 3(70-79)    %d    %.2f%%\n",count3,rate3);
        printf("Level 4(60-69)    %d    %.2f%%\n",count4,rate4);
        printf("Level 5(0-59)     %d    %.2f%%\n\n",count5,rate5);
    }
}
