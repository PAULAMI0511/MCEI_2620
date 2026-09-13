% Matriz A
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

% Solución exacta conocida (puros unos) para calcular el error real
x_exact = ones(10, 1);
b = A * x_exact;

% --- 1. Eliminación de Gauss / Operador Backslash (\) ---
tic;
x_gauss = A \ b;
time_gauss = toc * 1e6; % en microsegundos para comparar con C++

% --- 2. Factorización LU ([L, U, P] = lu(A)) ---
tic;
[L, U, P] = lu(A);
% Sistema equivalente: L * (U * x) = P * b
y_lu = L \ (P * b);
x_lu = U \ y_lu;
time_lu = toc * 1e6;

% --- 3. Factorización QR ([Q, R] = qr(A)) ---
tic;
[Q, R] = qr(A);
% Sistema equivalente: Q * R * x = b  =>  R * x = Q' * b
x_qr = R \ (Q' * b);
time_qr = toc * 1e6;

% --- Cálculo de Errores y Residuales ---
err_gauss = norm(x_gauss - x_exact);
res_gauss = norm(A * x_gauss - b);

err_lu = norm(x_lu - x_exact);
res_lu = norm(A * x_lu - b);

err_qr = norm(x_qr - x_exact);
res_qr = norm(A * x_qr - b);

% --- Impresión de la Tabla Comparativa ---
disp('Metodo                   Tiempo (us)    Error a la Solucion    Residual ||Ax-b||');
disp('----------------------------------------------------------------------------------');
fprintf('1. Operador Backslash     %.2f          %.2e          %.2e\n', time_gauss, err_gauss, res_gauss);
fprintf('2. Factorizacion LU       %.2f          %.2e          %.2e\n', time_lu, err_lu, res_lu);
fprintf('3. Factorizacion QR       %.2f          %.2e          %.2e\n', time_qr, err_qr, res_qr);