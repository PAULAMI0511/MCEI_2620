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
A_inv_direct = inv(A);
time_direct = toc * 1e6;

res_direct = norm(A * A_inv_direct - I, 'fro');

disp('--- Metodo Directo (Octave) ---');
fprintf('Tiempo (us): %.2f\n', time_direct);
fprintf('Residual ||A * A_inv - I||: %.2e\n', res_direct);
disp('Matriz Inversa:');
disp(A_inv_direct);