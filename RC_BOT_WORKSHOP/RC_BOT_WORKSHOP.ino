//--------------------------------------------- < DTLABZ-ROBOTIC WORKSHOP > ---------------------------------------


//--------------------------------------------- CONECTIONS-->
//--------------------------------------------- RX (ARDUINO) --> TX (HC_05-BLUETOOTH MODULE)
//--------------------------------------------- TX (ARDUINO) --> RX (HC_05-BLUETOOTH MODULE)

//---------------------- PWM PINS  ---------------------- D9 (ARDUINO) --> EN_A (MOTOR DRIVER)
//---------------------- PWM PINS  ---------------------- D10 (ARDUINO) --> EN_B (MOTOR DRIVER)

//--------------------------------------------- D2 (ARDUINO) --> IN-1 (MOTOR DRIVER) --> OUT1 OF MOTOR(+VE)
//--------------------------------------------- D3 (ARDUINO) --> IN-2 (MOTOR DRIVER) --> OUT2 OF MOTOR
//--------------------------------------------- D4 (ARDUINO) --> IN-3 (MOTOR DRIVER) --> OUT3 OF MOTOR(+VE)
//--------------------------------------------- D5 (ARDUINO) --> IN-4 (MOTOR DRIVER) --> OUT4 OF MOTOR

char A;        //    Variable to store recived data

const int LEFT_ENABLE = 10; // ENABLE PIN DECLARATION
const int RIGHT_ENABLE = 9;

const int MOTOR_SPEED = 150; // ROTATION SPEED

void Set_Speed(int SPEED)
{
  analogWrite(LEFT_ENABLE , SPEED);
  analogWrite(RIGHT_ENABLE , SPEED);
}

void moveForward()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void moveBackward()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void arcRight()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void arcLeft()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void spotRight()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void spotLeft()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void Stop()
{
  Set_Speed(0);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}



void setup() {
  // pin declarations
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600); //----------------BAUD RATE VALUE TO COMMUNICATE WITH HC_05 MODULE
}

void loop()
{
  if (Serial.available() > 0)
  {
    A = Serial.read();
    //Serial.println(A);  //uncomment to view the data recived while usb is connected to pc
  }
  switch (A)
  {
    case 'F' : moveForward();
      break;
    case 'B' : moveBackward();
      break;
    case 'R' : spotRight();
      break;
    case 'L' : spotLeft();
      break;
    case 'G' : arcRight();
      break;
    case 'I' : arcLeft();
      break;
    case 'S' : Stop();
      break;

  }
}
