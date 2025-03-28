auto exgcd = [&](auto &&self,int a,int b,int &x,int &y)->int{
    if(b==0){
        x = 1,y = 0;
        return a;
    }
    int d = self(self,b,a%b,y,x);
    /*
    int tmp = x;
    x = y;
    y = tmp-(a/b)*x;
    */
    y-=(a/b)*x;
    return d;
};