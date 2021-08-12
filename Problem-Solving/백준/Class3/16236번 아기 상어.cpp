#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef struct Dir {
	int y;
	int x;
}Dir;

Dir moveDir[4] = { {-1,0},{0,-1},{1,0},{0,1} };

typedef struct pass {
	int time;
	int y;
	int x;
}pass;

bool operator < (const pass& p1, const pass& p2) {
	if (p1.time > p2.time) return true;
	else if (p1.time == p2.time && p1.y > p2.y) return true;
	else if (p1.time == p2.time && p1.y == p2.y && p1.x > p2.x) return true;
	return false;
}

int arr[20][20];
bool visited[20][20];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	pair<int, int > start;
	for (int i = 0; i < N; i++) { // ют╥б
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				start = { i,j };
				arr[i][j] = 0;
			}
		}
	}
	int cnt = 0;
	int durTime = 0;

	queue<pair<pair<int, int>, int>> q;
	q.push({ { start }, 2 }); // startY startX size
	while (!q.empty()) {
		int y = q.front().first.first; int x = q.front().first.second; int size = q.front().second;
		q.pop();
		memset(visited, false, sizeof(visited));
		priority_queue<pass> temp; temp.push({ 0,y,x }); visited[y][x] = true;
		while (!temp.empty()) {
			int iter = temp.size();
			priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
			for (int j = 0; j < iter; j++) {
				int curY = temp.top().y; int curX = temp.top().x; int curTime = temp.top().time; temp.pop();
				for (int i = 0; i < 4; i++) {
					int dirY = curY + moveDir[i].y; int dirX = curX + moveDir[i].x; int dirTime = curTime + 1;
					if (dirY >= 0 && dirY < N && dirX >= 0 && dirX < N) {
						if (!visited[dirY][dirX]) {
							if (arr[dirY][dirX] <= size) {
								temp.push({ dirTime,dirY,dirX }); visited[dirY][dirX] = true;
								if (arr[dirY][dirX] >= 1 && arr[dirY][dirX] < size) pq.push({ { dirY,dirX},dirTime });
							}
						}
					}
				}
			}
			if(!pq.empty()) {
				cnt++;
				if (cnt == size) { q.push({ {pq.top().first},size + 1 }); cnt = 0; }
				else q.push({ { pq.top().first },size });
				arr[pq.top().first.first][pq.top().first.second] = 0;
				durTime += pq.top().second;
				break;
			}
		}
	}
	cout << durTime;
	return 0;
}