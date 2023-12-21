This project was create in order to produce a compiler which translates from one coding language to another. The way this is accomplished is by feeding
input code into a lexical analyzer which differentiates between keywords, variable names, digits, and operands. The lexical analyzer creates a series
of tokens which are then read into the below BNF:

<program>  ->     <vars> main <stats> end<br>
<vars>         ->      empty | let <varList> .<br>
<varList>     ->      id = integer | id = integer <varList><br>
<exp>          ->      <M> + <exp> | <M> - <exp> | <M><br>
<M>             ->      <N> * <M> | <N>      <br>
<N>             ->     <R> / <N> | - <N> |  <R><br>
<R>              ->      [ <exp> ]  | id | integer<br>
<stats>         ->      <stat>  <mStat><br>
<mStat>       ->      empty |  <stat>  <mStat><br>
<stat>           ->      <in>   | <out>   | <block> | <if>  | <loop>  | <assign><br>
<block>       ->      start <vars> <stats> stop<br>
<in>              ->      scan identifier .<br>
<out>            ->      print <exp> .<br>
<if>               ->      cond ( <exp> <RO> <exp> ) <stat><br>
<loop>          ->      loop ( <exp> <RO> <exp> )  <stat><br>
<assign>       ->      id  ~ <exp> .<br>
<RO>            ->      <= (one token)  | >=  (one token)  | < | > | = | ~   <br>

Using this BNF structure, P4.cpp then builds the a parse tree using a preorder traversal.

Here is an example input code:

main 
  print 1 .
  scan aa .
  start
    let aa = 2 .
    print aa .
  stop
end


![preorder traversal](https://github.com/ThomasCholak/CodeCompilationProject/assets/63080803/ea10e056-9a1a-4252-b92e-783bce074c99)
