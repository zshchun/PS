#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 12345678900ULL

ll mn = INF, mx = 0, n;
string ans_mn, ans_mx;

char c[11];
string s;

void backtrack(int x, int used) {
	int i;
	if (x == n+1) {
		ll sum = stol(s);
		if (sum < mn) {
			mn = sum;
			ans_mn = s;
		}
		if (sum > mx) {
			mx = sum;
			ans_mx = s;
		}
		return;
	}
	for (i=0;i<=9;i++) {
		if (used & (1<<i)) continue;
		s[x] = i + '0';
		if (x > 0) {
			if (c[x-1] == '<' && s[x-1] >= s[x]) continue;
			if (c[x-1] == '>' && s[x-1] <= s[x]) continue;
		}
		backtrack(x+1, used | (1<<i));
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	s.resize(n+1);
	for (int i=0;i<n;i++)
		cin >> c[i];
	backtrack(0, 0);
	cout << ans_mx << endl;
	cout << ans_mn << endl;
	return 0;
}
