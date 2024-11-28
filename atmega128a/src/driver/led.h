#include "common/def.h"
#define LED_DDR     DDRB
#define LED_PORT    PORTB

typedef struct
{
	volatile uint8_t* port;   
	// LED 연결 포트  내가 가지고 있는 데이터형 uint8
	//볼렛타일 컴파일러 최적화(skip)하지 말고 순서대로 처리
	uint8_t pinNumber;         // LED 연결 핀 번호
} LED; //LED_S 라는 typedef 를 사용한 자료형 재정의

// LED 초기화 함수: 지정된 핀을 출력으로 설정
void ledInit(LED* led); 
// LED ON 함수: 지정된 핀을 HIGH로 설정
void ledon(LED* led); 

// LED OFF 함수: 지정된 핀을 LOW로 설정
void ledoff(LED* led); 
void ledTog(LED* led);
