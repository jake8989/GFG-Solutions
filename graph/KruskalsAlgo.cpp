/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
   vector<int> rank;
   vector<int> parent;

public:
   DisjointSet(int n)
   {
      rank.resize(n + 1);
      parent.resize(n + 1);
      for (int i = 0; i <= n; i++)
         rank[i] = 0;
      for (int i = 0; i <= n; i++)
      {
         parent[i] = i;
      }
   }
   int findUltParent(int node)
   {
      if (node == parent[node])
         return node;
      return parent[node] = findUltParent(parent[node]);
   }
   void unionByRank(int u, int v)
   {
      int ult_u = findUltParent(u);
      int ult_v = findUltParent(v);
      if (ult_v == ult_u)
         return;
      if (rank[ult_v] < rank[ult_u])
      {
         parent[ult_v] = ult_u;
      }
      else if (rank[ult_v] > rank[ult_u])
      {
         parent[ult_u] = ult_v;
      }
      else
      {
         parent[ult_u] = ult_v;
         ult_v++;
      }
   }
};
int spanningTree(int V, vector<vector<int>> adj[])
{
   DisjointSet ds(V);
   vector<pair<int, pair<int, int>>> edges;
   for (int i = 0; i < V; i++)
   {
      for (auto it : adj[i])
      {
         int adjNode = it[0];
         int edgeW = it[1];
         int node = i;
         edges.push_back({edgeW, {node, adjNode}});
      }
   }
   sort(edges.begin(), edges.end());
   int ans = 0;
   for (auto it : edges)
   {
      int ew = it.first;
      int u = it.second.first;
      int v = it.second.second;
      if (ds.findUltParent(u) != ds.findUltParent(v))
      {
         ans += ew;
         ds.unionByRank(u, v);
      }
   }
   return ans;
}
int main()
{

   return 0;
}