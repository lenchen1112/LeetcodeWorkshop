/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = (nums, target) => {
    const indexMap = {};
    for (let i = nums.length - 1; i > -1; i--) {
        const num = nums[i];
        const complementIndex = indexMap[target - num];
        if (complementIndex) {
            return [i, complementIndex];
        }
        indexMap[num] = i;
    }
};
