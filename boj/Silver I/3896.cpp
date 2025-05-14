#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int T;
bool prime[1300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> T;
	fill_n(prime, 1300001, 1);
	prime[0] = prime[1] = 0;
	for (i=2;i<=1300000;i++) {
		if (!prime[i]) continue;
		for (j=i+i;j<=1300000;j+=i)
			prime[j] = 0;
	}
	vector<int> p;
	for (i=2;i<=1300000;i++)
		if (prime[i])
			p.push_back(i);

	while (T--) {
		cin >> j;
		if (prime[j]) {
			cout << "0\n";
		} else {
			auto it = lower_bound(p.begin(), p.end(), j);
			cout << (*it) - *(it-1) << endl;
		}
	}
	return 0;
}
