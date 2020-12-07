// ts的链表结构
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}
// ts的二叉树结构
class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}


// 树的深度优先遍历dfs

let visited: Set<TreeNode> = new Set();
let root: TreeNode;
function dfs(node: TreeNode): void {
    // terminator 
    if (visited.has(node)) {
        return;
    }
    // process logic
    visited.add(node);

    // drill down
    let next_nodes: Array<TreeNode> = generate_children(node) || [];
    for (let i: number = 0; i < next_nodes.length; i++) {
        let next_node: TreeNode = next_nodes[i];
        if (!visited.has(next_node)) {
            dfs(next_node);
        }
    }
}

// helper
function generate_children(node: TreeNode): Array<TreeNode> {
    return []
}

// 树的广度优先遍历bfs

function bfs(root: TreeNode): void {
    let queue: Array<TreeNode> = [];
    queue.push(root);

    while (queue.length > 0) {
        let node = queue.shift();

        if (visited.has(node)) break;
        visited.add(node);
        // process logic 

        // next_nodes
        let next_nodes = generate_children(node);

        for (let i: number = 0; i < next_nodes.length; i++) {
            let next_node: TreeNode = next_nodes[i];
            queue.push(next_node);
        }


    }

}