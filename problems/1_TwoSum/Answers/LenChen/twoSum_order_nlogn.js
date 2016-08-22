/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = (nums, target) => {
    const sortedNums = nums.map((num, index) => ({ num, index }));
    sortedNums.sort((a, b) => a.num - b.num);

    let [lowIndex, highIndex] = [0, sortedNums.length - 1];
    while(true) {
        const sum = sortedNums[lowIndex].num + sortedNums[highIndex].num;
        if (sum < target) {
            lowIndex++;
        } else if (sum > target) {
            highIndex--;
        } else {
           return [sortedNums[lowIndex].index, sortedNums[highIndex].index];
        }
    }
};
