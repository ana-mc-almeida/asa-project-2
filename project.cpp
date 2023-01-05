#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
typedef pair<int, edge> weightedEdge;

int V, E;
vector<int> parent;
vector<int> ranks;

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

    parent.resize(V + 1);
    ranks.resize(V + 1);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }

    return edges;
}

int findSet(int v)
{
    while (parent[v] != v)
    {
        parent[v] = parent[parent[v]];
        v = parent[v];
    }
    return v;
}

void unionSets(int a, int b)
{
    if (ranks[a] > ranks[b])
        parent[b] = a;
    else
        parent[a] = b;

    if (ranks[a] == ranks[b])
        ranks[b]++;
}

int main()
{
    vector<weightedEdge> edges = create_graph();
    sort(edges.rbegin(), edges.rend());

    int max = 0, a, b, aSet, bSet;

    for (int i = 0; i < E; i++)
    {
        a = edges[i].second.first;
        b = edges[i].second.second;

        aSet = findSet(a);
        bSet = findSet(b);

        if (aSet != bSet)
        {
            max += edges[i].first;
            unionSets(aSet, bSet);
        }
    }

    cout << max << endl;

    return 0;
}