#include <iostream>
#include <chrono>
#include <cmath>
#include <eigen3/Eigen/Dense>

using namespace Eigen;
using namespace std::chrono;

int main()
{
  MatrixXd A(10, 10);
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

  VectorXd b(10);
  b << 1, 1, 1, 1, 1, 1, 1, 1, 1, 1;
  int n = A.rows();

  // 1. MÉTODO GAUSS-JORDAN
  auto start = high_resolution_clock::now();
  MatrixXd aug(n, n + 1);
  aug.leftCols(n) = A;
  aug.rightCols(1) = b;
  for (int i = 0; i < n; ++i)
  {
    int maxRow = i;
    for (int k = i + 1; k < n; ++k)
    {
      if (std::abs(aug(k, i)) > std::abs(aug(maxRow, i)))
        maxRow = k;
    }
    aug.row(i).swap(aug.row(maxRow));
    double pivot = aug(i, i);
    if (std::abs(pivot) > 1e-12)
    {
      aug.row(i) /= pivot;
      for (int k = 0; k < n; ++k)
      {
        if (k != i)
          aug.row(k) -= aug(k, i) * aug.row(i);
      }
    }
  }
  VectorXd x_gj = aug.rightCols(1);
  auto end = high_resolution_clock::now();
  double time_gj = duration<double, std::micro>(end - start).count();
  double error_gj = (A * x_gj - b).norm();

  // 2. FACTORIZACIÓN LU
  start = high_resolution_clock::now();
  VectorXd x_lu = A.partialPivLu().solve(b);
  end = high_resolution_clock::now();
  double time_lu = duration<double, std::micro>(end - start).count();
  double error_lu = (A * x_lu - b).norm();

  // 3. FACTORIZACIÓN QR
  start = high_resolution_clock::now();
  VectorXd x_qr = A.householderQr().solve(b);
  end = high_resolution_clock::now();
  double time_qr = duration<double, std::micro>(end - start).count();
  double error_qr = (A * x_qr - b).norm();

  // RESULTADOS EN PANTALLA
  std::cout << "==========================================================" << std::endl;
  std::cout << "           COMPARATIVA DE RENDIMIENTO Y PRECISION         " << std::endl;
  std::cout << "==========================================================" << std::endl;
  std::cout << "Metodo          | Tiempo (microsegundos) | Residuo ||Ax - b||" << std::endl;
  std::cout << "----------------------------------------------------------" << std::endl;
  std::cout << "Gauss-Jordan    | " << time_gj << " us\t\t | " << error_gj << std::endl;
  std::cout << "Factorizacion LU| " << time_lu << " us\t\t | " << error_lu << std::endl;
  std::cout << "Factorizacion QR| " << time_qr << " us\t\t | " << error_qr << std::endl;
  std::cout << "==========================================================" << std::endl;

  return 0;
}