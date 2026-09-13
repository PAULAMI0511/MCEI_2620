#include <iostream>
#include <eigen3/Eigen/Dense>

using Eigen::MatrixXd;

int main()
{
  MatrixXd m(4, 3);

  // Asignación posición por posición (Fila, Columna)
  m(0,0) = 1;  m(0,1) = 0;  m(0,2) = 2;
  m(1,0) = 2;  m(1,1) = -1; m(1,2) = 5;
  m(2,0) = 0;  m(2,1) = 1;  m(2,2) = -1;
  m(3,0) = 1;  m(3,1) = 3;  m(3,2) = -1;

  // Cálculo de la pseudoinversa (inversa para matrices no cuadradas)
  MatrixXd m_inv = m.completeOrthogonalDecomposition().pseudoInverse();

  std::cout << "=== MATRIZ ORIGINAL m ===" << std::endl;
  std::cout << m << std::endl << std::endl;

  std::cout << "=== PSEUDOINVERSA DE m ===" << std::endl;
  std::cout << m_inv << std::endl;

  return 0;
}
//LA INVERSA DE UNA MATRIS ES 
//TRABAJO DE PAULA Y LUNA 


