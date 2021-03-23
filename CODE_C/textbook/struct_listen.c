/*向函数传递参数
*1结构体本身
int fun(struct a b);
fun(b);

*2结构体地址
struct a{}b;
int fun(stuct a *b);
fun(&b);
*/

//分配内存时对齐内存原则

//初始化
/*
{ , ,{},{}}
*/

//指针
/*
    若
    struct Student{};
    Student stu[];
    则
    Student *pt=stu;
    ==
    Student *pt=&stu[0];
    ==
    Student *pt;
    pt=stu;
    则
    (*pt).name=...;
    或
    pt->name=...;
*/



//相同类型的两个结构体可进行赋值操作a=b;

/*
    struct name b
    {
        char *first;
        char *last;
    };
    const Length 30

    struct name* pt=&b;
    char temp[Length];
    s_gets(temp,Length);
    pt->first=(char*)malloc(strlen(temp)+1);
    strcpy(pt->first,temp);
*/ 

//链表
/*****

struct temp
{
    int data;//数据域
    struct temp* pt;//指针域
}

*****/

/******


******/