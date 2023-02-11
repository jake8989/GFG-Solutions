/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int sum(int n)
{
   if (n == 0)
      return 0;
   return n + sum(n - 1);
}
int fact(int n)
{
   if (n == 0 || n == 1)
      return 1;
   return n * (fact(n - 1));
}
int fib(int n)
{
   if (n <= 1)
      return n;
   return (fib(n - 1) + fib(n - 2));
}
void printF(int arr[], vector<int> &db, int n, int idx)
{
   if (idx >= n)
   {
      for (auto it : db)
         cout << it << " ";
      cout << endl;
      return;
   }
   if (idx == 0)
   {
      cout << "{}" << endl;
   }

   printF(arr, db, n, idx + 1);
   db.push_back(arr[idx]);

   printF(arr, db, n, idx + 1);
   db.pop_back();
}
// How many subsequences
int printFM(int arr[], int n, int &s, int sum, int idx)
{
   if (idx >= n)
   {
      if (s == sum)
         return 1;
      else
         return 0;
   }
   s += arr[idx];
   int l = printFM(arr, n, s, sum, idx + 1);
   s -= arr[idx];
   int r = printFM(arr, n, s, sum, idx + 1);
   return l + r;
}
// for checking any subsequence is present or not
bool printFC(int arr[], vector<int> &db, int n, int &s, int sum, int idx)
{
   if (idx == n)
   {
      if (s == sum)
      {
         return true;
      }
      else
         return false;
   }
   sum += arr[idx];
   if (printFC(arr, db, n, s, sum, idx + 1) == true)
      return true;

   sum -= arr[idx];
   if (printFC(arr, db, n, s, sum, idx + 1) == true)
      return true;
   return false;
}

int main()
{
   cout << sum(6);
   cout << "\n";
   cout << fact(5);
   cout << "\n";
   cout << fib(5) << " \n";
   int arr[] = {1,
                2,
                3};
   vector<int> db;
   int index = 0;
   int n = 3;
   printF(arr, db, n, index);
   int sum = 4;
   int s = 0;
   printFM(arr, n, s, sum, index);
   printFC(arr, db, n, s, sum, index);
   return 0;
}