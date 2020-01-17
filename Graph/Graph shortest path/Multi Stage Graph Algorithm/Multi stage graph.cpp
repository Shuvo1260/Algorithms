#include<iostream>
#include<cstdio>
#define INF 9999

using namespace std;



/// Multi stage graph algorithm find the shortest path of directed graph
/// From source to destination using backward
int multiStageGraph(int graph[500][500], int nodeNumber)
{
    int cost[nodeNumber];

    cost[nodeNumber-1] = 0;
    for(int costIndex = nodeNumber-2; costIndex >= 0; costIndex--)
    {
        cost[costIndex] = INF;

        for(int index = 0; index < nodeNumber; index++)
        {
            if(graph[costIndex][index] != INF)
            {
                cost[costIndex] = min(cost[costIndex],
                                      graph[costIndex][index] + cost[index]);
            }
        }cout << cost[costIndex] << endl;
    }

    return cost[0];
}

int main()
{
    int nodeNumber;
    int graph[500][500];

    /// Input portion
    cout << "Total node number : ";
    cin >> nodeNumber;

    int via_node[nodeNumber];

    for(int row = 0; row < nodeNumber; row++)
        for(int column = 0; column < nodeNumber; column++)
            graph[row][column] = INF;

    int vertexNumber;

    cout << "Total vertex number : ";
    cin >> vertexNumber;

    int from;
    int to;
    int cost;

    for(int counter = 0; counter < vertexNumber; counter++)
    {
        cout << endl << "Vertex " << counter+1 << " : " << endl;
        cout << "\tFrom : ";
        cin >> from;

        cout << "\t  To : ";
        cin >> to;

        cout << "\tCost : ";
        cin >> cost;

        graph[from][to] = cost;
    }


    cost = multiStageGraph(graph, nodeNumber);

    cout << "Cost: " << cost << endl;

    return 0;
}




