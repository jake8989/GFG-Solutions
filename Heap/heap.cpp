/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
   int arr[100];
   int size;
   Heap()
   {
      this->size = 0;
   }
   void insert(int val)
   {
      size++;
      int index = size;
      arr[index] = val;
      while (index > 0)
      {
         /* code */
         int parent_index = index / 2;
         if (arr[parent_index] < arr[index])
         {
            swap(arr[parent_index], arr[index]);
            index = parent_index;
         }
         else
         {
            return;
         }
      }
   }
   void pop()
   {
      swap(arr[1], arr[size]);
      size--;
      int index = 1;
      while (index < size)
      {
         int leftChild = 2 * index;
         int rightChild = 2 * index + 1;
         if (leftChild <= size && arr[leftChild] > arr[index])
         {
            swap(arr[index], arr[leftChild]);
            index = leftChild;
         }
         else if (rightChild <= size && arr[rightChild] > arr[index])
         {
            swap(arr[index], arr[rightChild]);
            index = rightChild;
         }
         else
         {
            return;
         }
      }
   }

   void print(int arr[])
   {
      for (int i = 1; i <= size; i++)
      {
         cout << arr[i] << " ";
      }
      cout << endl;
   }
};
void heapify(int arr[], int size, int i)
{
   int largest = i;
   int leftChild = 2 * i;
   int rightChild = 2 * i + 1;

   /* code */
   if (arr[leftChild] > arr[largest] && leftChild < size)
   {
      // swap(arr[i], arr[leftChild]);

      largest = leftChild;
   }
   if (arr[rightChild] > arr[largest] && rightChild < size)
   {
      // swap(arr[i], arr[rightChild]);

      largest = rightChild;
   }
   if (largest != i)
   {
      swap(arr[i], arr[largest]);
      heapify(arr, 8, largest);
   }
}
int main()
{
   Heap h;
   h.insert(23);
   h.insert(25);
   h.insert(65);
   h.insert(32);
   h.insert(9);
   // h.print();./
   h.pop();
   // h.print();.
   int arr[] = {1, 3, 5, 6, 764, 554, 5343, 454};
   // h.heapify(arr, 8, 8 / 2);
   for (int i = 4; i > 0; i--)
   {
      heapify(arr, 8, i);
   }
   for (int i = 1; i <= 7; i++)
   {
      cout << arr[i] << " ";
   }
   // h.print(arr);
   // h.print(arr);
   return 0;
}