/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
   vector<int> ans;
   queue<int> q;
   q.push(0);
   bool vis[V] = {0};
   while (!q.empty())
   {
      int node = q.front();
      ans.push_back(node);
      q.pop();
      for (auto it : adj[node])
      {
         if (!vis[it])
         {
            q.push(it);
            vis[it] = 1;
         }
      }
   }
   return ans;
}
int main()
{

   return 0;
}