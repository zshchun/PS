#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

string dp[41];
// big number string
string add(string s, string t) {
	string r;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int carry = 0;

	for (int i=0;i<max(s.size(), t.size());i++) {
		int x = 0;
		if (i < s.size())
			x += s[i] - '0';
		if (i < t.size())
			x += t[i] - '0';
		x += carry;
		if (x > 9) carry = 1;
		else carry = 0;
		r += ('0' + (x % 10));
	}
	if (carry) r += '1';
	reverse(r.begin(), r.end());
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, x;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	dp[0] = "1";
	for (i=1;i<=s.size();i++) {
		if (i >= 2 && s[i-1] != '0') {
			x = s[i-2] - '0' + (s[i-1] - '0') * 10;
			if (x <= 34 && x >= 1)
				dp[i] = add(dp[i], dp[i-2]);
		}
		if (s[i-1] != '0')
			dp[i] = add(dp[i], dp[i-1]);
	}
	cout << dp[s.size()] << endl;
	return 0;
}
