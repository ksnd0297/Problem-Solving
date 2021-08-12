#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool match(const string& w, const string& s) {
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		pos++;

	if (pos == w.size()) return pos == s.size();
	if(w[pos] == '*')
		for (int skip = 0; pos + skip <= s.size(); skip++) {
			if (match(w.substr(pos + 1), s.substr(pos + skip))) return true;
		}
	return false;
}

int main() {
	int C; cin >> C;
	while (C--) {
		string w; cin >> w; //wardCard
		int N; cin >> N;
		vector<string> file;
		for (int i = 0; i < N; i++) {
			string s; cin >> s; // fileName
			if (match(w, s)) file.push_back(s);
		}
		sort(file.begin(), file.end());
		for (int i = 0; i < file.size(); i++) cout << file[i] << '\n';
	}
	return 0;
}