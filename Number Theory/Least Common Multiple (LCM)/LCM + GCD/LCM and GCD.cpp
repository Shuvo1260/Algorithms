#include<cstdio>

int gcd(int first, int second)
{
    int temp;

    while(second)
    {
        temp = second;
        second = first % second;
        first = temp;
    }
    return first;
}


int main()
{
    int first;
    int second;

    printf("Enter two positive integer number : ");
    scanf("%d%d", &first, &second);

    int gcd_value = gcd(first, second);

    int lcm_value = (first * second) / gcd_value;

    printf("GCD of %d and %d is : %d\n", first, second, gcd_value);
    printf("LCM of %d and %d is : %d\n", first, second, lcm_value);



    return 0;
}
