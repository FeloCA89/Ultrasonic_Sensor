int trig = 10 ;                           // Define el pin del trig para el sensor 
int eco = 9 ;                             // Define el pin del echo para el sensor 
int led = 3 ;                             // Define el pin del indicador 
int duracion;                             // Define la variable para la duracion de pulso enviado por el sensor 
int distancia;                            // Define la variable para calcular la distancia en centimetros que detecta el sensor 

void setup() {
  pinMode(trig, OUTPUT);                  // Define el trig como salida 
  pinMode(eco, INPUT);                    // Define el echo como entrada 
  pinMode(led, OUTPUT);                   // Define el pin del indicador como salida
  Serial.begin(9600);                     // Inicializa el monitor serial con operacion de 9600
}

void loop() {
  digitalWrite(trig, HIGH);               // El fabricante dice que para inicializar el sensor se debe poner el alto el trig  
  delay(1);                               // Dejar pasar un milisegundo y  
  digitalWrite(trig, LOW);                // Apagar nuevamente el trig
  duracion =  pulseIn(eco, HIGH);         // Mediante el pin echo medimos la respuesta del sensor  y lo almacenamos en la variable duracion almacenado en milisegundos
  distancia = duracion / 58.2;            // Se calcula la distancia en "cm" mediante la duracion de la respuesta almacenada anteriormente "58.2" esta dado por el fabricante
  Serial.println(distancia);              // Mostramos el valor de distancia en el monitor serial
  delay(200);                             // Tiempo de espera entre una linea y otra  
  if (distancia <= 20 && distancia >= 0){   // Si la distancia del objeto esta entre 0 y 20 cm enciende el led 
    digitalWrite (led, HIGH);
    delay(distancia * 10 );                 // El led parpadea con una latencia de la distancia por 10 milisegundos 
    digitalWrite(led, LOW);  
  }
} 
