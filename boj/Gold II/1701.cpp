#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans;
int lps[5001];
// kmp
void make_lps(string &pat) {
	int i, j;
	fill_n(lps, pat.size(), 0);

	for (j=0,i=1;i<pat.size();i++) {
		while (j > 0 && pat[i] != pat[j])
			j = lps[j-1];

		if (pat[i] == pat[j]) {
			lps[i] = ++j;
			ans = max(ans, lps[i]);
		}
	}
}

vector<int> kmp(string &s, string &pat) {
	int i, j;
	vector<int> ret;
	make_lps(pat);
	for (j=0,i=0;i<s.size();i++) {
		while (j > 0 && s[i] != pat[j])
			j = lps[j-1];

		if (s[i] == pat[j]) {
			j++;
			if (j == pat.size()) {
				ret.push_back(i-j);
				j = lps[j-1];
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	string s;
	cin >> s;

	for (i=0;i<s.size();i++) {
		string t = s.substr(i);
		make_lps(t);
	}
	cout << ans << endl;
	return 0;
}
