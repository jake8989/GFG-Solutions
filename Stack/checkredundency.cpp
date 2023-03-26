/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int checkRedundancy(string s)
{
   // code here
   stack<char> st;
   for (char &ch : s)
   {
      if (ch == ')')
      {
         char top = st.top();
         st.pop();
         bool ok = true;
         while (!st.empty() && top != '(')
         {
            if (top == '+' || top == '/' || top == '-' || top == '*')
            {
               ok = false;
            }
            top = st.top();
            st.pop();
         }
         if (ok)
            return true;
      }
      else
      {
         st.push(ch);
      }
   }
   return false;
}
int main()
{

   return 0;
}