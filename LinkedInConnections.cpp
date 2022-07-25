#include<bits/stdc++.h>

using namespace std;

class LinkedInConnections
{
    public:
        struct User
        {
            string name;
            vector<string> skills;
            int connections;
        };

        int n;
        struct User user_det[10000];
        map<int,User> mp;
        int m;
        vector<int> adj[10000];
        int dist[1000];
        int source;

        void getUserData()
        {
            cout<<"Enter number of users: ";
            cin>>n;

            for(int i=0;i<n;i++)
            {
                cout<<"Enter name: ";
                cin>>user_det[i].name;
                cout<<"Enter skills: "<<endl;
                int n = 2;
                while(n--){
                    string str;
                    cin>>str;
                    user_det[i].skills.push_back(str);
                }
                cout<<"Enter number of connections: ";
                cin>>user_det[i].connections;
                mp[i] = user_det[i];
            }
        }

        void getData()
        {
            cout<<"Enter number of connections: ";
            cin>>m;
            cout<<"Enter the connections"<<endl;
            for(int i=0;i<m;i++)
            {
                int x,y;
                cin>>x>>y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
            cout<<"Enter source: ";
            cin>>source;
        }

        void bfs()
        {
            vector<int> vis(n,0);
            memset(dist,sizeof(dist),0);
            queue<int> q;
            q.push(source);
            dist[source] = 0;
            vis[source] = 1;
            while(!q.empty())
            {
                int temp = q.front();
                q.pop();
                for(auto v: adj[temp])
                {
                    if(vis[v] == 0)
                    {
                        vis[v] = 1;
                        q.push(v);
                        dist[v] = dist[temp]+1;
                    }
                }
            }
        }

        void display()
        {
            cout<<"1st Degree connections: "<<endl;
            int c1=0,c2=0,c3=0;
            for(int i=0;i<n;i++)
            {
                if(dist[i] == 1)
                {
                    c1++;
                    auto it = mp[i];
                    cout<<"Name: "<<it.name<<endl;
                    cout<<"Skills: "<<endl;
                    for(int i=0;i<2;i++)
                    {
                        cout<<it.skills[i]<<endl;
                    }
                    cout<<"Number of connections: "<<it.connections<<endl;
                }
            }
            if(c1 == 0)
            {
                cout<<"No 1st degree connections"<<endl;
            }
            cout<<"2nd Degree connections: "<<endl;
            for(int i=0;i<n;i++)
            {
                if(dist[i] == 2)
                {
                    c2++;
                    auto it = mp[i];
                    cout<<"Name: "<<it.name<<endl;
                    cout<<"Skills: "<<endl;
                    for(int i=0;i<2;i++)
                    {
                        cout<<it.skills[i]<<endl;
                    }
                    cout<<"Number of connections: "<<it.connections<<endl;
                }
            }
            if(c2 == 0)
            {
                cout<<"No 2nd degree connections"<<endl;
            }
            cout<<"3rd Degree connections: "<<endl;
            for(int i=0;i<n;i++)
            {
                if(dist[i] == 3)
                {
                    c3++;
                    auto it = mp[i];
                    cout<<"Name: "<<it.name<<endl;
                    cout<<"Skills: "<<endl;
                    for(int i=0;i<2;i++)
                    {
                        cout<<it.skills[i]<<endl;
                    }
                    cout<<"Number of connections: "<<it.connections<<endl;
                }
            }
            if(c3 == 0)
            {
                cout<<"No 3rd degree connections"<<endl;
            }
        }
};

int main()
{
    LinkedInConnections l;
    l.getUserData();
    l.getData();
    l.bfs();
    l.display();
    return 0;
}
