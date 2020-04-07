# 基础的数据结构

## C++数组

## C++链表

## C++栈、队列、优先队列

## C++树形结构

## C++图结构

### 递归函数处理

通过函数体调用自己

递归就是循环

寻找重复性
特点：

1. 向下进入下一层
2. 通过原来的路径回到原来那一层
3. 递归将发生的变化携带回来

```
def Factorial(n)
    if(n=0) return 1;
    return n*Factorial(n-1)
```

代码模板

```java
public void recur (int level,int param){
    // teminator
    if(level>MAX_LEVEL){
        return ;

    }
}
```

```python
def recursion(level,param1,param2,...)
    # recursion termianator 递归终结者
    if level> MAX_LEVEL:
        process_result;
        retrun;

    # process logic in current level 处理当前逻辑
    process(level,data,...)

    # drill down
    self.recursion(level+1,p1,...) 下探到下一层

    # reverse the current level status if needed 清理当前层
```

思维要点

1. 不要人肉进行递归
2. 找到最近最简单方法，将其拆解成可重复解决的问题（重复子问题）
3. 数学归纳法思维
