/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int nodeLevel(int V, vector<int> adj[], int x)
{
   // code here
   queue<pair<int, int>> q;
   q.push({0, 0});
   vector<int> vis(V, 0);
   vis[0] = 1;
   // int level=0;
   while (!q.empty())
   {
      int level = q.front().first;
      int node = q.front().second;
      q.pop();
      for (auto it : adj[node])
      {
         if (it == x)
            return level + 1;
         if (!vis[it])
         {
            q.push({level + 1, it});
            vis[it] = 1;
         }
      }
   }
   return -1;
}
int main()
{

   return 0;
}