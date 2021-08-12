#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999;
bool Switch[10][16] = { // 스위치 배열
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

bool check(vector<int>& Clock) {
	bool ans = true;
	for (int i = 0; i < (int)Clock.size(); i++) {
		if (Clock[i] != 12) { ans = false; break; }
	}
	return ans;
}

void go(vector<int>& Clock, int swtch) {
	for (int i = 0; i < (int)Clock.size(); i++) {
		if (Switch[swtch][i] == 1) {
			Clock[i] += 3;
			if (Clock[i] == 15) Clock[i] = 3;
		}
	}
}

int change(vector<int>& Clock, int swtch) {
	if (swtch == 10) return check(Clock) ? 0 : INF;
	int ans = INF;
	for (int i = 0; i < 4; i++) { // 4번을 통해 원래대로 되돌리는 연산
		ans = min(ans, i + change(Clock, swtch + 1));
		go(Clock, swtch);
	}
	return ans;
}


int main() {
	int C; cin >> C;
	while (C--) {
		vector<int> Clock(16, 0); // 입력을 받을 배열
		for (int i = 0; i < 16; i++) cin >> Clock[i];

		int ans = change(Clock, 0);
		if (ans == 9999) cout << -1 << '\n';
		else cout << ans << '\n';
	}
	return 0;
}