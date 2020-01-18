
#include<iostream>
#include<cstdio>
#define INF 9999

using namespace std;

void printbool(bool visited[500], int nodeNumber)
{
    for(int index = 0; index < nodeNumber; index++)
    {
        cout << visited[index] << " " ;
    }
    cout << endl;
}

void travellingSalesman(int graph[500][500], int nodeNumber, bool visited[500],
                     int currentNode, int counter, int cost, int &resultCost)
{
    // If we are visiting last node then it return minimum cost of the route
    if(counter == nodeNumber-1 && graph[currentNode][0])
    {
        resultCost = min(resultCost, cost + graph[currentNode][0]);
        return;
    }
    else
    {
        // It creating subset and finding minimum cost
        for(int index = 0; index < nodeNumber; index++)
        {
            if(!visited[index] && graph[currentNode][index])
            {
                visited[index] = true;

                travellingSalesman(graph, nodeNumber, visited, index,
                                    counter + 1, cost + graph[currentNode][index], resultCost);

                visited[index] = false;
            }
        }
    }

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
        graph[to][from] = cost;
    }

    bool visited[nodeNumber];

    for(int index = 0; index < nodeNumber; index++)
        graph[index][index] = 0, visited[index] = false;

    visited[0] = true;

    int resultCost = INT_MAX;

    travellingSalesman(graph, nodeNumber, visited, 0, 0, 0, resultCost);

    cout << "Cost: " << resultCost << endl;

    return 0;
}




