/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *left;
   Node *right;
   Node(int data)
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
};
int getMaxWidth(Node *root)
{

   // Your code here
   int ans = 0;
   queue<pair<Node *, int>> q;
   q.push({root, 0});

   while (!q.empty())
   {
      int size = q.size();
      int first, last;
      int minn = q.front().second;
      for (int i = 0; i < size; i++)
      {
         int curr_id = q.front().second - minn;
         Node *par = q.front().first;
         q.pop();
         if (i == 0)
            first = curr_id;
         if (i == size - 1)
            last = curr_id;
         if (par->left)
         {
            q.push({par->left, curr_id * 2 + 1})
         }
         if (par->right)
         {
            q.push({par->right, curr_id * 2 + 2})
         }
      }
      ans = max(ans, last - first + 1);
   }

   return ans;
}
int main()
{

   return 0;
}