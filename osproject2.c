#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int burst_time[30];
	int waiting_time[30];
	int turn_around_time[30];
	int p[20];
	int  i,j,n,total=0,pos,temp;
	float avg_waiting_time;
	float avg_turn_around_time;
	printf("Enter total number of processes:");
	scanf("%d",&n);
	printf("\nenter estimated time:\n");
	for (i = 0; i < n; i++)
	{
	 
	 scanf("%d",&burst_time[i]);
	 p[i]=i+1;   //stores process number 
	}
	//sorting burst time in ascending order using selection sorting
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(burst_time[j]<burst_time[pos])
			pos=j;
		}
		temp=burst_time[i];
		burst_time[i]=burst_time[pos];
		burst_time[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	waiting_time[0] = 0;
	for(i=0;i<n;i++)
	{
		waiting_time[i]=0;
		for(j=0;j<i;j++)
		  waiting_time[i]+=burst_time[j];
		total+=waiting_time[i];
	}
	avg_waiting_time=(float)total/n;
	total=0;
	printf("\n Process number \t Waiting time  \t Estimated time\t Turn Around Time");
	for(i=0;i<n;i++)
	{
		turn_around_time[i]=burst_time[i] + waiting_time[i];   //turn around Time
		total+= turn_around_time[i];
		printf("\np%d \t \t\t   %d \t \t\t   %d\t\t\t  %d",p[i],waiting_time[i],burst_time[i],turn_around_time[i]);
	}
	avg_turn_around_time=(float)total/n;            //avd_tat
	printf("\n \n Average Turn around time =%f \n",avg_turn_around_time);
	printf("\nAverage waiting time=%f",avg_waiting_time);
		
}

