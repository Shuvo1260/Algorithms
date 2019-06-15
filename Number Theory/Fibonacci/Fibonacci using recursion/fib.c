#include<stdio.h>
long long int fib(long long int num,long long int first,long long int second)
{
    long long int fibonacci=0,n=0;
    if(num==n)
    {
        fibonacci=first+second;
        first=second;
        second=fibonacci;
        printf("%lld\n",fibonacci);
        fib(n+1,first,second);

        return fibonacci;

    }
    //printf("The fibonacci is %lld\n",fibonacci);
   // exit(0);
}

int main()
{
    long long int number,fibonacci;
    printf("Enter the place of fibonacci\n");
    scanf("%lld",&number);
    if(number==1)
        printf("0\n");
    else if(number==2)
        printf("1\n");
    else
    {
         fibonacci=fib(number,0,1);
         //printf("The fibonacci is %lld\n",fibonacci);
         exit(0);
    }

    return 0;
}
