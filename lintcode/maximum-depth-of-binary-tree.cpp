/**
 *  * Definition of TreeNode:
 *   * public class TreeNode {
 *    *     public int val;
 *     *     public TreeNode left, right;
 *      *     public TreeNode(int val) {
 *       *         this.val = val;
 *        *         this.left = this.right = null;
 *         *     }
 *          * }
 *           */
public class Solution {
    /**
 *      * @param root: The root of binary tree.
 *           * @return: An integer.
 *                */
    public int maxDepth(TreeNode root) {
		if(root == NULL) return 0;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		retunr (leftDepth>rightDepth?leftDepth:rightDepth)+1;


	}
}
