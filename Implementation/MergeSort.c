#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Merge(int a[], int low, int high, int mid)
{
	int i, j, k,b[100000];
	i=k=low;
	j=mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else 
			b[k++]=a[j++];
	}
	 while(i<=mid)
	 {
	 	b[k++]=a[i++];
	 }
	 while(j<=high)
	 {
	 	b[k++]=a[j++];
	 }
	 for(i=low;i<k;i++)
	 	a[i]=b[i]; 																	                                                                                                                                                                   
}
void MergeSort(int A[], int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		MergeSort(A, low, mid);
		MergeSort(A, mid+1, high);
		Merge(A, low, high, mid);
	}
}
int main()
{
	int n, i, j;
	srand(time(NULL));
	//printf("Enter no. of elements:");
	struct timeval tv;
	FILE *fp=fopen("mergedata.txt","w");
	double init, final;
	for(j=0;j<100000;j+=100){
	int arr[j];
	for(i=0;i<j;i++)
	{
		arr[i]=rand()%100;
		//printf("\t%d", arr[i]);
	}
	gettimeofday(&tv, NULL);
	init=tv.tv_sec+tv.tv_usec/1000000.0;
	MergeSort(arr, 0, j-1);
	gettimeofday(&tv, NULL);
	final=tv.tv_sec+tv.tv_usec/1000000.0;
	fprintf(fp, "%d\t%f\n", j, final-init);
	}
}