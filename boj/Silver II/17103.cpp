#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int f[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, j, x, y, ans;
	cin >> T;
	for (i=2;i<=1000000;i++)
		f[i] = i;
	for (i=2;i<=1000000;i++) {
		for (j=i*2;j<=1000000;j+=i) {
			f[j] = 0;
		}
	}
//	vector<int> prime;
//	for (i=2;i<=1000000;i++) {
//		if (!f[i])
//			prime.push_back(i);
//	}
	while (T--) {
		cin >> y;
		ans = 0;
		for (i=2;i<y;i++) {
			x = f[i] + f[y-i];
			if (x == y) {
				ans++;
				if (i == y - i)
					ans++;
			}
		}
		cout << ans / 2 << endl;
	}

	return 0;
}
