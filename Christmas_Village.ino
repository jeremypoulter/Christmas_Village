
uint8_t pwm[] = {3,5,6,9,10,11};
#define PWM_LENGTH 6

#define FADE_TIME           1000
#define DELAY_BETWEEN_FADES 50
#define DELAY_ALL_ON        1000
#define DELAY_ALL_OFF       1000

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < PWM_LENGTH; i++) {
    pinMode(pwm[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i = 0; i < PWM_LENGTH; i++) {
    fadeIn(pwm[i], FADE_TIME);
    delay(DELAY_BETWEEN_FADES);
  }

  delay(DELAY_ALL_ON);

  for(int i = 0; i < PWM_LENGTH; i++) {
    fadeOut(pwm[i], FADE_TIME);
    delay(DELAY_BETWEEN_FADES);
  }

  delay(DELAY_ALL_OFF);
}

void fadeIn(int pin, int time)
{
  int delayTime = time / 255;
  for(int i = 0; i < 256; i++) 
  {
    analogWrite(pin, i);
    delay(delayTime);
  }
}

void fadeOut(int pin, int time)
{
  int delayTime = time / 255;
  for(int i = 255; i >= 0; i--) 
  {
    analogWrite(pin, i);
    delay(delayTime);
  }
}
