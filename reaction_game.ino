void setup() 
{
  // put your setup code here, to run once:
  pinMode(5,INPUT);  //  BUTTON 1
  pinMode(6,OUTPUT); //  LED 1
  pinMode(4,OUTPUT); //  GAME LED 
  pinMode(3,OUTPUT); //  LED 2
  pinMode(2,INPUT);  //  Button 2

}

void loop() 
{
  //VARS
  int time_to_power_led;
  int red_button_press_time;
  int yellow_button_press_time;
  bool red_button_pressed    = false;
  bool yellow_button_pressed = false;
  //PROGRAM

  //power game LED
  time_to_power_led = random(1000,10000);
  delay(time_to_power_led);
  digitalWrite(4,HIGH);

  while (!red_button_pressed || !yellow_button_pressed)
  {
    if (digitalRead(5) == HIGH)
    {
      yellow_button_pressed = true;
      break;
    }
    if (digitalRead(2) == HIGH)
    {
      red_button_pressed = true;
      break;
    }
  }

  // Check winner
  if (red_button_pressed == true)
  {
    digitalWrite(3,HIGH);
  }
  else
  {
    digitalWrite(6,HIGH);
  }
  delay(2000);
  digitalWrite(6,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
}
