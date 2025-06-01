#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j;
	cin >> n;
	for (i=0;i<3*n+2*n;i++) {
		if (i >= n && i < n+3*n) {
			for (j=0;j<n;j++)
				cout << '@';
		} else {
			for (j=0;j<5*n;j++)
				cout << '@';
		}
		cout << endl;
	}
	return 0;
}
