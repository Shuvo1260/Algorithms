#include<bits/stdc++.h>

using namespace std;


/// This function determines how much way we have to
/// make the amount using given coins (1, 5, 10, 25, 50)

int coinChange(int coins[], int totalCoin, int amount)
{
    /// Initializing the whole table with value 0
    int table[amount+1] = {0};

    // First value set with 1
    table[0] = 1;

    for(int coin = 0; coin < totalCoin; coin++)
    {
        for(int index = coins[coin]; index <= amount; index++)
        {
            table[index] += table[index-coins[coin]];
        }
    }

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
