sjf 

#include<stdio.h>
#define max 30
void main()
{
int i,j,n,t,p[max],bt[max],wt[max],tat[max],temp;
float awt=0,atat=0;
/*clrscr();*/
printf("Enter the number of process");
scanf("%d",&n);
printf("Enter the process number");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
}
printf("Enter burst time of the process");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
for (i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(bt[j+1]<bt[j])
{
temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;

temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;

}
}
}
printf("Process\tburst time\twaiting time\tturn around time\n");
for(i=0;i<n;i++)
{
wt[i]=0;
tat[i]=0;
for(j=0;j<i;j++)
{
wt[i]=wt[i]+bt[j];

}
tat[i]=tat[i]+bt[i];
awt=awt+wt[i];
atat=atat+tat[i];
 printf("%d\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);

}
awt=awt/n;
atat=atat/n;
printf("Average waiting time=%f\n",awt);
printf("Average turn around time=%f\n",atat);
}



RR

#include<stdio.h> 
void main() 
{
// initlialize the variable name 
int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];
 float avg_wt, avg_tat; 
 printf(" Total number of process in the system: "); 
 scanf("%d", &NOP);
  y = NOP; // Assign the number of process to variable y 
  
// Use for loop to enter the details of the process like Arrival time and the Burst Ti me 
for(i=0; i<NOP; i++) 
{
printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);
 printf(" Arrival time is: \t"); // Accept arrival time 
 scanf("%d", &at[i]); 
 printf("\nBurst time is: \t"); // Accept the Burst time
 scanf("%d", &bt[i]); 
temp[i] = bt[i]; // store the burst time in temp array 
}
// Accept the Time qunat 
printf("Enter the Time Quantum for the process: \t"); 
scanf("%d", &quant); // Display the process No, burst time, Turn Around Time and the waiting time
 printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
 for(sum=0; i = 0; y!=0) 
{ 
if(temp[i] <= quant && temp[i] > 0) // define the conditions 
{ 
sum = sum + temp[i]; 
temp[i] = 0; 
count=1; 
}
else if(temp[i] > 0) 
{
temp[i] = temp[i] - quant; 
sum = sum + quant; 
}
if(temp[i]==0 && count==1) 
{
y--;//decrement the process no. 
printf("\n Process No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]); 
wt = wt+sum-at[i]-bt[i]; 
tat = tat+sum-at[i]; 
count =0; 
} 
if(i==NOP-1) 
{
i=0; 
}
else if(at[i+1]<=sum) 
{
i++; 
}
else 
{
i=0; 
}
}
// represents the average waiting time and Turn Around time 
avg_wt = wt * 1.0/NOP;
avg_tat = tat * 1.0/NOP; 
printf("\n Average Turn Around Time: \t%f", avg_wt); 
printf("\n Average Waiting Time: \t%f", avg_tat);  
 }

