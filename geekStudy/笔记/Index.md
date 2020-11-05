# Index.md

## 第 6 课

二叉树的面试题：

1. 基础要求

二叉树节点定义

```cpp
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
}
```

二叉树的前中后序遍历

```cpp
// 前序遍历postOrder
// 中序遍历inOrder
// 后序遍历lastOrder
```

第 7 课

递归代码模板

```java
public  void recur(int level,int param){
    // recursion terminator
    if(level>MAX_LEVEL){
        // process_result
        return ;
    }

    // process current logic
    process(level,param);

    // drill down
    recur(level:level+1,newParam)

    // reverse current level status if needed
}
```

写递归代码原则

1. 抵制人肉递归
2. 寻找可重复性
3. 使用数学归纳法进行递推
