#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int
int x;
void Q(int z)
{
   
    z += x;
    printf("%d\t", z);
}
void P(int *y)
{
    int x = *y + 2;
    Q(x);
    *y = x - 1;
    printf("%d\t", x);
}
int f(int x,int *py,int **ppx)
{
    int y, z;
    **ppx += 1;
    z = **ppx;
    *py += 2;
    y = *py;
    x+=3;
    return x + y + z;

}

void main()
{
    int c=4,*b,**a;
    b=&c,a=&b;

    printf("%d",f(c,b,a));
}
