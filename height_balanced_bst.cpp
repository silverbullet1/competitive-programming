/* We have already discussed how to insert a key in BST. The height of such BST in worst case can be as much as number of keys in BST. The worst case happens when given keys are sorted in ascending or 
descending order and we get a skewed tree where all the nodes except leaf have one and only one child.
For a height balanced BSTs, with each comparison we skip about half of the tree, so that each insertion operation takes time proportional to the logarithm of the number of items n stored in the tree. 
This is much better than the linear time required to find items by key in an (unsorted) array or unbalanced trees.

We can easily modify the solution to get height balanced BSTs if all keys are known in advance. The idea is to sort the given keys first. 
Then the root will be the middle element of the sorted array and we recursively construct the left subtree of root by keys less than the middle element 
and right subtree of root by keys more than the middle element.*/