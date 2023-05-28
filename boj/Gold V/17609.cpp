#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

bool is_palindrome(string &s) {
	ll i, len = s.size();
	for (i=0;i<len/2;i++) {
		if (s[i] != s[len-1-i])
			return false;
	}
	return true;
}

bool dfs(string &s, int l, int r, int c) {
	if (l >= r)
		return true;
	if (s[l] == s[r]) {
		return dfs(s, l+1, r-1, c);
	} else if (c > 0) {
		return false;
	} else {
		return (dfs(s, l, r-1, c+1) || dfs(s, l+1, r, c+1));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, j;
	cin >> n;
	for (i=0;i<n;i++) {
		string s, t;
		cin >> s;
		if (is_palindrome(s)) {
			cout << "0\n";
		} else {
			bool ok = dfs(s, 0, s.size()-1, 0);
			if (ok)
				cout << "1\n";
			else
				cout << "2\n";
		}
	}
	return 0;
}
