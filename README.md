<p dir="ltr" style="text-align: left;"></p>
<p dir="ltr"></p>
<h5><strong><u>Problem:</u></strong><br></h5>
<div>In this exam, you are given two 2D boxes consisting of full and empty cells. The goal is to convert the first box into the second with the minimum cost of operations (the operations are defined below). The boxes are represented as 2D char arrays.&nbsp;<span style="font-size: 0.9375rem;">In the arguments, both boxes will be defined&nbsp; to include the same number of rows, yet the number of their columns may be different. For instance, Box-1 can be an array of the size of 10x12 whereas Box-2 can be an array of the size of 10x15. In order to represent empty cells, '-' character is used and for the full cells a letter is used.&nbsp; In the figure below, a few input box illustrations are given:</span></div>
<div><span style="font-size: 0.9375rem;"><img src="https://github.com/user-attachments/assets/3ee1135a-c587-401d-8969-6cf105ee7e6e" alt="box examples a-b-c" width="1074" height="646" class="img-fluid atto_image_button_text-bottom"><br></span></div>
<div><span style="font-size: 0.9375rem;"><img src="https://github.com/user-attachments/assets/0c0bd6ed-4036-446e-bb83-89daf94bf689" alt="box examples d-e-f" width="1068" height="757" class="img-fluid atto_image_button_text-bottom"><br></span></div>
<div><span style="font-size: 0.9375rem;"><br></span></div>
<div>Your task is to convert the first box into the second box by using some operations resulting in the minimum cost. The conversion rules and operations are defined as follows:</div>
<div>
    <ul>
        <li>You should compare the boxes column by column. Each conversion operation is column-wise.</li>
        <li>A column could be deleted completely. The <strong>deletion operation</strong> costs as much as the number of full cells in the column. For instance; if the column consists of 5 cells where 3 of them full and 2 of them are empty, then deleting that column costs 3 units.</li>
        <li>For a column of Box-2, a new corresponding column could be inserted into Box-1 at any location (between two columns or as the initial column or as the final column). The <strong>insertion operation</strong> costs as much as the number of full cells inside the new column. For instance; if the newly inserted column consists of 5 cells where 3 of them full and 2 of them are empty, then inserting that column costs 3 units.</li>
        <li>A column could be converted into a new column by reordering its cells. For intance, if a column consists of 5 cells including ['X', 'A', '-', 'B', '-'], it can be reordered as ['A', '-', '-', 'B', 'X']. The <strong>reordering operation</strong> costs as much as the number of cells whose locations are changed. For the example given, since the locations of the cells including 'A', 'X' and '-' changed only, it costs 3 units.&nbsp;</li>
        <li>A column could be converted into a new column by replacing its cells with some other cells. For the<strong> replacement operation</strong>, if a full cell is replaced with some other full cell, then it costs 1 unit. However, if an empty cell is replaced with a full cell, or vice versa, then it costs 2 units. For instance, if a column consists of 5 cells including ['X', 'A', '-', 'B', '-'], its cells can be replaced as ['X', 'C', 'D', '-', '-'], it costs &lt;change from 'A' to 'C'&gt; + &lt;change from '-' to 'D'&gt; + &lt;change from 'B' to '-'&gt; = 1 + 2 + 2 = 5 units.</li>
        <li>Each operation is independent from each other. At each transition, apply only one of them.</li>
        <li><strong>HINT:</strong> You should implement the dynamic programming column-wise. That is, for each column of Box-2, consider a corresponding column inside Box-1 which has been obtained by the operations above. The way of how to apply memoization is explained in the following parts.</li>
    </ul>
</div>
<div><strong>Example IO:</strong><br>
    <table cellspacing="0" cellpadding="0" border="1">
        <tbody>
            <tr>
                <td width="604" valign="top">
                    <p><strong>1) Given boxes in (a) of the above Figure:</strong></p>
                    <ul>
                        <ul>
                            <li>return value (i.e. min cost) is 8.</li>
                            <li>Since this is the first example, let's explain all the cells of mem array:</li>
                        </ul>
                    </ul>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <strong>mem[0][0]</strong><strong> : </strong><em>Conversion
                        of no columns of box1 to no columns of box2</em><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; No operation <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;=&gt; costs 0<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <strong>mem[0][1] :</strong> <em>Conversion
                        of no columns of box1 to first column of box2</em><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Apply insertion
                    operation to obtain the first column of box2 <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;=&gt; costs 3<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <strong>mem[0][2] :</strong> <em>Conversion
                        of no columns of box1 to first 2 columns of box2</em><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Apply insertion
                    operation for
                    both
                    of
                    the
                    first
                    two columns of
                    box2
                    <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; =&gt;
                    costs 3 +2
                    =
                    5<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <strong>mem[0][3] :</strong> <em>Conversion
                        of no columns of box1 to first 3 columns of box2</em><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Apply
                    insertion operation for each of the 3 columns of box2 <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; =&gt; costs 3 + 2 + 3 = 8<span style="font-size: 0.9375rem;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <strong>mem[1][0] :</strong> <em>Conversion
                            of first column of box1 to no columns of box2</em><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Apply
                        deletion operation on the initial column of box1 <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; =&gt; costs 3<br></span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <strong>mem[1][1] :</strong>&nbsp;<em>Conversion of first column of box1 to first column of box2</em><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Apply reordering operation to
                    change the first column of box1 to <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;the first column of box2 <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;=&gt; costs 4<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <strong>mem[1][2] :</strong> <em>Conversion
                        of first
                        column
                        of
                        box1 to first 2 columns of box2</em><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Apply
                    reordering
                    operation to change the first column of box1 to <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;the first column of box2 and<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Apply
                    insertion
                    operation
                    to
                    obtain
                    the second column of box2 <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;=&gt; costs 4 + 2 = 6<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <strong>mem[1][3] :</strong> <em>Conversion
                        of first column of box1 to first 3 columns of box2</em><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Apply
                    insertion
                    operation to obtain the first column of box2 and<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Apply
                    insertion operation to obtain the second column of box2 and<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Apply
                    reordering operation to change the first column of box1 to&nbsp;<br><span style="font-size: 0.9375rem;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; the third column of
                        box2&nbsp;<br></span><span style="font-size: 0.9375rem;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;=&gt; costs 3 +2 + 3 = 8<br><br></span>
                    <p><strong style="font-size: 0.9375rem;">2) <strong>Given boxes in (b) of the above Figure:</strong></strong></p>
                    <div>
                        <ul>
                            <ul>
                                <li>return value (i.e. min cost) is 6.</li>
                                <li>at dynamic programming, final mem array is given its right side.</li>
                            </ul>
                        </ul>
                    </div>
                    <div>
                        <div>
                            <div>
                                <div></div>
                            </div>
                        </div>
                    </div>
                    <div>
                        <div></div>
                    </div>
                    <p></p>
                    <p><strong>3) </strong><strong>Given boxes in (c) of the above Figure:</strong></p>
                    <ul>
                        <ul>
                            <li>return value (i.e. min cost) is 19.</li>
                            <li>at dynamic programming, final mem array is given its right side.</li>
                        </ul>
                    </ul>
                    <p><strong>4) </strong><strong>Given boxes in (d) of the above Figure:</strong></p>
                    <ul>
                        <ul>
                            <li>return value (i.e. min cost) is 18.</li>
                            <li>at dynamic programming, final mem array is given its right side.</li>
                        </ul>
                    </ul>
                    <div>
                        <div>
                            <div></div>
                        </div>
                    </div>
                    <div>
                        <div>
                            <div>
                                <div></div>
                            </div>
                        </div>
                    </div>
                    <div>
                        <div>
                            <div></div>
                        </div>
                    </div>
                    <p></p>
                    <p></p>
                    <p><strong>5) </strong><strong>Given boxes in (e) of the above Figure:</strong></p>
                    <ul>
                        <ul>
                            <li>return value (i.e. min cost) is 7.</li>
                            <li>at dynamic programming, final mem array is given its right side.</li>
                        </ul>
                    </ul>
                    <p></p>
                    <p><strong></strong></p>
                    <p><strong><strong></strong></strong></p>
                    <p><strong>6) </strong><strong>Given boxes in (f) of the above Figure:</strong></p>
                    <ul>
                        <ul>
                            <li>return value (i.e. min cost) is 15.</li>
                            <li>at dynamic programming, final mem array is given its right side.</li>
                        </ul>
                    </ul>
                </td>
            </tr>
        </tbody>
    </table>
</div>
<h5><strong><u><br></u></strong></h5>
<h5><strong><u>Implementation:</u></strong></h5>
<div>You will implement only one function for solution of that problem:<ul>
        <li>Dynamic programming in<strong><em>&nbsp;dp_sln()</em></strong></li>
    </ul><strong>The function</strong>&nbsp;is expected to&nbsp;<strong>return</strong>&nbsp;the answer to the given problem which is&nbsp;<strong>the minimum cost of operations.&nbsp;</strong>Return&nbsp;<strong>only</strong>&nbsp;the min cost value and nothing more.</div>
<div><br></div>
<div>
    <div>The&nbsp;<span><strong style="font-style: italic;">char**&amp; box1 </strong>and<strong style="font-style: italic;"> char**&amp; box2&nbsp;</strong></span>variables are the parameters which pass the input 2D array of boxes to your functions.&nbsp;<strong>Do not modify those arrays!&nbsp;</strong>The&nbsp;format of boxes will be as stated in the problem definition above.<br></div>
    <div><br></div>
    <div>The&nbsp;<span><strong style="font-style: italic;">int nrow</strong><span style="">,</span><strong style="font-style: italic;"> int ncol1 </strong>and<strong style="font-style: italic;"> int ncol2</strong></span>&nbsp;variables are the parameters which passes the number of rows of both boxes, number of columns of <em>box1</em> and number of columns of <span><em>box2,</em> repectively,</span>&nbsp;to your function.&nbsp;</div>
</div>
<div><br></div>
<div>You should use&nbsp;<em><strong>int**&amp; mem&nbsp;</strong></em><strong></strong>variable (i.e. array), which is the last parameter at definition of the function, as&nbsp;<strong>the array of memoized values</strong>. For&nbsp;<em>dp_sln()</em>&nbsp;function, final values in the&nbsp;<em>mem</em>&nbsp;variable will be considered for grading. Note that it is a 2D array. It is defined as <strong>the size of (ncol1+1) x (ncol2+1</strong>) such that its rows correspond to columns of <em>box1</em> and its columns correspond to columns of <em>box2</em>. <strong>That is, the <span><em>mem[i][j]</em></span> will be used to indicate the TOTAL COST of
        matching of THE FIRST i columns of box1 with THE FIRST j columns of box2<em></em></strong>. Thus <em>mem[0][0]</em> indicates there is no matching columns in box1 and box2! While testing and grading, all the cells of&nbsp;<em>mem</em>&nbsp;array will be initialized to -1's. So, while implementing your function,&nbsp;<strong>you can assume that&nbsp;<em>mem</em>&nbsp;is an array of array of -1's. Do not return that variable/array.</strong></div>
<div><br>
    <div>The <em>dp_sln()</em>&nbsp;function should be implemented with bottom-up (iterative) approach.</div>
    <div><br>Implement the&nbsp; function in most efficient way.</div>
</div><br><strong>Constraints:</strong><br>
<p></p>
<ul>
    <li>Maximum number of rows and columns of boxes will be&nbsp;<strong>100</strong>.&nbsp;</li>
</ul>
<p><strong>Evaluation:</strong></p>
<p></p>
<ul>
    <li>After your exam, black box evaluation will be carried out. You will get full points if&nbsp;</li>
</ul>
<ol>
    <li>your functionsreturn the correct min cost&nbsp;</li>
    <li>and you fill the&nbsp;<em><strong>mem</strong></em>&nbsp;array correctly, as stated.</li>
    <li>you did not change the input arrays (the array of boxes).</li>
</ol>
<h5><u><strong>Specifications:</strong></u></h5>
<p dir="ltr"></p>
<ul>
    <li>There is&nbsp;<strong>1</strong><strong><strong>&nbsp;task</strong></strong>&nbsp;to be solved in&nbsp;<strong>12 hours</strong>&nbsp;in this take home exam.</li>
    <li>You will implement your solution in&nbsp;<strong>the4.cpp</strong>&nbsp;file.</li>
    <li>Do&nbsp;<strong>not&nbsp;</strong>change the first line of&nbsp;<strong>the4.cpp</strong>, which is&nbsp;<strong>#include "the4.h"</strong></li>
    <li><em>&lt;iostream&gt;,&nbsp; &lt;climits&gt;</em>&nbsp;,&nbsp;<em>&lt;cmath&gt;</em>&nbsp;,&nbsp;<em>&lt;cstdlib&gt;&nbsp;&nbsp;</em>are included in "the4.h" for your convenience.</li>
    <li>Do&nbsp;<strong>not&nbsp;</strong>change the arguments and return&nbsp;<strong>type</strong>&nbsp;of the function<strong>&nbsp;dp_sln()&nbsp;</strong>in the file&nbsp;<strong>the4.cpp.&nbsp;</strong>(You should change return&nbsp;<strong>value</strong>, on the other hand.)<strong><br></strong></li>
    <li>Do&nbsp;<strong>not&nbsp;</strong>include any other library or write include anywhere in your&nbsp;<strong>the4.cpp</strong>&nbsp;file (not even in comments).</li>
    <li>Do&nbsp;<strong>not</strong>&nbsp;write any helper method.</li>
</ul>
<h5><strong><u>Compilation:</u></strong></h5>
<p></p>
<ul>
    <li>You are given&nbsp;<strong>test.cpp</strong>&nbsp;file to&nbsp;<strong>test&nbsp;</strong>your work on&nbsp;<strong>ODTÜClass</strong>&nbsp;or your&nbsp;<strong>locale</strong>. You can and you are encouraged to modify this file to add different test cases.</li>
    <li>If you want to&nbsp;<strong>test&nbsp;</strong>your work and see your outputs you can&nbsp;<strong>compile and run&nbsp;</strong>your work on your locale as:</li>
</ul>
<table cellspacing="0" cellpadding="0" border="1">
    <tbody>
        <tr>
            <td width="604" valign="top">
                <p>&gt;g++ test.cpp the4.cpp -Wall -std=c++11 -o test</p>
                <p>&gt; ./test</p>
            </td>
        </tr>
    </tbody>
</table><br>
<ul>
    <li>You can test your&nbsp;<strong>the4.cpp</strong>&nbsp;on virtual lab environment. If you click&nbsp;<strong>run</strong>, your function will be compiled and executed with&nbsp;<strong>test.cpp</strong>. If you click&nbsp;<strong>evaluate</strong>, you will get a feedback for your current work and your work will be&nbsp;<strong>temporarily&nbsp;</strong>graded for&nbsp;<strong>limited&nbsp;</strong>number of inputs.</li>
    <li>The grade you see in lab is&nbsp;<strong>not</strong>&nbsp;your final grade, your code will be re-evaluated with&nbsp;<strong>completely</strong>&nbsp;<strong>different&nbsp;</strong>inputs after the exam.</li>
</ul>
<p>The system has the following limits:<br></p>
<ul>
    <li>a maximum execution time of 32 seconds</li>
    <li>a 192 MB maximum memory limit</li>
    <li>an execution file size of 1M.</li>
    <li>Solutions with longer running times will not be graded.</li>
    <li>If you are sure that your solution works in the expected complexity constrains but your evaluation fails due to limits in the lab environment, the constant factors may be the problem.<br><br></li>
</ul>
<table width="656" cellspacing="0" cellpadding="0" border="1">
    <tbody>
        <tr>
            <td width="656" valign="top">
                <p>int dp_sln(char**&amp; arr1, char**&amp; arr2, int nrow, int ncol1, int ncol2, int**&amp; mem);<br></p>
            </td>
        </tr>
    </tbody>
</table>
<div><br></div><br><br>
<p></p>
