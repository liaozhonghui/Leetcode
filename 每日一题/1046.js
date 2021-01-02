/**
 * 最后一块石头的重量
 */

const PriorityQueue = require('priorityqueuejs');

function lastStoneWeight (stones) {
    let maxpq = new PriorityQueue((a, b) => a - b);
    for (let stone of stones) maxpq.enq(stone);
    console.log('maxpqL:', JSON.stringify(maxpq));
    while (maxpq.size() > 1) {
        let a = maxpq.deq();
        let b = maxpq.deq();

        if (a > b) maxpq.enq(a - b);
    }
    return maxpq.size() === 0 ? 0 : maxpq.deq();
}

let arr = [2, 7, 4, 1, 8, 1];
let res = lastStoneWeight(arr);

console.log('res:', res);