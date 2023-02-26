#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> help_classmate(vector<ll> arr, int n)
{
   vector<ll> ans;
   stack<ll> st;
   for (int i = n; i >= 0; i--)
   {
      /* code */
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
            ans.push_back(st.top());
         }
      }
      st.push(arr[i]);
   }
   reverse(ans.begin(), ans.end());
}
int main()
{

   return 0;
}