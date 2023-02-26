/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// void solve(int index, int arr[])
// {
//    if (index < 0)
//       return 0;
//    if (index == 0)
//       return arr[0];
//    if (dp[index] != -1)
//       return dp[index];
//    int pick = arr[index] + solve(index - 2, arr);
//    int notPick = 0 + solve(index - 1, arr);
//    return dp[index] = max(pick, notPick);
// }
int FindMaxSum(int arr[], int n)
{
   // Your code here
   // recursive way to solve
   // solve(n - 1, arr);
   // memoization
   // vector<int> dp(n, -1);
   // return dp[n - 1];
   // tabulation
   // vector<int> dp(n, 0);
   // dp[0] = arr[0];
   // for (int i = 1; i < n; i++)
   // {
   //    int take = arr[i];
   //    if (i > 1)
   //       take += dp[i - 2];

   //    int notTake = 0 + dp[i - 1];
   //    dp[i] = max(take, notTake);
   // }
   // return dp[n - 1];

   // with costant space
   int prev2 = 0;
   int prev = arr[0];
   int curr = 0;
   for (int i = 1; i < n; i++)
   {
      // int prev = arr[i] + curr;
      int take = arr[i];
      if (i > 1)
      {
         take += prev2;
      }
      int notTake = arr[i] + 0;
      int curr = max(take, notTake);
      prev2 = prev;
      prev = curr;
   }
   return prev;
}

int main()
{

   return 0;
}