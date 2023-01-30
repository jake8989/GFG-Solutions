/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
   if (vis[node])
      return;
   vis[node] = 1;
   for (auto it : adj[node])
   {
      if (!vis[it])
         dfs(it, st, vis, adj);
   }
   st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[], vector<int> &vis)
{
   vector<int> ans;
   stack<int> st;
   while (!st.empty())
   {
      ans.push_back(st.top());
      st.pop();
   }
   dfs(0, st, vis, adj);
   return ans;
}
int main()
{

   return 0;
}