#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void quickSort(int a[],int start,int end);
int partition(int a[],int start,int end);
int main(int argc, char *argv[]) 
{
	
	int a[] ={5,4,2,1,3};
	quickSort(a,0,4);
	int i;
	for(i=0;i<5;i++)
	{
		printf(" %d ",a[i]);
	}
	return 0;
	
}
void quickSort(int a[],int left,int right)
{
	int i=left;  
	int j=right;
	int pivot=a[(left+right)/2];
	while(i<=j)
	{
		while(pivot > a[i])i++;
		while(pivot < a[j])j--;
		if(i  <= j)
		{
			int temp=a[i]; 
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	if(left<j)quickSort(a,left,j);
	if(right>i)quickSort(a,i,right);
	
}


	
	

