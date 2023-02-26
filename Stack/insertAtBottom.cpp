/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void solve(stack<int> &st, int ele)
{
   if (st.empty())
   {
      st.push(ele);
   }
   int num = st.top();
   st.pop();
   solve(st, ele);
   st.push(num);
}
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
   // Write your code here.
   solve(myStack, x);
   return myStack;
}
int main()
{

   return 0;
}