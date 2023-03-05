/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
bool check(int startingNode, int V, vector<int> adj[], vector<int> &color)
{
   vector<int> color(V, -1);
   color[startingNode] = 0;
   queue<int> q;
   q.push(startingNode);
   while (!q.empty())
   {
      /* code */
      int parent = q.front();
      q.pop();
      for (auto it : adj[parent])
      {
         if (color[it] == -1)
         {
            color[it] = !color[parent];
            q.push(it);
         }
         else
         {
            if (color[it] == color[parent])
               return false;
         }
      }
   }
   return true;
}
bool isBipartite(int V, vector<int> adj[])
{

   /////checking for multiple components
   vector<int> color(V, -1);
   for (int i = 0; i < V; i++)
   {
      if (color[i] == -1)
      {
         if (check(i, V, adj, color) == false)
            return false;
      }
   }
   return true;
}
int main()
{

   return 0;
}