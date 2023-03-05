/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   int sx = source.first;
   int sy = source.second;
   int dx = destination.first;
   int dy = destination.second;
   vector<vector<int>> dist(n, vector<int>(m, 1e9));
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
   pq.push({0, {sx, sy}});
   dist[sx][sy] = 0;
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   while (!pq.empty())
   {
      // int dis = pq.top().first;
      int row = pq.top().second.first;
      int col = pq.top().second.second;
      pq.pop();
      for (int i = 0; i < 4; i++)
      {
         int dr = row + movx[i];
         int dc = col + movy[i];
         if (dr >= 0 && dr < n && dc >= 0 && dc < m && grid[dr][dc] == 1)
         {
            if (dist[row][col] + 1 < dist[dr][dc])
            {
               dist[dr][dc] = dist[row][col] + 1;
               pq.push({dist[dr][dc], {dr, dc}});
            }
         }
      }
   }
   if (dist[dx][dy] == 1e9)
      return -1;
   return dist[dx][dy];
}
int main()
{

   return 0;
}