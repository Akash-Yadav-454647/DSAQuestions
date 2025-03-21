class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> ans;
        set<string> have; //items that we have
        for(string x : supplies) have.insert(x);
        vector<bool> vis(n);
        for(int k = 0; k < n; k++){
            bool change = false;
            for(int i = 0; i < n; i++){
                if(vis[i]) continue; //If we had already added it, we move on
                bool flag = true;
                for(int j = 0; j < ingredients[i].size(); j++)
                    flag &= have.count(ingredients[i][j]); //check that we have all the ingredients
                if(flag){
                    have.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    vis[i] = true;
                    change = true;
                }
            }
            if(!change) break; //check if there was a change
        }
        return ans;
    }
};
