/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int dn, int sn, vector<vector<int>> &ans, vector<int> &tp)
{
   if (sn == dn)
   {
      ans.push_back(tp);
      return;
   }
   for (auto it : adj[sn])
   {
      tp.push_back(it);

      dfs(adj, dn, it, ans, tp);
      tp.pop_back();
   }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
   // vector<vector<int>>ans;
   int n = graph.size();
   // int m=graph[0].size();
   vector<int> adj[15];
   for (int i = 0; i < n; i++)
   {
      for (auto it : graph[i])
      {
         adj[i].push_back(it);
      }
      // cout<<endl;
   }

   vector<int> temp;
   vector<vector<int>> ans;
   temp.push_back(0);
   dfs(adj, n - 1, 0, ans, temp);
}
int main()
{

   return 0;
}