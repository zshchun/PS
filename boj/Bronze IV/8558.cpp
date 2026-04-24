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
	int i, j, k = 1;
	cin >> j;
	for (i=1;i<=j;i++)
		k = k * i % 10;
	cout << k << endl;
	return 0;
}
