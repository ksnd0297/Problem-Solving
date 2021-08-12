#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int L[4][3][2] = {
	{{0,0},{1,0},{1,1}}, // 1)
	{{0,0},{0,1},{1,1}}, // 2)
	{{0,0},{1,0},{1,-1}}, // 3)
	{{0,0},{1,0},{0,1}} // 4)
};
int H, W; // 높이 너비

int game(vector<vector<int>>& board);
bool cover(vector<vector<int>>& board, int how, int y, int x, int value);

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> H >> W;
		vector<vector<int>> board(21, vector<int>(21, 0));

		char input;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> input;
				if (input == '#') board[i][j] = 1; //검은 블록
				else board[i][j] = 0; // 흰 블록
			}
		}
		cout << game(board) << '\n';
	}
}

int game(vector<vector<int>>& board) {
	int y = -1; int x = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == 0) { y = i; x = j; break; }
		}if (y != -1) break;
	}

	if (y == -1) return 1;

	int ans = 0;
	for (int how = 0; how < 4; how++) {
		if (cover(board, how, y, x, 1))
			ans += game(board);
		cover(board, how, y, x, -1);
	}
	return ans;
}

bool cover(vector<vector<int>>& board, int how, int y, int x, int value) {
	bool ans = true;
	int nowY = y; int nowX = x;
	for (int i = 0; i < 3; i++) {
		int dirY = nowY + L[how][i][0]; int dirX = nowX + L[how][i][1];
		if (!(dirY >= 0 && dirY < H && dirX >= 0 && dirX < W)) ans = false;
		else if ((board[dirY][dirX] += value) > 1) ans = false;
	}
	return ans;
}