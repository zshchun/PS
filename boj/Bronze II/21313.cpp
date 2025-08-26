#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n;
	cin >> n;
	for (i=0;i<n;i++)
		if (i == n-1 && (i & 1) == 0)
			cout << "3 ";
		else if (i & 1)
			cout << "2 ";
		else
			cout << "1 ";
	cout << endl;
	return 0;
}
