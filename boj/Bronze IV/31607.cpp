#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	vector<int> a(3);
	for (i=0;i<3;i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	if (a[0] + a[1] == a[2])
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}
