#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;



string dp[101][101];
string string_add(string a, string b) {
	string result;
	char c = 0;
	for (size_t i=1;i<=max(a.length(), b.length());i++) {
		if (i <= a.length()) c += a[a.length()-i] - '0';
		if (i <= b.length()) c += b[b.length()-i] - '0';
		result += (c % 10) + '0';
		c /= 10;
	}
	if (c) result += c + '0';
	reverse(result.begin(), result.end());
	return result;
}
string ncr(int n, int r) {
	if (n == r || r == 0) return "1";
	if (dp[n][r] != "") return dp[n][r];
	dp[n][r] = string_add(ncr(n-1, r-1), ncr(n-1, r));
	return dp[n][r];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	cout << ncr(n, m) << '\n';
	return 0;
}
