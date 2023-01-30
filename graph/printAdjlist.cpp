/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> printGraph(int V, vector<int> adj[])
{
   vector<vector<int>> ans;
   for (int i = 0; i < V; i++)
   {
      vector<int> tp;
      // cout<<i<<" ";
      tp.push_back(i);
      for (auto it : adj[i])
      {
         // cout<<it<<" \n";
         tp.push_back(it);
      }
      ans.push_back(tp);
      // tp.clear();
   }
   return ans;
}
int main()
{

   return 0;
}