<h2><a href="https://www.geeksforgeeks.org/problems/network-delay-time/1">Network Delay Time</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a network of <strong>V</strong> nodes (numbered from 0 to V-1) and <strong>E</strong> number of directed connections, described by an array<strong> edges[]</strong>, where each element <strong>{u, v, w}</strong> specifies that a signal requires <strong>w</strong> units of time to propagate from node <strong>u</strong> to node <strong>v</strong>.</span></p>
<p><span style="font-size: 18px;">A signal is transmitted from the source node <strong>src</strong>. Return the minimum time it takes for all the nodes to receive the signal. If any node remains unreachable, return -1.<br></span></p>
<p><span style="font-size: 18px;">Note: There are no multiple edge connections in the network.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> V = 3, edges[][] = [[0, 2, 1], [2, 1, 2], [0, 1, 4]], src = 0</span><span style="font-size: 18px;">
<strong>Output: </strong>3
<strong>Explanation:</strong> In 3 units of time the signal can cover all the nodes by following this path: 0 -&gt; 2 -&gt; 1.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>V = 2, edges[][] = [[0, 1, 5]], src = 1<br><strong>Output: </strong>-1<br><strong>Explanation:</strong> There is no connection from 1 to 0.</span></pre>
<p><strong><span style="font-size: 18px;">Constraint:</span></strong></p>
<ul>
<li><span style="font-size: 18px;">0 ≤ src &lt; V&nbsp;</span><span style="font-size: 18px;">≤ 10<sup>3</sup></span></li>
<li><span style="font-size: 18px;">1&nbsp;</span><span style="font-size: 18px;">≤ E&nbsp;</span><span style="font-size: 18px;">≤ 10<sup>5</sup></span></li>
<li><span style="font-size: 18px;">0&nbsp;</span><span style="font-size: 18px;">≤ edges[i][0], edges[i][1] &lt; V</span></li>
<li><span style="font-size: 18px;">0&nbsp;</span><span style="font-size: 18px;">≤ edges[i][2]&nbsp;</span><span style="font-size: 18px;">≤ 10<sup>5</sup></span></li>
</ul></div>