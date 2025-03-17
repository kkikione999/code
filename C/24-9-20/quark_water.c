#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quark_g_water;
    printf("请输入水的质量");
    scanf("%d", &quark_g_water);

    float single_quarter 3.0e-23;
    long long all_water;
    all_water = quark_g_water/single_quarter;
    printf("%ld", all_water); 


    exit(0);
}