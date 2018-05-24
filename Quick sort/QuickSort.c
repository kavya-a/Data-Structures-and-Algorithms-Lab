//Quick sort using Dijkstra 3 way partitioning algorithm


#include<stdio.h>
#include<conio.h>
#include<math.h>

void sort(int array[], int lo, int hi)
{

    int lt,gt,i,temp,cmp;

    if (hi <= lo) return;

	lt = lo;
	gt = hi;
	temp= array[lo];
	i = lo;

	while (i <= gt)
	     {

 	       if(array[i]<temp)
              cmp = -1;
           else
              cmp = 1;

 	       if (cmp < 0)
 	    	   exch(array, lt++, i++);

 	       else if (cmp > 0)
	    	   exch(array, i, gt--);

	       else i++;
	     }

	sort(array, lo, lt - 1);
	sort(array, gt + 1, hi);
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
