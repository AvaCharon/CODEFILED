class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area1 = (ax1 - ax2) * (ay1 - ay2);
        int area2 = (bx1 - bx2) * (by1 - by2);
        int x = min(ax2, bx2) - max(ax1, bx1);
        int y = min(ay2, by2) - max(ay1, by1);
        int area3 = max(x, 0) * max(y, 0);
        return area1 + area2 - area3;
    }
};