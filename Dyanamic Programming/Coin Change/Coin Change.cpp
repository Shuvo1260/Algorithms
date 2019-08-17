#include<bits/stdc++.h>

using namespace std;

int coinChange(int coins[], int totalCoin, int amount)
{
    int table[amount+1] = {0};

    table[0] = 1;

    for(int coin = 0; coins[coin] <= amount; coin++)
    {
        for(int index = coins[coin]; index <= amount; index++)
        {
            table[index] += table[index-coins[coin]];
        }
    }
//    for(int coin = 0; coin < totalCoin; coin++)
//    {
//        for(int index = coins[coin]; index <= amount; index++)
//        {
//            table[index] += table[index-coins[coin]];
//        }
//    }

    return table[amount];

}

int main()
{
    int totalCoin = 5;
    int amount;
    int coins[] = {1, 5, 10, 25, 50};

    while(scanf("%d", &amount) == 1)
    {
        int totalWay = coinChange(coins, totalCoin, amount);

        printf("%d\n", totalWay);
    }


    return 0;
}
