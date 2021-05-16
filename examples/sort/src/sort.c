// Autor: Luís Fernando Becker Santos
// Email: luis.s@edu.pucrs.br

#include "sort.h"

static void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void sort(int *v, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (v[j] > v[j+1])
            swap(&v[j], &v[j+1]);
}
