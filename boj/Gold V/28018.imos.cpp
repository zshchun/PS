#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, Q;
int imos[1000002];
int a[1000002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, s, e, q, sum = 0;
	cin >> N;
	for (i=1;i<=N;i++) {
		cin >> s >> e;
		imos[s]++;
		imos[e+1]--;
	}

	// imos, difference array
	for (i=1;i<=1000000;i++) {
		sum += imos[i];
		a[i] = sum;
	}

	cin >> Q;
	for (i=0;i<Q;i++) {
		cin >> q;
		cout << a[q] << endl;
	}
	return 0;
}
