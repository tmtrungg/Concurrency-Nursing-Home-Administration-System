//Arduino taking input code

int PIR = 2; //PCINT19
int PIR2 = 3;//PCINT20
int PIR3 = 4;//PCINT22
int LED = 12;
int ledstate = LOW;

const int led_pin = PB5;
const uint16_t tl_load = 0;
const uint16_t tl_comp = 31250;

void setup(){  
  Serial.begin(9600);
  pinMode(PIR,INPUT); 
  pinMode(PIR2,INPUT); 
  pinMode(PIR3,INPUT); 
  pinMode(LED,OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(PIR), toggle, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(PIR2), toggle2, CHANGE);
  
  //PIN 13 LED blinking code :
  DDRB |= (1 << led_pin);
  TCCR1A = 0;
  
  //Set to prescaler of 256
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1<< CS11);
  TCCR1B &= ~(1<< CS10);
  
  //Reset Timer 1, set compare value
  TCNT1 = tl_load;
  OCR1A = tl_comp;
  
  //Enable Timer1 compare interrupt
  TIMSK1 = ( 1 << OCIE1A);
  PCMSK0 |= (1<< PCINT7);
  PCICR |= (1 << PCIE0);
  
  //Enable global interrupt
  sei();
  
  PCICR |= 0b00000111;
  PCMSK2 |= 0b10011100;


  
} 
 
void loop(){
} 



ISR(TIMER1_COMPA_vect) {
  TCNT1 = tl_load;
  PORTB ^= ( 1 << led_pin);
}

//executed code for every interrupt events occurs
ISR(PCINT2_vect){
  ledstate = !ledstate;
  if(digitalRead(PIR) == HIGH)
  	{Serial.write("Requested for the food and drink\n");}
  if(digitalRead(PIR2) == HIGH)
    {Serial.write("Requested for a walk\n");}
  if(digitalRead(PIR3) == HIGH)
    {Serial.write("Requested for a toilet\n");}
  digitalWrite(LED, ledstate);
}
