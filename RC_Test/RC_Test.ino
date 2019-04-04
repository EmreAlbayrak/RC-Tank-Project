// RC module test program has been found on internet.

int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
 
void setup() {
  pinMode(2, INPUT); 
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  ch1 = pulseIn(2, HIGH, 25000);
  ch2 = pulseIn(3, HIGH, 25000);
  ch3 = pulseIn(4, HIGH, 25000);
  ch4 = pulseIn(5, HIGH, 25000);
  ch5 = pulseIn(6, HIGH, 25000);
  ch6 = pulseIn(7, HIGH, 25000);

  Serial.print("$RadioControl-1: ");
  Serial.println(map(ch1,1000,2000,-100,100));
  Serial.print("$RadioControl-2: ");
  Serial.println(map(ch3,1000,2000,-100,100));
}
