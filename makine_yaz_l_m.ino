

Servo sg90;
int Index;

const int sensor1 = 32 ;
const int sensor2 = 34 ;
#define in1  8
#define in2  9
#define en1  11

int deger;
int deger2;
void setup() 
{
  
  pinMode(4, OUTPUT); //Step
  pinMode(3, OUTPUT); //Direction
  pinMode(6, OUTPUT); //Step
  pinMode(5, OUTPUT); //Direction
  
  pinMode(32, INPUT); 
  pinMode(34, INPUT);


  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
      pinMode(en1, OUTPUT);
}

void loop() 
{ 
    deger=digitalRead(sensor1);
    deger2=digitalRead(sensor2);
 
  
      
   if(deger==LOW){

  


        motor1stop(); //DC MOTOR
          
   motor2geri();   //KOL  STEP MOTORLARI
     delay(1500);

   
      motor3ileri(); //kıskaC motoru
          delay(2000);
     motor3geri();//kıskac motoru
     
     delay(200);
      motor2ileri();
       delay(1000);


    motor1ileri(230);
 delay(1000);
}

    
  if(deger2==LOW){

   motor1stop();
   // motor2geri();
   
   //  delay(1500);

    
    motor3ileri(); //kıskaC motoru
          delay(2000);
      motor3geri();//kıskac motoru
          
    // delay(200);
   // motor2ileri();
     delay(1000);
    

     motor1geri(230);
     delay(1000);

  }
  if(deger==HIGH && deger2==HIGH){

    
     motor1geri(220);
     delay(1000);

    
  }

}


///*** KISKAC MOTORU***///

void motor3ileri(){
 digitalWrite(3,HIGH);

  for(Index = 0; Index < 1400; Index++)
  {
    digitalWrite(4,HIGH);
    delayMicroseconds(600);
    digitalWrite(4,LOW);
    delayMicroseconds(600);
  }
}

  void motor3geri(){
    digitalWrite(3,LOW);

  for(Index = 0; Index < 1400; Index++)
  {
    
    digitalWrite(4,HIGH);
    delayMicroseconds(600);
    digitalWrite(4,LOW);
    delayMicroseconds(600);
  }
}



///*** KOL STEP MOTORLARI ***///
void motor2ileri(){

   digitalWrite(5,HIGH);

  for(Index = 0; Index < 2700; Index++)
  {
    digitalWrite(6,HIGH);
    delayMicroseconds(500);
    digitalWrite(6,LOW);
    delayMicroseconds(500);
  }

 }

void motor2geri(){
    digitalWrite(5,LOW);

  for(Index = 0; Index < 2700; Index++)
  {
    digitalWrite(6,HIGH);
    delayMicroseconds(500);
    digitalWrite(6,LOW);
    delayMicroseconds(500);
  }

}

 void  motor2stop(){

    digitalWrite(5,HIGH);
     digitalWrite(5,LOW);

  
 }

/* void servomotor(){

  sg90.write(0);
  delay(1000);
  sg90.write(200);
  delay(1000);
 }*/


 
//****** DC MOTOR FONKSİYONLARI****///
 void motor1ileri(int en1_val){
  analogWrite(en1 , en1_val);

digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
}

void motor1geri(int en1_val){
  analogWrite(en1 ,en1_val );

digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
  
}

 void motor1stop(){

  analogWrite(en1 ,0);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);



}
