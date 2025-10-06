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
	if (n <= 9) {
		cout << "1\n";
		return 0;
	}
	for (i=2;i<=9;i++) {
		for (j=1;j<=9;j++) {
			if (i * j == n) {
				cout << "1\n";
				return 0;
			}
		}
	}
	cout << "0\n";
	return 0;
}
