#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int T, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v;
	cin >> T;
	while (T--) {
		cin >> M;
		priority_queue<int, vector<int>, greater<int>> r;
		priority_queue<int> l;
		cout << (M+1) / 2 << endl;
		for (i=1;i<=M;i++) {
			cin >> v;

			r.push(v);
			l.push(r.top());
			r.pop();

			r.push(l.top());
			l.pop();

			if (l.size() != r.size()) {
				l.push(r.top());
				r.pop();
			}

			if (i >= 20 && (i % 20) == 0)
				cout << endl;

			if (i & 1)
				cout << l.top() << ' ';
		}
		cout << endl;
	}
	return 0;
}
