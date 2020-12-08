/**
 * 合并两个有序链表
 * 1. 使用哨兵节点， 时间复杂度为O(m + n) 空间复杂度为O(1)
 */
var mergeTwoLists = function (l1, l2) {
    let head = new ListNode(-1);
    let p = head;
    while(l1 && l2) {
        if (l1.value < l2.value) {
            p.next = l1;
            l1 = l1.next;
        } else {
            p.next = l2;
            l2 = l2.next;
        }
        p = p.next;
    }

    if (l1) p.next = l1;
    if (l2) p.next = l2;
    return head.next;
}

class ListNode {
    constructor (val) {
        this.val = val;
        this.next = null;
    }
}