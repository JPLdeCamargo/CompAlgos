#include <bits/stdc++.h>
using namespace std;

double func(double x, int p, int q, int r, int s, int t, int u){
    return (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * pow(x, 2)) + u;
}
 
// Prints root of func(x) with error of EPSILON
pair<bool, double> bisection(double a, double b, int p, int q, int r, int s, int t, int u){
    double lst = -1;
    double c = a;

    if (func(a,p,q,r,s,t,u) * func(b,p,q,r,s,t,u) > 0)
    {
        return{false,-1};
    }
    if (func(0,p,q,r,s,t,u) > -0.00001 && func(0,p,q,r,s,t,u) < 0.00001){
        return {true, 0};
    }

    while (a + 0.000000001 <= b)
    {
        // if (func(b,p,q,r,s,t,u) > -0.00001 && func(b,p,q,r,s,t,u) < 0.00001){
        //     return {true, b};
        // }
        // Find middle point
        c = (a+b)/2.0;
 
        // Decide the side to repeat the steps
        if (func(c,p,q,r,s,t,u)*func(a,p,q,r,s,t,u) < 0)
            b = c;
        else
            a = c;
    }
    return {true, (a + b)/2.0};
}
