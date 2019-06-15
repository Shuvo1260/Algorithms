#include<iostream>
#include<cstdio>

using namespace std;

void knapsack(double weight[], double profit[], double Ratio[], double solution[], int number, double sack_weight)
{
    double temp;
    int sequence[number];
    int sequence_temp;

    for(int index = 0; index < number; index++)
        sequence[index] = index;

    for(int row = 0; row < number ; row++)
    {
        for(int column = 0; column < number-row-1; column++)
        {
            if(Ratio[column] < Ratio[column+1])
            {
                temp = Ratio[column];
                Ratio[column] = Ratio[column+1];
                Ratio[column+1] = temp;

                temp = weight[column];
                weight[column] = weight[column+1];
                weight[column+1] = temp;

                temp = profit[column];
                profit[column] = profit[column+1];
                profit[column+1] = temp;

                sequence_temp = sequence[column];
                sequence[column] = sequence[column+1];
                sequence[column+1] = sequence_temp;
            }
        }
    }

    double temp_weight = sack_weight;
    int index;
    double total_profit = 0.0;

    for(index = 0; index < number; index++)
    {
        if(weight[index] > temp_weight)
            break;
        else
        {
            solution[index] = 1.0;
            temp_weight -= weight[index];
            total_profit += profit[index];
        }
    }
    if(index < number)
    {
        solution[index] = temp_weight/weight[index];
        total_profit += profit[index] * solution[index];
    }

    for(int row = 0; row < number ; row++)
    {
        for(int column = 0; column < number-row-1; column++)
        {
            if(sequence[column] > sequence[column+1])
            {
                sequence_temp = sequence[column];
                sequence[column] = sequence[column+1];
                sequence[column+1] = sequence_temp;

                temp = solution[column];
                solution[column] = solution[column+1];
                solution[column+1] = temp;
            }
        }
    }

    cout << endl << "Optimal solution is :" << endl;;
    cout << "solution ( ";

    for(int index = 0; index < number ; index++)
    {
        cout << solution[index];
        if(index < number-1)
            cout << ",";
        cout << " ";
    }

    cout << ")\tUsed weight : " << sack_weight-temp_weight << "\t";

    cout << "Total Profit : " << total_profit << endl;
}

int main()
{

    double sack_weight;
    int number;

    cout << "Total item number : ";
    cin >> number;
    cout << "Total Sack weight : ";
    cin >> sack_weight;

    double weight[number];
    double profit[number];

    for(int index = 0; index < number ; index++)
    {
        cout << endl << "Product " << index + 1 << " :" << endl;
        cout << "\tWeight : ";
        cin >> weight[index];
        cout << "\tProfit : ";
        cin >> profit[index];
    }

    double Ratio[number];

    for(int index = 0; index < number; index++)
        Ratio[index] = profit[index]/weight[index];
    double solution[number];

    for(int index = 0; index < number; index++)
        solution[index] = 0.0;


    knapsack(weight, profit, Ratio, solution, number, sack_weight);





    return 0;
}

