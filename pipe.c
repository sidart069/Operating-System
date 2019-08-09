#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

void main(){
    
    char wr[50]; 
    char rd[50];
    
    int a[2];
    int id;
    
    pipe(a);
    id= fork();
    
    if(id!=0){
        close(a[0]);
        fgets(wr,50,stdin);
        write(a[1],&wr,50);
    
    }
    
    else{
        close(a[1]);
        read(a[0],&rd,50);
        printf("in baccha %s",rd);
    }
    
}
