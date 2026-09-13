% Matriz A y vector b original
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

b = ones(10, 1); 

% 1. Resolver sistema original
x_original = A \ b;

% 2. Crear perturbación pequeña en b (ej. 1e-5 en la primera componente)
b_pert = b;
b_pert(1) = b_pert(1) + 1e-5;

% 3. Resolver sistema perturbado
x_pert = A \ b_pert;

% 4. Mostrar comparación detallada elemento a elemento
diff = x_original - x_pert;
disp("    Original        Perturbada       Diferencia");
disp([x_original, x_pert, diff]);

% 5. Medir el cambio global entre las soluciones
desviacion = norm(diff);
disp("Desviacion total (norma de la diferencia):");
disp(desviacion);