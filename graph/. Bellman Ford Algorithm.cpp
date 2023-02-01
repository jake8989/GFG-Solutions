/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// Lamp
// Unable to Crack Interviews of Your Dream Companies ? Click Here to End This Problem!

// Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
// Note: If the Graph contains a negative cycle then return an array consisting of only -1.
// E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]

// Code here
vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
   // Code here
   vector<int> dist(V, 1e8);
   dist[S] = 0;
   for (int i = 0; i < V - 1; i++)
   {
      for (auto it : edges)
      {
         int u = it[0];
         int v = it[1];
         int weight = it[2];
         if (dist[u] + weight < dist[v] && dist[u] != 1e8)
         {
            dist[v] = dist[u] + weight;
         }
      }
   }
   // we have to check whether the grpah contain negative cycle or not? or Nth relaxation
   for (auto it : edges)
   {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      if (dist[u] + w < dist[v] && dist[u] != 1e8)
      {
         return {-1};
      }
   }
   return dist;
}
int main()
{

   return 0;
}