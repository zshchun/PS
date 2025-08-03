#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, x;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> x;
		if (((x+1) % (x % 100)) == 0)
			cout << "Good\n";
		else
			cout << "Bye\n";
	}
	return 0;
}
