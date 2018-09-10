/*********************************
*Author:Dinesh K R Navada        *
*Date of execution:07 Sept 2018  *
**********************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#define MAX 10

void topologicalSort(int a[MAX][MAX], int v){
	int in[MAX],out[MAX], stack[MAX];
	int i,j,k=0, top=-1;
	for(i=0;i<v;i++){
		in[i]=0;
		for(j=0;j<v;j++){
			if(a[j][i]==1)
				in[i]++;
		}
	}
	while(1){
		for(i=0;i<v;i++){
			if(in[i]==0){
				stack[++top]=i;
				in[i]=-1;
			}
		}
			if(top==-1) break;
			out[k]=stack[top--];
			for(i=0;i<v;i++){
				if(a[out[k]][i]==1)
					in[i]-=1;
			}
		k++;
	}
	printf("\nThe topological ordering is:");
	for(i=0;i<v;i++)
		printf("%d\t", out[i]+1);
	}
int main(){
	int a[MAX][MAX],v,i,j;
	printf("Enter number of vertices:");
	scanf("%d",&v);
	printf("\nEnter the Adjacancy matrix:\n");
	for(i=0;i<v;i++)
			for(j=0;j<v;j++)
				scanf("%d",&a[i][j]);
	topologicalSort(a,v);
	printf("\n");
	return 0;
}