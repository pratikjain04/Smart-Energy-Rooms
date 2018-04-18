
const int button = 7;
const int laser = 8;
const int ldr = A0;
const int allow = 0;
int 11;
int ldr_value;



void setup() {

pinMode(button , INPUT);
pinMode(laser, OUTPUT);
pinMode(ldr , INPUT);
Serial.begin(9600);
digitalWrite(laser, HIGH);\
 ldr_value = analogRead(ldr);
 l1= ldr_value - 150;
}

void loop() 
{
  
 ldr_value = analogRead(ldr);
 
 if(ldr_value <= l1)
   { ctr++;
      delay(650);

   }
 else
  ctr= ctr;  

 if(ctr>6)
  { allow = 1;
    button_value = digitalRead(button);
     if(button_value ==1)
       { digitalWrite(led,1);
          delay(2000);
       }   
     else
        digitalWrtie(led, 0);       
      }
  else
  allow= 0 ;
}
  
  
  
 
  

  

}
