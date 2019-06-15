#include<cstdio>

#define limit 190000000
bool prime[limit];
void sieve()
{
    for(int index = 0; index < limit; index++)
        prime[index] = true;

    for(int number = 4; number <= limit; number+=2)
        prime[number] = false;

    for(int number = 3; number * number <= limit; number+=2)
    {
        if(prime[number])
        {
            for(int index = number * number; index <= limit; index += number * 2)
                prime[index] = false;
        }
    }
}

int main()
{
    sieve();

    for(int index = 2; index < 50; index++)
    {
        if(prime[index])
            printf("%d ", index);
    }
    printf("\n");
}
