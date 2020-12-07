/**
 * 二叉树中和为某一值的路径
 */

class TreeNode {
    val: number;
    left: TreeNode | null;
    right: TreeNode | null;
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null : right);
    }
}

function pathSum(root: TreeNode | null, sum: number): number[][] {
    if (root === null) return [];

    let res: number[][] = [];

    // 辅助函数
    let path: number[] = [];
    function dfs(node: TreeNode, count: number) {
        count += node.val;
        path.push(node.val);

        let isLeaf: boolean = node.left === null && node.right === null;
        if (sum === count && isLeaf) {
            res.push([...path]);
        }
        if (node.left !== null) dfs(node.left, count);
        if (node.right !== null) dfs(node.right, count);

        path.pop();
    }
    dfs(root, 0);
    return res;
}