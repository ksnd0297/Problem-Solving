#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int S[501], cache[501];

int lis(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < N; next++) {
		if (S[start] < S[next]) ret = max(ret, lis(next) + 1);
	}
	return ret;
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> S[i];
		int maxlen = 0;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < N; i++) maxlen = max(maxlen, lis(i));
		cout << maxlen << '\n';
	}
	return 0;
}