#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream outfile;
	ifstream infile;
	outfile.open("output", ios::out);
	infile.open("input", ios:: in);

	int nA(0),nC(0),nG(0),nT(0);
	int stringLength=1000;
	char s1[1000];
	//char s2[1000];
	for (int i=0; i<stringLength; i++)
	{
		infile >> s1[i];
		switch (s1[i])
		{
			case 'A':nA++;break;
			case 'C':nC++;break;
			case 'G':nG++;break;
			case 'T':nT++;break;
			default: stringLength = i;
		}
	}
	char rna[stringLength];
	for (int i=0; i<stringLength; i++)
	{
		if(s1[i]=='T')rna[i]='U';
		else rna[i] = s1[i];
		outfile << rna[i];
	}
	//cout << endl;
	//cout << nA << " " << nC << " " << nG << " " << nT << " " << endl;
}
