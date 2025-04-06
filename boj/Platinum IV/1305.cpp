#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int lps[1000001];
// kmp
void make_lps(string &pat) {
	int i, j;
	for (i=1,j=0;i<pat.size();i++) {
		while (j > 0 && pat[i] != pat[j])
			j = lps[j-1];
		if (pat[i] == pat[j])
			lps[i] = ++j;
	}
}

int kmp(string &s, string &pat) {
	int i, j, ret = 0;
	for (i=0,j=0;i<s.size();i++) {
		while (j > 0 && s[i] != pat[j])
			j = lps[j-1];
		if (s[i] == pat[j]) {
			j++;
			if (j == pat.size()) {
				ret++;
				j = lps[j-1];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int L;
	string s;
	cin >> L >> s;

	make_lps(s);

	cout << L - lps[L-1] << endl;

	return 0;
}
