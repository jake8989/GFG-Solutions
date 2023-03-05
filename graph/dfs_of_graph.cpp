/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &ans, vector<int> &vis, vector<int> adj[], int node)
{
   if (vis[node])
      return;
   vis[node] = 1;
   ans.push_back(node);
   for (auto it : adj[node])
   {
      if (!vis[node])
         dfs(ans, vis, adj, it);
   }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
   vector<int> ans;
   vector<int> vis(V, 0);
   dfs(ans, vis, adj, 0);
   return ans;
}
int main()
{

   return 0;
}