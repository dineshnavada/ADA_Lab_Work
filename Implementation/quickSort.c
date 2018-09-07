#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
void swap(int *a, int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[], int l, int r)
{
	int p=a[l];
	int i=l;
	int j=r+1;
	do
	{
		do
		{
			i++;
		}while(a[i]<p);
		do
		{
			j--;
		}while(a[j]>p);
		swap(&a[i], &a[j]);
	}while(i<j);
	swap(&a[i], &a[j]);
	swap(&a[l], &a[j]);
	return j;
}
void quickSort(int a[], int l, int r)
{
	if(l<r)
	{
		int s=partition(a,l,r);
		quickSort(a, l, s-1);
		quickSort(a,s+1, r);
	}
}
int main()
{
	int i, j,n;
	FILE *fp;
	double init, final;
	struct timeval tv;
	//printf("%d",);
	
	//printf("\nEnter the no. of elements:");
	//scanf("%d", &n);
	fp=fopen("quickplot.txt", "w");
	srand(time(NULL));
	for( j=0;j<100000;j+=100){
	int a[j];
	
	for(i=0; i<j;i++)
	{
		a[i]=rand()%1000;
	}
	gettimeofday(&tv, NULL);
	init=tv.tv_sec+tv.tv_usec/1000000.0;
	quickSort(a,0,j-1);
	gettimeofday(&tv, NULL);
	final=tv.tv_sec+tv.tv_usec/1000000.0;
	fprintf(fp,"%d\t%f\n", j, final-init);
	}
	/*printf("\nThe elements are:");
	for(i=0; i<n;i++)
		printf("%d\t", a[i]);
	quickSort(a,0,n-1);
	printf("\nThe sorted elements are:");
	for(i=0; i<n;i++)
		printf("%d\t", a[i]);
	printf("%f",difftime(init, tv.tv_sec));
	printf("\n");*/
}
