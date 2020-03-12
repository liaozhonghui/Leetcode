/**
 * 盛水最多的容器
 */
function maxArea(heights) {
    if (heights == null || heights.length < 2) {
        return 0;
    }
    var i = 0, j = heights.length - 1;
    var result = 0;
    while (i < j) {
        let hmin = Math.min(heights[i], heights[j]);
        result = Math.max(result, hmin * (j - i));
        while (heights[i] <= hmin && i < j)
            i++;
        while (heights[j] <= hmin && i < j)
            j--;
    }
    return result;
}
function maxArea1(heights) {
    if (heights == null || heights.length < 2) {
        return 0;
    }
    var result = 0;
    for (let i = 0; i < heights.length; i++) {
        for (let j = i + 1; j < heights.length; j++) {
            result = Math.max(result, (j - i) * Math.min(heights[i], heights[j]));
        }
    }
    return result;
}

// test cases
var heights = [];
console.log('异常情况：空数组测试1', maxArea(heights));
console.log('异常情况：空数组测试2', maxArea1(heights));
var heights = [1, 8, 6, 2, 5, 4, 8, 3, 7];
console.log('正常情况：空数组测试1', maxArea(heights));
console.log('正常情况：空数组测试2', maxArea1(heights));