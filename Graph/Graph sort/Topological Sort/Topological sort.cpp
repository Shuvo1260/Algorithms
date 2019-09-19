#include<bits/stdc++.h>

using namespace std;


vector <int> nodes[101];
int visited[101];
stack <int> resultStack;

/// Output portion
void printResult()
{
    while(!resultStack.empty())
    {

        cout << resultStack.top()+1 << " ";
        resultStack.pop();
    }
    cout << endl;
}


/// Checking the adjacent nodes of current nodes
void topologicalSortUtil(int node)
{
    /// Current node marked as visited node
    visited[node] = true;

    int len = nodes[node].size();

    for(int index = 0; index < len; index++)
    {
        int adjNode = nodes[node][index];
        if(!visited[adjNode])
            topologicalSortUtil(adjNode);
    }

    /// If the current node doesn't left have any adjacent node
    /// then push in stack
    resultStack.push(node);
}


void topologicalSort(int n)
{
    /// Initializing all nodes as unvisited node
    for(int index = 0; index < n; index++)
        visited[index] = false;


    /// Checking each nodes
    for(int node = 0; node < n; node++)
    {
        if(!visited[node])
            topologicalSortUtil(node);
    }

    printResult();
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;


    int queryNumber;

    cout << "Number of query: ";
    cin >> queryNumber;
    int from, to;
    for(int counter = 0; counter < queryNumber; counter++)
    {
        cin >> from >> to;
        nodes[from-1].push_back(to-1);
    }

    topologicalSort(n);
    for(int index = 0; index < n; index++)
    {
        nodes[index].clear();
    }

//    for(int row = 0; row < n; row++)
//    {
//        for(int column = 0; column < nodes[row].size(); column++)
//        {
//            cout << nodes[row][column] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
