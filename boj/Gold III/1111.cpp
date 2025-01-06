#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, a, b;
	cin >> N;
	vector<int> ans;
	vector<int> v(N);
	for (i=0;i<N;i++)
		cin >> v[i];

	if (N <= 1) {
		cout << "A\n";
		return 0;
	}

	for (a=-200;a<=200;a++) {
		b = v[1] - v[0] * a;
		for (i=1;i<N;i++) {
			if (v[i-1] * a + b != v[i])
				break;
		}
		if (i == N)
			ans.push_back(v.back() * a + b);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	if (ans.size() == 1) {
		cout << ans[0] << endl;
	} else if (ans.size() > 1) {
		cout << "A\n";
	} else if (ans.size() == 0) {
		cout << "B\n";
	}
	return 0;
}
