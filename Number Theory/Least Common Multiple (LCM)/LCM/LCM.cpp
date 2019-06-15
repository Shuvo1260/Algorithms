#include<cstdio>

int lcm(int first, int second)
{
    int minimum;
    if(first < second)
        minimum = first;
    else
        minimum = second;

    while(true)
    {
        if(minimum % first == 0 && minimum % second == 0)
            return minimum;
        else
            minimum++;
    }
}

int main()
{
    int first;
    int second;

    printf("Enter two positive integer number : ");
    scanf("%d%d", &first, &second);

    printf("Least Common Multiple of %d and %d is : %d\n", first, second, lcm(first,second));

    return 0;
}
