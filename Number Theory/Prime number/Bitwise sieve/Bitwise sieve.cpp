#include<cstdio>
#include<cmath>
#define Max 190000000

int prime[(Max/32)+2];

bool check(int n, int pos)
{
    return (bool) (n & (1 << pos));
}

int Set(int n, int pos)
{
    return n = n | (1 << pos);
}

void sieve()
{
    int len = sqrt(Max);

    for(int i = 2; i <= Max; i+=2)
        prime[i>>5] = Set(prime[i>>5], i&31);

    for(int i = 3; i <= len; i += 2)
    {
        if(check(prime[i>>5], i&31) == 0)
        {
            for(int j = i * i; j <= Max; j += (i << 1))
            {
                prime[j>>5] = Set(prime[j>>5], j&31);
            }
        }
    }
}


int main()
{
    sieve();

    int value ;
    int index = 199;

//    while(scanf("%d", &value) == 1)
    {

//        for(int index = 3; index < 50; index++)
        {
            if(check(prime[index>>5], index &31) == 0)
                printf("%d ", index);
        }
        printf("\n");
    }



    return 0;
}
