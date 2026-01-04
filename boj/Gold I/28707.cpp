#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef pair<int, vector<int>> pv;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789

int N, M, ans = INF;
vector<int> a;
vector<tup> op;

bool is_sorted(vector<int> &v) {
	for (int i=1;i<v.size();i++)
		if (v[i-1] > v[i])
			return false;
	return true;
}

void dijkstra() {
	priority_queue<pv, vector<pv>, greater<pv>> pq;
	map<vector<int>, int> visited;
	pq.push(pv(0, a));
	while (!pq.empty()) {
		auto [cost, arr] = pq.top();
		pq.pop();
		if (is_sorted(arr))
			ans = min(ans, cost);

		for (auto &[l, r, c] : op) {
			swap(arr[l], arr[r]);
			if (visited.count(arr) == 0 || visited[arr] > cost + c) {
				visited[arr] = cost + c;
				pq.push(pv(cost + c, arr));
			}
			swap(arr[l], arr[r]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, l, r, c;
	cin >> N;
	a.resize(N);
	for (i=0;i<N;i++)
		cin >> a[i];
	cin >> M;
	op.resize(M);
	for (i=0;i<M;i++) {
		cin >> l >> r >> c;
		l--; r--;
		op[i] = tup(l, r, c);
	}
	dijkstra();

	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << endl;
	return 0;
}
