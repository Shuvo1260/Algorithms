#include<cstdio>
#define limit 1000001
bool prime[limit];
int prime_number[limit];
void sieve()
{
    for(int index = 0; index < limit; index++)
        prime[index] = true;

    for(int number = 2; number * number <= limit; number++)
    {
        if(prime[number])
        {
            for(int index = number * 2; index <= limit; index += number)
                prime[index] = false;
        }
    }
}
void prime_counter()
{
    int counter = 0;
    prime_number[0] = 0;
    prime_number[1] = 0;

    for(int number = 2; number < limit; number++)
    {
        if(prime[number])
        {
            counter++;
            prime_number[number] = counter;
        }
        else
            prime_number[number] = counter;
    }
}

int main()
{
    sieve();
    prime_counter();

    int test;

    scanf("%d", &test);

    while(test--)
    {
        int first;
        int second;

        scanf("%d%d", &first, &second);


        printf("%d\n", prime_number[second] - prime_number[first-1]);
    }


    return 0;
}
