int buzzerPin = 9;  // Asigna el pin 9 a la constante para el buzzer

// Definir las frecuencias de las notas en la escala de do mayor (octava comenzando desde do medio)
int c = 262;
int d = 294;
int e = 330;
int f = 349;
int g = 392;
int a = 440;
int b = 494;
int C = 523;  // Do alto

// Configurar la secuencia de notas y sus duraciones en milisegundos
int melody[] = { c, c, g, g, a, a, g, f, f, e, e, d, d, c, g, g, f, f, e, e, d, g, g, f, f, e, e, d, c, c, g, g, a, a, g, f, f, e, e, d, d, c };
int noteDurations[] = { 500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 500, 1000 };

void setup() {
  // Coloca aquí tu código de configuración para que se ejecute una vez:
  Serial.begin(9600);                              // Inicializar la comunicación serial a 9600 baudios
}

void loop() {
  // Coloca aquí tu código principal para que se ejecute repetidamente:
  int notes = sizeof(melody) / sizeof(melody);  // Calcula el número de elementos
  // Recorre cada nota en el arreglo melody
  for (int i = 0; i < notes; i = i + 1) {
    // Imprime la frecuencia de cada nota en el monitor serial
    // Serial.println(melody[i]);

    tone(buzzerPin, melody[i], noteDurations[i]);  // Reproduce la nota
    delay(noteDurations[i] * 1.30);                // Espera antes de cambiar la nota
    noTone(buzzerPin);                             // Detiene la reproducción de la nota
  }
}