#include<math.h>
#include<stdio.h>
#define TOL .00000001
#define M 50
double f(double x){
    return x*x*x*x*x*x - x -1;
}
double f_prime(double x){
    return 6*x*x*x*x*x -1;
}
double absf(double x){
    if(x<0)
        return x * -1;
    return x;
}
double secant(double x_0, double x_1){
    for(int i = 0; i< M; i++){
        double f_x0 = f(x_0);
        double f_x1 = f(x_1);
        if( f_x0 - f_x1 == 0){
            printf("f(%lf) and f(%lf) are same. Aborting\n",x_0,x_1);
            return -1;
        }
        double x_2 = x_1 - f_x1 * (x_1- x_0) / (f_x1  - f_x0);
        //double x_2 = (x_0 * f_x1) - (x_1-f_x0) / (f_x1 - f_x0);
        if(absf(x_2-x_1)<= TOL ){
            return x_2;
        }
        x_0 = x_1;
        x_1 = x_2;
    }
    return -1;
}

double bisection(double a, double b){

    for(int i =0; i<=M ; i++){
        double u = f(a);
        double v = f(b);
        if(u*v >=0){
            printf("No root found");
            return -1.0;
        }
        double c = (a + b)/2;
        double w = f(c);
        if(absf(c) <= TOL  || absf(w) <= TOL){
            return c;
        }
        if( u*w < 0){
            b = c;
            c = w;

        }else{
            a = c;
            v = w;
        }
    }

    return -1.0;
}
double newton(double x_0){
    double v = f_prime(x_0);
    if(absf(v) < TOL)
        return x_0;
    printf("Newton inner loop");
    for (int i = 0; i< M ;i++){
        double x_1 = x_0 - f(x_0) / f_prime(x_0);
        if(absf(x_1 - x_0) <= TOL || absf(f(x_1))<= TOL ){
            return x_1;
        }
        x_0 = x_1;
    }
    return -1.0;
}


int main(){
    int option;
    double ans;
    printf("Choose Option\n1: Bisection\n2: Newtons\n3 Secant\n");
    scanf("%d", &option);
    switch(option){
        case 1:
            double a,b;
            printf("Enter a and b\n");
            scanf("%lf %lf",&a,&b);
            ans = bisection(a ,b);
            printf("Bisection Root %lf\n",ans);
            printf("f(%.8lf) = %lf\n", ans, f(ans));
            
            break;
        case 2:
            double x_0;
            printf("Enter x_0\n");
            scanf("%lf",&x_0);
            ans = newton(x_0);
            printf("Newons Root %lf\n",ans);
            printf("f(%.8lf) = %lf\n", ans, f(ans));
            break;
        case 3:
            double x_1;
            printf("Enter x_0 and x_1\n");
            scanf("%lf %lf",&x_0,&x_1);
            ans = secant(x_0,x_1);
            printf("Secants Root %lf\n",ans);
            printf("f(%.8lf) = %lf\n", ans, f(ans));
            break;
        
    }
    return 0;

}
