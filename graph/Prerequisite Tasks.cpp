/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.
bool topoSort(vector<int> adj[], int V)
{
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
   int common = 0;
   while (!q.empty())
   {
      int parent = q.front();
      q.pop();
      common++;
      for (auto itr : adj[parent])
      {
         indg[itr]--;
         if (indg[itr] == 0)
         {
            q.push(itr);
         }
      }
   }
   if (common == V)
      return true;
   return false;
}

bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
   // Code here
   vector<int> adj[N];
   for (pair<int, int> it : prerequisites)
   {
      adj[it.first].push_back(it.second);
   }
   bool ans = topoSort(adj, N); // return true if it is DAG
   return ans;
}
int main()
{

   return 0;
}