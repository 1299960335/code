class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        if(i<j)
            j=i;
        m=m<<j;
        int num=n^m;
        num&=num;
        return num;
    }
};