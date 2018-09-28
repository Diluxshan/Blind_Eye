
int trigPin = 3;    //Right Ultrasonic Sensor
int echoPin = 2;  
long duration, distance ;   
#define R_sensor 8

int trigPin2 = 4;   //Left Ultrasonic Sensor
int echoPin2 = 5;  
long duration2, distance2 ;   
#define L_sensor 9
 
//################## CLASS begin ################

class A  //...........Code for Right Ultrasonic Sensor...............
{
  public:
    
    void g() {
   digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  distance = (duration/2) / 29.1;
  
  Serial.print("Distance Right: ");
  Serial.print(distance);
  Serial.print("cm         ");

   }  //end of void f
};
//................................end of class A........................................

 
class B   //...........Code for Left Ultrasonic Sensor...............
{
  public:
    
    void f() {
         digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);

  // convert the time into a distance
  distance2 = (duration2/2) / 29.1;
  
  Serial.print("Distance Left: ");
  Serial.print(distance2);
  Serial.println("cm         ");
   }   //end of void f
   
};
//................................end of class B........................................


// Method for call class
A *a;     
B *b; 

void setup()     // main function 
{
   a=new A(); 
   b=new B(); 
   
   Serial.begin (9600);
   
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(R_sensor, OUTPUT);
   

   pinMode(trigPin2, OUTPUT);
   pinMode(echoPin2, INPUT);
   pinMode(L_sensor, OUTPUT);
   
   pinMode(22, OUTPUT); //Center LED 
   pinMode(42, OUTPUT); //Right LED 
   pinMode(44, OUTPUT); //Left LED 
}

void loop()    //Continues loop
{
   
   
    b->f();
     a->g();   
      digitalWrite(22,HIGH);  // ON Green LED 
    
//...................Right Side LED+Sensor............
     if(distance<=25 && distance>0)
     {Right(200);
      digitalWrite(42,HIGH);      
     }
     else if(distance<=50 && distance>25)
     {Right(500); 
      digitalWrite(42,HIGH);       
     }  
     else if(distance<=100 && distance>50)
     {Right(1000); 
      digitalWrite(42,HIGH);
     }
     else{digitalWrite(8,LOW);
          digitalWrite(42,LOW);
            
     }
//...................Left Side LED+Sensor............
     if(distance2<=25 && distance2>0)
     {Left(200);
      digitalWrite(44,HIGH);
     }
     else if(distance2<=50 && distance2>25)
     {Left(500); 
       digitalWrite(44,HIGH);
        }
     else if(distance2<=100 && distance2>50)
     {Left(1000); 
       digitalWrite(44,HIGH);
       }
       
     else{digitalWrite(9,LOW);
            digitalWrite(44,LOW); 
            
         }     
}  //.................................End of loop...................................





void Right (int interval){
   static long prevMill = 0;
   if (((long)millis() - prevMill) >= interval){ 
    prevMill = millis(); 
    digitalWrite(R_sensor, !digitalRead(R_sensor));
  }
 }
  
 void Left (int interval){
   static long prevMill = 0;
   if ((millis() - prevMill) >= interval){ 
    prevMill = millis(); 
    digitalWrite(L_sensor, !digitalRead(L_sensor));
 } 
}
//....................................END of Programme................................
 
