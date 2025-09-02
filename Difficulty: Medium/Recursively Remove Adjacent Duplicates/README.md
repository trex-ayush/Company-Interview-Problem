<h2><a href="https://www.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1">Recursively Remove Adjacent Duplicates</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string s, remove all its adjacent duplicate characters recursively, until there are no adjacent duplicate characters left.</span></p>
<p><span style="font-size: 18px;">Note: If the resultant string becomes empty, return an empty string.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "geeksforgeek"
<strong>Output:</strong> "gksforgk"
<strong>Explanation:  </strong>g(ee)ksforg(ee)k -&gt; gksforgk</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "abccbccba"
<strong>Output:</strong> ""
<strong>Explanation: </strong>ab(cc)b(cc)ba-&gt;abbba-&gt;a(bbb)a-&gt;aa-&gt;(aa)-&gt;""(empty string)<br></span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "abcd"
<strong>Output:</strong> "abcd"
<strong>Explanation: </strong>There are no adjacent duplicate characters</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&lt;= s.size() &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Samsung</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Recursion</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;