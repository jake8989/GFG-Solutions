/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3 * i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.
int minimumStep(int n)
{
   // complete the function here
   int steps = 0;
   while (n != 1)
   {
      if (n % 3 == 0)
      {
         n = n / 3;
      }
      else
      {
         n = n - 1;
      }
   }
   return steps;
}
int main()
{

   return 0;
}