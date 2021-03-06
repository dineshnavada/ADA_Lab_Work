/********************************************************
*Description:Performs Insertion Sort using Decrease and * 
			  conquer technique on a list of  integers. *
*Author: Dinesh K R Navada                              *
*Date of execution: 07 Sept 2018                        *
*********************************************************/

#include<stdio.h>
#include<stdlib.h>

void InsertionSort(int a[], int n){
	int i, j, v;
	for(i=1;i<n;i++){
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
	}
}
int main(){
	int i, n;
	printf("Enter the number of elements:");
	scanf("%d", &n);
	int a[n];
	srand(time(NULL));
	printf("\nThe unsorted elements are:");
	for(i=0;i<n;i++){
		a[i]=rand()%100;
		printf("%d\t", a[i]);
	}
	InsertionSort(a,n);
	printf("\nThe sorted elements are:");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
	printf("\n");
	return 0;
}