/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// Given a matrix mat of size N x M where every element is either O or X.
// Replace all O with X that are surrounded by X.
// A O (or a set of O) is considered to be surrounded by X if there are X at locations' just below, just above, just left and just right' of it.
// Input: n = 5, m = 4
// mat = {{'X', 'X', 'X', 'X'},
//        {'X', 'O', 'X', 'X'},
//        {'X', 'O', 'O', 'X'},
//        {'X', 'O', 'X', 'X'},
//        {'X', 'X', 'O', 'O'}}
// Output: ans = {{'X', 'X', 'X', 'X'},
//                {'X', 'X', 'X', 'X'},
//                {'X', 'X', 'X', 'X'},
//                {'X', 'X', 'X', 'X'},
//                {'X', 'X', 'O', 'O'}}
// Explanation: Following the rule the above

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{

   vector<vector<int>> vis(n, vector<int>(m, 0));
   queue<pair<int, int>> q;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (mat[i][j] == 'O' && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
         {
            q.push({i, j});
            vis[i][j] = 1;
         }
      }
   }
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   while (!q.empty())
   {
      int row = q.front().first;
      int col = q.front().second;
      //   mat[row][col] = 'X';
      q.pop();
      for (int i = 0; i < 4; i++)
      {
         int dr = row + movx[i];
         int dc = col + movy[i];
         if (dr >= 0 && dr < n && dc >= 0 && dc < m)
         {
            if ((!vis[dr][dc]) && mat[dr][dc] == 'O')
            {
               q.push({dr, dc});
               vis[dr][dc] = 1;
            }
         }
      }
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (!vis[i][j] && mat[i][j] == 'O')
         {
            mat[i][j] = 'X';
         }
      }
   }
   return mat;
}
int main()
{

   return 0;
}