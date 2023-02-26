/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// using topoSort
/// DFS METHOD
// bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &b)
// {
//    vis[node] = 1;
//    b[node] = 1;
//    for (auto it : adj[node])
//    {
//       if (!vis[it])
//       {
//          if (dfs(it, adj, vis, b))
//             return 1;
//       }
//       else if (b[it])
//          return 1;
//    }
//    b[node] = 0;
//    return false;
// }
// bool isCyclic(int V, vector<int> adj[])
// {
//    vector<int> vis(V, 0);
//    vector<int> b(V, 0);
//    for (int i = 0; i < V; i++)
//    {
//       if (!vis[i])
//          if (dfs(i, adj, vis, b))
//             return 1;
//    }
//    return 0;
// }
// Topo Sort Method
bool isCyclic(int V, vector<int> adj[])
{
   vector<int> indg(V, 0);
   for (int i = 0; i < V; i++)
   {
      for (auto it : adj[i])
      {
         indg[it]++;
      }
   }
   queue<int> q;
   for (int i = 0; i < V; i++)
   {
      if (indg[i] == 0)
      {
         q.push(i);
      }
   }
   int common = 0;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      common++;
      for (auto it : adj[node])
      {
         indg[it]--;
         if (indg[it] == 0)
            q.push(it);
      }
   }
   if (common == V)
      return false;
   return true;
}
int main()
{

   return 0;
}