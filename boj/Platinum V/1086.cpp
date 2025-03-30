#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, K, ans;
ll mod[51];
string s[15];
vector<pa> a;
ll dp[1<<15][100];

ll bitmask(int bitmap, ll n) {
	ll ret = 0, x, d, i;
	if (__builtin_popcount(bitmap) == N)
		return (n % K) == 0;

	if (dp[bitmap][n] != -1)
		return dp[bitmap][n];

	for (i=0;i<N;i++) {
		if (bitmap & (1<<i)) continue;
		tie(x, d) = a[i];
		ret += bitmask(bitmap | (1<<i), (n * mod[d] + x) % K);
	}
	return dp[bitmap][n] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, x, total = 1, g;
	cin >> N;
	fill_n(&dp[0][0], (1<<15)*100, -1);

	for (i=0;i<N;i++) {
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
		total *= (i+1);
	}
	cin >> K;

	mod[0] = 1 % K;
	for (i=1;i<51;i++)
		mod[i] = (mod[i-1] * 10) % K;

	for (i=0;i<N;i++) {
		x = 0;
		for (j=0;j<s[i].size();j++)
			x += (s[i][j] - '0') * mod[j] % K;
		x %= K;
		a.push_back(pa(x, s[i].size()));
	}
	
	ans = bitmask(0, 0);
	g = gcd(ans, total);

	cout << ans / g  << '/' << total / g << endl;

	return 0;
}
