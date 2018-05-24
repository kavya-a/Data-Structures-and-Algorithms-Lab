/*number of compares = 1.39nlog(N)
 * 39% more comparisons than merge sort yet its faster cause of less data movement( In merge sort data is moved
 * in and out of the auxillary array which is expensive)
 */

#include<stdio.h>
#include<conio.h>
#include<math.h>


int partition(int array[],int low,int high)
{
    int i,j;

    i=low;
    j=high+1;

    while(1)
		{
			while((array[++i]<array[low]))
				if(i==high)
					break;

			while((array[low]<array[--j]))
				if(j==low)
					break;

			if(i>=j)
				break;

			exch(array,i,j);
		}

		exch(array,low,j);
		return j;

}

void sort(int a[],int low,int high)
{
    int temp;

    if (high <= low) return;
        temp = partition(a, low, high);
        sort(a, low, temp-1);
        sort(a, temp+1, high);
}


void exch(int array[], int num1 , int num2)
{
        int swap = array[num1];
	    array[num1] = array[num2];
	    array[num2] = swap;
}

main()
{
    int array[50],length,i,j,low,high;

    printf("Enter length of the array: ");
    scanf("%d",&length);
    for(i=0;i<length;i++)
    {
        printf("\n\nEnter element:  ");
        scanf("%d",&array[i]);
        printf("\n");
    }

    printf("\n\nBefore sorting:  ");
    for(i=0;i<length;i++)
        printf("%d  ",array[i]);

    low = 0;
    high = length-1;

    sort(array,low,high);

    printf("\n\nAfter sorting:  ");
    for(i=0;i<length;i++)
        printf("%d  ",array[i]);

    printf("\n\n");


}
