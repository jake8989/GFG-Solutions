/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// using extra n space
// method 1
class Solution
{
   int minEle;
   stack<int> s;
   stack<int> ss;

public:
   /*returns min element from stack*/
   int getMin()
   {

      // Write your code here
      if (ss.size() == 0)
         return -1;
      return ss.top();
   }

   /*returns poped element from stack*/
   int pop()
   {

      // Write your code here
      if (s.size() == 0)
         return -1;
      int ans = s.top();
      s.pop();
      if (!ss.empty() && ans == ss.top())
         ss.pop();
      return ans;
   }

   /*push element x into the stack*/
   void push(int x)
   {

      // Write your code here
      s.push(x);
      if (ss.empty() || ss.top() >= x)
         ss.push(x);
      return;
   }
};
// method 2
int main()
{

   return 0;
}