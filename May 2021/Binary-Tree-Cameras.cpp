class Solution {
private:
    int numCameras;
    void recur(TreeNode *node, bool& hasCamera, bool& unmonitored) {
        bool leftChildHasCamera = false, rightChildHasCamera = false;
        bool leftChildUnmonitored = false, rightChildUnmonitored = false;
        if (node->left != nullptr)
            recur(node->left, leftChildHasCamera, leftChildUnmonitored);
        if (node->right != nullptr)
            recur(node->right, rightChildHasCamera, rightChildUnmonitored);
        
        hasCamera = leftChildUnmonitored || rightChildUnmonitored;
        if (hasCamera)
            ++numCameras;
        unmonitored = !leftChildHasCamera && !rightChildHasCamera && !hasCamera;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        numCameras = 0;
        bool hasCamera, unMonitored;
        recur(root, hasCamera, unMonitored);
        if (unMonitored)
            ++numCameras;
        return numCameras;
    }
};