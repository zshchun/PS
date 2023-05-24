#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

bool is_palindrome(string &s) {
	ll i, len = s.size();
	for (i=0;i< len / 2;i++) {
		if (s[i] != s[len-1-i])
			return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	ll i, ans;
	cin >> s;
	ll len = s.size();
	for (i=0;i<=len;i++) {
		t = s.substr(0, i);
		reverse(t.begin(), t.end());
		t = s + t;
		if (is_palindrome(t)) {
			cout << len + i << endl;
			break;
		}
	}

	return 0;
}
