

def divide_conquer(problem, param1, param2):
    # recursion terminator
    if problem is None:
        print_result
        return

    # prepare data
    data = prepare_data(problem)
    subproblems = split_problem(problem, data)

    # conquer subproblems
    subresult1 = self.divide_conquer(subproblems[0], p1, ...)
    subresult2 = self.divide_conquer(subproblems[1], p1, ...)
    subresult3 = self.divide_conquer(subproblems[2], p1, ...)
    ...

    # process and generate the final result
    result = proces_result(subresult1, subresult2, subresult3)

    # revert the current states


def recursion(level, param1, param2):
    # recursion terminator
    if(level > MAX_LEVEL):
        process_result
        return

    # process logic in current level
    process(level, data...)

    # drill down
    self.recursion(level+1, p1, ...)

    # reverse the current level status if needed


visited = set()


def dfs(node, visited):
    if node in visited:  # terminator
        # already visited
        return

    visited.add(node)

    # process current node here.
    for next_node in node.children():
        if next_node not in visited:
            dfs(next_node, visited)


def DFS(self, tree):
    if tree.root is None:
        return []

    visited, stack = [], [tree.root]

    while stack:
        node = stack.pop()
        visited.add(node)

        process(node)
        nodes = gene_related_nodes(nmode)
        stack.push(nodes)

    # other processing work


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
