#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char arr[5][5];

typedef struct Dir {
	int y;
	int x;
}Dir;

Dir moveDir[] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

bool boogle(int y, int x, string& qus) {
	queue < pair<pair<int, int>, int>> q; // y x check
	q.push({ { y,x },1 }); //qus[1] 을 체크해야함
	while (!q.empty()) {
		int DirY = q.front().first.first; int DirX = q.front().first.second; int check = q.front().second;  q.pop();
		if (check == qus.size()) return true;
		for (int i = 0; i < 8; i++) {
			int nextY = DirY + moveDir[i].y; int nextX = DirX + moveDir[i].x;
			if (nextY >= 0 && nextY < 5 && nextX >= 0 && nextX < 5) { //범위 안에서
				if (arr[nextY][nextX] == qus[check]) { //원하는 값일 경우
					q.push({ { nextY,nextX },check + 1 });
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int C; cin >> C;
	while (C--) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				cin >> arr[i][j];
	
		

		int N; string qus;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> qus;
			bool flag = false;
			for (int y = 0; y < 5; y++) {
				for (int x = 0; x < 5; x++) {
					if (qus[0] == arr[y][x]) { //PRETTY 의 P 발견
						if (boogle(y, x, qus)) { flag = true; break; }
					}
				}if (flag) break;
			}
			if (!flag) cout << qus << ' ' << "NO\n";
			else cout << qus << ' ' << "YES\n";
		}
	}
}