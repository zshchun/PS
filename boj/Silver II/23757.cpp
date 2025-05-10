#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x, N, M;
	cin >> N >> M;
	priority_queue<int> present;

	for (i=0;i<N;i++) {
		cin >> j;
		present.push(j);
	}

	for (i=0;i<M;i++) {
		cin >> x;
		j = present.top();
		present.pop();

		if (j < x) {
			cout << "0\n";
			return 0;
		} else if (j > x) {
			present.push(j - x);
		}
	}
	cout << "1\n";

	return 0;
}
