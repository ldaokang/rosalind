#include <iostream>
#include <fstream>

using namespace std;

ofstream outfile;
ifstream infile;
int fiboArray[100];
int fiboFunc(int n)
{	
	int printer;
	if (n==0) printer= 0;
	else if (n==1) printer = 1;
	else printer = (fiboFunc(n-1) + fiboFunc(n-2));
	fiboArray[n] = printer;
	return printer;
}

int main()
{
	int n;
	outfile.open("fibo.out", ios:: out);
	infile.open("fibo.in", ios:: in);
	cin >> n;
	cout << fiboFunc(n) << endl;
	for (int i=0;i<=n;i++) cout << fiboArray[i] << ",";
	cout << endl;
}
