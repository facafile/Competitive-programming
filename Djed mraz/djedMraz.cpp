#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> iPair;

// To add an edge
void addEdge(vector<pair<long long, long long>> adj[], long long u,
             long long v, long long wt)
{
   adj[u].push_back(make_pair(v, wt));
   adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<pair<long long, long long>> adj[], long long V, long long src)
{
   long long rj = 0;
   vector<long long> lista;
   priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

   vector<long long> dist(V, LLONG_MAX);

   pq.push(make_pair(0, src));
   dist[src] = 0;

   while (!pq.empty())
   {
      long long u = pq.top().second;
      pq.pop();

      for (auto x : adj[u])
      {

         long long v = x.first;
         long long weight = x.second;

         if (dist[v] > dist[u] + weight)
         {

            dist[v] = dist[u] + weight;
            pq.push(make_pair(dist[v], v));
         }
      }
   }

   for (long long i = 0; i < V; ++i)
      lista.push_back(dist[i]);

   sort(lista.begin(), lista.end());

   for (long long i = 0; i < lista.size() - 1; i++)
      rj += 2 * lista[i];

   rj += lista[lista.size() - 1];

   cout << rj;
}

int main()
{
   long long n, m;
   cin >> n >> m;
   vector<iPair> adj[n];

   for (long long i = 0; i < m; i++)
   {
      long long g1, g2, t;
      cin >> g1 >> g2 >> t;
      addEdge(adj, g1 - 1, g2 - 1, t);
   }

   shortestPath(adj, n, 0);

   return 0;
}

//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/