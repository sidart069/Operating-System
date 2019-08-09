//arrival time is different for all the processes 
// SJF scheduling non-preemtive

#include<bits/stdc++.h>
using namespace std;

struct proc{
    int burstTime;
    int waitT;
    int tat;
    int arrival_time;
    int service_time;//cummulative time for the process to run
   	
};	
bool compare(struct proc p1,struct proc p2){
	return (p1.burstTime<p2.burstTime);		 
}


bool compareArrivals(struct proc p1, struct proc p2){
    return (p1.arrival_time<p2.arrival_time);
}


void ArrivalOrder(struct proc p[]){
     sort(p,p+4,compareArrivals);
      
}

void ShortJob(struct proc p[]){
    sort(p+1,p+4, compare);
}


void FindwaitingTime(struct proc p[]){
      p[0].waitT=0;
      p[0].service_time=0;
    for(int i=1;i<4;i++){
       
       p[i].service_time = p[i-1].service_time + p[i-1].burstTime;
       
       p[i].waitT= p[i].service_time-p[i].arrival_time;
    
    if(p[i].waitT<0){
    	p[i].waitT=0;
    	}
    }
}

 
void FindTurnAroundTime(struct proc p[]){
    for(int i=0;i<4;i++){
        p[i].tat= p[i].burstTime+ p[i].waitT;
    }
}


void findAvgTime(struct proc p[]){
    //int wt[n], tat[n]
    int total_wt=0, total_tat=0;
    FindwaitingTime(p);
    FindTurnAroundTime(p);
   
    cout<<"process "<<" burst time "<<" waiting time "<<" turn around-time"<<"arrival time"<<"\n";
   
    for(int i=0;i<4;i++){
        total_wt = total_wt + p[i].waitT;
        total_tat = total_tat + p[i].tat;
        cout<<"  "<<i+1<<"\t\t"<<p[i].burstTime<<"\t"<<p[i].waitT<<"\t\t  "<<p[i].tat<<"\t\t  "<<p[i].arrival_time<<endl;        
    }
    cout<<"average waiting time= "<<(float)total_wt/(float)4 ;
    cout<<"average turn around time= "<<(float)total_tat/(float)4 ;

}

int main(){
   proc p[] = {{2,0,0,1},{6,0,0,0}, {5,0,0,2},{4,0,0,3} };
 
    //findAvgTime(p);
    ArrivalOrder(p);
    ShortJob(p);
  
    findAvgTime(p);
    return 0;
}
