# 词法分析_实现C语言简单词法分析

#### 介绍
1. 编写.l文件并利用flex自动生成词法分析器；
2. 编写.c文件直接实现词法分析器。

#### 使用说明

1.  01~06均为测试用例
2.  auto_lex.l为编写的正则，使用时需要将其拖拽到win_flex.exe上，会生成一个lex.yy.c，利用如下语句将其编译：

```
gcc -o scan lex.yy.c
```
生成的scan可以直接使用，例如，如果想测试01用例，则使用如下语句：

```
.\scan < 01_var_defn.c
```

3.  man_lex.c为仿照lex.yy.c的功能手写的一个文件，也可将其编译并使用，编译语句为：

```
gcc -o man_scan man_lex.c
```
如果想测试01用例，则使用如下语句：

```
.\man_scan 01_var_defn.c
```
 **注意：** man_scan 后至多能输入一个参数

4.  请勿更改除  **auto_lex.l && man_lex.c && 01~06用例**  外的其他内容，否则可能导致无法正确使用。

English
# Lexical Analysis: Simple lexical analysis of C language

#### Introduction
1. Write .l file and use flex to automatically generate a lexical analysis
2. Write .c file to directly generate a lexical analysis

#### Instructions

1.  01~06 are all test cases
2.  auto_lex.l is a regular. When using, you need to drag it to win_flex.exe. It will automatically generate a 'lex.yy.c'.
    Please use statement below to compile it:

```
gcc -o scan lex.yy.c
```
Generated scan.exe can be used directly. For example, if you want to test case1, you can use:

```
.\scan < 01_var_defn.c
```

3.  'man_lex.c' is a handwritten file imitating the function of 'lex.yy.c', which can also be compiled and used. The compilation statement is:

```
gcc -o man_scan man_lex.c
```
If you want to test case1, you can use:

```
.\man_scan 01_var_defn.c
```
 **Attention：** At most one parameter can be entered after 'man_scan' 

4.  Do not change except  **auto_lex.l && man_lex.c && 01~06 test cases** , Otherwise, it may not be used correctly.

#### Test

![MV(HUP597CE9{O8EOK}VZNK](https://user-images.githubusercontent.com/71238790/138584197-92b8c749-9b7d-432e-bf58-14dcae28e19d.png)

#### Author
Brett Tseng  2021/10/22 Chengdu Sichuan Province

( If you have any questions about the code, please contact the author： e-mail： brettemail@163.com || 392184316@qq.com )
