//DECLARACION DE VARIABLES

int SER  = 2;
int SRCLK = 3;
int RCLK = 4;

int ingresar = 0;
int a[8][8];
bool opcion_menu;
bool seleccion;
int opcion;
char m[8];
int contador_char = 0;
int j = 0;

//DECLARACION DE FUNCIONES (PROTOTIPOS

void clockUpRCLK();
void verificacion(int &);
void imagen(int &);


void setup()
{
  Serial.begin(9600);
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  for (int i = 0; i < 64; i++)*(*(a) + i) = 0;
  opcion = 0;
  opcion_menu = true;
  seleccion == true;
  for (int i = 0; i < 8; i++) *(m + i) = '*';
}


void loop() {

  if (opcion_menu == true)
  {
    Serial.println("Seleccione 1 para verificacion");
    Serial.println("Seleccione 2 para graficar un patron");
    Serial.println("Seleccione 3 para graficar una serie de patrones");
    opcion_menu = false;
  }
  if (opcion == 0)
  {
    opcion = Serial.parseInt();
    if (opcion != 0)
    {
      Serial.println("Su opcion es: ");
      Serial.println(opcion);
      Serial.flush();
      seleccion = false;
      //opcion_menu = true;

    }
  }


  if (opcion == 1)
    verificacion(opcion);

  else if (opcion == 2) imagen(opcion);


}

/*void clockUpRCLK()
  {
  digitalWrite(RCLK, LOW);
  digitalWrite(RCLK, HIGH);
  }
*/
void verificacion (int &opcion)
{
  Serial.println("Encendiendo todos los leds para verificacion");
  //  digitalWrite(SRCLK, LOW);
  for (int i = 0; i < 64; i++)*(*(a) + i) = 1;

  for (int i = 0; i < 64; i++)
  {
    Serial.print(*(*(a) + i));
    Serial.print(' ');
    if ((i + 1) % 8 == 0) Serial.println(' ');
  }
  opcion = 0;
  opcion_menu = true;

  /*  digitalWrite(SRCLK, LOW);
    for (int i=0; i<8; i++)*(*(a)+i)=1;
    for (int i=0; i<64; i++){

      digitalWrite(SER,*(*(a)+i));
      clock();

    }
    digitalWrite(SRCLK, HIGH);
    delay(2000);
     digitalWrite(SRCLK, LOW);
    for (int i=0; i<64; i++)*(*(a)+i)=0;
    for (int i=0; i<64; i++){
      digitalWrite(SER,*(*(a)+i));
      clock();
    }
    digitalWrite(SRCLK, HIGH);
    opcion = 0;
    opcion_menu=true;

  */
}

void imagen(int &opcion)
{
  //digitalWrite(SRCLK, LOW);

  //Serial.println("Ingrese la fila");
  char f = 'x';

  if (j < 8)
  {
    if (contador_char < 8)
    {
      f = Serial.read();
      if ( f == '*' ||  f == 'o')
      {
        m[contador_char] = f;
        contador_char ++;
        f = 'x';
      }
      if (contador_char == 8)
      {
        for (int i = 0; i < 8; i++)
        {
          if (m[i] == '*')
            *(*(a) + i + 8 * j) = 0;


          else
            *(*(a) + i + 8 * j) = 1;
          if (i == 7) {
            contador_char = 0;
            for (int i = 0; i < 8; i++)
            {
              Serial.print(*(*(a) + i + 8 * j));
              Serial.print(' ');
              if ((i + 1) % 8 == 0) Serial.println(' ');
            }
            j++;
          }
        }
      }
    }
  }
  else {
    opcion = 0;
    opcion_menu = true;
    contador_char = 0;
    Serial.println(j);

    /* //if (Serial.available() == 0)
      {
       for (contador_char; contador_char < 8; contador_char++) {
         m[contador_char] = Serial.read();
         Serial.println(m[contador_char]);
         Serial.println(contador_char);
       }

       if (contador_char == 7)
       {
         opcion = 0;
         opcion_menu = true;
       }
       /*  //for (int i = 0; i < 64; i++) {

         digitalWrite(SER, *(*(a) + i));

         clock();

         }
         digitalWrite(SRCLK, HIGH);
         delay(2000);
         digitalWrite(SRCLK, LOW);
         for (int i = 0; i < 64; i++)*(*(a) + i) = 0;
         for (int i = 0; i < 64; i++) {

         digitalWrite(SER, *(*(a) + i));
         clock();
         }
         digitalWrite(SRCLK, HIGH);
         //  opcion = 0;
    */
  }
}
