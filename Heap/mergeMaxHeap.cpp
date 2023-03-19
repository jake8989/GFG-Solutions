/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void heapify(int index, vector<int> &arr, int size)
{
   int largest = index;
   int left_child = index * 2 + 1;
   int right_child = index * 2 + 2;
   if (left_child < size && arr[largest] < arr[left_child])
   {
      largest = left_child;
   }
   if (right_child < size && arr[largest] < arr[right_child])
   {
      largest = right_child;
   }
   if (largest != index)
   {
      swap(arr[largest], arr[index]);
      heapify(largest, arr, size);
   }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
   // your code herev
   vector<int> ans;
   for (auto it : a)
      ans.push_back(it);
   for (auto it : b)
      ans.push_back(it);
   int size = ans.size();
   for (int i = size / 2 - 1; i >= 0; i--)
   {
      heapify(i, ans, size);
   }
   return ans;
}
int main()
{

   return 0;
}