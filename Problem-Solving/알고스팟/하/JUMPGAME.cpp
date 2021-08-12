#include <iostream>

using namespace std;

int map[101][101];
int cache[101][101];
int N;

int jump(int y, int x) {
	if (y >= N || x >= N) return 0;
	if (y == N - 1 && x == N - 1) { cache[y][x] = 1; return 1; }
	if (cache[y][x] != -1) return cache[y][x];
	int jumpSize = map[y][x];
	return cache[y][x] = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				cache[i][j] = -1;
			}
		jump(0, 0);

		if (cache[N-1][N-1] == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}