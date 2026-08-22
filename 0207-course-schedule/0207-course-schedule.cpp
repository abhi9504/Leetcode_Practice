class Solution {
public:
    void topoSort(int n, vector<int>& ans,  unordered_map<int, list<int>>& adj) {
        unordered_map<int, int> indegree;
        queue<int> q;
        for(auto i : adj) {
            for(auto nbr : i.second) {
                indegree[nbr]++;
            }
        }

        //push zero indegree in queue
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS chla do
        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            ans.push_back(fNode);

            // Go to nbr
            for(auto nbr : adj[fNode]) {
                indegree[nbr]--;

                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        unordered_map<int, list<int>> adj;
        for(vector<int> i : prerequisites) {
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
        }

        vector<int> ans;
        topoSort(n, ans, adj);

        if(ans.size() == n)  return true;
        else return false;
    }
};