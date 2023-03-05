/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
vector<int> NGL(vector<int> &arr, int n)
{
   vector<int> ans;
   stack<int> st;
   for (int i = 0; i < n; i++)
   {
      if (st.empty())
      {
         ans.push_back(-1);
      }
      else if (!st.empty() && st.top() > arr[i])
      {
         ans.push_back(st.top());
      }
      else
      {
         while (!st.empty() && st.top() <= arr[i])
         {
            /* code */
            st.pop();
         }
         if (st.empty())
         {
            ans.push_back(-1);
         }
         else
         {
            ans.push_back(arr[i]);
         }
      }
      st.push(arr[i]);
   }
   return ans;
}
int main()
{
   vector<int> arr = {5, 4, 3, 2, 1};
   vector<int> ans = NGL(arr, 5);
   for (auto it : ans)
      cout << it << " ";
   return 0;
}