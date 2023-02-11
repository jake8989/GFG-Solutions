/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
// Alex is very fond of traveling. There are n cities, labeled from 1 to n.  You are also given flights, a list of travel flights as directed weighted edges flights[i] = (ui,vi,wi) where ui is the source node, vi is the target node, and wi is the price it takes for a person to travel from source to target.
// Currently, Alex is in k'th city and wants to visit one city of his choice. Return the minimum money Alex should have so that he can visit any city of his choice from k'th city. If there is a city that has no path from k'th city, which means Alex can't visit that city, return -1.
// Alex always takes the optimal path. He can any city via another city by taking multiple flights.
#include <bits/stdc++.h>
using namespace std;
int minimumCost(vector<vector<int>> &flights, int n, int k)
{
   // code here
   vector<pair<int, int>> adj[n + 1];
   vector<int> dist(n + 1, 1e9);
   dist[k] = 0;
   for (auto it : flights)
   {
      adj[it[0]].push_back({it[1], it[2]});
   }
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, k});
   while (!pq.empty())
   {
      int dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();
      for (auto it : adj[node])
      {
         int adjNode = it.first;
         int edgw = it.second;
         if (dist[adjNode] > dist[node] + dis)
         {
            dist[adjNode] = dist[node] + dis;
            pq.push({dist[adjNode], adjNode});
         }
      }
   }
   int ans = INT_MIN;
   for (int i = 1; i <= n; i++)
   {
      if (dist[i] == 1e9)
      {
         return -1;
      }
      else
      {
         ans = max(ans, dist[i]);
      }
   }
   return ans;
}
int main()
{

   return 0;
}