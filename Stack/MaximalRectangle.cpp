/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
vector<int> NSL(vector<int> &arr, int n)
{

   vector<int> ans;
   stack<int> st;
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
vector<int> NSR(vector<int> &arr, int n)
{

   vector<int> ans;
   stack<int> st;
   for (int i = n - 1; i >= 0; i--)
   {
      if (st.empty())
      {
         ans.push_back(n);
      }
      else if (arr[st.top()] < arr[i])
      {
         ans.push_back(st.top());
      }
      else
      {
         while (!st.empty() && arr[st.top()] >= arr[i])
         {
            st.pop();
         }
         if (st.empty())
            ans.push_back(n);
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
int MAH(vector<int> &arr, int n)
{
   int ans = INT_MIN;
   vector<int> x = NSL(arr, n);
   vector<int> y = NSR(arr, n);
   for (int i = 0; i < n; i++)
   {
      ans = max(ans, (arr[i] * (y[i] - x[i] - 1)));
   }
   return ans;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
   int n = matrix.size();
   int m = matrix[0].size();
   vector<int> arr(m);
   for (int i = 0; i < m; i++)
   {
      arr[i] = matrix[0][i] - 48;
   }
   int ans = MAH(arr, m);
   for (int i = 1; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (matrix[i][j] == '0')
         {
            arr[j] = 0;
         }
         else
         {
            arr[j] = arr[j] + matrix[i][j] - 48;
         }
      }
      ans = max(ans, MAH(arr, m));
   }
   return ans;
}

int main()
{

   // maximalRectangle() return 0;
}