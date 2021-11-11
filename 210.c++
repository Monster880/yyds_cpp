class Solution {
private:
    vector<vector<int>> edges;
    vector<int> ind;
    vector<int> result;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        ind.resize(numCourses);
        for(const auto& info : prerequisites){
            edges[info[1]].push_back(info[0]);
            ++ind[info[0]];
        }
        queue<int> q;
        for(int i=0; i < numCourses; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(int v : edges[u]){
                --ind[v];
                if(ind[v] == 0){
                    q.push(v);
                }
            }
        }
        if(result.size() != numCourses){
            return {};
        }
        return result;
    }
};