//DECLARACION DE VARIABLES

int SER  = 2;
int SRCLK = 3;
int RCLK = 4;

int a[8][8];
bool opcion_menu;
bool seleccion;
int opcion;
char m[8];

//DECLARACION DE FUNCIONES (PROTOTIPOS

void clockUpRCLK();
void verificacion(int &);
void imagen(int &opcion);


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
    //Serial.println("holi");
    opcion = Serial.parseInt();
    if (opcion != 0)
    {
      Serial.println("Su opcion es: ");
      Serial.println(opcion);
      seleccion = false;
      opcion_menu = true;

    }
  }


  if (opcion == 1) 
    verificacion(opcion);

  // else if (opcion == 2) imagen();


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

/*  void imagen() {
  digitalWrite(SRCLK, LOW);
  //
  Serial.println("Ingrese la fila");


  // for (int i=0; i<8; i++)*(*(a)+i);
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
  //  opcion = 0;

  }
*/
