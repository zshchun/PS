#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, a, b, n;
	char c;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> a >> c >> b;
		cout << a + b << endl;
	}
	return 0;
}
