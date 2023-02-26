/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[])
{
   // if (vis[node])
   //    return;
   vis[node] = 1;
   for (auto itr : adj[node])
   {
      if (!vis[itr])
      {
         if (dfs(itr, node, vis, adj))
            return 1;
      }
      else if (itr != parent)
      {
         return true;
      }
   }
}
bool isCycle(int V, vector<int> adj[])
{
   vector<int> vis(V, 0);
   for (int i = 0; i < V; i++)
   {
      if (!vis[i])
      {
         if (dfs(i, -1, vis, adj))
            return 1;
      }
   }
   return false;
}
int main()
{

   return 0;
}