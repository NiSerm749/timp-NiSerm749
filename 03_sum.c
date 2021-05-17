#include <stdio.h>
int main()
{
    int n;
    int x;
    int i;
    int sum = 0;
    (void)scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        (void)scanf("%d", &x);
        sum += x;
    }
    printf("%d", sum);
    return 0;
}
