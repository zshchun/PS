#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,char> pa;
#define INF 1234567890
#define endl "\n"

vector<vector<char>> words[26];

bool check(vector<char> &a, vector<char> &b) {
	for (int i=0;i<26;i++) {
		if (a[i] < b[i])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, mn, mx;
	string s;

	while (1) {
		cin >> s;
		if (s == "-") break;
		vector<char> a(26);
		for (char &c : s)
			a[c-'A']++;

		for (i=0;i<26;i++)
			if (a[i])
				words[i].push_back(a);
	}

	while (1) {
		cin >> s;
		if (s == "#") break;
		vector<char> a(26);
		int cnt[26] = {0, };
		mx = 0;
		mn = INF;

		for (char &c : s)
			a[c-'A']++;

		for (i=0;i<26;i++) {
			if (!a[i]) continue;
			for (vector<char> &w : words[i])
				if (check(a, w))
					cnt[i]++;

			mn = min(mn, cnt[i]);
			mx = max(mx, cnt[i]);
		}

		for (i=0;i<26;i++) {
			if (a[i] && mn == cnt[i])
			cout << (char)('A'+i);
		}
		cout << ' ' << mn << ' ';

		for (i=0;i<26;i++) {
			if (a[i] && mx == cnt[i])
			cout << (char)('A'+i);
		}
		cout << ' ' << mx << endl;
	}

	return 0;
}
