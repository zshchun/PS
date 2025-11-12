#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k, n, m;
	cin >> k >> n >> m;
	cout << max(0, k * n - m) << endl;
	return 0;
}
