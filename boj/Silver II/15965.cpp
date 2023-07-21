#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll g[7368788];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, K;
	vector<ll> prime;
	cin >> K;
	for (i=2;i<=7368787;i++) {
		j = i + i;
		while (j <= 7368787) {
			g[j] = 1;
			j += i;
		}
	}
	for (i=1;i<=7368787;i++) {
		if (!g[i])
			prime.push_back(i);
	}

	cout << prime[K] << endl;;
	
	return 0;
}
