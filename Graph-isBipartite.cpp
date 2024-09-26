class Solution {
private:
    bool check(int start,vector<int>&color,vector<vector<int>>& graph)
    {
        queue<int>q;
        q.push(start);
        color[start]=0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:graph[node])
            {
                cout<<it<<"     ";
                if(color[it]==-1)
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int>color(m,-1);
        for(int i=0;i<m;i++)
        {
            if(color[i]==-1)
            {
                if(check(i,color,graph)==false)
                return false;
            }
        }
        return true;
    }
};
