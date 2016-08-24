
#include <Arduino.h>

extern void fadeIn(int pin, int time);
extern void fadeOut(int pin, int time);


#ifdef AVR

uint8_t pwm[] = {3,5,6,9,10,11};
#define PWM_LENGTH 6
#define MAX_PWM 255

#else

uint8_t pwm[] = {2,4,5,12,13,14};
#define PWM_LENGTH 6
#define MAX_PWM PWMRANGE

#define WIFI_Connect

#endif

typedef enum {
  ChannelState_Off,
  ChannelState_On
} ChannelState;

ChannelState state[PWM_LENGTH];

#define FADE_TIME           1000
#define MAX_DELAY           1000

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < PWM_LENGTH; i++) 
  {
    pinMode(pwm[i], OUTPUT);
    digitalWrite(pwm[i], HIGH);
    state[i] = ChannelState_On;
  }
}

void loop() 
{
  int channel = random(PWM_LENGTH);
  switch(state[channel])
  {
    case ChannelState_Off:
      fadeIn(pwm[channel], FADE_TIME);
      state[channel] = ChannelState_On;
      break;
    case ChannelState_On:
      fadeOut(pwm[channel], FADE_TIME);
      state[channel] = ChannelState_Off;
      break;
  }
  delay(random(MAX_DELAY));
}

void fadeIn(int pin, int time)
{
  int delayTime = max(1, time / MAX_PWM);
  for(int i = 0; i <= MAX_PWM; i++) 
  {
    analogWrite(pin, i);
    delay(delayTime);
  }
}

void fadeOut(int pin, int time)
{
  int delayTime = max(1, time / MAX_PWM);
  for(int i = MAX_PWM; i >= 0; i--) 
  {
    analogWrite(pin, i);
    delay(delayTime);
  }
}
