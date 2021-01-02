var countPath = function (grid, row, col) {
    // terminator
    if (barrier(grid, row, col)) return 0;
    if (isAtEnd(grid, row, col)) return 1;

    let res = countPath(grid, row + 1, col) + countPath(grid, row, col + 1);

}

var countPath = function (m, n) {
    // todo: 从下往上进行递推
}




