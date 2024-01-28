int enable2 = 9;
int in3 = 10;
int in4 = 11;

int enable1 = 5;
int in1 = 7;
int in2 = 6;

int speed = 200; //default
void setup()
{
  Serial.begin(9600);
  pinMode(enable2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(enable1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop()
{
  // send data only when you receive data:
  analogWrite(enable2, speed); // Any value between 0 and 255
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  analogWrite(enable1, speed); // Any value between 0 and 255
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}