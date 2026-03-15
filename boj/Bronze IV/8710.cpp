#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int w, k, m;
	cin >> k >> w >> m;
	if (k >= w) {
		cout << "0\n";
	} else {
		cout << ((w - k) + m-1) / m << endl;
	}
	return 0;
}
