#include<iostream>
#include<cstdio>
#define INF 99999

using namespace std;

void prims(int graph[500][500], int node_number, bool visited_node[])
{


    visited_node[0] = true;
    int total_cost = 0;

    cout << endl << "From\t->   To\t  Cost" << endl;

    for(int counter = 0; counter < node_number-1; counter++)
    {
        int minimum = INF;
        int from = 0;
        int to = 0;

        for(int row = 0; row < node_number; row++)
        {
            if(visited_node[row])
            {
                for(int column = 0; column < node_number; column++)
                {
                    if(!visited_node[column] && graph[row][column] != INF)
                    {
                        if(graph[row][column] < minimum)
                        {
                            minimum = graph[row][column];
                            from = row;
                            to = column;
                        }
                    }
                }
            }
        }
        cout << "  " << from << "\t->   " << to << "\t  " << minimum << endl;
        visited_node[to] = true;
        total_cost += minimum;
    }
    cout << endl << "Total cost : " << total_cost << endl;
}

int main()
{
    int node_number;
    int graph[500][500];
    bool visited_node[500];

    cout << "Total node number : ";
    cin >> node_number;

    for(int row = 0; row < node_number; row++)
        for(int column = 0; column < node_number; column++)
            graph[row][column] = INF;

    for(int index = 0; index < node_number; index++)
        visited_node[index] = false;

    int vertex_number;

    cout << "Total vertex number : ";
    cin >> vertex_number;

    int from;
    int to;
    int cost;

    for(int counter = 0; counter < vertex_number; counter++)
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


    prims(graph, node_number, visited_node);

    return 0;
}
