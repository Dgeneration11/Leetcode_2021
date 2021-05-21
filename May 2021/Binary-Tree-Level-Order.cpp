class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        
        if(root == NULL)    return {};
        
        q.push(root);
        while(!q.empty()){
            int length = q.size();
            vector<int> row;
            
            while(length--){
                TreeNode* temp = q.front();
                row.push_back(temp->val);
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
            result.push_back(row);
        }
        
        return result;
    }
};