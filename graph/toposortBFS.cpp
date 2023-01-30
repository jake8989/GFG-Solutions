/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[], vector<int> &vis)
{
   vector<int> ans;
   // indgree vector??
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
   while (!q.empty())
   {
      int node = q.front();
      ans.push_back(node);
      q.pop();
      for (auto i : adj[node])
      {
         indg[i]--;
         if (indg[i] == 0)
            q.push(i);
      }
   }
   return ans;
}
int main()
{

   return 0;
}