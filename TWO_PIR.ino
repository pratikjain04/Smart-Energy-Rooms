bool pirstate1 = 0;
bool pirstate2 = 0;
int ledPin = 13;
int pirPin1 = 2;
int pirPin2 = 7;
int val1 = 0;
int val2 = 0;
int count = 0;
int i = 0;
int j = 1;
int Final = 0;

void setup() 
{
  pinMode (ledPin,OUTPUT);
  pinMode (pirPin1, INPUT);
  pinMode (pirPin2, INPUT);
}
void loop () 
{ 
  
  Serial.begin(9600);
//Callibaration Time
  
  ++i;
  if(i==1)
      { Serial.print("Calibartion Time On");
        for( j = 1; j<=40; j++)
      
        { Serial.print('.');
          delay(1000);
        }
      }
  //Callibaration Time Ended
  
  delay(10);
// Reading From PIR  
  val1 = 0;
  val2 = 0;
  pirstate1 = 0;
  pirstate2 = 0;
  digitalWrite(ledPin, 0);
  
    val1 = digitalRead(pirPin1);
    val2 = digitalRead(pirPin2);

    
if(val1==1)
   pirstate1 = 1;
else if(val2==1)
   pirstate2= 1;
else
  {
    pirstate1 = 0;
    pirstate2 = 0;
  }
  

   if(pirstate1 == 1)
    {
      if(digitalRead(pirPin2)== 1)
       { count++;
             pirstate1 = 0;
         pirstate2 = 0;
       }   
      else
       count = count;
    }
    
    else if(pirstate2 == 1)
    {
       if(digitalRead(pirPin1)== 1)
        { count--;
             pirstate1 = 0;
            pirstate2 = 0;
        }   
     else
       {count=count;
          pirstate1 = 0;
          pirstate2 = 0;
    }   
    }    
    else
    {
      count = count;  
         pirstate1 = 0;
    pirstate2 = 0;
    }
      
 delay(990);
 //Checking multiple of 3 because 3 readings increment on one passage
//if(k%2==0) 
  Final = count/2;
     
Serial.println((int)Final);
Serial.println("\n\n\n\n");
 
if(Final> 6)
  {digitalWrite(ledPin, 1);
    delay(5000);
  }
  
  else
    digitalWrite(ledPin, 0 );
delay(10);


}

