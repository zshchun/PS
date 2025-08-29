#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> v;
		pq.push(v);
	}
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		a += b;
		ans += a;
		pq.push(a);
	}
	cout << ans << endl;

	return 0;
}
