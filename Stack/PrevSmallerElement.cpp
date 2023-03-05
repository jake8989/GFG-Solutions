// obvious
/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
vector<long long> NSL(long long arr[], int n)
{
   vector<long long> ans;
   stack<long long> st;
   for (int i = 0; i < n; i++)
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
   return ans;
}
int main()
{

   long long arr[] = {1, 2, 3, 4, 5};
   int n = 5;
   vector<long long> x = NSL(arr, n);
   for (auto it : x)
   {
      cout << it << " ";
   }
   return 0;
}
