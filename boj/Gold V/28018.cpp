#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, Q;
int a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, s, e, q;
	priority_queue<int, vector<int>, greater<int>> pq;
	priority_queue<pa, vector<pa>, greater<pa>> pending;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> s >> e;
		pending.push(pa(s, e));
	}

	for (i=1;i<=1000000;i++) {
		while (!pending.empty() && pending.top().first <= i) {
			pq.push(pending.top().second);
			pending.pop();
		}
		while (!pq.empty() && pq.top() < i) {
			pq.pop();
		}
		a[i] = pq.size();
	}

	cin >> Q;
	for (i=0;i<Q;i++) {
		cin >> q;
		cout << a[q] << endl;
	}
	return 0;
}
