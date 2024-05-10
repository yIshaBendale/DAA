//topological ordering

#include <iostream>
using namespace std;

void cal_indegree(int matrix[20][20], int v_indegree[], int n)
{
    // Initialize in-degree of each vertex to 0
    for (int i = 0; i < n; ++i)
    {
        v_indegree[i] = 0;
    }

    // Iterate through the graph's adjacency matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 1)
            {
                v_indegree[j]++;
            }
        }
    }
}

void topological_sort(int matrix[20][20], int n)
{
    int v_indegree[n];
    cal_indegree(matrix, v_indegree, n);

    // array to store vertices with in-degree 0
    int zero_indegree[n];
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v_indegree[i] == 0)
        {
            zero_indegree[count++] = i;
        }
    }

    // Process vertices with in-degree 0
    int sorted_vertices[n];
    int sorted_count = 0;
    for (int i = 0; i < count; ++i)
    {
        int u = zero_indegree[i];
        sorted_vertices[sorted_count++] = u;

        // Reduce in-degree of adjacent vertices
        for (int v = 0; v < n; ++v)
        {
            if (matrix[u][v] == 1)
            {
                v_indegree[v]--;
                if (v_indegree[v] == 0)
                {
                    zero_indegree[count++] = v;
                }
            }
        }
    }

    // Print the sorted vertices
    for (int i = 0; i < sorted_count; ++i)
    {
        cout << sorted_vertices[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    // graph
    int matrix[20][20];
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    // in-degree 
    int v_indegree[n];
    cal_indegree(matrix, v_indegree, n);

    // Print the in-degree of each vertex
    for (int i = 0; i < n; ++i)
    {
        cout << "In-degree of vertex " << i << ": " << v_indegree[i] << endl;
    }

    //topological sort
    cout << "Topological Sort: ";
    topological_sort(matrix, n);

    return 0;
}

// approach: kahn's algorithm (dfs)
// TC: O(V+E)
// SC: O(V)