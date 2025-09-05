<h2><a href="https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1">Check if there exists a subsequence with sum K</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>arr&nbsp;</strong>and&nbsp;<code>target sum <strong>k</strong></code>,&nbsp;check whether&nbsp;there exists a subsequence&nbsp;such that the sum of all elements in the subsequence equals the given&nbsp;<code>target sum(k).</code></span></p>

<p><br>
<span style="font-size:18px"><strong>Example:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong> arr = [10,1,2,7,6,1,5], k = 8.
<strong>Output: </strong> Yes
<strong>Explanation: </strong> Subsequences like [2, 6], [1, 7] sum upto 8</span>

<span style="font-size:18px"><strong>Input: </strong> arr = [2,3,5,7,9], k = 100. </span>
<span style="font-size:18px"><strong>Output: </strong> No</span>
<span style="font-size:18px"><strong>Explanation: </strong> No subsequence can sum upto 100</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anything. Your task is to complete the boolean function&nbsp;<strong>checkSubsequenceSum()</strong>&nbsp;which takes N, arr and K as input parameter and returns true/false based on the whether any subsequence with sum K could be found.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N * K).<br>
<strong>Expected Auxiliary Space:</strong> O(N * K).</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= arr.length &lt;= 2000.<br>
1 &lt;= arr[i] &lt;= 1000.<br>
1 &lt;= target &lt;= 2000.</span></p>

<p>&nbsp;</p>
</div>