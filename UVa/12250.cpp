// https://onlinejudge.org/external/122/12250.pdf
#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	map<string, string> aux;
	aux["HELLO"] = "ENGLISH";
	aux["HOLA"] = "SPANISH";
	aux["HALLO"] = "GERMAN";
	aux["BONJOUR"] = "FRENCH";
	aux["CIAO"] = "ITALIAN";
	aux["ZDRAVSTVUJTE"] = "RUSSIAN";
	string s; int t = 0;
	while (getline(cin, s)) {
		if (s == "#") {
			break;
		}
		cout << "Case " << ++t << ": ";
		if (aux.find(s) != aux.end()) {
			cout << aux[s] << endl;
		} else {
			cout << "UNKNOWN" << endl;
		}
	}
	return 0;
}