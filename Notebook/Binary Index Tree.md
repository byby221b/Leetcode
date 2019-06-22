## Binary Indexed Tree

A **Fenwick tree** or **binary indexed tree** is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.  It's actually an array rather than a real tree.  Note that its index begins from 1 rather 0.

Given an array arr[1...n], three are mainly two methods:

* prefixSum(idx)

  > Compute the sum of the first i-th elements.

* update(idx,delta)

  > Modify the value of a specified element of the array arr[i] = x

### 1.prefixSum

* > 1) Initialize the output sum as 0, the current index as x+1.
  > 2) Do following while the current index is greater than 0.
  > ...a) Add BITree[index] to sum
  > ...b) Go to the parent of BITree[index].  The parent can be obtained by removing
  >      the last set bit from the current index, i.e., index = index - (index & (-index))
  > 3) Return sum.

* ```c++
  int prefixSum(int idx) {
      idx += 1;
      int result = 0;
      while (idx > 0) {
          result += this.bitArr[idx];
          idx = idx - (idx & -idx);
      }
  
      return result;
  }
  ```

### 2.update

* > 1) Initialize the current index as x+1.
  > 2) Do the following while the current index is smaller than or equal to n.
  > ...a) Add the val to BITree[index]
  > ...b) Go to parent of BITree[index].  The parent can be obtained by incrementing
  >      the last set bit of the current index, i.e., index = index + (index & (-index))

* ```c
  void update(int idx, int delta) {
      idx += 1;
      while (idx < this.bitArr.length) {
          this.bitArr[idx] += delta;
          idx = idx + (idx & -idx);
      }
  }
  ```

### Visualization

![](https://img-blog.csdnimg.cn/20190319155011531.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1lhb2thaV9Bc3N1bHRNYXN0ZXI=,size_16,color_FFFFFF,t_70)

### Reference

1. https://en.wikipedia.org/wiki/Fenwick_tree
2. https://blog.csdn.net/Yaokai_AssultMaster/article/details/79492190
3. https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
4. https://leetcode.com/problems/reverse-pairs/discuss/97268/general-principles-behind-problems-similar-to-reverse-pairs