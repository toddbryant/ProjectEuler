/* 
 * Finds the max sum from the top to the bottom of a full binary tree.
 * Consider a function maxSum(node) which tells us the max sum of any path to the 
 * bottom of the tree.
 * For a leaf, maxSum(leaf) = leaf.value
 * Otherwise, maxSum(parent) = parent.value + max(maxSum(leftChild), maxSum(rightChild))
 */

#include <iterator>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>

// Determines with level of the tree a given index is on
inline int getLevel(int index)
{
   return (int)( (sqrt(8*index + 1.0) + 1.0)/2.0);
}

// Computes the max sum in the tree starting at index i
int calcMaxSum(const std::vector<int>& tree, 
               std::vector<int>& maxSumCache,
               int index)
{
   if(index >= tree.size())
      return 0;
   if(maxSumCache[index]!=0)
      return maxSumCache[index];

   int level = getLevel(index);
   return maxSumCache[index] = tree[index] + std::max(calcMaxSum(tree, maxSumCache, index + level),
                                                      calcMaxSum(tree, maxSumCache, index + level + 1)); 
}

int main(int argc, char** argv)
{
   // Copy all nums from file into vector
   std::ifstream in("nums.txt");
   std::istream_iterator<int> start(in);
   std::istream_iterator<int> end;
   std::vector<int> tree(start, end);

   // Cache of max sums
   std::vector<int> maxSumCache(tree.size(), 0); 
   std::cout << calcMaxSum(tree, maxSumCache, 0) << std::endl;
}   

