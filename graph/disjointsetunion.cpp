/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class DisJointSet
{
   vector<int> parent;
   vector<int> rank;

public:
   DisJointSet(int n)
   {
      parent.resize(n + 1);
      rank.resize(n + 1, 0);
      for (int i = 0; i <= n; i++)
      {
         parent[i] = i;
      }
   }
   int findUltPar(int node)
   {
      if (node == parent[node])
         return node;
      return parent[node] = findUltPar(parent[node]);
   }
   void unionByRank(int u, int v)
   {
      int ult_u = findUltPar(ult_u);
      int ult_v = findUltPar(ult_v);
      if (ult_u == ult_v)
         return;
      if (rank[ult_u] < rank[ult_v])
      {
         parent[ult_u] = ult_v;
      }
      else if (rank[ult_u] > rank[ult_v])
      {
         parent[ult_v] = ult_u;
      }
      else
      {
         parent[ult_v] = ult_u; // rank paretn++;
         rank[ult_u]++;
      }
   }
};
int main()
{

   return 0;
}