#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789
int n, m, l;
int a[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x, y, z;
	priority_queue<tup> pq;

	cin >> n >> m >> l;

	if (n > 0) {
		for (i=0;i<n;i++)
			cin >> a[i];

		sort(a, a+n);

		pq.push(tup(a[0], a[0], 1));

		for (i=1;i<n;i++) {
			x = a[i] - a[i-1];
			pq.push(tup(x, x, 1));
		}
		pq.push(tup(l-a[n-1], l-a[n-1], 1));
	} else {
		pq.push(tup(l, l, 1));
	}

	for (i=0;i<m;i++) {
		tie(x, y, z) = pq.top();
		pq.pop();
		z++;
		x = (y + z - 1) / z;
		pq.push(tup(x, y, z));
	}
	tie(x, y, z) = pq.top();

	cout << x << endl;

	return 0;
}
