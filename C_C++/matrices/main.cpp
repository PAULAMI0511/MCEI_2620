#include <iostream>
#include <chrono>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/QR>

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

  MatrixXd I = MatrixXd::Identity(10, 10);

  auto t1 = high_resolution_clock::now();
  MatrixXd A_inv_qr = A.householderQr().solve(I);
  auto t2 = high_resolution_clock::now();
  double time_qr = duration_cast<microseconds>(t2 - t1).count();

  double res_qr = (A * A_inv_qr - I).norm();

  std::cout << "--- Metodo QR (C++) ---" << std::endl;
  std::cout << "Tiempo (us): " << time_qr << std::endl;
  std::cout << "Residual ||A * A_inv - I||: " << res_qr << std::endl;
  std::cout << "\nMatriz Inversa:\n"
            << A_inv_qr << std::endl;

  return 0;
}
