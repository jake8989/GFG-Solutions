/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>> &roads)
{
   // code here
   vector<int> ways(n, 0);
   ways[0] = 1;
   vector<int> dist(n, 1e9);
   dist[0] = 0;
   int mod = 1000000007;
   vector<pair<int, int>> adj[n];
   for (auto it : roads)
   {
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
   }
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, 0});
   while (!pq.empty())
   {
      int dis = pq.top().first;
      int c = pq.top().second;
      pq.pop();
      for (auto it : adj[c])
      {
         int adjNode = it.first;
         int edgeWeight = it.second;
         if (dist[adjNode] > dis + edgeWeight)
         {
            dist[adjNode] = dis + edgeWeight;
            ways[adjNode] = ways[c];
            pq.push({dist[adjNode], adjNode});
         }
         else if (dist[adjNode] == dis + edgeWeight)
         {
            ways[adjNode] = (ways[c] + ways[adjNode]) % mod;
         }
      }
   }
   return ways[n - 1] % mod;
}
int main()
{
   return 0;
}