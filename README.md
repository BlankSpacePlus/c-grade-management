# 简单学生成绩管理系统

## 系统简介
这个系统是之前学习数据结构的时候就想要尝试的。<br/>
因为当时没有学过C/C++，学习的数据结构也是Java语言描述的，但深觉C/C++之重要性，故不得不写几个小的project以练习。<br/>
此项目就是当时的一个构想，主要是使用链表来做整体的存储。<br/>
可惜学业繁忙，始终没有一个机会认真的学习指针与结构体等内容，故始终没有解决很多的Bug。<br/>
如今重启此项目，希望能有一个好的结果！

## 一些结合C语言自身的基本概念：
- 指针：指针保存变量的地址
- 数组：使用方括号[]声明的相似元素的列表
- 字符：char类型可容纳小整数或者表示文本或符号的特殊代码
- 字符串：一个字符串是以空终止符0x00结束的字符数组
- 结构：一个结构存储相关变量的集合
- 动态内存分配：malloc()是在程序运行时分配内存的内置函数；free()使用后释放分配的内存
- 链表：链表是一种常见的数据结构，可以用于存储可变数量的元素

## printf()和scanf()的格式化代码
| 代码 | 格式 |
|:---:|:---:|
| %d | 十进制 |
| %u | 无符号十进制 |
| %x | 十六进制 |
| %o | 八进制 |
| %f | 浮点数（float或double） |
| %e | 科学计数法 |
| %c | 字符 |
| %s | 字符串（采用空终止符） |

## 一些C语言的基本知识归纳
1. 用malloc()动态分配内存后，不能用free()动态释放的数据成为内存泄漏，是应该避免的。
2. 有关结构体标签与结构体数据类型的使用，[这篇文章](https://blog.csdn.net/grey_csdn/article/details/68954750) 讲的不错。
3. <code>Implicit declaration of function ‘XXXX’ is invalid in C99.</code>报错因为C99不接受函数在调用后声明！
4. [C语言结构体](https://www.runoob.com/cprogramming/c-structures.html)
5. [#include介绍](http://c.biancheng.net/view/443.html)

## C语言初学者常犯的18个错误
### 错误1：scanf中丢失&
```c
int a;
printf("Enter an integer:\t");
scanf("%d", a);
```
上面的代码第3行，a前面漏了&<br/>
<br/>
更正：
```c
int a;
printf("Enter an integer:\t");
scanf("%d", &a);
```
### 错误2：在比较语句中使用=代替==

```c
if (x=1)
    printf("Found!\n");
```
在一般的编程语言中共有的下面的语法：<br/>
=代表赋值<br/>
==代表相等的判断<br/>
<br/>
应该这么改写：

```c
if (x==1)
    printf("Found!\n");
```
### 错误3：索引超出数组的末端元素

```c
int array[10];
array[10]=42;
```
数组索引从0开始，终止于n-1，这个对长度为10的数组的索引10元素进行操作明显是越界了。<br/>
既然是写最后一个元素，那下标应该是9：
```c
int array[10];
array[9]=42;
```
### 错误4：在#define语句中使用=

```c
# define NUM = 4
```
这里不能用等号啊~~<br/>
应该改成这样：

```c
# define NUM 4
```
### 错误5：使用未初始化的变量

```c
int i;
if (i == 10)
    //do something
```
在Java里这就是最恐怖的“空指针异常（NullPointerException）”，无论在哪里都是要避免的，要有初始化再调用的好习惯：
```c
int i = 10;
if (i == 10)
    //do something
```
### 错误6：未包含用户创建头文件的路径

```c
# include "myfile.h"
```
地址路径不对，例如：

```c
# include "code\myfile.h"
```
### 错误7：使用逻辑运算符(!, ||, &&)代替位运算符(~, |, &)

```c
char x =! 5;
char y = 5 || 2;
char z = 5 && 2;
```
上面的其实是逻辑运算符，我们实际上想用的是位运算符：

```c
char x = ~5;
char y = 5 | 2;
char z = 5 & 2;
```
上面的语句分别代表非、或、与。
### 错误8：在switch/case语句中遗漏break语句

```c
char x = 'd';
//do something
switch (x) {
    case 'u': direction = 1;
    case 'd': direction = 2;
    case 'l': direction = 3;
    case 'r': direction = 4;
    default: direction = 0;
}
```
应该有加上break的好习惯：
```c
char x = 'd';
//do something
switch (x) {
    case 'u': direction = 1; break;
    case 'd': direction = 2; break;
    case 'l': direction = 3; break;
    case 'r': direction = 4; break;
    default: direction = 0;
}
```
### 错误9：遗漏大括号{}

```c
if (ptr == NULL)
    printf("Unable to open a file.\n");
    exit(1);
//do something
```
Java和C一样，不加{}的话循环语句和分支语句只包含紧接着的一句。<br/>
毕竟C、Java这种语言不看缩进，不像Python。<br/>
所以exit(1)实际上式if结束以后必然会执行的语句。<br/>
应该这么写：
```c
if (ptr == NULL) {
    printf("Unable to open a file.\n");
    exit(1);
}
//do something
```
### 错误10：在函数声明之前使用函数

```c
int main(void) {
    test();
}

void test() {
	//do something
}
```
没定义怎能使用？<br/>
所以换个顺序就OK：
```c
void test() {
	//do something
}

int main(void) {
    test();
}

```
### 错误11：用同一个名称声明的局部和全局变量

```c
int x = 5;
int test(void) {
    int x = 3;
    //do something
}
```
变量命名对冲了，能避免就要避免这种事：
```c
int x = 5;
int test(void) {
    int y = 3;
    //do something
}
```
### 错误12：在数组声明后尝试使用{}初始化该数组

```c
int scores[3];
scores = {93, 91, 97};
```
不能这么搞啊，只能是下面两种方式：
```c
int scores[3] = {93, 91, 97};
```
```c
int scores[3];
scores[0] = 93;
scores[1] = 91;
scores[2] = 97;
```
### 错误13：使用=将一个数组赋值给另一个数组

```c
int scores = {93, 91, 97};
int scores2[3];
scores2 = scores;
```
C语言不同于Java，Java可以“数组间赋值”（其实还是用了ArrayCopy）<br/>
这么写才是对的：

```c
int scores = {93, 91, 97};
int scores2[3];
int i;
for (i = 0; i < 3; i++)
    scores2[i] = scores[i];
```
应该用一个循环给数组逐位赋值。
### 错误14：do/while循环后遗漏分号

```c
int num;
do {
    num  = getNum();
} while (num < 100)
```
do...while语句最后需要一个分号结尾：
```c
int num;
do {
    num  = getNum();
} while (num < 100);
```
### 错误15：for循环使用逗号代替分号

```c
int i;
for (i = 0, i < 200, i++)
    //do something
```
一定要用分号（;）啊：
```c
int i;
for (i = 0; i < 200; i++)
    //do something
```
### 错误16：整数除法代替浮点数除法

```c
float x = 9/4;
```
两个整数的直接除法是生成一个截断后的整数。<br/>
应该这么写除法才能得到一个浮点数：
```c
float x = 9.0/4;
```
得到2.25。
### 错误17：写入未初始化的指针

```c
int *y = 77;
```
这是不对的，应该这么写：
```c
int x, *y = &x;
*y = 77;
```
### 错误18：过大的期望（或者缺乏期望）
所谓过大的期望是说：<br/>
一个初学者可能想要编写一个完整的程序（没有模块化），并且期望它第一次运行就完美运行。<br/>
对于复杂程序，模块化是必不可少的。将大的问题自顶向下逐级分解成小问题，模块化地进行开发正是C语言这种经典面向过程的高级编程语言的开发方法。<br/>
如果不进行合理的模块化划分，调试的困难程度甚至呈现指数级增长，很难以维护。<br/>
所谓缺乏期望是说：<br/>
在遇到情况时，初学者可能只去验证该代码是否能生成结果，而不去或者不会去验证生成的结果是否正确。<br/>
在验证功能方面使用已知输入和预期结果来调试程序是很关键的。<br/>
