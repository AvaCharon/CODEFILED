/*
字符串的储存：数组、指针
*/
char str[]="Hello";//数组名str不可修改，而其（数组）内容可修改
char weekday[][10]={"Sunday","Monday"};
char longstr[]="This is its first half,"
                "and this is the second.";
char *ptr="Hello";//指针变量ptr可修改，而且指向的内容不可修改

//将储存字符串的地址赋给指针：
char *ptr = "Hello";//等价于
char *ptr;
ptr="Hello";
//因此*ptr不可修改（即只读的）（它相当于一个实参，值为Hello）：*ptr='A';是非法的

char string[10]="Hello";
char *p=string;/*等价于 char *p;
                        p=&string[0]；*/
*p='A';//相当于p[0]='A';也相当于string[0]='A';
//*(p+i)==*(string+i)==string[i]
//也可通过p++来移动指针；但不能使用string++；


/*
字符串的读入：
scanf%s
gets（读入包括空格直到回车，且将回车清除而不读入）

与输出：
printf（读入直到空格，且不清除回车）注意不要加取地址符
puts（读至第一个'\0',且自动输出一个换行符）
*/
//漏洞：不能限制输入的字符串的长度


//解决方法：使用fgets(name,sizeof(name),stdin)
