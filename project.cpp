#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
typedef pair<int, edge> weightedEdge;

int V, E;
vector<int> root;

vector<weightedEdge> create_graph()
{
    int w, u, v;
    vector<weightedEdge> edges;

    // read number of vertices
    scanf("%d", &V);

    // read number of edges
    scanf("%d", &E);

    // read edges weight
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back(make_pair(w, make_pair(u, v)));
    }

    root.resize(V);
    for (int i = 0; i < V; i++)
        root[i] = i;

    return edges;
}

int findSet(int v)
{
    while (root[v] != v)
    {
        root[v] = root[root[v]];
        v = root[v];
    }
    return v;
}

void unionSets(int u, int v)
{
    int uSet = findSet(u);
    int vSet = findSet(v);
    root[uSet] = root[vSet];
}

int main()
{
    vector<weightedEdge> edges = create_graph();
    sort(edges.rbegin(), edges.rend());

    int a, b;
    unsigned long max = 0;

    for (int i = 0; i < E; i++)
    {
        a = edges[i].second.first;
        b = edges[i].second.second;

        if (findSet(a) != findSet(b))
        {
            max += edges[i].first;
            unionSets(a, b);
        }
    }

    cout << max << endl;

    return 0;
}