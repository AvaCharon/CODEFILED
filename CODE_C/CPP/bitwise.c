#include<stdio.h>
int main(void)
{

    return 0;
}


//按位取反：~
/*如
unsigned char val=2(00000010);
unsigned char newval=~val;(11111101)=253
*/

//按位与：&
//结果：(10010011)&(00111101)=(00010001)
/*如
val&=0377;==val=val&0377;
*/

//按位或：|
//(10010011)|(00111101)=(10111111)

//按位异或：^

//左移<<，右移>>
//int stonk=1;
//int onkoo=stonk<<2;(stonk不变，onkoo变为4)
//stonk<<=2;(stonk变为4)