#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, ans;
string target;

bool check(string s) {
	sort(s.begin(), s.end());
	if (target == s)
		return true;
	return false;
}

void dfs(string s, int n) {
	int i;
	if (n >= s.size()) return;
	string r, t = s;
	if (n)
		r += s.substr(0, n);
	if (n+1 < s.size())
		r += s.substr(n+1);
	if (check(r)) {
		ans++;
		return;
	}
	for (i=0;i<26;i++) {
		char c = i + 'A';
		t[n] = c;
		if (check(t) || check(s+c)) {
			ans++;
			return;
		}
	}
	if (i == 26)
		dfs(s, n+1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	string s;
	cin >> N;
	if (N == 0) {
		cout << "0\n";
		return 0;
	}
	cin >> target;
	sort(target.begin(), target.end());
	for (i=1;i<N;i++) {
		cin >> s;
		if (check(s))
			ans++;
		else
			dfs(s, 0);
	}
	cout << ans << endl;

	return 0;
}
