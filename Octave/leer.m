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

I = eye(10);

tic;
[Q, R] = qr(A);
A_inv_qr = R \ (Q' * I);
time_qr = toc * 1e6;

res_qr = norm(A * A_inv_qr - I, 'fro');

disp('--- Metodo QR (Octave) ---');
fprintf('Tiempo (us): %.2f\n', time_qr);
fprintf('Residual ||A * A_inv - I||: %.2e\n', res_qr);
disp('Matriz Inversa:');
disp(A_inv_qr);