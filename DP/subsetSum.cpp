/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int index, int *arr, int target, vector<vector<int>> &dp)
{
   if (target == 0)
   {
      return 1;
   }
   if (index == 0)
   {
      return target == arr[0];
   }
   if (dp[index][target] != -1)
      return dp[index][target];
   bool not_take = isPossible(index - 1, arr, target, dp);
   bool take = false;
   if (target >= arr[index])
   {
      take = isPossible(index - 1, arr, target - arr[index], dp);
   }
   return dp[index][target] = take or not_take;
}
int main()
{
   int arr[] = {1, 2, 3, 5, 4, 4, 343, 4, 4};
   int k = 13;
   // vector<vector<int>> dp(10, vector<int>(k + 1, -1));
   // isPossible(8, arr, k, dp);
   // cout << dp[8][k];
   vector<vector<bool>> dp(10, vector<bool>(k + 1, 0));
   for (int i = 0; i < 10; i++)
   {
      dp[i][0] = 1;
   }
   if (arr[0] <= k)
      dp[0][arr[0]] = 1;
   for (int i = 1; i < 10; i++)
   {
      for (int tar = 1; tar <= k; tar++)
      {
         // the condition
         // dp[i][tar] = dp[i - 1][tar] | dp[i - 1][tar - arr[0]];
      }
   }
   cout << dp[8][k];
   return 0;
}