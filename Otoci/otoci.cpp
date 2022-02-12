#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void obrisiOtok(vector<int> adj[], int x,int n) {
   vector<int> a;
	for(int i:adj[x]){
	vector<int>::iterator position = find(adj[i].begin(), adj[i].end(), x);
	if (position != adj[i].end())
    	adj[i].erase(position);
	}
	adj[x]=a;

	return;
}
void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

bool BFS(vector<int> adj[], int src, int dest, int v,
		int pred[], int dist[])
{

	list<int> queue;

	bool visited[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;
				pred[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

				if (adj[u][i] == dest)
					return true;
			}
		}
	}

	return false;
}

void printShortestDistance(vector<int> adj[], int s,
						int dest, int v)
{

	int pred[v], dist[v];

	if (BFS(adj, s, dest, v, pred, dist) == false) {
		cout << "-1\n";
		return;
	}

	vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	cout << dist[dest]<<"\n";

}

int main()
{
	int n,m,q,x,y,z;
	cin>>n>>m;
	vector<int> adj[n];

	for(int i=0;i<m;i++){
		cin>>x>>y;
		add_edge(adj,x-1,y-1);
	}
	cin>>q;

	for(int i=0;i<q;i++){
		cin>>x;
		if(x==1){
			cin>>x;
			obrisiOtok(adj,x-1,n);
		}
		else {
			cin>>x>>y;
			printShortestDistance(adj, x-1, y-1, n);
		}
	}
	return 0;
}

//https://www.geeksforgeeks.org/shortest-path-unweighted-graph/