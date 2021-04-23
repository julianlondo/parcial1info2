int SER  = 2;
int SRCLK = 3;
int RCLK = 4;

int a[8][8];
int m[8];
int ingresar = 0;
int opcion=0;
bool opcion_menu = true;
int contador_char = 0;
int j = 0;





void clock();
void verificacion(int &);
void imagen(int &); 


void setup(){
  Serial.begin(9600);
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  for (int i=0; i<7; i++){
  **(a+i)=0;
  } 
  
}

void loop()
{
  if (opcion_menu==true)
  {
    Serial.println("Seleccione 1 para verificacion");
  	Serial.println("Seleccione 2 para graficar un patron");
    Serial.println("Seleccione 3 para graficar una serie de patrones");
  opcion_menu=false;
  }
  
  if (opcion == 0)
  {
    opcion = Serial.parseInt();
    if (opcion != 0)
    {
      Serial.println("Su opcion es: ");
      Serial.println(opcion);
      Serial.flush();
    }
  } 
  if (opcion == 1)
    verificacion(opcion);  
  
  else if (opcion == 2) 
    imagen(opcion);
 
}

void clock()
{
  digitalWrite(RCLK, LOW);
  digitalWrite(RCLK, HIGH);
}

void verificacion(int &opcion)
{
  Serial.println("Encendiendo todos los leds para verificacion");
  digitalWrite(SRCLK, LOW);
  for (int i=0; i<64; i++)*(*(a)+i)=1;
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
  
    
}
            
void imagen(int &opcion) {
  digitalWrite(SRCLK, LOW);
  
  
  char f; 
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
         
            j++;
          }
        }
      }
    }
  }
  if (j==8){
   
  
  
  for (int i=0; i<64; i++){
    
    digitalWrite(SER,*(*(a)+i));
  
    clock();
    
  }
  digitalWrite(SRCLK, HIGH);
  delay(10000);
  digitalWrite(SRCLK, LOW);
  for (int i=0; i<64; i++)*(*(a)+i)=0;
  for (int i=0; i<64; i++){
    
    digitalWrite(SER,*(*(a)+i));
    clock();
  }
  digitalWrite(SRCLK, HIGH);
  opcion = 0;
    
    opcion_menu=true;
     
}
}  
 

