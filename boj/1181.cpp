#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin>>n;
	vector<string> s(n);
	for(i=0;i<n;i++) {
		cin>>s[i];
	}
	sort(s.begin(), s.end(), [] (const string& l, const string &r) {
		if (l.size() != r.size())
			return l.size() < r.size();
		return l < r;
	});
	for(i=0;i<n;i++) {
		if (i > 0 && s[i] == s[i-1])
			continue;
		cout<<s[i]<<"\n";
	}
	return 0;
}
