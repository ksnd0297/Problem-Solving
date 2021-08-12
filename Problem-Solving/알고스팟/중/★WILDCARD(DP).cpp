#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int cache[101][101];
string W, S;

bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) return ret = matchMemoized(w + 1, s + 1);

	if (w == (int)W.size()) return ret = (s == (int)S.size());
	if (W[w] == '*')
		if (matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1))) return ret = 1;

	return ret = 0;
}

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> W; 
		vector<string> file;
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> S;
			memset(cache, -1, sizeof(cache));
			if (matchMemoized(0, 0)) file.push_back(S);
		}
		sort(file.begin(), file.end());
		for (int i = 0; i < (int)file.size(); i++) cout << file[i] << '\n';
	}
}