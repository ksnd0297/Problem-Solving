#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pos = 1;

string QUAD(string& ans) { 
	bool div = false;
	string Q[4];
	for (int i = 0; i < 4; i++) {
		if (ans[pos] == '\0') break;
		if (ans[pos] == 'x') { div = true;}
		Q[i] += ans[pos++];
		if (div) { Q[i] += QUAD(ans); div = false; }
	}
	return (Q[2] + Q[3] + Q[0] + Q[1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int C; cin >> C;
	while (C--) {
		string ans; cin >> ans;
		if (ans[0] != 'x') cout << ans << '\n';
		else {
			ans = QUAD(ans);
			cout << 'x' << ans << '\n';
			pos = 1;
		}
	}
	return 0;
}