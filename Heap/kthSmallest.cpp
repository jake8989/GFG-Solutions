/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k)
{
   // code
   priority_queue<int> pq;
   for (int i = l; i < k; i++)
   {
      pq.push(arr[i]);
   }
   for (int i = k; i <= r; i++)
   {
      if (arr[i] < pq.top())
         pq.pop(), pq.push(arr[i]);
   }
   return pq.top();
}
int main()
{

   return 0;
}