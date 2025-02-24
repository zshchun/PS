#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	deque<int> q;
	int n, i, j, ans;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> j;
		q.push_back(j);
	}

	sort(q.begin(), q.end());
	ans = 0;
	while (!q.empty()) {
		while (!q.empty() && q.front() == 0)
			q.pop_front();
		if (!q.empty()) {
			for (i=0;i<q.size();i++)
				if (q[i] & 1) break;

			if (i == q.size()) {
				for (i=0;i<q.size();i++)
					q[i] /= 2;
			} else {
				q[i]--;
			}
			ans++;
		}
	}
	cout << ans << endl;


	return 0;
}
