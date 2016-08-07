#include <iostream>
#include <fstream>

using namespace std;

ofstream outfile;
ifstream infile;

int main()
{
outfile.open("output", ios::out);
infile.open("input", ios::in);
	int nVertex;
	int nEdge;
	infile >> nVertex;
	infile >> nEdge;
	int degVertex[nVertex];
	for (int i=0; i<nVertex; i++)
	{
		degVertex[i]=0;
	}
	for (int i=0; i<(nEdge*2); i++)
	{
		int j;
		infile >> j;
		degVertex[j-1]++;
	}
	for (int i=0; i<nVertex; i++)
	{
		outfile << degVertex[i] << " ";
	}
	cout << "Vertices: " << nVertex << endl << "Edges: " << nEdge << endl;

}
