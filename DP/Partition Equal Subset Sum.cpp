/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
bool solve(int n, int *arr, int tar)
{
   if (tar == 0)
   {
      return 1;
   }
   if (n == 0)
   {
      return arr[0] == tar;
   }
   bool pick = false;
   if (tar >= arr[n])
      pick = solve(n - 1, arr, tar - arr[n]);
   bool not_pick = solve(n - 1, arr, tar);
   return pick | not_pick;
}
int equalPartition(int N, int arr[])
{
   // code here
   int tar = 0;
   for (int i = 0; i < N; i++)
      tar += arr[i];
  return solve(N - 1, arr, tar);
}
int main()
{

   return 0;
}