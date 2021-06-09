/**
 * 两输之和
 * 1. 使用Map存储 时间复杂度为O(n) 空间复杂度为O(n)
 */

var twoSum = function (nums, target) {
    if (!nums || nums.length < 2) return [];
    let s = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (!s.has(target - nums[i])) s.set(nums[i], i);
        else return [s.get(target - nums[i]), i];
    }
    return [];
}