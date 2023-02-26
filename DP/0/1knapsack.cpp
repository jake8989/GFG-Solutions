/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin >> t;
   while (t--)
   {

      int n;
      cin >> n;
      int arr[n];
      int g = 0;
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      sort(arr, arr + n);
      bool ok = 0;
      g = __gcd(arr[0], arr[1]);
      if (g > 2)
         cout << "NO\n";
      else
      {
         int k = 3;

         for (int i = 2; i < n; i++)
         {
            g = __gcd(arr[i], g);
            if (g > k)
            {
               ok = 1;
            }
            else
            {
               k++;
            }
         }
         if (ok)
            cout << "NO\n";
         else
            cout << "YES\n";
      }
   }

   return 0;
}