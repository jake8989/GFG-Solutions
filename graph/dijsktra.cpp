/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
   // using proirity queue
   vector<int>
       dist(V, 1e9);
   dist[S] = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   // {distance,adjNode}
   pq.push({0, 0});
   while (!pq.empty())
   {
      int dis = pq.top().first;
      int parent = pq.top().second;
      pq.pop();
      for (auto it : adj[parent])
      {
         int adjNode = it[0];
         int edgeWeight = it[1];
         if (edgeWeight + dis < dist[adjNode])
         {
            dist[adjNode] = edgeWeight + dis;
            pq.push({dist[adjNode], adjNode});
         }
      }
   }
}
int main()
{

   return 0;
}