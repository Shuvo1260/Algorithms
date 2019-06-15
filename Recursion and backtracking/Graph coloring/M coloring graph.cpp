#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class m_coloring
{
private:
    int node_number;
    int vertex_number;
    bool graph[100][100];
    int color_node[100];
public:
    m_coloring()
    {
        cout << "Total Node number : ";
        cin >> node_number;

        for(int row = 0; row < node_number; row++)
            for(int column = 0; column < node_number; column++)
                graph[row][column] = false;

        for(int index = 0; index < node_number; index++)
            color_node[index] = 0;


        cout << "Total vertex number : ";
        cin >> vertex_number;

        int from;
        int to;

        for(int index = 0; index < vertex_number; index++)
        {
            cout << endl << "Vertex " << index+1 << " :" << endl;
            cout << "\tFrom : ";
            cin >> from;
            cout << "\t  To : ";
            cin >> to;
            graph[from][to] = true;
            graph[to][from] = true;
        }
    }
    void graph_coloring();
    bool color_graph(int node);
    bool is_safe(int visited_node, int color_index);

};

bool m_coloring :: is_safe(int visited_node, int color_index)
{
    for(int index = 0; index < node_number; index++)
    {
        if(graph[visited_node][index] && color_node[index] == color_index)
            return false;
    }
    return true;
}

bool m_coloring :: color_graph(int visited_node)
{
    if(visited_node == node_number)
        return true;
    else
    {
        for(int color_index = 1; color_index <= 3; color_index++)
        {
            if(is_safe(visited_node,color_index))
            {
                color_node[visited_node] = color_index;

                if(color_graph(visited_node+1))
                    return true;

                color_node[visited_node] = 0;
            }
        }
    }

    return false;
}

void m_coloring :: graph_coloring()
{
    char color[][10] = {"Black", "Green", "Red"};

    color_graph(0);

    cout << endl;
    for(int index = 0; index < node_number; index++)
        cout << "Node : " << index << " Color : " << color[color_node[index]-1] << endl;
}

int main()
{
    m_coloring object;

    object.graph_coloring();

    return 0;
}
