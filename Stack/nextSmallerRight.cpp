/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;

vector<long long> NSR(long long arr[], int n)
{
   vector<long long> ans;
   stack<long long> st;
   for (int i = n - 1; i >= 0; i--)
   {
      if (st.empty())
      {
         ans.push_back(-1);
      }
      else if (arr[st.top()] < arr[i])
      {
         ans.push_back(st.top());
      }
      else
      {
         while (!st.empty() && arr[st.top()] >= arr[i])
         {
            /* code */
            st.pop();
         }
         if (st.empty())
            ans.push_back(-1);
         else
         {
            ans.push_back(st.top());
         }
      }
      st.push(i);
   }
   reverse(ans.begin(), ans.end());
   return ans;
}
long long getMaxArea(long long arr[], int n){

    // vector<long long> y = NSR(arr, n);
};
int main()
{
   long long arr[] = {5, 54, 3, 32, 2, 2};
   int n = 5;
   vector<long long> x = NSR(arr, n);
   for (auto it : x)
   {
      cout << it << " ";
   }

   return 0;
}