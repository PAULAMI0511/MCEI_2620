% Matriz m del Punto 1 (4x3)
m = [1,  0,  2;
     2, -1,  5;
     0,  1, -1;
     1,  3, -1];

disp("=== MATRIZ ORIGINAL m ===");
disp(m);

% Cálculo de la pseudoinversa de Moore-Penrose (m+)
m_inv = pinv(m);

disp("=== PSEUDOINVERSA DE m (m+) ===");
disp(m_inv);

disp("=== VERIFICACION DE LAS 4 PROPIEDADES DE PENROSE ===");

% Propiedad 1: m * m+ * m = m
% La matriz m+ actúa como una inversa débil a derecha e izquierda respecto a m.
p1 = m * m_inv * m;
disp("1. Propiedad m * m+ * m = m (Norma de error):");
disp(norm(p1 - m));

% Propiedad 2: m+ * m * m+ = m+
% La matriz m actúa como una inversa respecto a su pseudoinversa m+.
p2 = m_inv * m * m_inv;
disp("2. Propiedad m+ * m * m+ = m+ (Norma de error):");
disp(norm(p2 - m_inv));

% Propiedad 3: (m * m+)^T = m * m+
% El producto m * m+ es una matriz simétrica. Representa la proyección ortogonal sobre el espacio columna de m.
p3_trans = (m * m_inv)';
p3_orig = m * m_inv;
disp("3. Propiedad (m * m+)^T = m * m+ (Norma de error):");
disp(norm(p3_trans - p3_orig));

% Propiedad 4: (m+ * m)^T = m+ * m
% El producto m+ * m es una matriz simétrica. Representa la proyección ortogonal sobre el espacio fila de m.
p4_trans = (m_inv * m)';
p4_orig = m_inv * m;
disp("4. Propiedad (m+ * m)^T = m+ * m (Norma de error):");
disp(norm(p4_trans - p4_orig));

% TRABAJO DE LUNA Y PAULA