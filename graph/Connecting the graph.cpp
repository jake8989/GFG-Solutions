/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{

public:
   vector<int> rank;
   vector<int> parent;
   DisjointSet(int size)
   {
      rank.resize(size + 1);
      parent.resize(size + 1);
      for (int i = 0; i <= size; i++)
      {
         rank[i] = 0;
         parent[i] = i;
      }
   }
   int findUParent(int u)
   {
      if (u == parent[u])
         return u;
      return parent[u] = findUParent(parent[u]);
   }
   void unionByRank(int u, int v)
   {
      int ult_u = findUParent(u);
      int ult_v = findUParent(v);
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
         parent[ult_v] = ult_u;
         rank[ult_u]++;
      }
   }
};
int Solve(int n, vector<vector<int>> &edge)
{
   DisjointSet ds(n);
   int cntExtra = 0;
   int cNode = 0;
   for (auto it : edge)
   {
      int u = it[0];
      int v = it[1];

      if (ds.findUParent(u) == ds.findUParent(v))
      {
         cntExtra++;
      }
      else
      {
         ds.unionByRank(u, v);
      }
   }
   for (int i = 0; i < n; i++)
   {
      if (ds.parent[i] == i)
      {
         cNode++;
      }
   }
   if (cntExtra >= cNode)
   {
      return cNode - 1;
   }
   return -1;
}
int main()
{

   return 0;
}