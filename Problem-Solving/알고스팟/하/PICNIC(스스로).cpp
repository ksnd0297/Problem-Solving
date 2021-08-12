#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool areFriends[10][10];

int Pair(vector<bool>& pa, int N) { //짝지어줄 학생 pa배열, 총 학생의 수
	int FirstPair = -1; // 친구 A
	for (int i = 0; i < N; i++) {
		if (pa[i] == false) { FirstPair = i; break; } // 짝을 아직 못찾은 친구를 찾음 사전순으로 찾기 위해 FirstPair 에 저장
	}

	if (FirstPair == -1) return 1; // 짝을 모두 찾았기에 경우의 수 1 추가

	int ans = 0;
	for (int WithPair = FirstPair + 1; WithPair < N; WithPair++) { // 친구 B && 사전 순으로 0 -> 1, 2, 3 / 1-> 2,3 / 2 -> 3
		if (!pa[WithPair] && areFriends[FirstPair][WithPair]) {
			pa[FirstPair] = pa[WithPair] = true; // 친구 A 와 친구 B를 짝 지어 줌
			ans += Pair(pa, N);
			pa[FirstPair] = pa[WithPair] = false; // 다음 경우를 위해 친구 A와 친구 B 짝 해제
		}
	}
	return ans;
}

int main() {
	int C; cin >> C; // 3
	while (C--) {
		int N, M; cin >> N >> M; // 4 6

		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b; // 0 1 1 2 2 3 3 0 0 2 1 3
			areFriends[a][b] = areFriends[b][a] = true;
		}

		vector<bool> pa(N, false);
		cout << Pair(pa, N) << '\n';
		memset(areFriends, false, sizeof(areFriends)); // 친구배열 초기화
	}
	return 0;
}