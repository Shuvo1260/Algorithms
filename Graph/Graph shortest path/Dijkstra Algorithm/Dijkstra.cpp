#include<iostream>
#include<cstdio>


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
    // Initializing the variables
    bool visitedNode[nodeNumber] = {false};
    int visitedCost[nodeNumber];

    // Visited cost marking as max
    for(int index = 0; index < nodeNumber ; index++)
        visitedCost[index] = INT_MAX;

    // source node cost is zero
    visitedCost[source] = 0;

    for(int currentNode = 0; currentNode < nodeNumber-1; currentNode++)
    {
        int minCostedNode = INT_MAX;
        int minNode = -1;

        // Finding least cost node that hasn't visited yet
        for(int tempNode = 0; tempNode < nodeNumber; tempNode++)
        {
            if(!visitedNode[tempNode] && visitedCost[tempNode] < minCostedNode)
            {
                minNode = tempNode;
                minCostedNode = visitedCost[tempNode];
            }

        }
        // Marking the minNode as visited
        visitedNode[minNode] = true;

        /** Processing adjacent node of minNode and
         determining least cost for the node**/
        for(int adjacentNode = 0; adjacentNode < nodeNumber; adjacentNode++)
        {
            if(!visitedNode[adjacentNode] &&
                    graph[minNode][adjacentNode] != INT_MAX &&
                    visitedCost[minNode] != INT_MAX &&
                    visitedCost[minNode] + graph[minNode][adjacentNode] < visitedCost[adjacentNode])
                visitedCost[adjacentNode] = visitedCost[minNode] + graph[minNode][adjacentNode];
        }
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
            graph[row][column] = INT_MAX;
    for(int index = 0; index < nodeNumber; index++)
        via_node[index] = -1,visitedCost[index] = INT_MAX, visited_node[index] = false;

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

