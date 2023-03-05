/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int solve(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
   if (row == 0 && col == 0)
      return mat[row][col];
   if (row < 0 || col < 0)
   {
      return 1e9;
   }
   if (dp[row][col] != -1)
      return dp[row][col];
   int up = mat[row][col] + solve(row - 1, col, mat, dp);
   int left = mat[row][col] + solve(row, col - 1, mat, dp);
   return dp[row][col] = min(up, left);
}

int maximumPath(int N, vector<vector<int>> Matrix)
{
   // code here
   // recursion
   vector<vector<int>> dp(N, vector<int>(N, -1));
   return solve(N - 1, N - 1, Matrix, dp);
}
int main()
{

   return 0;
}