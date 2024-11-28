#include "pwm8.h"

void pwm8Init(void)
{
    DDRB |= (1<<PORTB4);
    TCCR0 |= (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS02) |(1<<CS01);
}

void pwm8Run(uint8_t duty)
{
    OCR0 = duty;
}
void increaseSpeed(uint8_t *duty)
{
    // 속도를 증가시키려면 듀티 사이클을 조금씩 증가
    if (*duty < 255)  // 최대 듀티 사이클 255로 제한
    {
        *duty += 5;  // 듀티 사이클을 5씩 증가
    }
    pwm8Run(*duty);  // 새로운 듀티 사이클로 PWM 실행
}
void decreaseSpeed(uint8_t *duty)
{
    // 속도를 감소시키려면 듀티 사이클을 조금씩 감소
    if (*duty > 0)  // 최소 듀티 사이클 0으로 제한
    {
        *duty -= 5;  // 듀티 사이클을 5씩 감소
    }
    pwm8Run(*duty);  // 새로운 듀티 사이클로 PWM 실행
}