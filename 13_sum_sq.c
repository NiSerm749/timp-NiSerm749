#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int x;
    int i;
    double sum = 0;
    (void)scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        (void)scanf("%d", &x);
        sum += (pow((double)x, (double)2));
    }
    printf("%lf", sum);
    return 0;
}