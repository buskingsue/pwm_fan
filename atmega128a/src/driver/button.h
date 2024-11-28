// Header file: Button.h
#include "common/def.h"

#define BUTTON_DDR    DDRD
#define BUTTON_PIN    PIND
#define BUTTON_ON     0
#define BUTTON_OFF    1
#define BUTTON_TOGGLE 2

enum {PUSHED, RELEASED};
enum {NO_ACT, ACT_PUSH, ACT_RELEASE};

typedef struct _button
{
	volatile uint8_t *ddr;
	volatile uint8_t *pin;
	uint8_t           btnPin;
	uint8_t           prevState;
} Button;

void Button_init(Button *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t Button_getState(Button *button);