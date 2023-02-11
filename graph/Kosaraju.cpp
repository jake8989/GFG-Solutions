/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int parent, vector<int> adj[], stack<int> &st, vector<int> &vis)
{
   if (vis[parent])
      return;
   vis[parent] = 1;
   for (auto child : adj[parent])
   {
      if (!vis[child])
      {
         dfs(child, adj, st, vis);
      }
   }
   st.push(parent);
}
void dfss(int parent, vector<int> &vis, vector<int> adjT[])
{
   if (vis[parent])
      return;
   vis[parent] = 1;
   for (auto it : adjT[parent])
   {
      if (!vis[it])
      {
         dfss(it, vis, adjT);
      }
   }
}
int kosaraju(int V, vector<int> adj[])
{
   // step1:sort the edges wrt their starting and ending time
   // step2:reverse the edges
   // step3:run dfs
   stack<int> st;
   vector<int> vis(V, 0);
   for (int i = 0; i < V; i++)
   {
      if (!vis[i])
      {
         dfs(i, adj, st, vis);
      }
   }
   vector<int> adjTranspose[V];
   for (int i = 0; i < V; i++)
   {
      vis[i] = 0;
      for (auto neigh : adj[i])
      {
         adjTranspose[neigh].push_back(i);
      }
   }
   int scc = 0;
   while (!st.empty())
   {
      int o = st.top();
      if (!vis[o])
      {
         dfss(o, vis, adjTranspose);
         scc++;
      }
   }

   return scc;
}
int main()
{

   return 0;
}