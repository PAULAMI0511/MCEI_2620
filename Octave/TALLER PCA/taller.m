clc; clear; close all;

printf("\n===== ACTIVIDAD 1: Matriz X, media, desviación y Z =====\n");

X = [48 5.1 2.1;
     50 5.3 2.4;
     51 5.4 2.5;
     53 5.7 2.8;
     55 5.8 3.0;
     56 6.0 3.1;
     58 6.2 3.5;
     60 6.3 3.6;
     61 6.5 3.8;
     63 6.7 4.0];

printf("\nMatriz X (10x3):\n");
disp(X)
mu    = mean(X);
sigma = std(X);
Z     = (X - mu) ./ sigma; % ecuación de estandarización
printf("\nMedia de cada variable [T I V]:\n");
disp(mu)
printf("\nDesviación estándar [T I V]:\n");
disp(sigma)
printf("\nMatriz estandarizada Z:\n");
disp(Z)
printf("\n===== ACTIVIDAD 2: Matriz de covarianza =====\n");
S = cov(Z); % matriz de covarianza de la matriz estandarizada Z
printf("\nMatriz de covarianza S:\n");
disp(S)

printf("\nInterpretación de la matriz de covarianza:\n");
printf("Las variables T, I y V están altamente correlacionadas entre sí, con valores cercanos a 1. Esto sugiere que hay redundancia en la información proporcionada por estas variables.\n");  % respuestas en el mismo codigo menos comins en el futuro 
printf("(~0.997), lo que indica correlación lineal positiva muy fuerte entre T, I y V.\n");


printf("\n===== ACTIVIDAD 3: Autovalores y autovectores =====\n");
[V, D] = eig(S);
printf("\nAutovectores (columnas), sin ordenar:\n");
disp(V)
printf("\nAutovalores (diagonal de D), sin ordenar:\n");
disp(diag(D)')
lambda = diag(D);                       % autovalores como vector columna
[lambda, idx] = sort(lambda, "descend"); % ordenar de mayor a menor
W = V(:, idx);                          % reordenar autovectores igual
printf("\nAutovalores ordenados (PC1, PC2, PC3):\n");
disp(lambda')

printf("\nAutovectores ordenados (columnas = PC1, PC2, PC3):\n");
disp(W)

printf("\nSuma de autovalores: %.6f\n", sum(lambda));
printf("Traza de S:          %.6f\n", trace(S));
printf("Interpretación de los autovalores:\n");
printf("Los autovalores representan la varianza explicada por cada componente principal. En este caso, el primer autovalor es significativamente mayor que los otros dos, lo que indica que la primera componente principal (PC1) captura la mayor parte de la varianza en los datos. Los otros dos autovalores son mucho menores, lo que sugiere que las componentes principales PC2 y PC3 contribuyen menos a la varianza total. Esto confirma que la mayoría de la información en los datos puede ser representada por la primera componente principal, y que las otras dos componentes principales   aportan menos información adicional.\n");    

printf("\n===== ACTIVIDAD 4: Proyección de los datos =====\n");

var_exp = lambda / sum(lambda) *100 ; % varianza explicada por cada componente principal
printf("\nVarianza explicada individual:\n");
printf("PC1: %.4f %%\n", var_exp(1));
printf("PC2: %.4f %%\n", var_exp(2));
printf("PC3: %.4f %%\n", var_exp(3));

printf("\nVarianza explicada acumulada:\n");
printf("PC1: %.4f %%\n", sum(var_exp(1)));
printf("PC2: %.4f %%\n", sum(var_exp(1:2))); % se descarta la pc3 que explica un %.4f %% de la varianza total
printf("\n teniendo en cuaneta esto podemos reducir la dimensionalidad de los datos a dos componentes principales (PC1 y PC2) sin perder demasiada información, lo que facilita el análisis y la visualización de los datos. Y responderia la pregunta de:\n");
printf(" \n¿puedo reducir de 3 a 2 sin perder una fracción importante?\n");
printf(" \n la respuesta seria que si, ya que solo se estaira perdiendo el %.4f %% de la varianza total\n", var_exp(3));
printf("\nInterpretación de la varianza explicada:\n");
printf("La primera componente principal (PC1) explica aproximadamente %.4f %% de la varianza total, lo que indica que captura la mayor parte de la información en los datos. La segunda componente principal (PC2) explica un %.4f %% adicional, y por ende descartamos la pc3 que explica un %.4f %% de la varianza total. Esto sugiere que podemos reducir la dimensionalidad de los datos a dos componentes principales (PC1 y PC2) sin perder demasiada información, lo que facilita el análisis y la visualización de los datos.\n", var_exp(1), var_exp(2), var_exp(3));

printf("\n===== ACTIVIDAD 5: Proyección sobre PC1-PC2 =====\n");
scores = Z * W(:, 1:2);
printf("\nCoordenadas de las muestras [PC1  PC2]:\n");
disp(scores)
graphics_toolkit("gnuplot");
figure;
plot(scores(:,1), scores(:,2), "bo", "MarkerFaceColor", "b");
hold on;
for k = 1:10
    text(scores(k,1), scores(k,2) + 0.01, num2str(k));
end
grid on;
xlabel("PC1 (99.80 %)");
ylabel("PC2 (0.11 %)");
title("Proyección de las 10 muestras sobre PC1-PC2");
print("pca_pc1_pc2_zoom.png", "-dpng");   % versión con ejes ajustados
axis equal;
xlim([-3 3]);
ylim([-1 1]);
print("pca_pc1_pc2.png", "-dpng", "-r150");       % versión con escala real
printf("\nInterpretación del gráfico PC1-PC2:\n");
printf("Las muestras se ordenan de la 1 a la 10 a lo largo de PC1, reflejando un\n");
printf("aumento gradual y simultáneo de T, I y V. Las muestras 1 y 10 son los extremos;\n");
printf("2 y 3 son las más próximas. La dispersión en PC2 (8, 4 y 6) parece grande por la\n");
printf("escala del eje (±0.1), pero es mínima frente a PC1 (±3), por lo que no hay atípicos.\n");
