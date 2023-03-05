/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &ans, vector<int> &ds, int index, vector<int> arr)
{
   if (index == arr.size())
   {
      ans.push_back(ds);
      return;
   }
   for (int i = 0; i < arr.size(); i++)
   {
      if (i != index && arr[i] == arr[i - 1])
      {
         continue;
      }
      ds.push_back(arr[index]);
      solve(ans, ds, index + 1, arr);
      ds.pop_back();
   }
}
vector<vector<int>> subsets(vector<int> &A)
{
   vector<vector<int>> ans;
   vector<int> ds;
   sort(A.begin(), A.end());
   solve(ans, ds, 0, A);
   return ans;
}
int main()
{

   return 0;
}