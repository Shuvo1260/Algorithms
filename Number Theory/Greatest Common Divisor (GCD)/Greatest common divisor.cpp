#include<cstdio>

int gcd(int a, int b)
{
    if(a%b == 0)
        return b;
    else
        return gcd(b, a%b);
}

int main()
{
    int first;
    int second;

    printf("Enter two positive integer number : ");
    scanf("%d%d", &first, &second);

    printf("GCD of %d and %d is : %d\n", first, second, gcd(first, second));



    return 0;
}
