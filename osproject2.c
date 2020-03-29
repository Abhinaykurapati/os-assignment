#include<stdio.h>
#include<conio.h>
int main()
{
  int n,i=0,j=0;
  double priority[n],average_waiting,average_turn_around,burst_time[n];
  double arrival_time[n],waiting_time[n],turn_around_time[n], process[n];
  double temp, completion_time[n],min,SUM=0,SUM2=0,wait_final, turn_around_fin, wait_avg, turnaround_avg;
  printf("Enter Number of Processes : ");
  scanf("%ld",&n );
  
  for(i=0;i<n;i++)
  {
    printf("\nEnter burst_time for process [%d] :", i+1 );
    scanf("%lf", &burst_time[i]);
    printf("Enter Arrival Time for Process [%d] : ", i+1 );
    scanf("%lf", &arrival_time[i] );
    process[i]=i+1;
  }

  printf("\n\nEntered Values are:\n\n");
 
  printf("\t\tProcess   \t  Arrival Time    \tBurst Time \n");
 
  for(i=0;i<n;i++)
  {
    printf("\t\t  P[%0.0lf]      \t   %0.0lf         \t   %0.0lf      \n",process[i],arrival_time[i],burst_time[i]);
  }
    


  printf("\n\n\n\t\t Arranging according to arrival_time");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrival_time[i]<arrival_time[j])
      {
       
        temp = burst_time[j];
        burst_time[j] = burst_time[i];
        burst_time [i] = temp;

     temp = process[j];
        process[j] = process[i];
        process[i] = temp;

     temp = arrival_time[j];
        arrival_time[j] = arrival_time[i];
        arrival_time[i] = temp;
     
      }
    }
  }
  printf("\n\n\nValues:\n\n");
  printf("\t\t Process \t Arrival Time \t Burst Time \n");
  for(i=0;i<n;i++)
  {
    printf("\t\t  P[%0.0lf]        \t %0.0lf        \t   %0.0lf      \n",process[i],arrival_time[i],burst_time[i]);
  }
  long int k = 1;
  double b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + burst_time[j];
    min = burst_time[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= arrival_time[i])&&(burst_time[i]<min))
      {
        temp = burst_time[k];
        burst_time[k] = burst_time[i];
        burst_time[i] = temp;

        temp = arrival_time[k];
        arrival_time[k] = arrival_time[i];
        arrival_time[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
      }
    }
    k++;
  }
  waiting_time[0] = 0;
  for(i=1;i<n;i++)
  {
    SUM += burst_time[i-1];
    waiting_time[i] = SUM - arrival_time[i];
    wait_final += waiting_time[i];
  }
  wait_avg = wait_final/n;
  for(i=0;i<n;i++)
  {
    SUM2 += burst_time[i];
    turn_around_time[i] = SUM2 - arrival_time[i];
    turn_around_fin += turn_around_time[i];
  }
  turnaround_avg=turn_around_fin/n;
printf("\n\n\nValues:\n");
  
  printf("\t\t Process \t Arrival Time  \tBurst Time  \t Waiting Time    \tTurn Around Time  \n");
  
  for(i=0;i<n;i++)
  {
    printf("\t\t  P[%0.0lf]          \t%0.0lf          \t %0.0lf          \t%0.0lf           \t%0.0lf\n",process[i],arrival_time[i],burst_time[i],waiting_time[i],turn_around_time[i]);
  }
   



  /*Now we have to prioritize the processes according to the formulae
      Priority = 1+ Waiting time / Estimated run time
  */
 
 
  completion_time[0] = burst_time[0];
  for(i=1;i<n;i++)
  {
    completion_time[i] = completion_time[i-1] + burst_time[i];
  }

  for(i=0;i<n;i++)
  {
    priority[i] = 1+waiting_time[i]/completion_time[i];
    printf("%lf\n",priority[i]);
  }


  printf("\n\n\n\n\t\tFinal Values:\n\n");
 
  printf("\t\t Process \tArrival Time \t Burst Time  \t Waiting Time  \tTurn Around Time  \n");
 
    printf("\t\t  P[%0.0lf]      \t   %0.0lf         \t  %0.0lf           \t   %0.0lf             \t   %0.0lf    \n   ",process[0],arrival_time[0],burst_time[0],waiting_time[0],turn_around_time[0]);
  for(i=n-1;i>0;i--)
  {
    printf("\t\t  P[%0.0lf]      \t    %0.0lf         \t  %0.0lf           \t   %0.0lf             \t   %0.0lf       \n   ",process[i],arrival_time[i],burst_time[i],waiting_time[i],turn_around_time[i]);
  }
    

  printf("\n\n\n\t\tAverage Turn Around Time : %lf",turnaround_avg);
  printf("\n\t\tAverage Waiting Time     : %lf\n\n",wait_avg);
  getch();
  return 0;
}


