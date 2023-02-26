// /*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
// #include <bits/stdc++.h>
// using namespace std;
// int frogJump(int n, int ans, int arr[])
// {
//    int ans = 0;
//    // solve(n, ans, arr);
//    vector<int> dp(n);
//    dp[0] = 0;
//    for (int i = 1; i < n; i++)
//    {
//       int min_steps = INT_MAX;
//       for (int j = 1; j <= k; j++)
//       {

//          int jump;
//          if (i - j >= 0)
//          {
//             jump = dp[i - j] + abs(dp[i] - dp[i - j]);
//             min_steps = min(jump, min_steps);
//          }
//       }
//       dp[i] = min_steps;
//    }
//    return dp[n - 1];
// }
// int main()
// {

//    return 0;
// }