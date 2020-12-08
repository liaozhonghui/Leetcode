# 代码模板

#### 递归代码模板
```js
function recursion(level, param1, param2) {
    // recursion terminator
    if (level > MAX_LEVEL) {
        process_result;
        return;
    }

    // process logic in current level
    process(level, data...);

    // drill down
    recursion(level + 1, newParam1, newParam2);

    // reverse the current level status if needed
}

```

#### 分治算法代码模板
```js
function divide_conquer(problem, param1. param2) {
    // recursion terminator;
    if (!problem) {
        return;
    }

    // prepare data
    data = prepate_data(problem);
    subproblems = split_problem(problem, data);

    // conquer subproblems
    subresult1 = divide_conquer(subproblems[0], p1, ...);
    subresult2 = divide_conquer(subproblems[1], p1, ...);
    subresult3 = divide_conquer(subproblems[2], p1, ...);

    // process and generate the final result
    result = process_result(subresult1, subresult2, ...);

    // revert the current states
}
```
#### DFS 代码模板

递归写法
```js
let visited = new Set();
function dfs(node, visited) {
    // terminator
    if (visited.has(node) ) {   
        return
    }

    visited.add(node);

    // process current node here
    for (let next_node of node.children()) {
        if (!visited.has(next_node)) {
            dfs(next_node, visited);
        }
    }
}
```

迭代写法

```js
function dfs(tree) {
    if (!tree.root) {
        return ;
    }
    let visited = new Set();
    let stack = [tree.roo];
    while(stack.length) {
        let node = stack[stack.length - 1];

        let nodes = gene_related_nodes(node);
        let i = 0;
        for (;i < nodes.length; i++) {
            let node = nodes[i];
            if (!visited(node)) {
                // process logic
                console.log(node.value);
                stack.push(node);
                visited.add(node);
                break;
            }
        }
        if (i === nodes.length) stack.pop();
    }
}

def DFS(self, tree):
    if tree.root is None:
        return []

    visited, stack = [], [tree.root]

    while stack:
        node = stack.pop()
        visited.add(node)

        process(node)
        nodes = gene_related_nodes(node)
        stack.push(nodes)

    # other processing work
```

## BFS 代码模板

递归写法-python 版本

```python
def BFS(graph, start, end):
    visited = set()
    queue = []
    queue.append([start])
    while queue:
        node = queue.pop()
        visited.add(node)

        process(node)
        nodes = gene_related_nodes(node)
        queue.push(nodes)

    # other processing work

```

## 二分查找代码模板

python 版本

```python
left, right = 0, len(array)-1
while left <= right:
    mid = (left+right)/2
    if array[mid] == target:
        # find the target!!
        break or return result
    elif array[mid] < target:
        left = mid+1
    else:
        right = mid-1
```

## trie 树代码模板

python 版本

```python
class Trie(object):
    def __init__(self):
        self.root = {}
        self.end_of_word = '#'

    def insert(self, word):
        node = self.root
        for char in word:
            node = node.setdefault(char, {})
        node[self.end_of_word] = self.end_of_word

    def search(self, word):
        node = self.root
        for char in word:
            if char not in node:
                return False
            node = node[char]
        return self.end_of_word in node
    def startsWith(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node:
                return False
            node = node[char]
        return True
```
