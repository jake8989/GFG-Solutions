
/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int maxWeightCell(int N, vector<int> Edge)
{
   // code here
   vector<int> w(N, 0);
   vector<int> adj[N];
   for (int i = 0; i < N; i++)
   {
      if (Edge[i] != -1)
      {
         adj[i].push_back(Edge[i]);
      }
   }
   int ans = 0;
   int max_w = INT_MIN;
   for (int i = 0; i < N; i++)
   {
      for (auto it : adj[i])
      {
         w[it] += i;
      }
   }
   for (int i = 0; i < N; i++)
   {
      if (max_w <= w[i])
      {
         max_w = w[i];
         ans = i;
      }
      //  cout<<w[i]<<" ";
   }
   return ans;
}
int main()
{

   return 0;
}