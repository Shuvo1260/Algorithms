#include<iostream>
#include<cstdio>
#define INF 9999

using namespace std;

class tsp
{
private:
    int city_number;
    int path;
    int city[100][100];
    bool visited_city[100];
    int cost;
    int visited_cost[100];

public:

    /// Constructor, used to takes input
    tsp()
    {
        cost = 0;
        cout << "Total city number : ";
        cin >> city_number;

        for(int row = 0; row < city_number; row++)
            for(int column = 0; column < city_number; column++)
                city[row][column] = 0;

        for(int index = 0; index < city_number; index++)
            visited_city[index] = false, visited_cost[index] = 0;

        cout << "Total path number : ";
        cin >> path;

        int from;
        int to;
        int cost;

        for(int counter = 0; counter < path; counter++)
        {
            cout << endl << "Path " << counter+1 << " : " << endl;
            cout << "\tFrom : ";
            cin >> from;

            cout << "\t  To : ";
            cin >> to;

            cout << "\tCost : ";
            cin >> cost;

            city[from][to] = cost;
            city[to][from] = cost;
        }
    }

    int least_path(int present_city);
    void minimum_cost(int present_city);
};

/// This function determines the least path for traveling salesman

int tsp :: least_path(int present_city)
{
    int minimum = INF;
    int near_city = INF;
    int temp_cost;

    for(int index = 0; index < city_number; index++)
    {
        if(city[present_city][index] != 0 && !visited_city[index])
        {
            if(minimum > city[present_city][index] + visited_cost[present_city])
            {
                minimum = city[present_city][index] + visited_cost[present_city];
                near_city = index;
                temp_cost = city[present_city][index];
            }
        }
    }

    if(minimum != INF)
        cost += temp_cost;

    return near_city;
}

/// This function  determines the minimum cost with nearest city
void tsp :: minimum_cost(int present_city)
{
    visited_city[present_city] = true;
    int near_city = least_path(present_city);

    cout << present_city << " --> ";

    if(near_city == INF)
    {
        near_city = 0;

        cout << near_city << endl ;
        cost += city[present_city][near_city] ;
        cout << "Minimum cost = " << cost << endl;
        return;
    }

    visited_cost[near_city] = cost;

    minimum_cost(near_city);

}

int main()
{
    tsp salesman;
    cout << endl;

    salesman.minimum_cost(0);

    return 0;
}
