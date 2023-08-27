class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>=sx && ty>=sy) {
            if(tx==sx && ty==sy)
                return true;
            else {
                if(tx>ty)
                    tx -= max((tx-sx)/ty, 1)*ty;
                else
                    ty -= max((ty-sy)/tx, 1)*tx;
            }
        }
        return false;
    }
};