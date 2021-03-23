//最大公因数
int gcd(LL a, LL b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
//最小公倍数
int lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}