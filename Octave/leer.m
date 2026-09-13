% Matriz m del Punto 1 (4x3)
m = [1,  0,  2;
     2, -1,  5;
     0,  1, -1;
     1,  3, -1];

disp("=== MATRIZ ORIGINAL m ===");
disp(m);

% Cálculo de la pseudoinversa de Moore-Penrose
m_inv = pinv(m);

disp("=== PSEUDOINVERSA DE m ===");
disp(m_inv);

