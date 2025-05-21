#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int lps[1000001];
vector<int> x;

void make_lps(string &p) {
	int i, j;
	for (i=1,j=0;i<p.size();i++) {
		while (j && p[i] != p[j])
			j = lps[j-1];
		if (p[i] == p[j])
			lps[i] = ++j;
	}
}

int kmp(string &s, string &p) {
	int i, j, ret = 0;
	for (i=0,j=0;i<s.size();i++) {
		while (j && s[i] != p[j])
			j = lps[j-1];
		if (s[i] == p[j]) {
			j++;
			if (j == p.size()) {
				ret++;
				x.push_back(i-j+2);
				j = lps[j-1];
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string t, p;
	getline(cin, t);
	getline(cin, p);
	make_lps(p);
	kmp(t, p);
	cout << x.size() << endl;
	for (int &i : x)
		cout << i << ' ';
	return 0;
}
