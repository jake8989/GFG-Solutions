/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int solve(int row, int col, vector<vector<int>> &grid)
{
   if (col < 0 || col >= grid.size())
   {
      return -1e9;
   }
   if (row == 0 && col == 0)
   {
      return grid[0][col];
   }
   int up = grid[row][col] + solve(row - 1, col, grid);

   int left = INT_MIN;
   if (col > 1)
      left = grid[row][col] + solve(row - 1, col - 1, grid);
   int dg = INT_MIN;
   if (col < grid.size() - 1)
      dg = grid[row][col] + solve(row - 1, col + 1, grid);
   return max(up, max(left, dg));
}
int maximumPath(int N, vector<vector<int>> Matrix)
{
   // code here
   // recursive
   int maxi = INT_MIN;
   // for (int j = 0; j < N; j++)
   // {
   //    int maxi = max(Matrix[N - 1][j] + solve(N - 1, j, Matrix), maxi);
   // }
   // return maxi;
   vector<vector<int>> dp(N, vector<int>(N, 0));
   for (int i = 0; i < N; i++)
   {
      dp[0][i] = Matrix[0][i];
   }
   for (int i = 1; i < N; i++)
   {
      for (int j = 0; j < N; j++)
      {
         int up = Matrix[i][j] + dp[i - 1][j];
         int dg = INT_MIN;
         if (j > 0)
            dg = Matrix[i][j] + dp[i - 1][j - 1];
         int left = INT_MIN;
         if (j + 1 < N)
            left = Matrix[i][j] + dp[i - 1][j + 1];
         dp[i][j] = max(max(up, left), dg);
      }
   }
   int ans = INT_MIN;
   for (int i = 0; i < N; i++)
   {
      ans = max(ans, dp[N - 1][i]);
   }
   return ans;
}
int main()
{

   return 0;
}