class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        
        int closestX =clamp(x,x1,x2);
        int closestY =clamp(y,y1,y2);

        // if(x1>x)closestX=x1;
        // else if(x2<x)closestX=x2;
        // else closestX = x;

        // if(y1>y)closestY=y1;
        // else if(y2<y)closestY=y2;
        // else closestY = y;

        int dx = x - closestX;
        int dy = y - closestY;

        return dx*dx + dy*dy <= r*r;
    }
};