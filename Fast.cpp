#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int*,int,int);
void print_mass(int*,int);

void main()
{
	int num,bottom = 0,top;
	int *mass;
	srand(time(0));

	printf("Input number of elements: ");
	scanf("%d", &num);
	top = num-1;

	mass = new int [num];
	printf("\nRandom array whith %d elements:\n", num);
	for (int i = 0; i < num; i++)					/// create random values
	{
		mass[i] = rand() % 50;
		printf( "| %d\t" , mass[i] );
	}
	quick_sort(mass,bottom,top);					/// call sorting function
	printf("\n\nResult:");
	print_mass(mass,num);							/// call printing function
	delete mass;
	getch();
}



*/
void quick_sort(int *mass, int bottom, int top)
{
	int i = bottom;
	int j = top;
	int mid;										/// middle of array
	int temp;
	mid = mass[(bottom + top)/2];
	do 
	{
		while(mass[i] < mid)
			i++; 
		while(mass[j] > mid)
			j--;
		if(i <= j)
		{           
			temp = mass[i];
			mass[i] = mass[j];
			mass[j] = temp;
			i++;
			j--;
		}
	} 
	while(i < j);
	if (bottom < j) 
		quick_sort(mass,bottom,j);
	 if (i < top) 
		quick_sort(mass,i,top);
}

void print_mass(int *mass, int num)
{
	printf("\n");
	for( int i = 0; i < num; i++ )
	{
		printf( "|%d \t" , mass[i] );
	}
}