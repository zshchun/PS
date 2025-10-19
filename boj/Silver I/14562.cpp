#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789

void bfs(int s, int t) {
	int cur, end, step;
	queue<tup> q;
	q.push(tup(s, t, 0));

	while (!q.empty()) {
		tie(cur, end, step) = q.front();
		q.pop();
		if (cur == end) {
			cout << step << endl;
			break;
		}
		if (cur > end) continue;
		if (cur+1 <= 300) 
			q.push(tup(cur+1, end, step+1));
		if (cur*2 <= 300)
			q.push(tup(cur*2, end+3, step+1));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, c, s, t;
	cin >> c;
	for (i=0;i<c;i++) {
		cin >> s >> t;
		bfs(s, t);
	}

	return 0;
}
