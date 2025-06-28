<h2><a href="https://www.geeksforgeeks.org/problems/prerequisite-tasks/1?page=2&difficulty%5B%5D=1&category%5B%5D=Graph&sortBy=submissions">Prerequisite Tasks</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]<br>Given the total number of tasks <strong>N</strong> and a list of <strong>P prerequisite pairs</strong>, find if it is possible to finish all tasks.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>N = 4, P = 3, prerequisites = [[1,0],[2,1],[3,2]]
<strong>Output: </strong>Yes
<strong>Explanation</strong>: To do task 1 you should have completed task 0, and to do task 2 you should have finished task 1, and to do task 3 you should have finished task 2. So it is possible.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>N = 2, P = 2, prerequisites = [[1,0],[0,1]]
<strong>Output: </strong>No
<strong>Explanation</strong>: To do task 1 you should have completed task 0, and to do task 0 you should have finished task 1. So it is impossible.
</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ N ≤ 10<sup>4</sup><br>1 ≤ P ≤ 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Google</code>&nbsp;<code>Facebook</code>&nbsp;<code>Twitter</code>&nbsp;<code>Apple</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;