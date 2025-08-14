#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int f[101] = { 0, 500, 300, 300, 200, 200, 200, 50, 50, 50, 50, 30, 30, 30, 30, 30, 10, 10, 10, 10, 10, 10,  };
int g[65] = { 0, 512, 256, 256, 128, 128, 128, 128, 64, 64, 64, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, i, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << (f[a] + g[b]) * 10000 << endl;
	}
	return 0;
}
