#include <bits/stdc++.h>
using namespace std;



struct Graph{
    int V;
    vector<int> *adj;
    Graph(int V);
    void addEdge(int v, int w);
    void eraseEdge(int v, int w);
    int degree(int v);
    bool isConected(int v, int w);
    vector<int> getNeighbours(int v);
    int no_components();
    int distance(int v, int w);
    vector<int> shortestPath(int v, int w);

};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::eraseEdge(int v, int w){
    adj[v].erase(remove(adj[v].begin(), adj[v].end(), w), adj[v].end());
    adj[w].erase(remove(adj[w].begin(), adj[w].end(), v), adj[w].end());
}

int Graph::degree(int v){
    return adj[v].size();
}

bool Graph::isConected(int v, int w){
    for(auto i: adj[v]){
        if(i == w){
            return true;
        }
    }
    return false;
}

vector<int> Graph::getNeighbours(int v){
    return adj[v];
}

int Graph::no_components(){
    vector<bool> visited(V, false);
    int count = 0;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            count++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto i: adj[u]){
                    if(!visited[i]){
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }
    return count;
}

int Graph::distance(int v, int w){
    vector<int> dist(V, -1);
    queue<int> q;
    q.push(v);
    dist[v] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto i: adj[u]){
            if(dist[i] == -1){
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }
    return dist[w];
}

vector<int> Graph::shortestPath(int v, int w){
    vector<int> dist(V, -1);
    vector<int> prev(V, -1);
    queue<int> q;
    q.push(v);
    dist[v] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto i: adj[u]){
            if(dist[i] == -1){
                dist[i] = dist[u] + 1;
                prev[i] = u;
                q.push(i);
            }
        }
    }
    vector<int> path;
    for(int at = w; at != -1; at = prev[at]){
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}





int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.eraseEdge(1, 2);
    g.isConected(0, 1) ? cout << "Yes\n" : cout << "No\n";
    cout<<"degree: "<<g.degree(0)<<endl;
    vector<int> asi=g.getNeighbours(0);
    cout<<"neighbours: ";
    for(auto i: asi){
        cout << i << " ";
    }
    cout<<endl;
    cout<<"Components: "<<g.no_components()<<endl;
    cout<<"vzdialenost medzi 0,3: "<<g.distance(0, 3)<<endl;
    vector<int> path = g.shortestPath(0, 3);
    cout<<"path: ";
    for(auto i: path){
        cout << i << " ";
    }
    cout<<endl;
    

    return 0;

}