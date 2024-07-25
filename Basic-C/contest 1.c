#include <stdio.h>
int main()
{
int a,b,c,abc;
scanf("%d",&abc);
a = abc / 100;
b = abc / 10 % 10;
c = abc % 10;
    int bca = b * 100 + c * 10 + a;
    int cab = c * 100 + a * 10 + b;
    int sum = abc + bca + cab;
    printf("%d",sum);

    return 0;
}
