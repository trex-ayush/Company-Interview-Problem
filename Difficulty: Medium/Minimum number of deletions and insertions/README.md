<h2><a href="https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1">Minimum number of deletions and insertions</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two strings <strong>s1</strong> and <strong>s2</strong>. The task is to <strong>remove or insert</strong> the <strong>minimum</strong> <strong>number</strong> of characters from/in <strong>s1</strong> to transform it into <strong>s2</strong>. It could be possible that the same character needs to be removed from one point of <strong>s1</strong> and inserted into another point.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s1 = "heap", s2 = "pea"
<strong>Output:</strong> 3
<strong>Explanation: </strong>'</span><span style="font-size: 18px;">p'</span><span style="font-size: 18px;"> and 'h' deleted from <strong>h</strong>ea<strong>p</strong>. Then, 'p' is inserted at the beginning.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input : </strong>s1 = "geeksforgeeks", s2 = "geeks"
<strong>Output: </strong>8
<strong>Explanation: </strong>8 deletions, i.e. remove all characters of the string "forgeeks".</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ s1.size(), s2.size() ≤ 1000</span><br><span style="font-size: 18px;">All the characters are lowercase English alphabets.</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;