#include <iostream>
#include <fstream>
#define INF -1

using namespace std;

ofstream outfile;
ifstream infile;

class Graph
{
    public:
        void setLink(int node1, int node2, bool isLinked, bool isDirectional);
        void setWeightedLink(int node1, int node2, bool isLinked, bool isDirectional, int weight);
        void setDistanceFrom (int startNode,int pathDistance);
        void printGraph();
        int getDegree(int node);
        int getDoubleDegree(int node);
        int getDistance (int node);
        Graph(int nVertex); //constructor
    private:
        int nVertex;
        int linkTable[1001][1001]; //[0][0] is not used at all
        int distTable[1001]; //sets distance from node 1
};

void Graph::setLink(int node1, int node2, bool isLinked, bool isDirectional)
{
    linkTable[node1][node2] = isLinked ? 1:0;
    linkTable[node2][node1] = isLinked && !isDirectional ? 1:0;
}

void Graph::setWeightedLink(int node1, int node2, bool isLinked, bool isDirectional, int weight)
{
    linkTable[node1][node2] = isLinked ? weight:0;
    linkTable[node2][node1] = isLinked && !isDirectional ? weight:0;
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
        cout << "Distance: " << distTable[i] << endl;
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

void Graph::setDistanceFrom (int startNode,int pathDistance)
{
    int prevDistance = distTable[startNode];
    if (prevDistance==-1||prevDistance>pathDistance)
    {
        distTable[startNode] = pathDistance;
        for (int j=1; j<=nVertex;j++)
        {
            int linkValue = linkTable[startNode][j];
            if (linkValue>0) setDistanceFrom(j,linkValue+pathDistance);
        }
    }

}

int Graph::getDistance (int node)
{
    return distTable[node];
}

Graph::Graph(int n)
{
    Graph::nVertex = n;
    for (int i=1; i<=nVertex; i++)
    {
        for (int j=1; j<=nVertex; j++)
        {
            setLink(i,j,false,false);
        }
        distTable[i] = INF;
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
            int a,b,c;
            infile >> a >> b >>c;
            rox.setWeightedLink(a,b,true,true,c);
        }
        rox.setDistanceFrom(1,0);
        //rox.printGraph();

        for (int i=1;i<=nodes;i++)
        {
            outfile << rox.getDistance(i) << " ";
        }

}
