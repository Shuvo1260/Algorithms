#include<cstdio>

// Function of Big Mod. It determines the big mod of a number
long long int big_mod(long long int base, long long int power, long long int mod)
{

    if(power == 0)
        return 1;

    // If the number is even
    else if(power % 2 == 0)
    {
        long long int value = (big_mod(base, power/2, mod)%mod);
        return ((value * value) % mod);
    }
    // If the number is odd
    else if(power % 2 == 1)
    {
        long long int first = base % mod;
        long long int second = (big_mod(base, power-1, mod)%mod);
        return ((first * second) % mod);
    }
}

int main()
{
    long long int base;
    long long int power;
    long long int mod;

    printf("Base = ");
    scanf("%lld", &base);
    printf("Power = ");
    scanf("%lld", &power);
    printf("Mod = ");
    scanf("%lld", &mod);

    printf("Result = %lld\n", big_mod(base, power, mod));

    return 0;
}
