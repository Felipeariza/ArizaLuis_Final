//Se incluyen las librerias//
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
//Se busca resolver una ecuacion diferencial ordinaria de segubndo orden por el metodo de Rungekutta de cuarto orden
//Se definen las constantes a usar en el codigo
const double q=2;
const double m=7294.29;
//Variable que define el cambio en el eje x
const double p = 0.01;
//Numero de puntos para iterar
int n;
//Variables que van a guardar las pendientes en diferentes intervalos para X
double kx1, kx2,kx3, kx4;
//Variables que van a guardar las pendientes en diferentes intervalos para Y
double ky1,ky2, ky3, ky4;
//Variable para el promedio de las penddientes de la posicion y la velocidad
double kxp,kyp,vxp, vyp;
//Variables que van a guardar las pendientes en diferentes intervalos para la velocidad en Y
double vy1,vy2,vy3,vy4;
//Variables que van a guardar las pendientes en diferentes intervalos para la velocidad en Y
double vx1,vx2,vx3,vx4;
//Se declaran los punteros
double *x;
double *y;
//Se declaran las funciones a usar
double fx_p(double tiempo, double x, double vx);
double fy_p(double tiempo, double y, double vy);
double fvx_p(double tiempo, double vy, double vx);
double fvy_p(double tiempo, double vy, double vx);
void rk4(double tiempomax);
//Main en el que se llaman las funciones y se corren las funciones para ejecutar el codigo
int main()
{
//Se llama a la funcion que resuelve la ecuacion 
 rk4(10);
 //Se declara d que sera la variable que almacene los datos
 ofstream d;
 d.open("valores.txt");
 //Loop para imprimir los valores del vector X y Y en el archivo txt
 for(int i=0;i<n;i++)
 {
  d<<x[i]<<" "<< y[i]<<endl;
 }
 d.close();
 
 //Loop para imprimir los valores del Vector Y separado para facilitar la grafica.
 for(int i=0;i<n;i++)
 {
  d <<y[i]<<" ";
 
 d<<endl;
 }
 d.close();
 return 0;
}
/*Se definen las funciones que retornan la velocidad en x dado un tiempo, posicion y vel inicial*/
double fx_p(double tiempo, double x, double vx)
{
 return vx;
}
double campo(double tiempo)
{
    if(tiempo<3 || tiempo > 7)
        return 3;
}
/*Se definen las funciones que retornan la velocidad en y dado un tiempo, posicion y vel inicial*/
double fy_p(double tiempo, double y, double vy)
{
 return vy;
}
/*Funcion en la que se evalua un tiempo y velocidad y se retornal el valor de la posicion*/
double fvx_p(double tiempo, double vy, double vx)
{
 return (campo(tiempo)*q*p+2*vx/sqrt(vy*vy+vx*vx))/2;
}
/*Funcion en la que se evalua un tiempo y velocidad y se retornal el valor de la posicion*/
double fvy_p(double tiempo, double vy, double vx)
{
return (campo(tiempo)*q*p+2*vx/sqrt(vy*vy+vx*vx))/2;
}

/*Metodo runge kutta de cuarto orden en donde se resolvera la ecuadion ODE llamando a las funciones anteriormente definidas*/
//Implementacion rescatada de un laboratorio propio
void rk4(double tiempomax)
{
//Tiempo en donde inicia
 double tiempoini=0;
 //Se calcula el numero de puntos a interar con base en el tiempo de la simulacion y el paso (p)
 n=(tiempomax-tiempoini)/p;
 //Se declaran los arreglos con el tamaño encontrado arriba
 double tiempo[n];
 x=new double[n];
 double vx[n];
 y=new double[n];
 double vy[n];
 //Se inicializa el arreglo del tiempo
 tiempo[0]=tiempoini;
 //Se inicializan las posiciones en x y y
 x[0]=1;
 y[0]=0;
 //Se inicializa la velocidad en x y y 
 
 vx[0]=0;
 vy[0]=1;
 
/*Loop que actualiza las variables para cada punto llamando las diferentes funciones para evaluar los puntos*/
 for(int i =1;i<n;i++)
 {
 //Implementacion para encontrar las pendientes en cada punto
 //Paso 1
    kx1 = p*fx_p(tiempo[i-1],x[i-1],vx[i-1]);
    ky1 = p*fy_p(tiempo[i-1],y[i-1],vy[i-1]);
    vx1 = p*fvx_p(tiempo[i-1],vy[i-1],vx[i-1]);
    vy1 = p*fvy_p(tiempo[i-1],vy[i-1],vx[i-1]);
//Paso 2
    kx2 = p*fx_p(tiempo[i-1]+0.5*p, x[i-1]+0.5*kx1,vx[i-1]+0.5*vx1);
    ky2 = p*fy_p(tiempo[i-1]+0.5*p, y[i-1]+0.5*ky1,vy[i-1]+0.5*vy1);
    vx2 = p*fvx_p(tiempo[i-1]+0.5*p, vy[i-1]+0.5*vy1,vx[i-1]+0.5*vx1);
    vy2 = p*fvy_p(tiempo[i-1]+0.5*p, vy[i-1]+0.5*vy1,vx[i-1]+0.5*vx1);
//Paso 3
    kx3 = p*fx_p(tiempo[i-1]+0.5*p, x[i-1]+0.5*kx2,vx[i-1]+0.5*vx2);
    ky3 = p*fy_p(tiempo[i-1]+0.5*p, y[i-1]+0.5*ky2,vy[i-1]+0.5*vy2);
    vx3 = p*fvx_p(tiempo[i-1]+0.5*p, vy[i-1]+0.5*vy2,vx[i-1]+0.5*vx2);
    vy3 = p*fvy_p(tiempo[i-1]+0.5*p, vy[i-1]+0.5*vy2,vx[i-1]+0.5*vx2);
//Paso 4
    kx4 = p*fx_p(tiempo[i-1]+p,x[i-1]+kx3,vx[i-1]+vx3);
    ky4 = p*fy_p(tiempo[i-1]+p,y[i-1]+ky3,vy[i-1]+vy3);
    vx4 = p*fvx_p(tiempo[i-1]+p,vy[i-1]+vy3,vx[i-1]+vx3);
    vy4 = p*fvy_p(tiempo[i-1]+p,vy[i-1]+vy3,vx[i-1]+vx3);
//Se obtiene el promedio con cada uno de los pasos
    kxp = (1.0/6.0)*(kx1+2.0*kx2+2.0*kx3+kx4);
    kyp = (1.0/6.0)*(ky1+2.0*ky2+2.0*ky3+ky4);
    vxp = (1.0/6.0)*(vx1+2.0*vx2+2.0*vx3+vx4);
    vyp = (1.0/6.0)*(vy1+2.0*vy2+2.0*vy3+vy4);
//Se actualiza el arreglo para el tiempo avanzando 0.01
    tiempo[i] = tiempo[i-1] + p;
//Se actualizan las variables anteriores con la nueva pendiente promedio obtenida
    x[i] = x[i-1] + kxp;
    y[i] = y[i-1] + kyp;
    vx[i] = vx[i-1] + vxp;
    vy[i] = vy[i-1] + vyp;
 }
}
