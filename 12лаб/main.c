//  main.c
//  12la
//
//  Created by Арсений Билецкий on 11/12/2019.
//  Copyright © 2019 Арсений Билецкий. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int  di(int a, int b)//функция div
{
  return (a/b)-(1/10)*(a%b);
}
int stepen(int u,int y){//возведение в степень
int o;
o=u;
    while(y>1){
        u=u*o;
        y=y-1;
    }
    return u;
}
int main() {
    int dlina=0,chislo,chislo1,otvet,per,ser;
    scanf("%d", &chislo);
    chislo1=chislo;
    while (chislo1>0){
        chislo1=di(chislo1,10);
        dlina++;//находим длину числа
        }
    if (dlina%2==0){
        printf("У числа нет средней цифры\n");
    }
    else if(dlina==1){
        printf("%d\n", 0);
        }
    else{
        chislo1=chislo;
    per=di(chislo,stepen(10,(dlina+1)/2));
    ser=di(chislo % stepen(10,(dlina+1)/2),stepen(10,(dlina-1)/2));
    otvet=chislo-(per*9*stepen(10,(dlina-1)/2)+ser*stepen(10,(dlina-1)/2));
    printf("Число без средней цифры %d\n", otvet);//из числа можно убрать среднюю цифру если умножить первую половину числа без средней цифры (например если у нас 123,то берем 1) на 9 и на 10 в степени (длина числа-1)/2 (для 123 это 9*10*1=90) складываем все это с произведением средней цифры на 10 в степени (длину числа-1)/2. Получем 123-(90+20)=13
    }
    return 0;
}
