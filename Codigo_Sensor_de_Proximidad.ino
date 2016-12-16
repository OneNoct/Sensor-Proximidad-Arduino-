
#include "Ultrasonic.h"     //Libreria del sonar
Ultrasonic ultrasonic(4,5); //Trigger, Echo
Ultrasonic ultrasonic2(13,12); //Declarar cuantos "ultrasonic" sean necesarios (uno por sensor)
//Ultrasonic ultrasonic3(0,0);

// Señal acustica
#include "pitches.h"        //Libreria que contiene las notas musicales
int sonido = NOTE_A4;       //Declaramos la nota musical elegida como el sonido
int sonido2 = NOTE_C4;      //al igual que los ultrasonic, se declara cuantos sonidos deseen
// int sonido3 = NOTE_C5;

int sonar, sonar2;  //Declaramos la variable sonar (guardara la distancia del sensor)
// int sonar3;

void setup()
{
   Serial.begin(9600);    //Inicio de la comunicacion serie a 9600 baudios
}

void loop() {
   sonar = ultrasonic.Ranging(CM); //Leemos la distancia del sonar
   sonar2 = ultrasonic2.Ranging(CM); //cada sonar con su ultrasonic
//   sonar3 = ultrasonic3.Ranging(CM);

//La funcion ultrasonic.ranging(cm) viene declarada en la libreria del sonar
//Calcula la distancia a la que rebota una señal enviada basandose en el
//tiempo que tarda en recorrer dicha distancia, devolviendonos la distancia
//en centimetros, lista para utilizar en casos de medicion por ultrasonidos.

   if (sonar < 500)             //Mientras que la distancia sea menor a 500 cm (esta depende de cuanta capacidad tenga el sensor)
   {
       noTone(8);                  //Mantenemos el sonido apagado


       delay(sonar*10);            //Delay dependiente del valor del sonar. Si la distancia se reduce
                                   //el delay es menor y la señal acustica sonara con mayor frecuencia.
                                   //Si la distancia aumenta, el delay aumenta, disminuyendo la frecuencia
                                   //con la que suenan los pitidos.

       tone(8, sonido);            //Señal acustica de aviso


       delay(100);                 //Delay para mantener la señal acustica 0,1 segundos minimo

       noTone(8);                  //Apagamos el sonido


       if (sonar < 5)          //Si la distancia del sonar es menor que 10 cm
       {
         tone(8, sonido);                //Suena sin interrupciones indicando la proximidad del objeto
         sonar = ultrasonic.Ranging(CM); //Distancia del sonar

       }

       sonar = ultrasonic.Ranging(CM);
   }


   if (sonar2 < 500)
   {
       noTone(9);
       delay(sonar2 *10);
       tone(9, sonido2);
       delay(100);
       noTone(9);
       if (sonar2 < 5)
       {
         tone(9, sonido2);
         sonar2 = ultrasonic2.Ranging(CM);
       }
       sonar2 = ultrasonic2.Ranging(CM);
   }

  //  if (sonar3 < 500)
  //  {
  //      noTone(0);
  //      delay(sonar3 *10);
  //      tone(0, sonido3);
  //      delay(100);
  //      noTone(0);
  //      if (sonar3 < 5)
  //      {
  //        tone(0, sonido3);
  //        sonar3 = ultrasonic3.Ranging(CM);
  //      }
  //      sonar3 = ultrasonic3.Ranging(CM);
  //  }

}
