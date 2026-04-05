#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
int odd, even, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, v;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> v;
		if (v % 2 == 0)
			even = odd + 1;
		else
			odd = even + 1;
	}
	ans = max(odd, even);
	cout << ans << endl;
	
	return 0;
}
