#include "button.h"

void Button_init(Button *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
    button->ddr = ddr;
    button->pin = pin;
    button->btnPin = pinNum;
    button->prevState = RELEASED;
    *button->ddr &= ~(1 << button->btnPin);
}

uint8_t Button_getState(Button *button)
{
    uint8_t curstate = *button -> pin & (1 << button->btnPin); // 버튼의 현재 상태 값을 읽어옴
    if ((curstate == PUSHED) && (button->prevState == RELEASED)) // 안누른 상태에서 누르면
    {
        _delay_ms(50); // 디바운스 코드
        button->prevState = PUSHED; // 버튼의 상태를 누름으로 변경
        return ACT_PUSH;  // 리턴값을 누름으로 반환
    }
    else if ((curstate != PUSHED) && (button->prevState == PUSHED)) // 버튼을 누른 상태에서 떼면
    {
        _delay_ms(50);
        button->prevState = RELEASED;
        return ACT_RELEASE;
    }
    return NO_ACT;   // 아무것도 안 했을 때 또는 누르고 있을 때
}