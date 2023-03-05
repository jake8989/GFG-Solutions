/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>

using namespace std;
void subsets(vector<int> &ds, vector<vector<int>> &ans, vector<int> arr, int index)
{
   if (index == arr.size())
   {
      ans.push_back(ds);
      return;
   }
   ds.push_back(arr[index]);
   subsets(ds, ans, arr, index + 1);
   ds.pop_back();
   subsets(ds, ans, arr, index + 1);
}
vector<vector<int>> subsets(vector<int> &A)
{
   // code here
   vector<vector<int>> ans;
   vector<int> ds;
   subsets(ds, ans, A, 0);
   sort(ans.begin(), ans.end());
   return ans;
}
int main()
{

   return 0;
}