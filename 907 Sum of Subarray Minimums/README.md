Runtime: 63ms

This is a problem of DP and mono stack. We could record the states of each position in the array, meaning that by having the current element as the last element in the subarray, what would be the minimum sum.
Then we add all the minimum total to get the final answer.