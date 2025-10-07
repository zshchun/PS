#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
unordered_map<string, int> a;
unordered_set<string> w;
int ans[9];

void dfs(string &s, int x, string t) {
	if (x >= 9) return;
	dfs(s, x+1, t);
	string next = t + s[x];
	if (next.size() >= 4 && a.find(next) != a.end() && w.count(next) == 0) {
		for (int i=0;i<9;i++) {
			for (int j=0;j<next.size();j++) {
				if (j && next[j] == next[j-1]) continue;
				if (s[i] == next[j]) ans[i] += a[next];
			}
		}
		w.insert(next);
	}
	dfs(s, x+1, next);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, mn, mx;
	string s;

	while (1) {
		cin >> s;
		if (s == "-") break;
		sort(s.begin(), s.end());
		a[s]++;
	}

	while (1) {
		cin >> s;
		if (s == "#") break;
		sort(s.begin(), s.end());
		memset(ans, 0, sizeof(ans));
		w.clear();
		dfs(s, 0, "");
		mn = INF;
		mx = 0;
		string min_str, max_str;
		for (i=0;i<9;i++) {
			if (i && s[i] == s[i-1]) continue;
			if (ans[i] < mn) {
				min_str = s[i];
				mn = ans[i];
			} else if (ans[i] == mn)
				min_str += s[i];
			if (ans[i] > mx) {
				max_str = s[i];
				mx = ans[i];
			} else if (ans[i] == mx)
				max_str += s[i];
		}
		cout << min_str << ' ' << mn << ' ' << max_str << ' ' << mx << endl;
	}
	return 0;
}
