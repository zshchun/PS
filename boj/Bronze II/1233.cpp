#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int mx, ans;
int cnt[81];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, a, b, c, s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for (i=10101;i<1000000;i++) {
		a = i % 100;
		b = i / 100 % 100;
		c = i / 10000 % 100;
		if (a <= 0 || b <= 0 || c <= 0 || a > s1 || b > s2 || c > s3)
			continue;
		cnt[a + b + c]++;
	}
	for (i=1;i<=80;i++) {
		if (cnt[i] > mx) {
			ans = i;
			mx = cnt[i];
		}
	}
	cout << ans << endl;
	return 0;
}
