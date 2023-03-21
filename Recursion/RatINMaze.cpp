/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void solve(string move, vector<vector<int>> &vis, vector<vector<int>> &m, int n, vector<string> &ans, int row, int col)
{
   if (row == n - 1 && col == n - 1)
   {
      ans.push_back(move);
      return;
   }
   // right
   if (row + 1 >= 0 && row + 1 < n && m[row + 1][col] == 1 && !vis[row + 1][col])
   {
      vis[row][col] = 1;
      solve(move + 'D', vis, m, n, ans, row + 1, col);
      vis[row][col] = 0;
   }
   else if (row >= 0 && row < n && m[row - 1][col] == 1 && !vis[row - 1][col])
   {
      vis[row][col] = 1;
      solve(move + 'D', vis, m, n, ans, row - 1, col);
      vis[row][col] = 0;
   }
   else if (col + 1 >= 0 && col + 1 < n && m[row][col + 1] == 1 && !vis[row][col + 1])
   {
      vis[row][col] = 1;
      solve(move + 'D', vis, m, n, ans, row, col + 1);
      vis[row][col] = 0;
   }
   else if (col - 1 >= 0 && col - 1 < n && m[row][col - 1] == 1 && !vis[row][col - 1])
   {
      vis[row][col] = 1;
      solve(move + 'D', vis, m, n, ans, row, col - 1);
      vis[row][col] = 0;
   }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
   // Your code goes here
   vector<string> ans;

   vector<vector<int>> vis(n, vector<int>(n, 0));

   string move = "";
   if (m[0][0] == 1)
      solve(move, vis, m, n, ans, 0, 0);
   return ans;
}
int main()
{

   return 0;
}