<b> Program Translation Project </b>

This project was create in order to produce a compiler which translates from one coding language to another. The way this is accomplished is by feeding
input code into a lexical analyzer which differentiates between keywords, variable names, digits, and operands. The lexical analyzer creates a series
of tokens which are then read into the below BNF:

![P2BNF](https://github.com/ThomasCholak/CodeCompilationProject/assets/63080803/4e4800d3-f245-44f1-a657-cbc8f1568d87)

Using this BNF structure, P4.cpp then builds the a parse tree using a preorder traversal.

Here is an example input code:

![inputcode](https://github.com/ThomasCholak/CodeCompilationProject/assets/63080803/67c9eede-d640-4720-b5f8-09b77e45ef83)

This will produce the following tree (however this is not shown to the user):

![preorder traversal](https://github.com/ThomasCholak/CodeCompilationProject/assets/63080803/ea10e056-9a1a-4252-b92e-783bce074c99)

Then, following the same example, the below .asm file will be generated using the aforementioned input code:

![outputcode](https://github.com/ThomasCholak/CodeCompilationProject/assets/63080803/5cf55024-9212-4758-bcf3-746b864733f9)

We can then run this code on the following website: https://comp.umsl.edu/assembler/interpreter

After being 'ran' this will then prompt the user for user input (in this example I used '4') and then display the following:

![Screenshot 2023-12-21 173756](https://github.com/ThomasCholak/CodeCompilationProject/assets/63080803/2d1443a3-b851-450c-8e57-1c271d9c77a9)

<b> How to Run </b>

To run this project, you will have to inport the files <i>Makefile</i>, <i>P4.cpp</i>, and <i>P4.h</i> into a Linux.

Upon running the 'make' command to run the Makefile, the <i>comp</i> executable will then be generated.
![makefilestuff](https://github.com/ThomasCholak/CodeCompilationProject/assets/63080803/2c67539c-37a8-4200-8935-b450adffb926)

We can then run <i>./comp</i> and then enter the name of the file, which will create a '.asm' file with the same name:

![circlinganswerthing](https://github.com/ThomasCholak/CodeCompilationProject/assets/63080803/cd986a4d-dcfe-4e11-bef4-e2064a48fba6)

However, if no file is entered then it will request user input instead and then generate a file named 'a.asm' instead:

![aasm](https://github.com/ThomasCholak/CodeCompilationProject/assets/63080803/434dd586-e468-4f10-989d-82330f8a471e)


