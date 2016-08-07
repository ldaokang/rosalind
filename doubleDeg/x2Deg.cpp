#include <iostream>
#include <fstream>

using namespace std;

ofstream outfile;
ifstream infile;
int nVertex;
int nEdge;
void populateGraph();
void printGraph();

int main()
{
outfile.open("output", ios::out);
infile.open("input", ios::in);

	infile >> nVertex;
	infile >> nEdge;
	int degVertex[nVertex];
	int x2degVertex[nVertex];
	int graph[nVertex][nVertex];
	int (*v0)[nVertex] = graph;  //or int *v0 = graph[0]

	populateGraph();
	printGraph();
	cout << "Vertices: " << nVertex << endl << "Edges: " << nEdge << endl;

}

void populateGraph()
{
	for (int i=0; i<nVertex; i++)
	{
		for (int j=0; j<nVertex; j++)
		{
			graph[i][j] = 0;
		}
	}

}

void printGraph()
{
	for (int i=0; i<nVertex; i++)
	{
		for (int j=0; j<nVertex; j++)
		{
			cout << graph[i][j];
		}
	}

}
