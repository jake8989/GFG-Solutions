/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int solve(int row, int col, int max_row, int max_col, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
   //    if(col>max_col)return 1e9;
   if (row == max_row)
   {
      return triangle[max_row][col];
   }
   if (dp[row][col] != -1)
      return dp[row][col];
   int down = triangle[row][col] + solve(row + 1, col, max_row, max_col, triangle, dp);
   int diag = triangle[row][col] + solve(row + 1, col + 1, max_row, max_col, triangle, dp);
   return dp[row][col] = min(down, diag);
}
int n = triangle.size();
int m = triangle[0].size();
// recursion mujhe choices dikhi!
//    vector<vector<int>>dp.
// vector<vector<int>> dp(n, vector<int>(m, -1));
// return solve(0, 0, n - 1, m - 1, triangle, dp);
// tabulation
vector<vector<int>> dp(n, vector<int>(m, 0));
for (int col = 0; col < m; col++)
{
   dp[n - 1][col] = triangle[n - 1][col];
}
for (int row = n - 2; row >= 0; row--)
{
   for (int col = row; col >= 0; col--)
   {
      int down = triangle[row][col] + dp[row + 1][col];
      int diag = triangle[row][col] + dp[row + 1][col + 1];
      dp[row][col] = min(down, diag);
   }
}
int main()
{

   return 0;
}