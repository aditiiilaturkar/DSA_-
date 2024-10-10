class Solution {
public:
    
    double solve(double x, long n){
       if(n == 0) return 1;
        if(n<0) return solve(1/x, -1*n);
        if(n%2 == 0) return solve(x*x, n/2);
        else return x*solve(x*x, (n-1)/2);
    }
    double myPow(double x, int n) {
        return solve(x, (long)n);
    }
};
/*
NOTE : 
1. binary exploitation
    pow(x, n) = x*x*x... n times
              = pow(x*x, n/2) === if n is even
            
    pow(x, n) = x*pow(x*x, (n-1)/2) ===== if n is odd

    also rememer if n<0
    we do pow(1/x, n*-1);
    eg. pow(8, -3) = pow(1/8, 3)

    but what happens when this n is INT_MIN ie.e 2^-31
    when we make it n*-1 it becomes 2^31 which is > INT_MAX
    why?
     coz INT_MAX = 2^31 -1
     hence we need to make it long while passing to solve function
*/