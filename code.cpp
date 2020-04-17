#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

//Global scoped variables start;


int p,waiting_time3[30],turnaround_time3[30];
float avgWt3=0.0,avgTat3=0.0;

int position,q,tempo1,sum=0,waiting_time2[30],turnaround_time2[30];
float avgWt2,avgTat2;



int a_t1[30],a_t2[30],priorr2[30],pross2[30],a_t3[30];
int Bu_t1[30],Bu_t2[30],Bu_t3[30];

int Tott=0,t1=0,t2=0,t3=0;

int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0;

int total,x,tempo[30],counter=0;
float avgWt1=0.0,avgTat1=0.0;


//Global scoped variables end;


void Rrobin()
{
	printf("Time Quantum for Queue1 is 4\n");
	for(i=0;i<j;i++)
	{
		tempo[i]=Bu_t1[i];
	}
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	x=j;
    for(i=0,total=0;x!=0;)
    {
    	if(tempo[i]<=4&&tempo[i]>0)
        {
			printf("\nProcess %d of Queue1 is running for %d units",i+1,tempo[i]);
            total=total+tempo[i];
            tempo[i]=0;
            counter=1;
        }
        else if(tempo[i]>0)
        {
			printf("\nProcess %d of Queue1 is running for 4 units",i+1);
            tempo[i]=tempo[i]-4;
            total=total+4;
        }
        if(tempo[i]==0&&counter==1)
        {
            x--;
            printf("\nProcess %d\t%d\t%d\t%d",i+1,Bu_t1[i],total-a_t1[i],total-a_t1[i]-Bu_t1[i]);
            avgWt1=avgWt1+total-a_t1[i]-Bu_t1[i];
            avgTat1=avgTat1+total-a_t1[i];
            counter = 0;
        }
        if(i==j-1)
        {
            i=0;
        }
        else if(a_t1[i+1]<=total)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    avgWt1=avgWt1/j;
    avgTat1=avgTat1/j;
    printf("\nAverage Waiting Time:%f",avgWt1);
    printf("\nAverage Turnaround Time:%f\n",avgTat1);
}

void priorr()
{
	for(i=0;i<k;i++)
    {
        position=i;
        for(q=i+1;q<k;q++)
        {
            if(priorr2[q]<priorr2[position])
            {
                position=q;
            }
        }
        tempo1=priorr2[i];
        priorr2[i]=priorr2[position];
        priorr2[position]=tempo1;

        tempo1=Bu_t2[i];
        Bu_t2[i]=Bu_t2[position];
        Bu_t2[position]=tempo1;

        tempo1=pross2[i];
        pross2[i]=pross2[position];
        pross2[position]=tempo1;
    }
    waiting_time2[0]=0;
    for(i=1;i<k;i++)
    {
        waiting_time2[i]=0;
        for(q=0;q<i;q++)
        {
            waiting_time2[i]=waiting_time2[i]+Bu_t2[j];
        }
        sum=sum+waiting_time2[i];
    }
    avgWt2=sum/k;
    sum=0;
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i=0;i<k;i++)
    {
    	turnaround_time2[i]=Bu_t2[i]+waiting_time2[i];
        sum=sum+turnaround_time2[i];
        printf("\nProcess %d\t\t%d\t\t %d\t\t %d\n",pross2[i],Bu_t2[i],waiting_time2[i],turnaround_time2[i]);
    }
    avgTat2=sum/k;
    printf("\nAverage Waiting Time:\t%f",avgWt2);
    printf("\nAverage Turnaround Time:\t%f\n",avgTat2);

    for(i=0;i<k;i++)
    {
    	while(Bu_t2[i]!=0)
    	{
    		if(Bu_t2[i]>10)
    		{
				printf("\nProcess %d of Queue2 is running for 10 units",i+1);
				Bu_t2[i]=Bu_t2[i]-10;
			}
			else if(Bu_t2[i]<=10)
			{
				printf("\nProcess %d of Queue2 is running for %d units",i+1,Bu_t2[i]);
				Bu_t2[i]=0;
			}
		}
	}

}

void fcfs()
{
	waiting_time3[0] = 0;
    for(i=1;i<l;i++)
    {
        waiting_time3[i] = 0;
        for(p=0;p<l;p++)
        {
            waiting_time3[i]=waiting_time3[i]+Bu_t3[p];
        }
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<l;i++)
    {
        turnaround_time3[i]=Bu_t3[i]+waiting_time3[i];
        avgWt3=avgWt3+waiting_time3[i];
        avgTat3=avgTat3+turnaround_time3[i];
        printf("\nProcess %d\t\t%d\t\t%d\t\t%d\n",i+1,Bu_t3[i],waiting_time3[i],turnaround_time3[i]);
    }
    avgWt3=avgWt3/l;
    avgTat3=avgTat3/l;
    printf("\nAverage Waiting Time=%f",avgWt3);
    printf("\nAverage Turnaround Time=%f",avgTat3);
    for(i=0;i<l;i++)
    {
    	while(Bu_t3[i]!=0)
    	{
    		if(Bu_t3[i]>10)
    		{
				printf("\nProcess %d of Queue3 is running for 10 units",i+1);
				Bu_t3[i]=Bu_t3[i]-10;
			}
			else if(Bu_t3[i]<=10)
			{
				printf("\nProcess %d of Queue2 is running for %d units",i+1,Bu_t3[i]);
				Bu_t3[i]=0;
			}
		}
	}
}

void Rrobin1()
{
	printf("Time Quantum between the 3 queues is 10\n");
	for(i=1;i<Tott;i=i+10)
	{
		if(t1>10)
		{
			printf("Queue1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10&&t1!=0)
		{
			printf("Queue1 is running for %d units\n",t1);
			t1=0;
		}
		if(t2>10)
		{
			printf("Queue2 is running for 10 units\n");
			t2=t2-10;
		}
		else if(t2<=10&&t2!=0)
		{
			printf("Queue2 is running for %d units\n",t2);
			t2=0;
		}
		if(t3>10)
		{
			printf("Queue3 is running for 10 units\n");
			t3=t3-10;
		}
		else if(t3<=10&&t3!=0)
		{
			printf("Queue3 is running for %d units\n",t3);
			t3=0;
		}
	}
}

int main()
{
	printf("Enter the no. of pross you want to enter\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of pross %d\n",i+1);
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d",&pr[i]);
		Tott=Tott+bt[i];
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("\n\nProcess %d belongs to Queue 1\n",i+1);
			a_t1[j]=at[i];
			Bu_t1[j]=bt[i];
			j++;
			t1=t1+bt[i];
		}

		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process %d belongs to Queue 2\n",i+1);
			a_t2[k]=at[i];
			Bu_t2[k]=bt[i];
			priorr2[k]=pr[i];
			pross2[k]=k+1;
			k++;
			t2=t2+bt[i];
		}

		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("Process %d belongs to Queue 3\n\n\n\n",i+1);
			a_t3[l]=at[i];
			Bu_t3[l]=bt[i];
			l++;
			t3=t3+bt[i];
		}
	}

	Rrobin1();
	Rrobin();
	fcfs();
	priorr();

	return 0;
}
