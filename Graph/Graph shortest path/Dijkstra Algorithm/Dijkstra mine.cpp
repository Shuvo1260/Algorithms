#include<iostream>
#include<cstdio>
#include<queue>


using namespace std;


void printSolution(int visitedCost[], int nodeNumber)
{
    cout << endl << "Node\tCost" << endl;

    for(int index = 0; index < nodeNumber; index++)
        cout << index << "\t" << visitedCost[index] << endl;
}

/// Dijkstra find the shortest path of directed graph
void dijkstra(int graph[500][500], int nodeNumber, int source)
{
    queue<int> visitedQueue;
    bool visitedNode[nodeNumber] = {false};
    int visitedCost[nodeNumber];


    for(int index = 0; index < nodeNumber ; index++)
        visitedCost[index] = INT_MAX;
    visitedCost[source] = 0;

    visitedQueue.push(source);

    while(!visitedQueue.empty())
    {
        int pivotNode = visitedQueue.front();
        visitedQueue.pop();

        for(int node = 0; node < nodeNumber; node++)
        {
            if(!visitedNode[node] && graph[pivotNode][node])
            {cout << node << " " ;
                visitedQueue.push(node);
                visitedNode[node] = true;
            }

            if(graph[pivotNode][node] && visitedCost[node] > visitedCost[pivotNode] + graph[pivotNode][node])
                visitedCost[node] = visitedCost[pivotNode] + graph[pivotNode][node];
        }cout << endl;
    }

    printSolution(visitedCost, nodeNumber);
}

int main()
{
    int nodeNumber;
    int graph[500][500];
    int visitedCost[500];
    bool visited_node[500];

    /// Input portion
    cout << "Total node number : ";
    cin >> nodeNumber;

    int via_node[nodeNumber];

    for(int row = 0; row < nodeNumber; row++)
        for(int column = 0; column < nodeNumber; column++)
            graph[row][column] = 0;

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

    int source;

    cout << "Source node : ";
    cin >> source;

    dijkstra(graph, nodeNumber, source);

    return 0;
}


