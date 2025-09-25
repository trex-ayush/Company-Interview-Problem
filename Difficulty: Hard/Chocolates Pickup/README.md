<h2><a href="https://www.geeksforgeeks.org/problems/chocolates-pickup/1">Chocolates Pickup</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">You are given an <strong><code>n </code></strong><code>rows</code><strong><code> </code></strong><code>and</code><strong><code> m </code></strong><code>cols</code>&nbsp;matrix&nbsp;<strong><code>grid</code></strong> representing a field of chocolates where&nbsp;<code>grid[i][j]</code>&nbsp;represents the number of chocolates&nbsp;that you can collect from the&nbsp;<code>(i, j)</code>&nbsp;cell.</span></p>
<p><span style="font-size: 18px;">You have two robots that can collect chocolates for you:</span></p>
<ul>
<li><span style="font-size: 18px;"><strong>Robot #1</strong>&nbsp;is located at the&nbsp;<strong>top-left corner</strong>&nbsp;<code>(0, 0)</code>, and</span></li>
<li><span style="font-size: 18px;"><strong>Robot #2</strong>&nbsp;is located at the&nbsp;<strong>top-right corner</strong>&nbsp;<code>(0, cols - 1)</code>.</span></li>
</ul>
<p><span style="font-size: 18px;">Return&nbsp;the maximum number of chocolates collection using both robots by following the rules below:</span></p>
<ul>
<li><span style="font-size: 18px;">From a cell&nbsp;<code>(i, j)</code>, robots can move to cell&nbsp;<code>(i + 1, j - 1)</code>,&nbsp;<code>(i + 1, j)</code>, or&nbsp;<code>(i + 1, j + 1)</code>.</span></li>
<li><span style="font-size: 18px;">When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.</span></li>
<li><span style="font-size: 18px;">When both robots stay in the same cell, only one takes the chocolates.</span></li>
<li><span style="font-size: 18px;">Both robots cannot move outside of the grid at any moment.</span></li>
<li><span style="font-size: 18px;">Both robots should reach the bottom row in&nbsp;<code>grid</code>.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Example:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>n = 4, m = 3
grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
<strong>Output:</strong>
24</span><span style="font-size: 18px;">
<strong>Explanation:</strong>
Path of robot #1 and #2 are described in color green and blue respectively. Chocolates taken by Robot #1, (3 + 2 + 5 + 2) = 12. Chocolates taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of Chocolates: 12 + 12 = 24.</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n * m * m)</span><br><span style="font-size: 18px;"><strong>Expected Space Complexity:</strong> O(n * m * m)</span></p>
<p><strong><span style="font-size: 18px;">Constraint:</span></strong><br><span style="font-size: 18px;">2 &lt;= n, m &lt; = 70<br>0 &lt;= grid[i][j] &lt;= 100</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;