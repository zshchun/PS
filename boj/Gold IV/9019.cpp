#include <bits/stdc++.h>
using namespace std;
int dp[10001];

int shift(int n, int s) {
	int p[4], r = 0, i;
	for(i=3;i>=0;i--) {
		p[i] = n % 10;
		n /= 10;
	}
	for(i=s;i<s+4;i++) {
		r = r * 10 + p[i%4];
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, f, t, v, i;
	cin >> T;
	queue<int> q;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		q = queue<int>();
		cin >> f >> t;
		q.push(f);
		dp[f] = f<<8 | '0';
		v = 0;
		while (!q.empty()) {
			v = q.front();
			q.pop();
			if (v == t) break;
			if (!dp[(v*2)%10000]) { // double
				q.push((v*2)%10000);
				dp[(v*2)%10000] = v<<8 | 'D';
			}
			if (!dp[v ? v-1 : 9999]) { // subtraction
				q.push(v ? v-1 : 9999);
				dp[v ? v-1 : 9999] = v<<8 | 'S';
			}
			if (!dp[(shift(v, 1))]) { // shift left
				q.push(shift(v, 1));
				dp[shift(v, 1)] = v<<8 | 'L';
			}
			if (!dp[(shift(v, 3))]) { // shift right
				q.push(shift(v, 3));
				dp[shift(v, 3)] = v<<8 | 'R';
			}

		}
		string s;
		while (v != f) {
			v = dp[v];
			s += (char)v;
			v >>= 8;
		}
		for (i=s.size()-1;i>=0;i--)
			cout << s[i];
		if (s.size() > 0)
			cout << '\n';
	}
	return 0;
}
