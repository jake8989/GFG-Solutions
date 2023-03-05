/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int minSteps(int target)
{
   int moves = 0;
   int total = 0;
   target = abs(target);
   while (total < target || (total - target) % 2 != 0)
   {
      moves++;
      total += moves;
   }
   return moves;
}
int main()
{

   return 0;
}