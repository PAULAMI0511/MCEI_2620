#include <iostream>   // se encarga de la entrada y salida de datos
#include <iomanip>  // se encarga de la manipulacion de datos
#include <cmath>  // se encarga de las funciones matematicas
#include <gsl/gsl_roots.h> // se encarga de la busqueda de raices
#include <gsl/gsl_errno.h> // se encarga de la gestion de errores

double f(double x, void *params) {  // funcion a la que se le busca la raiz
  return 0;             // se puede cambiar por cualquier funcion que se desee
}

int main() {            // funcion principal
  const gsl_root_fsolver_type *T;  
  gsl_root_fsolver *s; 
  gsl_function F; 
  F.function = &f;  
  F.params = nullptr;
  double x_lo = 0.0;
  double x_hi = 1.0;
  T = gsl_root_fsolver_bisection;
  s = gsl_root_fsolver_alloc(T);%
  gsl_root_fsolver_set(s, &F, x_lo, x_hi);
  std::cout << "iter\t" << "inf\t" << "sup\t" << "raíz\n";

  int status; // se encarga de la gestion de errores
  int iter = 0; // se encarga de contar el numero de iteraciones
  int max_iter = 100;  // se encarga de limitar el numero de iteraciones
  double r; // se encarga de almacenar la raiz encontrada

  do {
    iter++;
    status = gsl_root_fsolver_iterate(s);  // se encarga de iterar el metodo de biseccion
    r = gsl_root_fsolver_root(s); // se encarga de almacenar la raiz encontrada
    x_lo = gsl_root_fsolver_x_lower(s);  // se encarga de almacenar el limite inferior del intervalo
    x_hi = gsl_root_fsolver_x_upper(s);  // se encarga de almacenar el limite superior del intervalo
    std::cout << iter << "\t" << x_lo << "\t" << x_hi << "\t" << r << "\n";   // se encarga de mostrar el resultado de cada iteracion
          status = gsl_root_test_interval( x_lo, x_hi, 0.0, 1e-8); // se encarga de comprobar si la raiz encontrada es suficientemente precisa
  } while(status == GSL_CONTINUE && iter < max_iter);  // se encarga de continuar iterando mientras no se haya encontrado la raiz o se haya alcanzado el numero maximo de iteraciones

  std::cout << "\nRaiz encontrada = " << r << std::endl; gsl_root_fsolver_free(s);  // se encarga de liberar la memoria utilizada por el solver
  return 0;
}

