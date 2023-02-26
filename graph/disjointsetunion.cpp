/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// class DisJointSet
// {
//    vector<int> parent;
//    vector<int> rank;

// public:
//    DisJointSet(int n)
//    {
//       parent.resize(n + 1);
//       rank.resize(n + 1, 0);
//       for (int i = 0; i <= n; i++)
//       {
//          parent[i] = i;
//       }
//    }
//    int findUltPar(int node)
//    {
//       if (node == parent[node])
//          return node;
//       return parent[node] = findUltPar(parent[node]);
//    }
//    void unionByRank(int u, int v)
//    {
//       int ult_u = findUltPar(ult_u);
//       int ult_v = findUltPar(ult_v);
//       if (ult_u == ult_v)
//          return;
//       if (rank[ult_u] < rank[ult_v])
//       {
//          parent[ult_u] = ult_v;
//       }
//       else if (rank[ult_u] > rank[ult_v])
//       {
//          parent[ult_v] = ult_u;
//       }
//       else
//       {
//          parent[ult_v] = ult_u; // rank paretn++;
//          rank[ult_u]++;
//       }
//
// }
// };

class dsu
{

public:
   vector<int> parent;
   vector<int> rank;
   dsu(int n)
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
      int ult_u = findUltPar(u);
      int ult_v = findUltPar(v);
      if (ult_v == ult_u)
         return;
      else if (rank[ult_v] > rank[ult_u])
      {
         parent[ult_u] = ult_v;
      }
      else if (rank[ult_v] < rank[ult_u])
      {
         parent[ult_v] = ult_u;
      }
      else
      {
         parent[ult_v] = ult_u;
         rank[ult_v]++;
      }
   }
};
int makeConnected(int n, vector<vector<int>> &connections)
{
   int extraE = 0;
   int cp = 0;
   dsu ds(n);
   for (auto it : connections)
   {
      int u = it[0];
      int v = it[1];
      if (ds.findUltPar(u) == ds.findUltPar(v))
      {
         extraE++;
      }
      else
      {
         ds.unionByRank(u, v);
      }
   }
   for (int i = 0; i < n; i++)
   {
      if (ds.parent[i] == i)
         cp++;
   }
   if (extraE >= cp - 1)
   {
      return cp - 1;
   }
   return -1;
}
int main()
{

   return 0;
}