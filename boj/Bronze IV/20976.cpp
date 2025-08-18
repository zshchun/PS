#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, a[3];
	for (i=0;i<3;i++)
		cin >> a[i];
	sort(a, a+3);
	cout << a[1] << endl;
	return 0;
}
