#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	for (i=0;i<n;i++) {
		for (j=0;j<i;j++) cout << ' ';
		for (j=0;j<n-i-1;j++) cout << '*';
		cout << '*';
		for (j=0;j<n-i-1;j++) cout << '*';
		cout << endl;
	}
	return 0;
}
