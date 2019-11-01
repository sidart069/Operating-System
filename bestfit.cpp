#include<bits/stdc++.h>
using namespace std;

void bestfit(int* process, int *block ,int n , int m){
	 int allocation[n];
	
  	memset(allocation ,-1,sizeof(allocation));
	
	for(int i=0;i<n;i++){
		int flag=-1;
		for(int j=0;j<m;j++){
			
			if(block[j]>=process[i]){
				if(flag==-1)
				flag=j;
				
				else if(block[flag]>block[j]){
				flag=j;
			}
		}
	}
	if(flag!=-1){
		allocation[i]=flag;
		block[flag]-=process[i];
	
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

bestfit(process,block,n,m);

return 0;
}

