#include <bits/stdc++.h>
using namespace std;

class graph{
     int v;
     list<int>*adj;
 public:
     graph(int v)
     {
         this->v=v;
         adj=new list<int>[v];
     }
void addedge(int u,int v)
 {
     adj[u].push_back(v);

     adj[v].push_back(u);
 }
void BFS(int source,int l)
 {
     vector<bool>visited(v,false);  //vector er all sob size false kore deya holo
     queue<int>q;

     int LVL=0;

     visited[source]=true;

     q.push(source);
     q.push(-1);

    while(!q.empty())
    {
        int c=q.front();

        q.pop();

 if(c!=-1)
{
 if(l==LVL)
     {
      cout<<c<<" ";
     }
else
    {
  for(auto i:adj[c])
    {
     if(visited[i]!=true)
     {
       visited[i]=true;
       q.push(i);
     }
    }
    }
}

else
    {

    if(!q.empty())
   {
     q.push(-1);
      LVL++;
   }

    }
 }

 }

};
int main()
{

int n,e;
   cin>>n>>e;

   graph g (n);

   for(int i=0;i<e;i++)
   {
       int a,b;
       cin>>a>>b;
       g.addedge(a,b);
   }
   int l;
   cin>>l;
   g.BFS(0,l);


}
