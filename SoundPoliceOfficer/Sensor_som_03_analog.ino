

// Versão Analógica


const int limite = 50; // Define limite do que é considerado ruído

const int ledPin1 = 5; // Porta do led 1
const int ledPin2 = 6; // Porta do Led 2

int ledState = LOW;  // Estado do Led

const int buzzer = 9; //buzzer to arduino pin 9

void setup()
{
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
    pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}
void loop()
{
    int barulho = analogRead(3);  //connect mic sensor to Analog 3
   // int barulho = digitalRead(2); //connect mic sensor to Digital 2

     // Debug
     Serial.println(barulho);//print the sound value to serial in decimal values (,DEC)     
    // delay(1000); // delay de apresentação do barulho - original 1000


      // Liga led se valor do ruído for superior ao threshold
      // if the sensor reading is greater than the threshold
      
  if (barulho == HIGH) {
    
    // toggle the status of the ledPin:
    // update the LED pin itself:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      
      tone(buzzer, 1800); // Send 1KHz sound signal... default - 1000 / 1KHz
      delay(1000);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
    
    // send the string "Silence!" back to the computer, followed by newline
    Serial.println("Miúdos! Silêncioooooooooooo!");
  //  delay(3000);  // delay to avoid overloading the serial port buffer - default - 3000
  }
  
    else {
         digitalWrite(ledPin1, LOW);
         digitalWrite(ledPin2, LOW);
         delay(1000);  // delay to avoid overloading the serial port buffer
  }
  
}
