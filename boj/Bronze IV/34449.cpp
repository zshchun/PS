#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double d, w, n;
	cin >> d >> w >> n;
	if (d * 3.14159 >= w * n) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}
