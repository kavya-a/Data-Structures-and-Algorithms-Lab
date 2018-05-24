#include<stdio.h>
#include<conio.h>
#include<math.h>

void sort(int array[], int length)
{
    int i,j;

    for ( i = 0; i < length; i++)
	       {
	        int min = i;
	        for (j = i+1; j < length; j++)
	             if (array[j]< array[min])
	                 min = j;
	        exch(array, i, min);
	       }

}

void exch(int array[], int num1 , int num2)
{
        int swap = array[num1];
	    array[num1] = array[num2];
	    array[num2] = swap;
}



main()
{
    int array[50],length,i,j;

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

    sort(array,length);

    printf("\n\nAfter sorting:  ");
    for(i=0;i<length;i++)
        printf("%d  ",array[i]);

    printf("\n\n");


}
