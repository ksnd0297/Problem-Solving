#include <iostream>
#include <cstring>

using namespace std;

int N, triangle[100][100];
int cache[100][100];

int path(int y, int x) {
	if (y == N - 1) return triangle[y][x];
	int& ret = cache[y][x];
	if (ret != -1) return cache[y][x];
	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> triangle[i][j];
			}
		}
		memset(cache, -1, sizeof(cache));
		cout << path(0, 0) << '\n';
	}
	return 0;
}