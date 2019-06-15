#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

ull mod(ull a, ull m, ull n)
{
    ull result = 1;

    a = a % n;

    while(m > 0)
    {
        if(m & 1)
            result = (result * a) % n;
        m = m >> 1;

        a = (a * a) % n;
    }

    return result;
}

bool miller_test(ull m, ull n)
{
    ull a = 2 + rand() % (n-4);

    // a^m mod n
    ull k = mod(a, m, n);

    if(k == 1 || k == n-1)
        return true;

    while(m != n-1)
    {
        k = (k * k) % n;
        m <<= 1;

        if(k == 1)
            return false;
        if(k == n-1)
            return true;
    }

    return false;

}


bool is_prime(ull n)
{
    if(n == 3 || n == 2)
        return true;
    if((n & 1) == 0 || n <= 1)
        return false;

    ull m = n - 1;

    while((m & 1) == 0)
        m = m >> 1;

    for(int counter = 0; counter < 4; counter++)
    {
        if(!miller_test(m,n))
            return false;
    }
    return true;
}


int main()
{

    ull n;

    while(scanf("%llu", &n) == 1)

    if(is_prime(n))
        printf("Prime!!!\n");
    else
        printf("Not prime\n");


    return 0;
}
