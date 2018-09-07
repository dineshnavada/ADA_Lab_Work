#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void RecminMax(int A[], int low, int high, int *max, int *min)
{
	if(high-low==1)
	{
	if (A[low]>A[high])
	{
		*max=A[low];
		*min=A[high];
	}
	
	else{
		*max=A[high];
		*min=A[low];
	}}
	else if(high==low) *max=*min=A[low];
	else if(high>low){
	int mid, max1, max2, min1, min2;
	mid=(high+low)/2;
	RecminMax(A, low, mid, &max1, &min1);
	RecminMax(A, mid+1, high, &max2, &min2);
	if(max1>max2){
	*max=max1;
	}
	else *max=max2;
	if(min1<min2){
	*min=min1;
	}
	else *min=min2;	
	}
}

int main()
{
	
	int max, min,n,i;
	srand(time(NULL));
	printf("Enter the no of elements:");
	scanf("%d", &n);
	int arr[n];
	printf("\nThe elements are:");
	for( i=0;i<n;i++)
	{
		arr[i]=rand()%100;
		printf("\t%d", arr[i]);
	}
	RecminMax(arr, 0, n-1, &max, &min);
	printf("\nMaximum is %d\nMinimum is %d\n", max, min);
	
}
