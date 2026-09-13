#include <iostream>
#include <eigen3/Eigen/Dense>

using Eigen::MatrixXd;

int main()
{
  MatrixXd m(4, 3);

  // Asignación posición por posición (Fila, Columna)
  m(0, 0) = 1;
  m(0, 1) = 0;
  m(0, 2) = 2;
  m(1, 0) = 2;
  m(1, 1) = -1;
  m(1, 2) = 5;
  m(2, 0) = 0;
  m(2, 1) = 1;
  m(2, 2) = -1;
  m(3, 0) = 1;
  m(3, 1) = 3;
  m(3, 2) = -1;

  // Cálculo de la pseudoinversa (inversa para matrices no cuadradas)
  MatrixXd m_inv = m.completeOrthogonalDecomposition().pseudoInverse();

  std::cout << "=== MATRIZ ORIGINAL m ===" << std::endl;
  std::cout << m << std::endl
            << std::endl;

  std::cout << "=== PSEUDOINVERSA DE m ===" << std::endl;
  std::cout << m_inv << std::endl;

  std::cout << "=== VERIFICACION DE LAS 4 PROPIEDADES DE PENROSE ===" << std::endl;

  // Propiedad 1: m * m+ * m = m
  // La matriz m+ actua como una inversa debil a derecha e izquierda respecto a m.
  MatrixXd p1 = m * m_inv * m;
  std::cout << "\n1. Propiedad m * m+ * m = m:" << std::endl;
  std::cout << p1 << std::endl;
  std::cout << "Diferencia (norma error): " << (p1 - m).norm() << std::endl;

  // Propiedad 2: m+ * m * m+ = m+
  // La matriz m actua como una inversa respecto a su pseudoinversa m+.
  MatrixXd p2 = m_inv * m * m_inv;
  std::cout << "\n2. Propiedad m+ * m * m+ = m+:" << std::endl;
  std::cout << p2 << std::endl;
  std::cout << "Diferencia (norma error): " << (p2 - m_inv).norm() << std::endl;

  // Propiedad 3: (m * m+)^T = m * m+
  // El producto m * m+ es una matriz simetrica. Representa la proyeccion ortogonal sobre el espacio columna de m.
  MatrixXd p3_trans = (m * m_inv).transpose();
  MatrixXd p3_orig = m * m_inv;
  std::cout << "\n3. Propiedad (m * m+)^T = m * m+:" << std::endl;
  std::cout << "Transpuesta (m * m+)^T:" << std::endl
            << p3_trans << std::endl;
  std::cout << "Diferencia (norma error): " << (p3_trans - p3_orig).norm() << std::endl;

  // Propiedad 4: (m+ * m)^T = m+ * m
  // El producto m+ * m es una matriz simetrica. Representa la proyeccion ortogonal sobre el espacio fila de m.
  MatrixXd p4_trans = (m_inv * m).transpose();
  MatrixXd p4_orig = m_inv * m;
  std::cout << "\n4. Propiedad (m+ * m)^T = m+ * m:" << std::endl;
  std::cout << "Transpuesta (m+ * m)^T:" << std::endl
            << p4_trans << std::endl;
  std::cout << "Diferencia (norma error): " << (p4_trans - p4_orig).norm() << std::endl;

  return 0;
}

// LA INVERSA DE UNA MATRIS ES
// TRABAJO DE PAULA Y LUNA
