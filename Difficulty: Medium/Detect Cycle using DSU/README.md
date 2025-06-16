<h2><a href="https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1">Detect Cycle using DSU</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an <strong>undirected graph</strong> with <strong>no self loops</strong> with <strong>V (from 0 to V-1)</strong> nodes and <strong>E</strong> edges, the task is to check if there is any <strong>cycle </strong>in the <strong>undirected graph</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> Solve the problem using <strong>disjoint set union (DSU).</strong></span></p>
<p><span style="font-size: 18px;"><strong>Examples</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: 
</strong></span><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/701410/Web/Other/blobid0_1745299580.jpg" width="303" height="268"><br><span style="font-size: 18px;"><strong>Output:</strong><strong>&nbsp;</strong>1
<strong>Explanation: </strong>There is a cycle between 0-&gt;2-&gt;4-&gt;0</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: 
</strong></span><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/701410/Web/Other/blobid1_1745299616.jpg" width="307" height="272"><br><span style="font-size: 18px;"><strong>Output: </strong>0
<strong>Explanation: </strong>The graph doesn't contain any cycle</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read or print anyhting. Your task is to complete the function&nbsp;<strong>detectCycle()&nbsp;</strong>which takes number of vertices in the graph denoting as <strong>V</strong> and adjacency list <strong>adj </strong>and returns <strong>1</strong> if graph contains any <strong>cycle </strong>otherwise returns <strong>0</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(V + E)<br><strong>Expected Space Complexity:&nbsp;</strong>O(V)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">2 ≤ V ≤ 10<sup>4<br></sup></span><span style="font-size: 18px;">1 ≤ E ≤ 10<sup>4</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>Disjoint Set</code>&nbsp;<code>Data Structures</code>&nbsp;