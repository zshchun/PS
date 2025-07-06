#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	char pl, eq;
	cin >> a >> pl >> b >> eq >> c;
	if (a + b == c)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
