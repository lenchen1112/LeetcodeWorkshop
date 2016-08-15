/* 
 BUCKET_SIZE 4096 => 4ms
 BUCKET_SIZE 1024 => 8ms
 BUCKET_SIZE 512 => 12ms
 BUCKET_SIZE 256 => 24ms
 BUCKET_SIZE 128 => 40ms
*/
#define BUCKET_SIZE 4096

typedef struct Node {
	int Key;
	int Val;
	struct Node *nextNode;
} Node;

typedef struct HashTable {
	Node *entry;
} HashTable;

void insert_hash(HashTable *hTable, int key, int value)
{
	int slot = abs(value)%BUCKET_SIZE;	
	if (hTable->entry[slot].nextNode == 0) { // empty
		hTable->entry[slot].Key = key;
		hTable->entry[slot].Val = value;
		hTable->entry[slot].nextNode = (Node *)calloc(1, sizeof(Node));
	} else { 
		Node *node = hTable->entry[slot].nextNode;
		while (node->nextNode != 0) 
			node = node->nextNode;
		node->Key = key;
		node->Val = value;
		node->nextNode = (Node *)calloc(1, sizeof(Node));
	}
}

int find_hash(HashTable *hTable, int key, int value)
{
	int slot = abs(value)%BUCKET_SIZE;
	Node *node = &(hTable->entry[slot]);
	while (node) {
		if (node->Val == value && node->Key != key && node->nextNode != 0)
			return node->Key;
		node = node->nextNode;
	}	
	return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int i, searchValue;
	int *output;
	HashTable *myHash;
    
	output = (int *)calloc(2, sizeof (int));
	// default use BUCKET_SIZE entry
	myHash = (HashTable *)calloc(1, sizeof(HashTable));
	myHash->entry = (Node *)calloc(BUCKET_SIZE, sizeof(Node));

	// insert array to hash table
	for (i=0; i<numsSize; i++) 
		insert_hash(myHash, i, nums[i]);		
	
	// start scan
	for (i=0; i<numsSize; i++) {
		int val;
		searchValue = target - nums[i];	
		val = find_hash(myHash, i, searchValue);		
		if (val >= 0) {
			if (i > val) {
				output[0] = val+1;
				output[1] = i+1;
			} else {
				output[0] = i+1;
				output[1] = val+1;
			}
			return output;
		}
	}
	return (int*)-1;
}
Contact GitHub API Training Shop Blog About
© 2016 GitHub, Inc. Terms Privacy Secur