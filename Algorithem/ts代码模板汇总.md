# ts代码模板汇总
```ts
// ListNode结构 singly-linkedlist
class ListNode {
    val: number,
    next: ListNode | null,
    constructor (val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
}

// 二叉树结构
class TreeNode {
    val: number,
    left: TreeNode | null,
    right: TreeNode | null,
    constructor (val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null :right);
    }
}
```

## DFS代码模版


