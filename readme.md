## :bookmark_tabs:Plan

* 动态规划
	* 背包问题

	  > <del>[POJ-1837](http://exp-blog.com/2018/06/23/pid-882/)</del>
	  >
	  > <del>[POJ-1276](http://exp-blog.com/2018/06/23/pid-887/) </del>
	  >
	  > <del>[POJ-1014](http://exp-blog.com/2018/06/25/pid-1168/)</del>
		
	* 动态规划
	
	  > <del>[POJ 1018](http://poj.org/problem?id=1018)</del>
	  >
	  > <del>POJ 3267</del>
	  >
	  > <del>POJ 1260</del>
	  >
	  > <span style="color:red">POJ 1015</span>
	  >
	  > <del>POJ 3176</del>
	  >
	  > <del>POJ 1080</del>
	  >
	  > <del>POJ 1159</del>
	  >
	  > <del>POJ 2533</del>
	  >
	  > <del>POJ 1836</del>
	
* 搜索

  * DFS

    > <del>POJ 2488</del>
    >
    > <del>POJ 3083</del>
    >
    > <del>POJ 3009</del>
    >
    > <del>POJ 1321</del>
    
  * BFS
  
    > <del>POJ 3278 </del>
    >
    > <del>POJ 1426</del>	
    >
    > <del>POJ 3126</del>
    >
    > <del>POJ 3414</del>
    >
    > <del>POJ 2251</del>
  
  * 简单搜索技巧和剪枝
  
    > <del>POJ 1010</del> :star:
    >
    > <span style="color:red">POJ 2362</span>
    >
    > <span style="color:red">POJ 1011</span>（搜索+剪枝）
    >
    > <del>POJ 1416</del>
    >
    > <del>POJ 2676</del>
    >
    > <del>POJ 1129</del>:grey_question:
  
* 数据结构

  * 串

    > <del>POJ 1016</del>
    >
    > POJ 1035
    >
    > POJ 3080
    >
    > <del>POJ 1936</del>

  * 排序

    > <del>POJ 1007</del>
    >
    > POJ 2388
    >
    > POJ 1804
    >
    > <del>POJ 2299</del>

  * 高效查找

    > <del>POJ 1002</del>
    >
    > <span style="color:red">POJ 3349</span>
    >
    > <del>POJ 3274</del>
    >
    > POJ 1840
    >
    > POJ 2002
    >
    > POJ 3432
    >
    > POJ 2503
    
  * 哈夫曼树、优先队列

    > <del>POJ 3253</del>

  * trie树

    > <del>POJ 2513</del>

* 图算法

  * 图遍历（前序、中序、后序）

    > <del>POJ 2255</del>
    
  * 最短路（Bellman-Ford/SPFA/Dijkstra）

    > <del>POJ 1860</del>
    >
    > <del>POJ 3259</del>
    >
    > <del>POJ 1062</del>
    >
    > POJ 2253
    >
    > POJ 1125
    >
    > POJ 2240

  * 最小生成树(Prime)

    > <del>POJ 1789</del>
    >
    > <del>POJ 2485</del>
    >
    > <del>POJ 1258</del>
    >
    > POJ 3026
    
  * 拓扑排序(Kahn)

    > <del>POJ 1094</del>

  * 二分图的最大匹配:ghost:(<u>不够熟练</u>)

    > <del>POJ 3041</del>
    >
    > POJ 3020

* 北大叉院2019

  > POJ 1064
  >
  > POJ 1321
  >
  > 百练 3421
  >
  > 百练 4128 
  >
  > POJ 1185
  >
  > 


## :star:*READ*

* [Manacher’s Algorithm](http://articles.leetcode.com/longest-palindromic-substring-part-ii/)

  *O(n)*时间复杂度寻找字符串中的最长回文子串
  
* [POJ试题分类](http://exp-blog.com/2018/06/28/pid-38/)

## :busstop:TODO

* KMP
* 背包问题及其变种
  * 多重背包
    * 二进制拆分
    * O(Vn)解法
* DP  :small_airplane: :small_airplane: :small_airplane: :small_airplane: :small_airplane: :small_airplane:
  * 最大子段和
  * 最长递增子序列(LIS)
  * 最长公共子序列(LCS)
* 最短路  :small_airplane:
  * Floyd
  * Dijkstra
  * Bellman-Ford(检查出的是包含源点的负环还是所有负环？)
  * SPFA
* 并查集  :small_airplane:
* BFS  :small_airplane: :small_airplane:
* DFS  :small_airplane:
* 贪心  :small_airplane:
* 二叉树遍历  :small_airplane:
* 输入输出整理
  * long long 
  * double

## :artificial_satellite:Knowledge

* 闰年：能被4整除且不能被100整数；能被400整除

* 使用BIT时需要特别注意，当*idx*为0时*update*会陷入死循环

* 滚动数组

* <span style="color:red">有整数求和操作时注意是否需要使用long long !!!</span>

* 欧拉图（一笔画问题）

  > * 联通无向图存在欧拉路径的充要条件：度数为奇数的结点的数目等于0或2
  > * 联通无向图存在欧拉回路的充要条件：每个结点的度数均为偶数
  > * 联通有向图可以表示为一条从u到v的欧拉路径的充要条件：u的出度比入度多1，v的出度比入度少1，其他结点的出度和入度相等
  
* 拓扑排序

  * *Kahn*算法（前驱结点法）

## :grey_question:Problem

* 图着色问题与最大团是否等价？（仿佛有个反例）

  A-B B-C C-D D-E E-A

## :kissing_smiling_eyes:Key

* POJ 1018

* POJ 1837

* POJ 3274

* POJ 2513

  




