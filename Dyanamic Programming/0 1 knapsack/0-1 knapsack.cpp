#include<iostream>
#include<cstdio>

using namespace std;

/// Knapsack determines the most profitable value of given values
void knapsack(int weight[], int profit[], int table[500][500], int number, int sack_weight)
{
    /// Setting value 0 at table first row
    for(int column = 0; column < sack_weight; column++)
        table[0][column] = 0;

    for(int row = 1; row <= number ; row++)
    {
        for(int column = 0; column <= sack_weight; column++)
        {
            if(weight[row-1] <= column)
                table[row][column] = max(table[row-1][column], profit[row-1] + table[row-1][column - weight[row-1]]);
            else
                table[row][column] = table[row-1][column];
        }
    }
}

int main()
{

    int sack_weight;
    int number;

    /// Input portion
    cout << "Total item number : ";
    cin >> number;
    cout << "Total Sack weight : ";
    cin >> sack_weight;

    int weight[number+1];
    int profit[number+1];
    int table[500][500];

    for(int index = 0; index < number ; index++)
    {
        cout << endl << "Product " << index + 1 << " :" << endl;
        cout << "\tWeight : ";
        cin >> weight[index];
        cout << "\tProfit : ";
        cin >> profit[index];
    }

    knapsack(weight, profit, table, number, sack_weight);

    /// Output portion
    cout << endl << "Product\\Weight" << endl;

    for(int row = 0; row <= number; row++)
    {
        cout << "\t" << row << " | ";
        for(int column = 0; column <= sack_weight; column++)
        {
            cout << "\t" << table[row][column];
        }
        cout << endl;
    }

    cout << endl << "Total Profit : " << table[number][sack_weight] << endl;

    return 0;
}
