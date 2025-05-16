#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, Q;
int a[(2<<20)+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, p;
	cin >> N >> Q;
	for (i=0;i<Q;i++) {
		p = 0;
		cin >> j;
		k = j;
		while (k >= 1) {
			if (a[k])
				p = k;
			k >>= 1;
		}
		if (!p) a[j] = 1;
		cout << p << endl;
	}
	return 0;
}
