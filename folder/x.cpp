/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class dsu
{
public:
   vector<int> rank;
   vector<int> parent;
   dsu(int n)
   {
      rank.resize(n);
      parent.resize(n);
      for (int i = 0; i <= n; i++)
      {
         parent[i] = i;
         rank[i] = 0;
      }
   }
   int find_ult_parent(int node)
   {
      if (parent[node] == node)
         return node;
      return parent[node] = find_ult_parent(parent[node]);
   }
   void union_by_rank(int u, int v)
   {
      int ult_u = find_ult_parent(u);
      int ult_v = find_ult_parent(v);
      if (ult_u == ult_v)
         return;
      if (rank[ult_u] > rank[ult_v])
      {
         parent[ult_u] = ult_v;
      }
      else if (rank[ult_u] < rank[ult_v])
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
int main()
{

   return 0;
}