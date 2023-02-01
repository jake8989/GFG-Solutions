/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
   // Code here
   vector<int> dist(n, 1e8);
   dist[0] = 0;
   for (int i = 0; i < n - 1; i++)
   {
      for (auto it : edges)
      {
         int u = it[0];
         int v = it[1];
         int w = it[2];
         if (dist[u] != 1e8 && dist[u] + w < dist[v])
         {
            dist[v] = dist[u] + w;
         }
      }
   }
   for (auto it : edges)
   {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      if (dist[u] != 1e8 && dist[u] + w < dist[v])
      {
         return true;
      }
   }
   return false;
}
int main()
{

   return 0;
}