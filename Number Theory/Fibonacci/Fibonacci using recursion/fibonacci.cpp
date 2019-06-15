#include<cstdio>

long long int fibonacci(long long int number)
{
    if(number <= 2)
        return 1;
    else
        return fibonacci(number -1) + fibonacci(number -2);
}

int main()
{
    long long int number;

    while(scanf("%lld", &number))
        printf("%lld\n", fibonacci(number));

    return 0;
}
