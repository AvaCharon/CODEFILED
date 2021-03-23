class Solution {
public:
    int waysToStep(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        int f[n+1];
        f[1]=1;
        f[2]=2;
        f[3]=4;
        for(int i=4;i<=n;i++)
        {
            if(f[i-1]>=INT_MAX-f[i-2])f[i]=f[i-1]%1000000007+f[i-2]%1000000007;
            else f[i]=f[i-1]+f[i-2];
            if(f[i]>=INT_MAX-f[i-3])f[i]=f[i]%1000000007+f[i-3]%1000000007;
            else f[i]=f[i]+f[i-3];
        }
        return f[n]%1000000007;
    }
};


//以矩阵为过程 f[i]=Af[i-1] 转化为求A的幂 利用快速幂法求出
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
const ll p = 1e9+7;
class Solution {
public:
    vvl mat_mul(vvl& A, vvl& B) {
        int a = A.size(), b = B.size(), c = B[0].size();
        vvl C(a, vl(c, 0));
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int k = 0; k < b; ++k) {
                    (C[i][j] += A[i][k] * B[k][j]) %= p;
                }
            }
        }
        return C;
    }

    vvl mat_pow(vvl& A, int n) {
        int m = A.size();
        vvl B(m, vl(m, 0));
        for (int i = 0; i < m; ++i) B[i][i] = 1;
        while (n > 0) {
            if (n&1) B = mat_mul(B, A);
            A = mat_mul(A, A);
            n >>= 1;
        }
        return B;
    }

    vvl mat_pow_rec(vvl& A, int n) {
        if (n == 1) return A;
        vvl B = mat_pow_rec(A, n/2);
        B = mat_mul(B, B);
        if (n&1) return mat_mul(A, B);
        return B;
    }

    int waysToStep(int n) {
        vl f = {1, 2, 4};
        if (n <= 3) return f[n-1];
        vvl A = {{0, 0, 1}, {1, 0, 1}, {0, 1, 1}};
        vvl B = mat_pow(A, n-3);
        ll res = 0;
        for (int i = 0; i < 3; ++i) {
            (res += f[i] * B[i][2]) %= p;
        }
        return res;
    }
};