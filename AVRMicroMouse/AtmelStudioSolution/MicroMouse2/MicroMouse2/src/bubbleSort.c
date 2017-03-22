/************************************************************************/
/*					C Bubble sort Implementation						*/
/*							Sourced From:								*/
/*			http://www.zentut.com/c-tutorial/c-bubble-sort/             */
/************************************************************************/

#include "bubblesort.h"

#define SIZE 10



void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void buble_sort(int a[], int size)
{
	int i,j;
	for(i=0; i<(size-1); i++)
	{
		for(j=0; j<(size-(i+1)); j++)
		{
			{
				if(a[j] > a[j+1])
				swap(&a[j],&a[j+1]);
			}

		}
	}
}

// void display(int a[],const int size)
// {
// 	int i;
// 	for(i = 0; i < size; i++)
// 	printf("%d ",a[i]);
//
// 	printf("\n");
// }