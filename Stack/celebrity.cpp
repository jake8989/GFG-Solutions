/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &M, int n)
{
   // code here
   stack<int> st;
   for (int i = 0; i < n; i++)
   {
      st.push(i);
   }
   while (st.size() > 1)
   {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      if (M[a][b] == 1)
      {
         st.push(b);
      }
      else
      {
         st.push(a);
         st.push(a);
      }
   }
   bool rowCheck = false;
   int row = 0;
   bool colCheck = false;
   int col = 0;
   for (int i = 0; i < n; i++)
   {
      if (M[st.top()][i] == 0)
         row++;
   }
   if (row == n)
      rowCheck = 1;
   for (int i = 0; i < n; i++)
   {
      if (M[i][st.top()] == 1)
         col++;
   }
   if (col == n - 1)
      colCheck = 1;
   if (rowCheck && colCheck)
      return st.top();
   return -1;
}
int main()
{

   return 0;
}