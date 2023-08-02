#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

#define MAX 1003001
bool a[MAX+1];

bool is_palindrome(int x) {
	string s, t;
	while (x) {
		char c = '0' + (x % 10);
		s += c;
		t = c + t;
		x /= 10;
	}
	if (s == t)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j;
	cin >> N;
	for (i=2;i<=MAX;i++) {
		for (j=i*2;j<MAX;j+=i) {
			a[j] = 1;
		}
	}
	vector<int> ans;
	for (i=2;i<=MAX;i++) {
		if (a[i]) continue;
		if (is_palindrome(i))
			ans.push_back(i);
	}
	cout << *lower_bound(ans.begin(), ans.end(), N) << endl;
	return 0;
}
