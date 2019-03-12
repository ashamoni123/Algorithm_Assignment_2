#include <iostream>
using namespace std;

#define ROW 7
#define COL 7
#define infi 500

class prims
{
   int graph[ROW][COL],nodes;
   public:
   prims();
   void createGraph();
   void primsAlgo();
};

prims :: prims()
{
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            graph[i][j]=0;
}

void prims :: createGraph()
{
    int i,j;
    cout<<"Enter Total Nodes : ";
    cin>>nodes;
    cout<<"Enter Adjacency Matrix : ";
    for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
        cin>>graph[i][j];

        for(j=0;j<nodes;j++)
    {
        if(graph[i][j]==0)
            graph[i][j]=infi;
        }
}


void prims :: primsAlgo()
{
    int selected[ROW],i,j,ne;
    int min,x,y;

    for(i=0;i<nodes;i++)
        selected[i]=false;

    selected[0]=true;
    ne=0;

    while(ne < nodes-1)
    {
        min=infi;
        for(i=0;i<nodes;i++)
        {
            if(selected[i]==true){
                for(j=0;j<nodes;j++){
                    if(selected[j]==false){
                        if(min > graph[i][j])
                        {
                            min=graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        selected[y]=true;
        cout<<"n"<<x+1<<" --> "<<y+1;
        ne=ne+1;
    }
}

int main()
{
    prims MST;
    cout<<"nPrims Algorithm to find Minimum Spanning Tree";
    MST.createGraph();
    MST.primsAlgo();
    return 0;
}
