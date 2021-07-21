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
class Solution {
public:
    int count=0;
    vector<int> countpair(TreeNode *root,int distance)
     {
       if(root==NULL)return {0};
        if(root->left==NULL && root->right==NULL)return {1};
        vector<int>left=countpair(root->left,distance);
         vector<int>right=countpair(root->right,distance);
        for(auto x:left)
        {
            for(auto y:right)
            {
                if(y>0 && x>0 &&  x+y<=distance)
                {
                    count++;
                }
            }
        }
        vector<int>Ans;
        for(auto x:left)
        {
            if(x>0 && x<distance)
            {
                Ans.push_back(x+1);
            }
        }
        for(auto y:right)
        {
            if(y>0 && y<distance)
            {
                Ans.push_back(y+1);
            }
        }
        return Ans;
    }
    int countPairs(TreeNode* root, int distance){
        countpair(root,distance);
        return count;
    }
};
