#include<cstdio>

#define MOD 1000000007

long long int fibonacci(long long int number)
{
    if(number < 2)
        return number;
    else
    {
        long long int first = 0;
        long long int second = 1;
        long long int fib_number;

        for(int counter = 1; counter < number; counter++)
        {
            fib_number = (first + second) % MOD;
            first = second;
            second = fib_number;
        }
        return fib_number;
    }
}

int main()
{
    long long int n;
    scanf("%lld", &n);

    printf("%lld\n", fibonacci(n));
    return 0;
}
