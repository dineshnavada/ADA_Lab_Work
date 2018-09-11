/**************************************************************
*Description:Performs Quick Sort using Divide and conquer     * 
             technique on a list of  integers.                *
*Author: Dinesh K R Navada                                    *
*Date of execution: 24 Aug 2018                               *
***************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
void swap(int *a, int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[], int l, int r){
	int p=a[l];
	int i=l;
	int j=r+1;
	do{
		do{
			i++;
		}while(a[i]<p);
		do{
			j--;
		}while(a[j]>p);
		swap(&a[i], &a[j]);
	}while(i<j);
	swap(&a[i], &a[j]);
	swap(&a[l], &a[j]);
	return j;
}
void quickSort(int a[], int l, int r){
	if(l<r){
		int s=partition(a,l,r);
		quickSort(a, l, s-1);
		quickSort(a,s+1, r);
	}
}

void smallExp(){  //For smaller values of n, to verify sorting
	int i,n;
	printf("Demonstrating for smaller size\nEnter no. of elements:");
    scanf("%d",&n);
    int a[n];
    printf("\nThe unsorted elements are:");
    for(i=0;i<n;i++){
		a[i]=rand()%100;
		printf("%d\t", a[i]);
	}
	quickSort(a, 0, n-1);
	printf("\nThe sorted elements are:");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);	
}
int main(){
	int i,j,n;
	FILE *fp;
	double init, final;
	struct timeval tv;
	smallExp();
	printf("\nRepeating for larger list sizes.......");
	fp=fopen("quickplot.txt", "w");
	srand(time(NULL));
	for( j=0;j<100000;j+=100){
		int a[j];
		for(i=0; i<j;i++)
			a[i]=rand()%1000;
		gettimeofday(&tv, NULL);
		init=tv.tv_sec+tv.tv_usec/1000000.0;
		quickSort(a,0,j-1);
		gettimeofday(&tv, NULL);
		final=tv.tv_sec+tv.tv_usec/1000000.0;
		fprintf(fp,"%d\t%f\n", j, final-init);
	}
	printf("\nData file mergedata.txt generated in present working directory.\n");
	return 0;
}
