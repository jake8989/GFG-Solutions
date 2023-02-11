/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void shortest_distance(vector<vector<int>> &matrix)
{
   // Code here
   int n = matrix.size();
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (matrix[i][j] == -1)
         {
            matrix[i][j] = (int)1e9;
         }
         if (i == j)
            matrix[i][j] = 0;
      }
   }
   for (int k = 0; k < n; k++)
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            matrix[i][j] = min(matrix[i][j], matrix[k][j] + matrix[i][k]);
         }
      }
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (matrix[i][j] == 1e9)
         {
            matrix[i][j] = -1;
         }
      }
   }
}
int main()
{

   return 0;
}