#include<iostream>
using namespace std;
int main()
{
    int n,tq;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter the time quantum: ";
    cin>>tq;
    int bt[n],wt[n],tat[n],rt[n],at[n],ct[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the arrival time and burst time of process "<<i+1<<": ";
        cin>>at[i]>>bt[i];
        rt[i]=bt[i];
    }
    int t=0;
    int done=0;
    while(done<n)
    {
        for(int i=0;i<n;i++)
        {
            if(rt[i]>0)
            {
                if(rt[i]<=tq)
                {
                    t+=rt[i];
                    rt[i]=0;
                    ct[i]=t;
                    done++;
                }
                else
                {
                    t+=tq;
                    rt[i]-=tq;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    float awt=0,att=0;
    for(int i=0;i<n;i++)
    {
        awt+=wt[i];
        att+=tat[i];
    }
    awt/=n;
    att/=n;
    cout<<"\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++)
        cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    cout<<"Average Turnaround Time: "<<att<<endl;
    cout<<"Average Waiting Time: "<<awt<<endl;
}

