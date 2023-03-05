/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void prem(vector<vector<int>> &ans, vector<int> &ds, vector<int> arr, int freq[])
{
   if (ds.size() == arr.size())
   {
      ans.push_back(ds);
      return;
   }
   for (int i = 0; i < arr.size(); i++)
   {
      if (!freq[i])
      {
         freq[i] = 1;
         ds.push_back(arr[i]);
         prem(ans, ds, arr, freq);
         ds.pop_back();
         freq[i] = 0;
      }
   }
}
vector<vector<int>> permutations(vector<int> &arr)
{
   vector<vector<int>> ans;
   vector<int> ds;
   int freq[arr.size()] = {0};
   prem(ans, ds, arr, freq);
}
int main()
{

   return 0;
}