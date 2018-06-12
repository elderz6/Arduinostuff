int led1 = 13; 
int led2 = 8;
int sby = 2;
int serialData = 0;

char senha2[] = "eae men kk";
String readString;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sby, OUTPUT);
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
   delay(100);
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
    readString = "";
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(5000);
  }
  else
  {
    Serial.println("Wrong pw");
    readString = "";
    digitalWrite(led2, HIGH);
    delay(2000);
  }      
  
}


