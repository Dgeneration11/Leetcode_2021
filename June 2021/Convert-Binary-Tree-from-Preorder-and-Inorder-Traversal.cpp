/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        int i = 0;
        return makeBT(i, 0, preorder.size() - 1, preorder, inorder);
    }
    TreeNode *makeBT(int &i, int l, int r, vector<int> &preorder, vector<int> &inorder)
    {

        if (i >= preorder.size())
            return NULL;

        TreeNode *curr = new TreeNode(preorder[i]);

        int j;
        for (j = l; j <= r; j++)
        {
            if (preorder[i] == inorder[j])
                break;
        }
        if (l <= j - 1)
        {
            i++;
            curr->left = makeBT(i, l, j - 1, preorder, inorder);
        }
        if (j + 1 <= r)
        {
            i++;
            curr->right = makeBT(i, j + 1, r, preorder, inorder);
        }
        return curr;
    }
};