/************************************************
*Description:Performs Binary search recursively * 
*              on a list of integers.           *
*Author:Dinesh K R Navada           			*
*Date of execution:03 Aug 2018      			*
*************************************************/
#include<stdio.h>
#include<stdlib.h>

int RecBinSearch(int a[],int l,int h,int key){
	if(l>h)
		return -1;
	int mid=(l+h)/2;
	if(key==a[mid])
		return mid;
	if(key<a[mid])
		RecBinSearch(a,l,mid-1,key);
	else 
		RecBinSearch(a,mid+1,h,key);
}
int main(){
	int i,n,pos,key;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in ascending order:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nEnter the key element:");
	scanf("%d",&key);
	pos=RecBinSearch(arr,0,n-1,key);
	if(pos==-1)
		printf("\n%d not found!",key);
	else
		printf("\n%d is found at position %d.",key,pos);
	return 0;
}
