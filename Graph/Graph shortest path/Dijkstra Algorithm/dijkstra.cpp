#include<iostream>
#include<cstdio>
#include<queue>
#define INF 99999


using namespace std;


/// Output function
void print_solution(int via_node[], int visited_cost[], int node_number)
{
    int via_path[node_number][node_number];
    for(int row = 0; row < node_number; row++)
        for(int column = 0; column < node_number; column++)
            via_path[row][column] = -1;

    cout << endl << "Node\tVisited path\t\tCost" << endl;

    for(int index = 0; index < node_number; index++)
    {
        cout << index << "\t";
        if(via_node[index] == INF)
            cout << "Source\t";
        else if(via_node[index] == -1)
            cout << "None,leave your hope";
        else
        {
            int node = via_node[index];
            int path_index = 0;
            while(node != INF)
            {
                via_path[index][path_index++] = node;
                node = via_node[node];
            }
            for(int path = path_index-1; path >= 0; path--)
            {
                cout << via_path[index][path];
                if(path == 0)
                    cout << "\t";
                else
                    cout << ", ";
            }
        }
        if(visited_cost[index] == INF)
            cout << "\t" << "Money can't do everything!!" << endl;
         else
            cout << "\t\t" << visited_cost[index] << endl;
    }
}
/** I use above print_solution code for a organized output if you think this is so much
hard then you can use below code **/

//void print_solution(int via_node[], int visited_cost[], int node_number)
//{
//    cout << endl << "Node\tVia\tCost" << endl;
//
//    for(int index = 0; index < node_number; index++)
//        cout << index << "\t" << via_node[index] << "\t" << visited_cost[index] << endl;
//}

/// Dijkstra find the shortest path of directed graph
void dijkstra(int graph[500][500], int node_number, int source, int visited_cost[], bool visited_node[], int via_node[])
{
    queue <int> my_queue;

    visited_cost[source] = 0;
    via_node[source] = INF;
    my_queue.push(source);
    visited_node[source] = true;

    int vertex;

    while(!my_queue.empty())
    {
        vertex = my_queue.front();
        my_queue.pop();

        /// Visiting all the nodes which connected with the current node
        for(int index = 0; index < node_number; index++)
        {
            /// Finding the lowest cost node from the current node
            if(graph[vertex][index] != INF && !visited_node[index])
            {
                my_queue.push(index);
                visited_node[index] = true;
            }
            if(graph[vertex][index] != INF)
            {
                if(visited_cost[index]>visited_cost[vertex]+graph[vertex][index])
                {
                    visited_cost[index] = visited_cost[vertex]+graph[vertex][index];
                    via_node[index] = vertex;
                }
            }
        }
    }
    print_solution(via_node, visited_cost, node_number);
}

int main()
{
    int node_number;
    int graph[500][500];
    int visited_cost[500];
    bool visited_node[500];

    /// Input portion
    cout << "Total node number : ";
    cin >> node_number;

    int via_node[node_number];

    for(int row = 0; row < node_number; row++)
        for(int column = 0; column < node_number; column++)
            graph[row][column] = INF;
    for(int index = 0; index < node_number; index++)
        via_node[index] = -1,visited_cost[index] = INF, visited_node[index] = false;

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
    }

    int source;

    cout << "Source node : ";
    cin >> source;

    dijkstra(graph, node_number, source, visited_cost, visited_node, via_node);

    return 0;
}
