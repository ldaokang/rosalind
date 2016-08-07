#include <iostream>
#include <fstream>

using namespace std;

ofstream outfile;
ifstream infile;

class Graph
{
    public:
        void setLink(int node1, int node2, bool isLinked);
        void printGraph();
        int getDegree(int node);
        int getDoubleDegree(int node);
        Graph(int nVertex); //constructor
    private:
        int nVertex;
        int linkTable[1001][1001];
};

void Graph::setLink(int node1, int node2, bool isLinked)
{
    linkTable[node1][node2] = isLinked ? 1:0;
    linkTable[node2][node1] = isLinked ? 1:0;
}

void Graph::printGraph()
{
    for (int i=1; i<=nVertex; i++)
    {
        cout << i << ": ";
        for (int j=1; j<=nVertex; j++)
        {
            cout<< linkTable[i][j] << " ";
        }
        cout << endl;
    }
}
int Graph::getDegree (int node)
{
    int deg=0;
    for(int i=1;i<=nVertex;i++)
        {
            if(linkTable[node][i]==1)
            deg+=1;
        }
    return deg;
}
int Graph::getDoubleDegree(int node)
{
    int x2deg=0;
        for(int i=1;i<=nVertex;i++)
        {
            if(linkTable[node][i]==1)
            x2deg += getDegree (i);
        }
    return x2deg;
}

Graph::Graph(int n)
{
    Graph::nVertex = n;
    for (int i=1; i<=nVertex; i++)
    {
        for (int j=1; j<=nVertex; j++)
        {
            setLink(i,j,false);
        }
    }
}

int main()
{
outfile.open("output", ios::out);
infile.open("input", ios::in);
        int nodes;
        infile >> nodes;
        Graph rox(nodes);
        int edges;
        infile >> edges;
        for (int i=0;i<edges;i++)
        {
            int a,b;
            infile >> a >> b;
            rox.setLink(a,b,true);
        }
        //cout << "a:" << a << "b:" << b << endl;
        //rox.printGraph();
    //    int blah;
  //      cin >> blah;
//        cout << "getx2Degree(1)" << rox.getDoubleDegree (blah) << endl;

        for (int i=1;i<=nodes;i++)
        {
            outfile << rox.getDoubleDegree(i) << " ";
        }

        /*
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
    */
}
