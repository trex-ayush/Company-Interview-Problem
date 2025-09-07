<h2><a href="https://www.geeksforgeeks.org/problems/implement-stack-using-array/1">Implement stack using array</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p data-pm-slice="0 0 []"><span style="font-size: 14pt;">Write a program to implement a stack using an array <strong>oper[]</strong>. You need&nbsp; to complete the <strong>push(int x)</strong> and <strong>pop()</strong> methods inside a class <strong>MyStack</strong> to simulate the standard stack operations:<br></span><span style="font-size: 14pt;"><strong>push(x)</strong>: Pushes the integer x onto the stack.<br></span><span style="font-size: 14pt;"><strong>pop()</strong>: Removes and returns the topmost element of the stack. If the stack is empty, return -1.<br></span><span style="font-size: 14pt;">You will be given a list of space-separated queries consisting of two types:<br></span><span style="font-size: 14pt;">Type 1 : <strong>1 x</strong> — Push <strong>x</strong> into the stack.<br></span><span style="font-size: 14pt;">Type 2 : <strong>2</strong>&nbsp; — Pop the <strong>top</strong> element from the stack and print it. If the stack is empty, print -1.<br><strong>Note:</strong> It is guaranteed that for Type 1, there will always be a value x.</span><br><strong style="font-size: 18px;">Examples </strong><span style="font-size: 18px;">:</span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: oper[] = [1, 2, 1, 3, 2, 1, 4, 2] 
<strong>Output</strong>: [3, 4]
<strong>Explanation</strong>: 
push(2)   the stack will be {2}
push(3)   the stack will be {2 3}
pop()     poped element will be 3, the stack will be {2}
push(4)   the stack will be {2 4}
pop()     poped element will be 4</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: oper[] = [2, 1, 4, 1, 5, 2]
<strong>Output</strong>: [-1, 5]</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ numbers of calls made to push, pop ≤ 100<br>1 ≤ x ≤ 100</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>FactSet</code>&nbsp;<code>Visa</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Qualcomm</code>&nbsp;<code>Kritikal Solutions</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;