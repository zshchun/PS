#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define INF 1234567890
#define endl "\n"
ll N, K;

int m[100001];
int o[100001];

void bfs() {
	int cur;
	queue<int> q;
	q.push(N);
	m[N] = -1;
	o[N] = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur*2 <= 100000 && (o[cur] + 1) < o[cur*2]) { // && cur < K) {
			q.push(cur*2);
			m[cur*2] = cur;
			o[cur*2] = o[cur] + 1;
		}
		if (cur+1 <= 100000 && (o[cur] + 1) < o[cur+1]) { // && cur < K) {
			q.push(cur+1);
			m[cur+1] = cur;
			o[cur+1] = o[cur] + 1;
		}
		if (cur-1 >= 0 && (o[cur] + 1) < o[cur-1]) { // && cur > K) {
			q.push(cur-1);
			m[cur-1] = cur;
			o[cur-1] = o[cur] + 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	int n = K, ans = 0, prev, pprev;
	cin >> N >> K;
	for (int i=0;i<=100000;i++) {
		o[i] = INF;
	}
	bfs();
	n = K;
	prev = K;
	pprev = K;

	while (n != N) {
		pprev = prev;
		prev = n;
		n = m[n];
		m[prev] = pprev;
		ans++;
	}
	m[n] = prev;
	cout << ans << endl;
	n = N;
	cout << n << ' ';
	while (n != K) {
		cout << m[n] << ' ';
		n = m[n];
	}
	cout << endl;

	return 0;
}
