#include <iostream>

using namespace std;

int main()
{
  /*  int a[3][4] ={{2,2,2,2},{0,0,0,0},{1,1,1,1}};
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++)
            cout << a[i][j] << ' ' ;
        cout << endl;
    }

*/
  //int m_array[8][8];
  //int **ptr = new int m_array[8][8];

    char a[8];
    short imagen[8][8];
    for (int i=0; i<64; i++) *(*(imagen)+i)=0;
    cout << "El ingreso se hace por renglones, por lo tanto son 8 " << endl;
    cout << "Ingrese * para leds apagados y o para leds encendidos " << endl;
    for (int j=0; j<8; j++)
    {
        cout << "Ingrese la fila " << j << endl;

        for (int i=0;i<8; i++) cin >> a[i];

        for (int i=0;i<8; i++)
        {
            if (a[i]=='*') *(*(imagen)+j+i*8)=0;
            else if ( a[i]=='o') *(*(imagen)+j+i*8)=1;
        }
    }
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            cout <<imagen[j][i];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
*/
}

