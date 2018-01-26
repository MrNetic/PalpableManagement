// Palpable management v1
// Paulo Condeça 2018

#include <Servo.h>
Servo servo;

int servoPin = 9; // where my servo 9g is connected
int servoAngle = 0;   // servo position in degrees
char rx_byte = 'P'; // where I will write the input from COM portal RX
int outputservodetails; // for storing the servo position

void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop()
{

  outputservodetails = servo.read();
  Serial.println("ValorDoServoDetails:");   
  Serial.println(outputservodetails); // Just to grab the value from the servo position that can be read in the serial monitor.
  
  // Wait 5 seconds before doing any mechanical movement
  delay(5000);

  Serial.println("Hello Paulo Starting Monitoring Dashboard !");  // prints hello with ending line break

  // Check if there are any incoming bytes from "external", check for the byte value.
  if (Serial.available() > 0)
  {
    rx_byte = Serial.read(); // read the incoming byte:
    Serial.print(" I received:");
    Serial.readString();
    Serial.println(rx_byte);
    if (rx_byte == 't')
    {
      Serial.println("Não se passa nada, está tudo bem");  // prints hello with ending line break
      // Turn SG90 servo Left to 135 degrees
      servo.write(135);      
      // Wait 5 seconds before doing any mechanical movement
      delay(5000);
    }
    else 
    {
      Serial.println("Temos problemas"); 
      // Turn SG90 servo Right to 45 degrees
      servo.write(65);      
      delay(5000);          // Wait 1 second // para apagar
    }

  }
  // Could have handled the servo movement in a while loop for an extra-smooth movement, but lets leave it racy :)
}


