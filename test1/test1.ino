int led1 = 13;
int led2 = 8;
int serialData = 0;

char senha2[] = "eae men kk";
String readString;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()
{
    serialRead();
    auth();
}  

void serialRead()
{
  while(Serial.available())
  {
   delay(10);
    if(Serial.available()>0)
    {
      char c = Serial.read();
      readString+=c; 
    } 
   }
       Serial.println(readString);
}
void auth()
{
  if(readString == senha2)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else
  {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
   }    
   delay(1000);
   readString = "";
}
