#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, L;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, mod, s, e, m;
	cin >> N >> L;
	for (i=L;i<=100;i++) {
		mod = i & 1 ? 0 : i / 2;
		if (N % i == mod) {
			m = N / i;
			s = m - (i-1) / 2;
			e = m + (i-1) / 2;
			if (s < 0) continue;
			for (j=s;j<=e;j++)
				cout << j << ' ';
			if (mod)
				cout << e + 1 << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
