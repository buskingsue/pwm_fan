#include "led.h"

void ledInit(LED* led)
{
	//포트에 해당하는 핀을 출력으로 설정
	*(led->port - 1) |= (1 << led->pinNumber); // |= 복합 연산자 += 과 같음
}
void ledon(LED* led)
{
	*(led->port) |= (1 << led->pinNumber);
}
void ledoff(LED* led)
{
	*(led->port) &= ~(1 << led->pinNumber);
}
 void ledTog(LED* led)
 {
     *(led->port) ^= (1<< led->pinNumber); //led 끄기(현제 led 반전)
 }