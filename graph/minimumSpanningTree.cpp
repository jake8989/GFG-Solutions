/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// using prims Algo int
int spanningTree(int V, vector<vector<int>> adj[])
{
   int sum = 0;
   vector<int> vis(V, 0);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, 0});
   while (!pq.empty())
   {
      int di = pq.top().first;
      int parent = pq.top().second;
      pq.pop();
      if (vis[parent])
         continue;
      vis[parent] = 1;
      sum += di;
      for (auto it : adj[parent])
      {
         int edw = it[1];
         int adjN = it[0];
         if (!vis[adjN])
            pq.push({edw, adjN});
      }
   }
   return sum;
}
main()
{

   return 0;
}