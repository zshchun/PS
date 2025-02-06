#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
bool prime[100001];
vector<int> primes;
int a, b;

bool is_underprime(int x) {
	int cnt = 0, k = x;
	for (int &i : primes) {
		while (k % i == 0) {
			k /= i;
			cnt++;
		}
		if (i > k) break;
	}
	if (prime[k]) cnt++;
	if (cnt[prime]) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans = 0, cnt = 0;
	cin >> a >> b;
	fill_n(prime, 100001, 1);
	prime[0] = 0;
	prime[1] = 0;
	for (i=2;i<=sqrt(100000);i++) {
		for (j=i+i;j<=100000;j+=i) {
			prime[j] = 0;
		}
	}
	for (i=2;i<=sqrt(100000);i++) {
		if (prime[i])
			primes.push_back(i);
	}

	for (i=a;i<=b;i++) {
		if (is_underprime(i))
			ans++;
	}

	cout << ans << endl;

	return 0;
}
