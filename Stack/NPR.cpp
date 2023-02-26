/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
vector<int> NPR(vector<int> &arr, int n)
{
   vector<int> ans;
   stack<int> st;
   for (int i = n - 1; i >= 0; i--)
   {
      if (st.empty())
      {
         ans.push_back(-1);
      }
      else if (st.top() < arr[i])
      {
         ans.push_back(st.top());
      }
      else
      {
         while (!st.empty() && st.top() >= arr[i])
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
      st.push(arr[i]);
   }
   return ans;
}

int main()
{

   s return 0;
}