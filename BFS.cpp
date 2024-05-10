#include <iostream>
using namespace std;

int n = 7;
int queue[7], front = -1, rear = -1;
int a[7][7] = {{0, 0, 0, 0, 0, 0, 0},
               {0, 0, 1, 1, 0, 0, 0},
               {0, 1, 0, 0, 1, 0, 0},
               {0, 1, 0, 0, 1, 0, 0},
               {0, 0, 1, 1, 0, 1, 1},
               {0, 0, 0, 0, 1, 0, 0},
               {0, 0, 0, 0, 1, 0, 0}};

void enqueue(int val)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}

int dequeue()
{
    int u = queue[front];
    front++;
    return u;
}

int isEmpty()
{
    if (front > rear || front == -1)
    {
        return 0;
    }

    return 1;
}

void BFS(int s)
{
    int q;
    cout << s << " ";
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    visited[s] = 1;
    enqueue(s);

    while (isEmpty())
    {
        q = dequeue();
        for (int i = 0; i < n; i++)
        {
            if (a[q][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                cout << i << " ";
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    cout << "BFS : ";
    BFS(4);
    return 0;
}