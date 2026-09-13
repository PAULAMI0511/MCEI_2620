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
[U, S, V] = svd(A);
S_inv = diag(1 ./ diag(S));
A_inv_svd = V * S_inv * U';
time_svd = toc * 1e6;

res_svd = norm(A * A_inv_svd - I, 'fro');

disp('--- Metodo SVD (Octave) ---');
fprintf('Tiempo (us): %.2f\n', time_svd);
fprintf('Residual ||A * A_inv - I||: %.2e\n', res_svd);
disp('Matriz Inversa:');
disp(A_inv_svd);