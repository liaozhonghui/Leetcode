/**
 * 去除有序数组的重复项
 * 1. 使用双指针方法
 */
var removeDuplicates = function (nums) {
    let i = 0;
    for (let j = 1; j < nums.length; j++) {
        if (nums[j] !== nums[j - 1]) {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}