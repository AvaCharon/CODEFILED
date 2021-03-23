/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int ans;
    void getit(Employee *a, vector<Employee *> employees)
    {
        int len = a->subordinates.size();
        if (len == 0)
        {
            ans += a->importance;
            return;
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                getit(employees[a->subordinates[i]], employees);
            }
        }
        return;
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        getit(employees[id], employees);
        return ans;
    }
};



//success
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int ans;
    int lenn;
    unordered_set<int> us;
    void getid(Employee *a, vector<Employee *> employees)
    {
        if (a == nullptr)
            return;
        int len = a->subordinates.size();
        if (!len)
            return;
        else
        {
            for (int i = 0; i < len; i++)
            {
                int t = a->subordinates[i];
                int pos;
                for (int j = 0; j < lenn; j++)
                {
                    if (employees[j]->id == t)
                    {
                        pos = j;
                        break;
                    }
                }
                bool b = us.insert(t).second;
                if (b)
                {
                    ans += employees[pos]->importance;
                    getid(employees[pos], employees);
                }
            }
        }
        return;
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        lenn = employees.size();
        int pos;
        for (int i = 0; i < lenn; i++)
        {
            if (employees[i]->id == id)
            {
                pos = i;
                break;
            }
        }
        ans += employees[pos]->importance;
        getid(employees[pos], employees);
        return ans;
    }
};

//success
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        int pos;
        for (int i = 0; i < employees.size(); ++i)
            if (employees[i]->id == id)
            {
                pos = i;
                break;
            }
        int ans = employees[pos]->importance;
        for (int i = 0; i < employees[pos]->subordinates.size(); ++i)
            ans += getImportance(employees, employees[pos]->subordinates[i]);
        return ans;
    }
};