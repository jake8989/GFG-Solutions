/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
string topoSort(vector<int> adj[], int V)
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
   vector<int> ans;
   for (int i = 0; i < V; i++)
   {
      if (indg[i] == 0)
      {
         q.push(i);
      }
   }
   while (!q.empty())
   {
      /* code */
      int parent = q.front();
      ans.push_back(parent);
      q.pop();
      for (auto i : adj[parent])
      {
         indg[i]--;
         if (indg[i] == 0)
         {
            q.push(i);
         }
      }
   }
   string tp = "";
   for (int i = 0; i < ans.size(); i++)
   {
      tp += ans[i] + 'a';
   }
   return tp;
}
string findOrder(string dict[], int N, int K)
{
   // code here
   string ans = "";
   vector<int> adj[K];
   for (int i = 0; i < N - 1; i++)
   {
      string a = dict[i];
      string b = dict[i + 1];
      int len = min(a.length(), b.length());

      for (int i = 0; i < len; i++)
      {
         if (a[i] != b[i])
         {
            adj[a[i] - 'a'].push_back(b[i] - 'a');
            break;
         }
      }
   }
   string topo = topoSort(adj, K);
   return topo;
}
int main()
{

   return 0;
}