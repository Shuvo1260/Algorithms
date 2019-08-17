#include<bits/stdc++.h>

using namespace std;

char first[1001];
char second[1001];
int counter;
int firstLength;
int secondLength;
int table[1100][1100];

// This function determinate the longest common subsequence
int lcs(int firstLen, int secondLen)
{
    for(int row = 1; row <= firstLen; row++)
    {
        for(int column = 1; column <= secondLen; column++)
        {
            if(first[row-1] == second[column-1])
            {
                table[row][column] = table[row-1][column-1]+1;
            }
            else
            {
                table[row][column] = max(table[row][column-1], table[row-1][column]);
            }
        }
    }

    return table[firstLen][secondLen];
}

int main()
{

    while(printf("Enter first string: "))
    {
        gets(first);
        printf("Enter second string: ");
        gets(second);
        firstLength = strlen(first);
        secondLength = strlen(second);

        int result;

        result = lcs(firstLength,secondLength);
        printf("%d\n", result);


    }
    return 0;
}

