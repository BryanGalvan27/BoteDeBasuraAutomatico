#include <Ultrasonic.h>
#include <Servo.h>

Servo myservo;  // Crea un objeto de tipo Servo llamado "myservo"
Ultrasonic ultrasonic(2, 3);  // Crea un objeto de tipo Ultrasonic con los pines 2 (ECHO) y 3 (TRIGGER)
int distance;  // Variable para almacenar la distancia medida por el sensor ultrasónico

void setup() {
  myservo.attach(9);  // Adjunta el servo al pin 9 y lo asocia con el objeto "myservo"
  Serial.begin(9600);  // Inicia la comunicación serial a una velocidad de 9600 baudios
  myservo.write(60);  // Coloca el servo en su posición inicial (ángulo 0 grados)
}

void loop() {
  // Lee la distancia en centímetros utilizando el sensor ultrasónico
  distance = ultrasonic.read();
  
  // Comprueba si la distancia medida es menor o igual a 30 centímetros
  if (distance <= 30) {  
    // Si la distancia es menor o igual a 30 cm, realiza lo siguiente:
    
    myservo.write(-60);  // Gira el servo a un ángulo de 60 grados (puede ser un ángulo específico para realizar una acción)
    delay(4000);  // Espera 4 segundos (4000 milisegundos)
    myservo.write(60);  // Vuelve a la posición inicial del servo (ángulo 0 grados)
  }
  
  // Imprime la distancia medida en centímetros en el Monitor Serie
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  
  delay(100);  // Espera 100 milisegundos antes de realizar la siguiente medición
}
