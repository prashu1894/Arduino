/*
3 LEDs are attached to pins D2, D4, D7
Setting the condition for LEDs to blink(ON 0.5 second and OFF 0.2sec)
*/

int led1 = 7;         // pin # in which the LED is attached
int led2 = 3;         //PWM pin for dimming the LED
int led3 = 4;
int brightness = 0;
int offset = 5;

void on_led() {
  digitalWrite(led1, HIGH);
  digitalWrite(led3, HIGH);
}
void off_led() {
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
}
// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  on_led(); 
  delay(500);
  analogWrite(led2, brightness);
  brightness = brightness + offset;
  if (brightness <= 0 || brightness > 250) {   //reversing direction
    offset = -offset;
  }
  off_led();
  delay(200);
}