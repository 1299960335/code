class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
      if(employees.empty())
      return 0;
      unordered_map<int,Employee*> mp;
      for(auto& e:employees){
          mp[e->id]=e;
      }  
      int sum=0;
      DFS(mp,sum,id);
      return sum;
    }
    void DFS(unordered_map<int,Employee*>& mp,int& sum,int id)
    {
        sum+=mp[id]->importance;
        for(auto & e:mp[id]->subordinates){
            DFS(mp,sum,e);
        }
    }
};