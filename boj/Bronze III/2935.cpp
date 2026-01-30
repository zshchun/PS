#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a, b, ans;
	int i, j, k;
	char op;
	cin >> a >> op >> b;
	j = a.size() - 1;
	k = b.size() - 1;
	if (j > k) swap(j, k);
	if (op == '*') {
		for (i=0;i<j+k;i++)
			ans += '0';
		ans = "1" + ans;
		cout << ans << endl;
	} else if (op == '+') {
		for (i=0;i<max(j+1,k+1);i++)
			ans += '0';
		ans[j]++;
		ans[k]++;
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}

	return 0;
}
