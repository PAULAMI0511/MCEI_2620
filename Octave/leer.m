% Matriz A del sistema (10x10)
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

% Vector de términos independientes b
b = [1; 1; 1; 1; 1; 1; 1; 1; 1; 1];

n = size(A, 1);

% Construcción de la matriz aumentada [A | b]
aug = [A, b];

% Algoritmo de Gauss-Jordan con pivoteo parcial
for i = 1:n
    % Buscar el pivote máximo en la columna i
    [~, max_row] = max(abs(aug(i:n, i)));
    max_row = max_row + i - 1;
    
    % Intercambiar filas si es necesario
    if max_row ~= i
        aug([i, max_row], :) = aug([max_row, i], :);
    endif
    
    pivot = aug(i, i);
    if abs(pivot) < 1e-12
        error("La matriz es singular o casi singular.");
    endif
    
    % Normalizar la fila del pivote
    aug(i, :) = aug(i, :) / pivot;
    
    % Hacer ceros en las demás filas (arriba y abajo)
    for k = 1:n
        if k ~= i
            factor = aug(k, i);
            aug(k, :) = aug(k, :) - factor * aug(i, :);
        endif
    endfor
end

% Extraer la solución de la última columna
x = aug(:, end);

disp("=== MATRIZ A (10x10) ===");
disp(A);

disp("=== SOLUCION POR GAUSS-JORDAN (x) ===");
disp(x);

% TRABAJO DE PAULA Y LUNA