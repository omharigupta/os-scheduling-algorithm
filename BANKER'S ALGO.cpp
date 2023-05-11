#include<iostream>
#include<algorithm>
#include <climits>
using namespace std;
struct process
{
    int pid;
    int at,bt,ct,tat,wt,rt,priority;
};
bool compare(process a,process b)
{
    return a.at<b.at;
}
bool compare2(process a,process b)
{
    return a.rt>b.rt;
}
int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    process p[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the arrival time and burst time of process "<<i+1<<": ";
        cin>>p[i].at>>p[i].bt;
        p[i].pid=i+1;
        p[i].rt=p[i].bt;
    }
    sort(p,p+n,compare);
    int t=0,minn=INT_MAX,index;
    bool check=false;
    int done=0;
    while(done<n)
    {
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=t && p[i].rt<minn && p[i].rt>0)
            {
                minn=p[i].rt;
                index=i;
                check=true;
            }
        }
        if(check==false)
        {
            t++;
            continue;
        }
        p[index].rt--;
        minn=p[index].rt;
        if(minn==0)
            minn=INT_MAX;
        if(p[index].rt==0)
        {
            done++;
            check=false;
            int fin=t+1;
            p[index].ct=fin;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;   
        }
        t++;
    }
    float awt=0,att=0;
    for(int i=0;i<n;i++)
    {
        awt+=p[i].wt;
        att+=p[i].tat;  
    }
    awt/=n;
    att/=n; 
    cout<<"\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++)
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl; 
    cout<<"Average Turnaround Time: "<<att<<endl;
    cout<<"Average Waiting Time: "<<awt<<endl; 
}