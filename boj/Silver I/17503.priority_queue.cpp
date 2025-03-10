#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, M, K, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, x, y, v=0;
	cin >> N >> M >> K;
	vector<pa> a(K);
	for (i=0;i<K;i++)
		cin >> a[i].second >> a[i].first;
	sort(a.begin(), a.end());

	priority_queue<pa, vector<pa>, greater<pa>> pq;

	for (i=0;i<K;i++) {
		tie(x, y) = a[i];
		pq.push(pa(y, x));
		v += y;
		if (pq.size() > N) {
			v -= pq.top().first;
			pq.pop();
		}
		if (pq.size() == N && v >= M) {
			cout << x << endl;
			return 0;
		}
	}

	cout << "-1\n";

	return 0;
}
