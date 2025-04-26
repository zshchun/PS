#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

bool prime[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	fill_n(prime, 1000001, 1);
	prime[1] = 0;

	for (i=2;i<=1000000;i++) {
		for (j=i+i;j<=1000000;j+=i) {
			prime[j] = 0;
		}
	}

	while (1) {
		cin >> i;
		if (i == 0) break;
		for (j=1;j<i;j++) {
			if (prime[j] && prime[i-j]) {
				cout << i << " = " << j << " + " << i-j << endl;
				break;
			}
		}
	}
	return 0;
}
