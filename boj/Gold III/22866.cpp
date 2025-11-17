#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	vector<int> a(n+1);
	vector<int> ans(n+1, INF);
	vector<int> cnt(n+1);
	vector<int> l, r;

	for (i=1;i<=n;i++) {
		cin >> a[i];
		while (!l.empty()) {
			if (a[l.back()] > a[i]) {
				ans[i] = l.back();
				cnt[i] += l.size();
				break;
			} else {
				l.pop_back();
			}
		}
		l.push_back(i);
	}

	for (i=n;i>=1;i--) {
		while (!r.empty()) {
			if (a[r.back()] > a[i]) {
				if (r.back() - i < abs(ans[i] - i))
					ans[i] = r.back();
				cnt[i] += r.size();
				break;
			} else {
				r.pop_back();
			}
		}
		r.push_back(i);
	}

	for (i=1;i<=n;i++) {
		cout << cnt[i] << ' ';
		if (cnt[i] > 0) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
