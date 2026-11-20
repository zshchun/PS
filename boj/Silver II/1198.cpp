#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 1234567890
#define X first
#define Y second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, n;
	ll mx = 0;
	double ans;
	cin >> n;
	vector<pl> v(n);
	for (i=0;i<n;i++)
		cin >> v[i].X >> v[i].Y;

	for (i=0;i<n;i++) {
		for (j=i+1;j<n;j++) {
			for (k=j+1;k<n;k++) {
				mx = max(mx, abs((v[j].X-v[i].X) * (v[k].Y-v[i].Y) - (v[j].Y-v[i].Y) * (v[k].X-v[i].X)));
			}
		}
	}

	cout << fixed << setprecision(1) << mx / 2.0 << endl;

	return 0;
}
