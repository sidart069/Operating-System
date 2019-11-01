#include<bits/stdc++.h>
using namespace std;

void firstfit(int* process, int *block ,int n , int m){
	 int allocation[n];
  	memset(allocation ,-1,sizeof(allocation));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(block[j]>=process[i]){
				allocation[i]=j;
				block[j]-=process[i];
				break;
		}
	}
}
	cout<<"\n process number \tprocess size\tblock number\n ";
	for(int i=0;i<n;i++){
		cout<<" "<<i+1<<"\t\t";
		if(allocation[i]!=-1)
			cout<<allocation[i]+1;
		else
			cout<<"can not allocate";
		cout<<endl;
	
	}


}



int main(){
int n,m;
cout<<"enter no. of processes\n";
cin>>n;
int process[n];

cout<<"enter no. of block used\n";
cin>>m;
int block[m];

for(int i=0;i<n;i++){
	cin>>process[i];
}


for(int i=0;i<m;i++){
	cin>>block[i];
}

firstfit(process,block,n,m);

return 0;
}

