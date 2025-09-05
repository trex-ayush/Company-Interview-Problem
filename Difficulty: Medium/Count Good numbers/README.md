<h2><a href="https://www.geeksforgeeks.org/problems/count-good-numbers/1">Count Good numbers</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">A digit string is <strong>good</strong> if the digits <strong>(0-indexed)</strong> at <strong>even</strong> indices are even and digits at <strong>odd</strong> indices are <strong>prime</strong> ( 2 , 3 , 5 or 7 ).</span></p>

<ul>
	<li><span style="font-size:18px">For example, "4562" is good because the digits (4&nbsp;and 6) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is <strong>not</strong> good.</span></li>
</ul>

<p><span style="font-size:18px">Given an integer <strong>N</strong>&nbsp;, return the <strong>total</strong> number of <strong>good digit strings</strong> of length N.<br>
Since the answer may be too large, return it <strong>modulo 10<sup>9</sup> + 7</strong>.</span></p>

<p><span style="font-size:18px">Note : A <strong>digit string</strong> is a string consisting of digits 0 through 9 that may contain leading zeros.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<div style="background: rgb(238, 238, 238); border: 1px solid rgb(204, 204, 204); padding: 5px 10px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:#222426; --darkreader-inline-border-top:#3e4446; --darkreader-inline-border-right:#3e4446; --darkreader-inline-border-bottom:#3e4446; --darkreader-inline-border-left:#3e4446;"><span style="font-size:18px"><strong>Input:</strong><br>
N = 1<br>
<strong>Output:</strong><br>
5<br>
<strong>Explanation:</strong><br>
The good digit string of length of 1 are "0" , "2" , "4" ,"6" and "8".</span></div>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<div style="background: rgb(238, 238, 238); border: 1px solid rgb(204, 204, 204); padding: 5px 10px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:#222426; --darkreader-inline-border-top:#3e4446; --darkreader-inline-border-right:#3e4446; --darkreader-inline-border-bottom:#3e4446; --darkreader-inline-border-left:#3e4446;"><span style="font-size:18px"><strong>Input:</strong><br>
N = 3<br>
<strong>Output:</strong><br>
100</span></div>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong></span></p>

<p><span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function<strong> countGoodNumbers()</strong>&nbsp;which takes an integer N as inputs&nbsp;returns the total number of good digit strings of length N&nbsp;. As this result can be very large return the result under modulo 10<sup>9</sup>+7.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(logN)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>1</sup><sup>5</sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Algorithms</code>&nbsp;