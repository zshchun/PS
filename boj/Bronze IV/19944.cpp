#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	if (m <= 2)
		cout << "NEWBIE!\n";
	else if (m <= n)
		cout << "OLDBIE!\n";
	else
		cout << "TLE!\n";

	return 0;
}
