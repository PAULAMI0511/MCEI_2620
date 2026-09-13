% Matriz A y vector b
A = [
  2, 1, 0, 3, 2, 1, 0, 2, 1, 4;
  1, 3, 2, 0, 1, 4, 2, 1, 0, 2;
  0, 2, 4, 1, 3, 0, 1, 2, 4, 1;
  3, 0, 1, 5, 2, 1, 3, 0, 2, 1;
  2, 1, 3, 2, 6, 2, 1, 4, 0, 3;
  1, 4, 0, 1, 2, 5, 2, 1, 3, 0;
  0, 2, 1, 3, 1, 2, 4, 0, 2, 1;
  2, 1, 2, 0, 4, 1, 0, 5, 3, 2;
  1, 0, 4, 2, 0, 3, 2, 3, 6, 1;
  4, 2, 1, 1, 3, 0, 1, 2, 1, 5
];

b = [1; 1; 1; 1; 1; 1; 1; 1; 1; 1];

% Descomposición QR (A = Q * R)
[Q, R] = qr(A);

% Resolución del sistema lineal usando QR (R * x = Q' * b)
x = R \ (Q' * b);

disp("=== SOLUCION POR FACTORIZACION QR (OCTAVE) ===");
disp(x);