#include <math.h>
#include <stdio.h>

int search;
float n;
double e,loan,payment,rate,a,prev,curr,abst;

int main()
{   

    scanf("%i",&search);
    if (search==1){
        scanf(" %f %lf %lf", &n, &payment, &rate);
        e=1+rate;
        loan=((pow(e,n)-1)/rate)*payment/pow(e,n);
        printf("%.16f", loan);
    }
    else if (search==2){
        scanf(" %lf %lf %lf", &loan, &payment, &rate);
        e=1+rate;
        a=(double)log(loan*(e-1)/(payment-loan*(e-1))+1)/log(e);
        printf("%.16f", a);
    }
    else if (search==3){
        scanf(" %lf %f %lf", &loan, &n, &rate);
        e=1+rate;
        payment=pow(e,n)*loan*(e-1)/(pow(e,n)-1);
        printf("%.16f", payment);
    }
    else if (search==4){
        scanf(" %lf %f %lf", &loan, &n, &payment);
        prev=1.0;
        curr=prev-(pow((1+prev),n)*loan-((pow((1+prev),n)-1)*payment/prev))/(loan*n*pow((1+prev),(n-1))-(payment/pow(prev,2))*(n*pow((1+prev),(n-1))*prev-(pow((1+prev),n)-1)));
        abst=abs(curr-prev);
        while (abst>=0.00001){
                prev=curr;
                curr=curr-(pow((1+curr),n)*loan-((pow((1+curr),n)-1)*payment/curr))/(loan*n*pow((1+curr),(n-1))-(payment/pow(curr,2))*(n*pow((1+curr),(n-1))*curr-(pow((1+curr),n)-1)));
                abst=abs(curr-prev);}
        rate=curr;
        printf("%.16f\n", rate);
    }
    return 0;
}
