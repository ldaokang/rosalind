#include <iostream>
#include <fstream>

using namespace std;

ofstream outfile;
ifstream infile;

int binIndex (int *refAy, int refmin, int refmax, int testNum)
{
    int refmid = (refmin+refmax)/2;
    if (refmin>refmax) return -1;
    else if (*(refAy+refmid) == testNum) return refmid + 1;
    else if (*(refAy+refmid)<testNum) return binIndex(refAy, refmid+1, refmax, testNum);
    else return binIndex(refAy, refmin, refmid-1, testNum);

}
int main()
{
	int nRef;
	int nTest;
	outfile.open("output",ios::out);
	infile.open("input",ios::in);
	infile >> nRef;
	infile >> nTest;
	int refArray[nRef];
	for (int i=0; i<nRef; i++)
	{
		infile >> refArray[i];
		//cout << refArray[i] << ",";
	}
    //cout << "Reference Array Populated!" << endl;
	int testNum;
	for (int i=0; i<nTest; i++)
	{
		infile >> testNum;
		//cout << testNum << ",";
		outfile << binIndex(&refArray[0],0,nRef,testNum) << " ";
	}
    //cout << endl;
	//cout << "Test Numbers Indentified!" << endl;

}
