#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int prime[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x, n;
	cin >> n;
	fill_n(prime, 10001, 1);
	prime[0] = 0;
	prime[1] = 0;
	for (i=2;i*i<10001;i++) {
		for (j=i*2;j<10001;j+=i) {
			prime[j] = 0;
		}
	}

	for (i=0;i<n;i++) {
		cin >> x;
		for (j=x/2;j>=2;j--) {
			if (prime[j] && prime[x-j]) {
				cout << j << ' ' << x-j << endl;
				break;
			}
		}
	}
	return 0;
}
