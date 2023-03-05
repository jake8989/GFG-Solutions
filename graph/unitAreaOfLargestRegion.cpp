/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
// Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
// Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
// Output: 5
// Explanation: The grid is-
// 1 1 1 0
// 0 0 1 0
// 0 0 0 1
// The largest region of 1's is colored
// in orange.
// void dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &vis, int &len)
// {
//    int n = grid.size();
//    int m = grid[0].size();
//    if (row < 0 || row >= n || col < 0 || col >= m)
//       return;
//    if (vis[row][col])
//       return;
//    vis[row][col] = 1;
//    len++;
//    for (int i = -1; i <= 1; i++)
//    {
//       for (int j = -1; j <= 1; j++)
//       {
//          int dr = row + i;
//          int dc = col + j;
//          if (dr >= 0 && dr < n && dc >= 0 && dc < m && (!vis[dr][dc]) && grid[dr][dc] == 1)
//          {
//             dfs(dr, dc, grid, vis, len);
//          }
//       }
//    }
// }
int findMaxArea(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   int ans = 0;
   int len = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 1 && (!vis[i][j]))
         {
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            len = 1;
            while (!q.empty())
            {
               int r = q.front().first;
               int c = q.front().second;
               q.pop();
               for (int i = -1; i <= 1; i++)
               {
                  for (int j = -1; j <= 1; j++)
                  {
                     int dr = i + r;
                     int dc = j + c;
                     if (dr >= 0 && dr < n && dc >= 0 && dc < m && (!vis[dr][dc]) && grid[dr][dc] == 1)
                     {
                        q.push({dr, dc});
                        vis[dr][dc] = 1;
                        len++;
                     }
                  }
               }
            }
            ans = max(ans, len);
         }
      }
   }
   return ans;
}

int main()
{

   return 0;
}