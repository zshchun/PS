#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	double a, b, c;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> a >> b >> c;
		cout << fixed << setprecision(2) << '$' << a * b * c << endl;
	}
	return 0;
}
