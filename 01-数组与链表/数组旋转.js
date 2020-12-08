/**
 * 数组旋转-189
 * 1. 使用环状替代
 * 2. 使用反转
 * 3. 使用暴力法，一次旋转一次，使用哨兵变量
 * 4. 使用额外数组进行存储
 */
var rotate = function(nums, k) {
    k = k % nums.length;
    let count = 0;
    for (let start = 0; count < nums.length; i++) {
        let cur = start;
        let prev = nums[cur];
        do {
            next = (start + k) % nums.length;
            let temp = nums[next];
            nums[next] = prev;
            prev = temp;
            cur = next;
            count++;
        } while (start != cur)
    }
}
var rotate = function (nums, k) {
    k = k % nums.length;
    reverse(nums, 0, nums.length - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.length - 1);

    function reverse(nums, start, end) {
        while (start < end) {
            let temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
var rotate = function (nums, k) {
    k = k % nums.length;
    for (let i = 0; i < k; i++) {
        let prev = nums[nums.length - 1];
        for (let j = 0; j < nums.length; j++) {
            let temp = nums[j];
            nums[j] = prev;
            prev = temp;
        }
    }
}

var rotate = function (nums, k) {
    k = k % nums.length;
    let a = new Array(nums.length);
    for (let i = 0; i < nums.length; i++) {
        a[(i + k) % nums.length] = nums[i];
    }
    for (let i = 0; i < nums.length; i++) {
        nums[i] = a[i];
    }
}