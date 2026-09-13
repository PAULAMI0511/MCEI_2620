#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main()
{
  // Declaración de la matriz A de 10x10
  MatrixXd A(10, 10);

  // Asignación de valores posición por posición (Fila, Columna)
  A(0, 0) = 2;
  A(0, 1) = 1;
  A(0, 2) = 0;
  A(0, 3) = 3;
  A(0, 4) = 2;
  A(0, 5) = 1;
  A(0, 6) = 0;
  A(0, 7) = 2;
  A(0, 8) = 1;
  A(0, 9) = 4;

  A(1, 0) = 1;
  A(1, 1) = 3;
  A(1, 2) = 2;
  A(1, 3) = 0;
  A(1, 4) = 1;
  A(1, 5) = 4;
  A(1, 6) = 2;
  A(1, 7) = 1;
  A(1, 8) = 0;
  A(1, 9) = 2;

  A(2, 0) = 0;
  A(2, 1) = 2;
  A(2, 2) = 4;
  A(2, 3) = 1;
  A(2, 4) = 3;
  A(2, 5) = 0;
  A(2, 6) = 1;
  A(2, 7) = 2;
  A(2, 8) = 4;
  A(2, 9) = 1;

  A(3, 0) = 3;
  A(3, 1) = 0;
  A(3, 2) = 1;
  A(3, 3) = 5;
  A(3, 4) = 2;
  A(3, 5) = 1;
  A(3, 6) = 3;
  A(3, 7) = 0;
  A(3, 8) = 2;
  A(3, 9) = 1;

  A(4, 0) = 2;
  A(4, 1) = 1;
  A(4, 2) = 3;
  A(4, 3) = 2;
  A(4, 4) = 6;
  A(4, 5) = 2;
  A(4, 6) = 1;
  A(4, 7) = 4;
  A(4, 8) = 0;
  A(4, 9) = 3;

  A(5, 0) = 1;
  A(5, 1) = 4;
  A(5, 2) = 0;
  A(5, 3) = 1;
  A(5, 4) = 2;
  A(5, 5) = 5;
  A(5, 6) = 2;
  A(5, 7) = 1;
  A(5, 8) = 3;
  A(5, 9) = 0;

  A(6, 0) = 0;
  A(6, 1) = 2;
  A(6, 2) = 1;
  A(6, 3) = 3;
  A(6, 4) = 1;
  A(6, 5) = 2;
  A(6, 6) = 4;
  A(6, 7) = 0;
  A(6, 8) = 2;
  A(6, 9) = 1;

  A(7, 0) = 2;
  A(7, 1) = 1;
  A(7, 2) = 2;
  A(7, 3) = 0;
  A(7, 4) = 4;
  A(7, 5) = 1;
  A(7, 6) = 0;
  A(7, 7) = 5;
  A(7, 8) = 3;
  A(7, 9) = 2;

  A(8, 0) = 1;
  A(8, 1) = 0;
  A(8, 2) = 4;
  A(8, 3) = 2;
  A(8, 4) = 0;
  A(8, 5) = 3;
  A(8, 6) = 2;
  A(8, 7) = 3;
  A(8, 8) = 6;
  A(8, 9) = 1;

  A(9, 0) = 4;
  A(9, 1) = 2;
  A(9, 2) = 1;
  A(9, 3) = 1;
  A(9, 4) = 3;
  A(9, 5) = 0;
  A(9, 6) = 1;
  A(9, 7) = 2;
  A(9, 8) = 1;
  A(9, 9) = 5;

  // Vector de términos independientes b (puedes ajustarlo según tu taller)
  VectorXd b(10);
  b << 1, 1, 1, 1, 1, 1, 1, 1, 1, 1;

  int n = A.rows();

  // Construcción de la matriz aumentada [A | b] para aplicar Gauss-Jordan
  MatrixXd aug(n, n + 1);
  aug.leftCols(n) = A;
  aug.rightCols(1) = b;

  // Algoritmo de Eliminación de Gauss-Jordan con pivoteo parcial
  for (int i = 0; i < n; ++i)
  {
    int maxRow = i;
    for (int k = i + 1; k < n; ++k)
    {
      if (std::abs(aug(k, i)) > std::abs(aug(maxRow, i)))
      {
        maxRow = k;
      }
    }

    // Intercambiar filas
    aug.row(i).swap(aug.row(maxRow));

    double pivot = aug(i, i);
    if (std::abs(pivot) < 1e-12)
    {
      std::cerr << "Advertencia: La matriz puede ser singular." << std::endl;
      continue;
    }

    // Normalizar la fila del pivote
    aug.row(i) /= pivot;

    // Hacer ceros en las demás filas (arriba y abajo del pivote)
    for (int k = 0; k < n; ++k)
    {
      if (k != i)
      {
        double factor = aug(k, i);
        aug.row(k) -= factor * aug.row(i);
      }
    }
  }

  // Extraer la solución del vector resultante en la última columna
  VectorXd x = aug.rightCols(1);

  std::cout << "=== MATRIZ A (10x10) ===" << std::endl;
  std::cout << A << std::endl
            << std::endl;

  std::cout << "=== SOLUCION POR GAUSS-JORDAN (x) ===" << std::endl;
  std::cout << x << std::endl;

  return 0;
}

// TRABAJO DE PAULA Y LUNA
// sistemas de ecuaciones lineales
// TRABAJO DE PAULA Y LUNA
