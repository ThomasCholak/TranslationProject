This project was create in order to produce a compiler which translates from one coding language to another. The way this is accomplished is by feeding
input code into a lexical analyzer which differentiates between keywords, variable names, digits, and operands. The lexical analyzer creates a series
of tokens which are then read into the below BNF:

<program>  ->     <vars> main <stats> end
<vars>         ->      empty | let <varList> .
<varList>     ->      id = integer | id = integer <varList>
<exp>          ->      <M> + <exp> | <M> - <exp> | <M>
<M>             ->      <N> * <M> | <N>      
<N>             ->     <R> / <N> | - <N> |  <R>
<R>              ->      [ <exp> ]  | id | integer
<stats>         ->      <stat>  <mStat>
<mStat>       ->      empty |  <stat>  <mStat>
<stat>           ->      <in>   | <out>   | <block> | <if>  | <loop>  | <assign>
<block>       ->      start <vars> <stats> stop
<in>              ->      scan identifier .
<out>            ->      print <exp> .
<if>               ->      cond ( <exp> <RO> <exp> ) <stat>
<loop>          ->      loop ( <exp> <RO> <exp> )  <stat>
<assign>       ->      id  ~ <exp> .
<RO>            ->      <= (one token)  | >=  (one token)  | < | > | = | ~   

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
