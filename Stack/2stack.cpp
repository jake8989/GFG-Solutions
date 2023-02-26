/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class twoStack
{
public:
   int top1;
   int top2;
   int size;
   int *arr;
   twoStack(int size)
   {
      this->size = size;
      arr = new int[this->size];
      top1 = -1;
      top2 = size;
   }
   void push1(int num)
   {
      if (top2 - top1 > 0)
      {
         top1++;
         arr[top1] = num;
      }
      else
      {
         return;
      }
   }
   void push2(int num)
   {
      if (top2 - top1 > 0)
      {
         top2--;
         arr[top2] = num;
      }
      else
      {
         return;
      }
   }
   int pop1()
   {
      if (top1 >= 0)
      {
         int x = arr[top1];
         top1--;
      }
      else
         return -1;
   }
   int pop2()
   {
      if (top2 < size)
      {
         int x = arr[top2];
         top2++;
      }
      else
         return -1;
   }
};
int main()
{

   return 0;
}