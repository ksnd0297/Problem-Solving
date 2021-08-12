#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool visited[10001];

int D(int qus) { return (qus * 2) % 10000; }
int S(int qus) {
	if (qus == 0) return 9999;
	else return qus - 1;
}
int L(int qus) { return (qus % 1000) * 10 + qus / 1000; }
int R(int qus) { return (qus % 10) * 1000 + qus / 10; }

void bfs(int A, int B) {
	queue<pair<int, string>> q;
	q.push({ A,"" });
	while (!q.empty()) {
		int qus = q.front().first; string ans = q.front().second; q.pop();
		visited[qus] = true;
		
		if (B == qus) { cout << ans << '\n'; break; }
		int d = D(qus);
		if (!visited[d]) { q.push(make_pair(d, ans + 'D')); visited[d] = true; };
		int s = S(qus);
		if (!visited[s]) { q.push(make_pair(s, ans + 'S')); visited[s] = true; };
		int l = L(qus);
		if (!visited[l]) { q.push(make_pair(l, ans + 'L')); visited[l] = true; };
		int r = R(qus);
		if (!visited[r]) { q.push(make_pair(r, ans + 'R')); visited[r] = true; };
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int A, B; cin >> A >> B;
		bfs(A, B);
		for (int i = 0; i < 10001; i++) visited[i] = false;
	}
	return 0;
}