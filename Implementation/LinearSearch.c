/************************************************
*Description:Performs Linear search recursively * 
              on a list of integers.            *
*Author:Dinesh K R Navada           			*
*Date of execution:03 Aug 2018      			*
*************************************************/
#include<stdio.h>
#include<stdlib.h>

int RecLinSearch(int a[],int n,int key){
	if(n==0)
		return -1;
	if(key==a[n-1])
		return n-1;
	RecLinSearch(a,n-1,key);
}
int main(){
	int i,n,pos,key;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nEnter the key element:");
	scanf("%d",&key);
	pos=RecLinSearch(arr,n,key);
	if(pos==-1)
		printf("\n%d not found!",key);
	else
		printf("\n%d is found at position %d.",key,pos);
	return 0;
}