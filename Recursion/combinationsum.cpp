/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void combinations(int index, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, int target)
{
   if (index == arr.size())
   {
      if (target == 0)
      {
         ans.push_back(ds);
      }
      return;
   }
   if (arr[index] <= target)
   {
      ds.push_back(arr[index]);
      combinations(index, ds, ans, arr, target - arr[index]);
      ds.pop_back();
   }
   combinations(index + 1, ds, ans, arr, target);
}
vector<vector<int>> combinationSum(vector<int> &A, int B)
{
   vector<vector<int>> ans;
   vector<int> ds;
   int index = 0;
   combinations(index, ds, ans, A, B);
   return ans;
}
int main()
{

   return 0;
}