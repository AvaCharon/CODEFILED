struct car
{
    bool inside;
    double time;
};

struct park
{
private:
    car *base;
    car *top;
    int parksize;

public:
    park()
    {
        parksize = 0;
        car *base = new car[parksize];
        top = base;
    }

    int pop()
    {
        if (top == base)
            return 0;
        top--;
        return 1;
    }

    int push(car a)
    {
        if (top - base == parksize)
            return 0;
        *++top = a;
        return 1;
    }
};
