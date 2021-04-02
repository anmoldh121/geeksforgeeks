#include <iostream>
#include <map>
#include <list>

using namespace std;

class Graph {
    public:
        map<int, bool> visited;
        map< int, list<int> > adj;
        void addEdge(int v, int w);
        void DFS(int s);
};

void Graph::addEdge(int v, int w) {
    this->adj[v].push_back(w);
}

void Graph::DFS(int s) {
    this->visited[s] = true;
    cout << s << " ";
    list<int>::iterator i;

    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}

int main() {

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    g.DFS(2);

}