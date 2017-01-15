#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string S, T, R;
vector<int> ms;

void censor() {
	int m = 0;
	for (int i = 0; i < S.size(); i++) {

		R += S[i];
		if (S[i] == T[m])
			m++;
		else if (S[i] == T[0])
			m = 1;
		else
			m = 0;

			cout << "hello "<< m << endl;
		ms.push_back(m);

		if (m == T.size()) {
				R.resize(R.size() - T.size());
				ms.resize(ms.size() - T.size());
				if (ms.size() > 0) {
					m = ms.back();
					cout << "back is" << m << endl;
				}
				else m = 0;
			}
		}
}

string censor2() {
	string R;
	for (int i = 0; i < S.size(); i++) {
		R += S[i];

		/* If the end of R matches T then delete it. */
		if (R.size() >= T.size() && R.substr(R.size() - T.size()) == T) {
			R.resize(R.size() - T.size());
		}
	}

	return R;
};

int main()
{
	ifstream in("censor.in");
	ofstream out("censor.out");
	cin >> S;
	cin >> T;

	censor();
	string R2 = censor2();
	cout << R;
	if (R2 != R) {
		cout << "mismatch" << endl;
	}
	system("pause");
    return 0;
}

