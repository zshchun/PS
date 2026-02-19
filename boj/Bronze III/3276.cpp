#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j, ans = INF, a, b;
	cin >> N;
	for (i=1;i<=100;i++) {
		for (j=1;j<=100;j++) {
			if (i * j >= N && ans > i + j) {
				ans = i + j;
				a = i;
				b = j;
			}
		}
	}
	cout << a << ' ' << b << endl;
	return 0;
}
