#define LED 2 
void setup() 
{ 
// Set pin mode 
pinMode(LED,OUTPUT); 
} 

void loop() 
{ 
//Hello = .... . .-.. .-.. --- 

//H
for (int i=0; i<4; i++)
{
  lowMorse();
}
intervalMorse();

//E
lowMorse();
intervalMorse();

//LL
for (int i=0; i<2; i++)
{
  lowMorse();
  longMorse();
  lowMorse();
  lowMorse();
  intervalMorse();
}

//O
for (int i=0; i<3; i++)
{
  longMorse();
}
intervalMorse();
intervalMorse();

}

void lowMorse()
{
  int a = 500;
  delay(a); 
  digitalWrite(LED,HIGH); 
  delay(a); 
  digitalWrite(LED,LOW); 
}

void longMorse()
{
  int b = 4000;
  delay(b); 
  digitalWrite(LED,HIGH); 
  delay(b); 
  digitalWrite(LED,LOW); 
}

void intervalMorse()
{
  int c = 2000;
  delay(c); 
  digitalWrite(LED,HIGH); 
  delay(c); 
  digitalWrite(LED,LOW); 
}