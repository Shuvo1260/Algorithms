#include<stdio.h>

int fact(int n)
{
    int result = 1;

    for(int number = 1; number <= n; number++)
        result *= number;


    return result;

}

int main()
{
    int n;

    scanf("%d",&n);

    printf("%d\n",fact(n));
}
