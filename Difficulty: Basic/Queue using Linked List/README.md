<h2><a href="https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1">Queue using Linked List</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Implement a Queue using Linked List.&nbsp;<br>A Query&nbsp;<strong>Q</strong>&nbsp;is of 2 Types<br><strong>(i)</strong>&nbsp;1 x&nbsp; &nbsp;(a query of this type means&nbsp;&nbsp;pushing&nbsp;<strong>'x'</strong>&nbsp;into the queue)<br><strong>(ii)</strong>&nbsp;2 &nbsp; &nbsp; (a query of this type means to pop an element from the queue and print the poped element)</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>Q = 5, Queries = [[1, 2], [1, 3], [2], [1, 4], [2]]<br><strong>Output: </strong>2 3&nbsp;<strong><br>Explanation: <br></strong>[1,2] queue will be 2<br>[1,3] queue will be 2,3<br>[2] poped element will be 2 the queue will be 3<br>[1, 4] queue will be 3, 4<br>[2] poped element will be 3 </span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>Q = 4, Queries = [[1, 2], [2], [2], [1, 3]]
<strong>Output: </strong>2 -1<strong>
Explanation:</strong>
[1, 2] queue will be 2
[2] &nbsp;poped element will be 2 then
&nbsp;   the queue will be empty.&nbsp;
[2] &nbsp;the queue is empty and hence -1
[1, 3] the queue will be 3</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤<strong>&nbsp;</strong>Q ≤ 100<br>1 ≤ x ≤ 100</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Queue</code>&nbsp;<code>Data Structures</code>&nbsp;