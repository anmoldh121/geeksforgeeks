#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
    public:
        Graph(int v);
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    bool *visited = new bool[V];
    for (int i=0; i<V; i++) {
        visited[i] = false;
    }

    queue<int> q;
    q.push(s);
    visited[s] = true;

    list<int>::iterator i;

    while(!q.empty()) {
        s = q.front();
        cout << s << " ";
        q.pop();

        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main() {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);
    return 0;
}