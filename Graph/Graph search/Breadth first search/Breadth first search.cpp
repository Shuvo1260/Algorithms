#include<iostream>
#include<cstdio>
using namespace std;

#define Max 999


/// Queue class
class Queue
{
    int Front;
    int Rear;
    int List[99999];
public:
    Queue()
    {
        Front = 0;
        Rear = 0;
    }
    void push(int item)
    {
        List[Rear++] = item;
    }
    int pop()
    {
        int item;
        item = List[Front++];
        return item;
    }
    bool Empty()
    {
        if(Front == Rear)
            return false;
        else
            return true;

    }
};


/// Display the outputs
void display(int node_list[], int Size)
{
    cout << "Visited node sequence : ";
    for(int index = 0; index < Size; index++)
    {
        cout << node_list[index] << " ";
    }
    cout << endl;
}


/// Breadth first search function
void bfs(bool adjacent_list[Max][Max], int node_number, int started_node)
{
    /// Initializing all visited array values as non visited
    bool visited[node_number];
    for(int index = 0; index < node_number; index++)
        visited[index] = false;

    int node_list[node_number];
    int node_list_index = 0;
    int vertex;
    Queue queue_list;

    /// First node picked up
    queue_list.push(started_node);
    visited[started_node] = true;

    /// The loop won't stop until all nodes are visited
    while(queue_list.Empty())
    {
        vertex = queue_list.pop();
        node_list[node_list_index++] = vertex;

        for(int index = 0; index < node_number; index++)
        {
            if(adjacent_list[vertex][index] && !visited[index])
            {
                /// If new node found that haven't visited yet
                /// that will be pushed into queue
                visited[index] = true;
                queue_list.push(index);
            }

        }
    }
    display(node_list, node_list_index);
}

int main()
{
    int node_number;

    /// Input portion
    cout << "Total node number : ";
    cin >> node_number;

    bool adjacent_list[Max][Max];

    for(int row = 0; row < node_number; row++)
        for(int column = 0; column < node_number; column++)
            adjacent_list[row][column] = false;

    int query_number;

    cout << "Enter query number : ";
    cin >> query_number;

    int first_node;
    int second_node;

    for(int counter = 0; counter < query_number; counter++)
    {
        cout << endl << "Query (" << counter + 1 << ") :" << endl;
        cout << "From : ";
        cin >> first_node;
        cout << "To : ";
        cin >> second_node;
        adjacent_list[first_node][second_node] = true;
        adjacent_list[second_node][first_node] = true;
    }

    int started_node;
    cout << "Start visiting from : ";
    cin >> started_node;

    bfs(adjacent_list, node_number, started_node);

    return 0;
}
