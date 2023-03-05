/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, bool vis[], vector<int> adj[])
{
   if (vis[node])
      return;
   vis[node] = 1;
   for (auto it : adj[node])
   {
      if (!vis[it])
         dfs(it, vis, adj);
   }
}
int numProvinces(vector<vector<int>> grid, int V)
{
   // code here
   // V=V;
   // V;
   int n = grid.size();
   int m = grid[0].size();
   vector<int> adj[V];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 1 && i != j)
         {
            adj[i].push_back(j);
            adj[j].push_back(i);
         }
      }
   }
   bool vis[V] = {0};
   int ans = 0;
   for (int i = 0; i < V; i++)
   {

      if (!vis[i])
      {
         ans++;
         dfs(i, vis, adj);
      }
   }
   return ans;
}
int main()
{

   return 0;
}