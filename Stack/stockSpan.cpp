#include <bits/stdc++.h>
using namespace std;
vector<int> calculateSpan(int price[], int n)
{
   // Your code here
   vector<int> ans;
   stack<int> st;
   for (int i = 0; i < n; i++)
   {
      /* code */
      if (st.empty())
         ans.push_back(-1);
      else if (price[st.top()] > price[i])
      {
         ans.push_back(st.top());
      }
      else
      {
         while (st.size() > 0 && price[st.top()] <= price[i])
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
      st.push(i);
   }

   for (int i = 0; i < n; i++)
   {
      ans[i] = i - ans[i];
   }
   return ans;
}
int main()
{

   return 0;
}