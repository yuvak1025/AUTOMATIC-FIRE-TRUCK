bool fire=false;
bool flag=0;

int flame_sensor_L= 8;

int flame_sensor_F= 6;

int flame_sensor_R= 9;

int flame_detected_L;

int flame_detected_F;

int flame_detected_R;

int motor_input1=3; //right
int motor_input2=7; //right
int motor_input3=5; //left
int motor_input4=2; //left
int pump = 12;   
String voice;
void setup()

{

  Serial.begin(9600);

  pinMode(flame_sensor_L, INPUT);

  pinMode(flame_sensor_F, INPUT);

  pinMode(flame_sensor_R, INPUT);

  pinMode(motor_input1, OUTPUT);

  pinMode(motor_input2, OUTPUT);

  pinMode(motor_input3, OUTPUT);

  pinMode(motor_input4, OUTPUT);

  pinMode(pump, OUTPUT);

}

void put_off_fire()

{
    delay (300);
 

    digitalWrite(motor_input1, LOW);

    digitalWrite(motor_input2, LOW);

    digitalWrite(motor_input3, LOW);

    digitalWrite(motor_input4, LOW);

   digitalWrite(pump, LOW); 

   delay(400);

   digitalWrite(pump,HIGH);

   fire=false;

}

void loop()

{
       while(Serial.available()>0)
  {
    delay(10);
    char c=Serial.read();
    Serial.println(c);
    if(c=='#')
    {
      break;
    }
    voice+=c;
    }
    
   if(voice=="back"){
    digitalWrite(motor_input1, HIGH);
    digitalWrite(motor_input2, HIGH);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, LOW);
     delay(1500);
    }
  else if(voice=="right"){
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, HIGH);  
    delay(400);}
  else if(voice=="forward"){
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, HIGH);
    digitalWrite(motor_input4, HIGH);
    delay(1500); 
    }
  else if(voice=="left"){
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, HIGH);
    digitalWrite(motor_input4, LOW);
    delay(400);   
    }
    else if(voice=="stop"){
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, LOW);
    delay(400);   
    }
   else
    {
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, LOW);
    } 

    voice="";


  flame_detected_L = digitalRead(flame_sensor_L);
  flame_detected_F = digitalRead(flame_sensor_F);
  flame_detected_R = digitalRead(flame_sensor_R);


  


  if (flame_detected_L == 1)

  {

    Serial.println("Flame detected in left...! take action immediately.");
    //Move the robot left
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, HIGH);
    digitalWrite(motor_input4, LOW);  
    delay(600);
    digitalWrite(motor_input1, LOW);

    digitalWrite(motor_input2, LOW);

    digitalWrite(motor_input3, LOW);

    digitalWrite(motor_input4, LOW);
    }

  else if (flame_detected_F == 1)

  {

    Serial.println("Flame detected in front...! take action immediately.");
    //Move the robot left
     digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, HIGH);
    digitalWrite(motor_input4, HIGH); 
    fire = true;
    }

     else if (flame_detected_R == 1)

  {

    Serial.println("Flame detected in right...! take action immediately.");
    //Move the robot left
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, HIGH);  
    delay(600);

    digitalWrite(motor_input1, LOW);

    digitalWrite(motor_input2, LOW);

    digitalWrite(motor_input3, LOW);

    digitalWrite(motor_input4, LOW);
    }



  else

  {

    digitalWrite(motor_input1, LOW);

    digitalWrite(motor_input2, LOW);

    digitalWrite(motor_input3, LOW);

    digitalWrite(motor_input4, LOW);
  }

  delay(100);

     if(flag==0){
      delay(200);
      flag=1;
    }
    delay(200); //Slow down the speed of robot
     while (fire==true)
     {
      put_off_fire();
     }

}