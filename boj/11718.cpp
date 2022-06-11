#include <bits/stdc++.h>
using namespace std;
int main() {
	string l;
	vector<string> a;
	do {
		getline(cin, l);
		if (!l.empty())
			a.push_back(l);
	} while (!l.empty());

	for (vector<string>::size_type i=0;i<a.size();i++) {
		cout << a[i] << "\n";
	}
	return 0;
}
