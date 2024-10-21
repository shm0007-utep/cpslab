#include<math.h>
#include<stdio.h>
double f(double x){
    return x*x*x*x*x*x - x -1;
}
double f_prime(double x){
    return 6*x*x*x*x*x -1;
}
void secant(){
    printf("Secant");
    return;
}
double absf(double x){
    if(x<0)
        return x * -1;
    return x;
}
double bisection(int M, double tol){
    double a = -1;
    double b = 0;
    
    printf("Bisection");
    for(int i =0; i<=M ; i++){
        double u = f(a);
        double v = f(b);
        if(u*v >=0){
            printf("No root found");
            return -1.0;
        }
        double c = (a + b)/2;
        double w = f(c);
        if(absf(c) <= tol  || absf(w) <= tol){
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
double newton(int m,double tol){
    double x_0 = -1;
    double v = f_prime(x_0);
    if(absf(v) < tol)
        return x_0;
    printf("Newton inner loop");
    for (int i = 0; i< m ;i++){
        double x_1 = x_0 - f(x_0) / f_prime(x_0);
        if(absf(x_1 - x_0) <= tol || absf(f(x_1))<= tol ){
            return x_1;
        }
        x_0 = x_1;
    }
    return -1.0;
}


int main(){
    double tol = .000001;
    int m = 50;
    int option;
    double ans;
    printf("Choose Option\n1: Bisection\n2: Newtons\n3 Secant\n");
    scanf("%d", &option);
    switch(option){
        case 1:
            ans = bisection(m,tol);
            printf("Bisection Root %lf\n",ans);
            printf("f(%lf) = %lf\n", ans, f(ans));
            
            break;
        case 2:
            ans = newton(m,tol);
            printf("Newons Root %lf\n",ans);
            printf("f(%lf) = %lf\n", ans, f(ans));
            break;
        case 3:
            secant();
            break;
        
    }
    return 0;

}