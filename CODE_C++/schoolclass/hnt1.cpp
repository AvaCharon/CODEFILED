#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class student //基类,考生信息
{
public:
    student(){};
    virtual ~student(){};
    void getseat_f(){};
    void getnum(){};
    void getname(){};
    friend int menu();
    string lname[10];
    char seat_f[20]{}; //座位号,最好别太长
    char num[20]{};    //学号，最好别太长
    char name[20]{};   //姓名
};
int menu()
{
    return 0;
}
class stuscore : public student /*派生类1，学生成绩和考试科目信息*/
{
public:
    stuscore(){};
    ~stuscore(){};
    char lname[10]{};      //学科名
    static int lesson_num; //学科数目
    int score[10]{};
    float sum{}; //总分
    float ave{}; //平均分
} stu[100];
int stuscore::lesson_num = 3;
int main(int n)
{
    int lesson_num;

    cout << "请输入考试科目数量:";
    cin >> lesson_num;
    cout << "请输入考试科目名称（用空格隔开）:";
    for (int k = 0; k < lesson_num; k++)
    {
        cin >> stu[n].lname[k];
    }
    system("cls");
    int i = 0;
    char sign = '\0';
    cout << endl
         << "======>>    请输入学生信息及成绩    <<======" << endl;
    while (sign != 'n' && sign != 'N')
    {
        cout << "请输入学生的信息" << endl;
        cout << "座位号：";
        cin >> stu[n + i].seat_f;

    loop:
        cout << "学号：";
        cin >> stu[n + i].num;
        int c = 0;
        while (c < i)
        {
            c++;
            if (stu[n + i].num == stu[n + i - c].num) //链表查询判断
            {
                cout << "您输入的学号已存在！请重新输入。" << endl;
                goto loop;
            }
        }

        cout << "姓名：";
        cin >> stu[n + i].name;

        for (int k = 0; k < lesson_num; k++)
        {
            cout << "请输入该学生的科目【" << stu[n].lname[k] << "】的成绩：" << endl;
            cin >> stu[n + i].score[k];
        }

        cout << "======>>提示：继续写入成绩？（y/n）";
        cin >> sign;
        i++;
    }
}