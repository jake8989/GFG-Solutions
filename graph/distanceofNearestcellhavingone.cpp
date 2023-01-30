/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
// Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
// Explanation: The grid is-
// 0 1 1 0
// 1 1 0 0
// 0 0 1 1
// 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
// (2,1) are at a distance of 1 from 1's at (0,1),
// (0,2), (0,2), (2,3), (1,0) and (1,1)
// respectively.

/// using dijkstra

vector<vector<int>> nearest(vector<vector<int>> grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   vector<vector<int>> dist(n, vector<int>(m, 1e9));
   // queue<pair<int, int>> q;
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 1)
         {
            pq.push({0, {i, j}});
            dist[i][j] = 1;
         }
      }
   }
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   while (!pq.empty())
   {
      /* code */
      int dis = pq.top().first;
      int row = pq.top().second.first;
      int col = pq.top().second.second;
      pq.pop();
      for (int i = 0; i < 4; i++)
      {
         int dr = row + movx[i];
         int dc = col + movy[i];
         if (dr >= 0 && dr < n && dc >= 0 && dc < m)
         {
            if (dist[dr][dc] > dis + 1)
            {
               dist[dr][dc] = dis + 1;
               pq.push({dist[dr][dc], {dr, dc}});
            }
         }
      }
   }
}
int main()
{

   return 0;
}