#include <iostream>

using namespace std;

char word[5][5];

typedef struct Dir {
	int y;
	int x;
}Dir;

Dir moveDir[] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

bool hasWord(int y, int x, string& str,int pos) {
	if (str.size() == pos) return 1;
	for (int i = 0; i < 8; i++) {
		int nextY = y + moveDir[i].y; int nextX = x + moveDir[i].x;
		if (word[nextY][nextX] == str[pos]) {
			if (hasWord(nextY, nextX, str, pos + 1)) { return 1; }
		}
	}
	return 0;
}

int main() {
	int C; cin >> C;
	while (C--) {
		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 5; x++)
				cin >> word[y][x];

		int N; string str;
		cin >> N;
		while (N--) {
			cin >> str;
			
			bool flag = false;
			for (int y = 0; y < 5; y++) {
				for (int x = 0; x < 5; x++) {
					if (str[0] == word[y][x]) {
						if (hasWord(y, x, str, 1)) { flag = true; break;}
					}
				}if (flag) break;
			}

			if (flag) cout << str << ' ' << "YES\n";
			else cout << str << ' ' << "NO\n";
		}
	}
}