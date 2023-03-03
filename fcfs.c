#include <stdio.h>
struct fcfs{
int pid,at,bt,ct,st,wt,tat;
};

int main(){
struct fcfs p[100];
int n;
printf("enter no of process");
scanf("%d",&n);
for(int i=0;i<n;i++){
p[i].pid=i;
printf("enter arrival time");
scanf("%d",&p[i].at);
printf("enter burst time");
scanf("%d",&p[i].bt);
}
for(int i=0;i<n;i++){
for(int j=0;j<n-i-1;j++){
if(p[j].at>p[j+1].at){
struct fcfs temp=p[j+1];
p[j+1]=p[j];
p[j]=temp;
}
}
}
p[0].st=p[0].at;
p[0].ct=p[0].st+p[0].bt;
for(int i=1;i<n;i++){
if(p[i-1].ct<p[i].at){
p[i].st=p[i].at;
p[i].ct=p[i].st+p[i].bt;
}
else{
p[i].st=p[i-1].ct;
p[i].ct=p[i].st+p[i].bt;}
}

float sumtat=0;
float sumwt=0;
for(int i=0;i<n;i++){
p[i].wt=p[i].st-p[i].at;
p[i].tat=p[i].ct-p[i].at;
sumwt=sumwt+p[i].wt;
sumtat=sumtat+p[i].tat;
}
float avgtat=sumtat/n;
float avgwt=sumwt/n;
for(int i=0;i<n;i++){
for(int j=0;j<n-i-1;j++){
if(p[j].pid>p[j+1].pid){
struct fcfs temp=p[j+1];
p[j+1]=p[j];
p[j]=temp;
}}}
printf("Process\tAT\tBT\tST\tFT\tWT\tTAT\n");
for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].wt,p[i].tat);
        printf("\n");
    }
    printf("Average waiting time:%f",avgwt);
    printf("\n");
    printf("Average turnaround time:%f",avgtat);
    printf("\n");
}
