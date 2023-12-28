#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, last, u, v;
	cin >> N;
	vector<pa> a;
	deque<int> ans;

	for (i=0;i<N;i++) {
		cin >> u >> v;
		a.push_back(pa(u, v));
	}
	sort(a.begin(), a.end());

	// longest increasing subsequence
	vector<int> idx;
	vector<int> lis;
	for (pa &p : a) {
		int cur = p.second;

		if (lis.empty() || lis.back() < cur) {
			idx.push_back(lis.size());
			lis.push_back(cur);
		} else {
			auto it = lower_bound(lis.begin(), lis.end(), cur);
			*it = cur;
			idx.push_back(it - lis.begin());
		}
	}

	cout << N - lis.size() << endl;

	last = lis.size() - 1;
	for (i=N-1;i>=0;i--) {
		if (idx[i] == last)
			last--;
		else
			ans.push_front(a[i].first);
	}

	for (int x : ans)
		cout << x << endl;

	return 0;
}
