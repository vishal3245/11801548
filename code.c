
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int executiontime[20],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10];
    int totwt=0,totta=0;
    float avgwaitingtime,avgturnaroundtime;
    char pn[10][10],t[10];
    //clrscr();
    printf("please enter no.of processes:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Please Enter process name, arrival time & execution time:");
        scanf("%s%d%d",pn[i],&at[i],&executiontime[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(executiontime[i] < executiontime[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=executiontime[i];
                executiontime[i]=executiontime[j];
                executiontime[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            st[i]=at[i];
        else
            st[i]=ft[i-1];
        wt[i]=st[i]-at[i];
        ft[i]=st[i]+executiontime[i];
        ta[i]=ft[i]-executiontime[i];
        totwt+=wt[i];
        totta+=ta[i];
    }
    avgwaitingtime=(float)totwt/n;
    avgturnaroundtime=(float)totta/n;
    printf("\nPname\tarrivaltime\texecutiontime\twaitingtime\ttatime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],executiontime[i],wt[i],ta[i]);
    printf("\nThe Average waitingtime is:%f",avgwaitingtime);
    printf("\nThe Average turnaroundtime is:%f",avgturnaroundtime);
    getch();
}
