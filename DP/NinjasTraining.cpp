/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int f(vector<vector<int>> &points, int last_task,
      int size, vector<vector<int>> &dp)
{
   if (size == 0)
   {
      int maxi = 0;
      for (int i = 0; i < 3; i++)
      {
         if (i != last_task)
            maxi = max(maxi, points[0][i]);
      }
      return maxi;
   }
   int task_score = 0;
   if (dp[size][last_task] != -1)
      return dp[size][last_task];
   for (int i = 0; i < 3; i++)
   {
      if (last_task != i)
      {
         int score = points[size][i] + f(points, i, size - 1, dp);
         task_score = max(score, task_score);
      }
   }
   return dp[size][last_task] = task_score;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
   // Write your code here.
   int last = 3;
   // vector<vector<int>> dp(n, vector<int>(4, -1));
   // return f(points, last, n - 1, dp);
   // tabulation
   vector<vector<int>> dp(n, vector<int>(4, 0));
   dp[0][0] = max(points[0][1], points[0][2]);
   dp[0][1] = max(points[0][2], points[0][0]);
   dp[0][2] = max(points[0][1], points[0][0]);
   dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));
   for (int day = 1; day < n; day++)
   {
      for (int last = 0; last < 4; last++)
      {
         for (int i = 0; i < 3; i++)
         {
            dp[day][last] = max(dp[day][last], points[day][i] + dp[day - 1][last]);
         }
      }
   }
   return dp[n - 1][3];
}
int main()
{

   return 0;
}