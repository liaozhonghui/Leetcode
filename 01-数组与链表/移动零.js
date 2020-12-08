/**
 * 移动零
 * 1. 使用双指针解法 算法的时间复杂度为O(n), 空间复杂度为O(1)
 */
var moveZeroes = function (nums) {
    let i = 0;
    for (let j = 0; j < nums.length; j++) {
        if (nums[j] !== 0) {
            if (i === j) ++i;
            else {
                nums[i++] = nums[j];
                nums[j] = 0;
            }
        }
    }
}