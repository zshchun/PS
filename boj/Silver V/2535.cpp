#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
int N;
int n[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, v, ans = 0;
	cin >> N;
	vector<tup> a;

	for (i=0;i<N;i++) {
		cin >> j >> k >> v;
		a.push_back(tup(v, j, k));
	}
	sort(a.begin(), a.end(), greater<tup>());
	for (tup &t : a) {
		tie(v, j, k) = t;
		if (n[j] >= 2)
			continue;
		n[j]++;
		ans++;
		cout << j << ' ' << k << endl;
		if (ans >= 3)
			break;
	}

	return 0;
}
