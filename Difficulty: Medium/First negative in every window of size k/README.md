<h2><a href="https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1">First negative in every window of size k</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr[] </strong>&nbsp;and a positive integer <strong>k</strong>, find the first negative integer for each and every window(contiguous subarray) of size <strong>k.</strong></span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong></span><span style="font-size: 18px;">&nbsp;</span><span style="font-size: 18px;">If a window does not contain a negative integer, then return 0 for that window.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">arr[] = [-8, 2, 3, -6, 10] , k = 2
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">[-8, 0, -6, -6]
</span><strong style="font-size: 18px;">Explanation:</strong><span style="font-size: 18px;">
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.<br></span></span></pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">[-1, -1, -7, -15, -15, 0] <br></span><strong style="font-size: 18px;">Explanation:<br></strong><span style="font-size: 18px;">Window [12, -1, -7] First negative integer is -1.
Window [-1, -7, 8] First negative integer is -1.
Window [-7, 8, -15] First negative integer is -7.
Window [8, -15, 30] First negative integer is -15.
Window [-15, 30, 16] First negative integer is -15.
Window [30, 16, 28] No negative integers, output is 0.<br></span></span></pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">arr[] = [12, 1, 3, 5] , k = 3
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">[0, 0] <br></span><strong style="font-size: 18px;">Explanation:<br></strong><span style="font-size: 18px;">Window [12, 1, 3] No negative integers, output is 0.
Window [1, 3, 5] No negative integers, output is 0.</span></span></pre>
<p><span style="font-size: 18px;"><br><strong>Constraints:</strong><br>1 &lt;= arr.size() &lt;= 10<sup>6</sup><br>-10<sup>5</sup> &lt;= arr[i] &lt;= 10<sup>5</sup><br>1 &lt;= k &lt;= arr.size()</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>sliding-window</code>&nbsp;<code>two-pointer-algorithm</code>&nbsp;<code>Arrays</code>&nbsp;<code>Queue</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;