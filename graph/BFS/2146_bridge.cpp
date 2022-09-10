#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int a[101][101];
int check[101][101]; 
int dist[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n;

void dfs(int x, int y, int cnt) 
{
	check[x][y] = cnt; 

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			if (check[nx][ny] == 0 &&
					a[nx][ny] == 1)
			{
				dfs(nx, ny, cnt);
			}
		}
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == 0 && a[i][j] == 1)
			{
				dfs(i, j, ++cnt);
			}
		}
	}

	int ans = 10001;
	for (int k = 1; k <= cnt; k++) 
	{
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = -1;
				if (check[i][j] == k)
				{
					q.push(make_pair(i, j));
					dist[i][j] = 0;
				}
			}
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < n)
				{
					if (dist[nx][ny] == -1) 
					{
						dist[nx][ny] = dist[x][y] + 1; 
						q.push(make_pair(nx, ny));
					}
				}
			}
		}

		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (check[i][j] != k && check[i][j] != 0) 
				{
					if (dist[i][j] - 1 < ans) 
						ans = dist[i][j] - 1; 
				}

			}
	}

	cout << ans << '\n';

}
