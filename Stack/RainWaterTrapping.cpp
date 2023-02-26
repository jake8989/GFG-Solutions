/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long trappingWater(int arr[], int n)
{
   // code here
   ll ans = 0;
   int maxl[n] = {INT_MIN};
   int maxr[n] = {INT_MIN};
   maxl[0] = arr[0];
   maxr[n - 1] = arr[n - 1];
   for (int i = 1; i < n; i++)
   {
      maxl[i] = max(maxl[i - 1], arr[i]);
   }
   for (int i = n - 2; i >= 0; i--)
   {
      maxr[i] = max(maxr[i + 1], arr[i]);
   }
   for (int i = 0; i < n; i++)
   {
      ans += min(maxr[i], maxl[i]) - arr[i];
   }
   return ans;
}
int main()
{

   return 0;
}