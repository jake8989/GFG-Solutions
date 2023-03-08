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
int main()
{
   int sum[100005] = {0};
   sum[0] += 342;
   cout << sum[0];
   return 0;
}
// void flatten(Node *root)
// {
//    // code here
//    stack<Node *> st;
//    st.push(root);
//    while (!st.empty())
//    {
//       Node *curr = st.top();
//       st.pop();
//       if (curr->right)
//       {
//          st.push(curr->right);
//       }
//       if (curr->left)
//       {
//          st.push(curr->left);
//       }
//       if (st.size() > 0)
//       {
//          curr->right = st.top();
//       }
//       curr->left = NULL;
//    }
// }
