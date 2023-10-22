#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; 

struct Edge {
  int from, to, cost;
};

vector<vector<Edge>> graph;
vector<int> dist;

void dijkstra(int start) {

  dist.assign(graph.size(), INF);
  dist[start] = 0;

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0, start});

  while(!pq.empty()) {
    int cost = pq.top().first;
    int curr = pq.top().second;
    pq.pop();

    if (dist[curr] < cost) continue;

    for(auto& e: graph[curr]) {
      int next = e.to;
      int ncost = cost + e.cost;
      
      if (dist[next] > ncost) {
        dist[next] = ncost;
        pq.push({ncost, next});  
      }
    }
  }
}

int main() {

  int N;
  cin >> N;

  graph.resize(N+1);
  
  for(int i = 0; i < N-1; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back({u, v, 1});
    graph[v].push_back({v, u, 1});
  }

  dijkstra(1);

  // Print shortest path  
  cout << dist[N] << "\n"; 
  vector<int> path;
  int curr = N;
  while(curr != 1) {
    for(auto& e: graph[curr]) {
      if (dist[e.from] == dist[curr] - 1) {
        path.push_back(e.from);
        curr = e.from;
        break;
      }
    }
  }
  path.push_back(1);
  
  for(int i = path.size()-1; i >= 0; i--) {
    cout << path[i] << " ";
  }

  return 0;
}