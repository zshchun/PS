#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;
int a[3000001];

void bfs() {
	queue<pa> q;
	q.push(pa(1, 0));
	a[1] = 0;
	while (!q.empty()) {
		pa p = q.front();
		q.pop();
		int cur = p.first;
		int ans = p.second;
		if (cur == N) {
			cout << ans << endl;
			break;
		}

		if (cur > N) continue;
		if (!a[cur*3]) {
			q.push(pa(cur*3, ans+1));
			a[cur*3] = cur;

		}
		if (!a[cur*2]) {
			q.push(pa(cur*2, ans+1));
			a[cur*2] = cur;
		}
		if (!a[cur+1]) {
			q.push(pa(cur+1, ans+1));
			a[cur+1] = cur;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	bfs();

	int x = N;
	while (x) {
		cout << x << ' ';
		x = a[x];
	}
	return 0;
}
