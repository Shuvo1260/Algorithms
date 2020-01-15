#include<iostream>
#include<cstdio>
#define INF 9999

using namespace std;


void printSolution(int graph[500][500], int nodeNumber)
{
    cout << endl << "New graph:" << endl;
    for(int row = 0; row < nodeNumber; row++)
    {
        for(int column = 0; column < nodeNumber; column++)
        {
            if(graph[row][column] == INF)
                printf("INF ");
            else
                printf("%d ", graph[row][column]);
        }
        cout << endl;
    }
}

/// Warshall find the shortest path of directed graph
void Warshall(int graph[500][500], int nodeNumber)
{
    for(int intermediateVertex = 0; intermediateVertex < nodeNumber; intermediateVertex++)
    {
        for(int row = 0; row < nodeNumber; row++)
        {
            for(int column = 0; column < nodeNumber; column++)
            {
                if(graph[row][column] > graph[row][intermediateVertex] + graph[intermediateVertex][column])
                    graph[row][column] = graph[row][intermediateVertex] + graph[intermediateVertex][column];
            }
        }
    }

    printSolution(graph, nodeNumber);
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


    Warshall(graph, nodeNumber);

    return 0;
}



