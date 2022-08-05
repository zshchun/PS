#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;
ll a[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		a[0][0] = 1;
		a[0][1] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		for (i=2;i<m;i++) {
			if (a[0][i-1] == a[0][i-2]) {
				a[0][i] = !a[0][i-1];
			} else {
				a[0][i] = a[0][i-1];
			}
			if (a[1][i-1] == a[1][i-2]) {
				a[1][i] = !a[1][i-1];
			} else {
				a[1][i] = a[1][i-1];
			}
		}
		for (i=2;i<n;i++) {
			for (j=0;j<m;j++) {
				if (a[i-1][j] == a[i-2][j]) {
					a[i][j] = !a[i-1][j];
				} else {
					a[i][j] = a[i-1][j];
				}
			}
		}
		for (i=0;i<n;i++) {
			for (j=0;j<m;j++) {
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}
