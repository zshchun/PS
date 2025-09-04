#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int u, v, i;
	cin >> n;
	vector<int> a(n);
	for (i=0;i<n;i++) {
		cin >> u >> v;
		a[i] = v - u;
	}
	sort(a.begin(), a.end());
	if (n & 1)
		cout << "1\n";
	else
		cout << abs(a[n/2] - a[n/2-1] + 1) << endl;

	return 0;
}
