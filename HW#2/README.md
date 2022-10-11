# HW#2

1. Реализовать классическое перемножение матриц и умножение матрицы на вектор на C/C++ с разным порядком циклов (25\%) +
2.  Разбейте на модули, со статической линковкой скомпилируйте текст, подготовьте Makefile, проверьте флаги -g,  -O3  (25\%) +
3. Измерьте времена исполнения для размеров $N = 500, 512, 1000, 1024, 2000, 2048$  (25\%) +
Файлы находятся в папке /matmul
```
500 
Vector to matrix 
average runtime ij 0.000079 seconds 
average runtime ji 0.000145 seconds 
----------------------------------
Matrix to matrix 
average runtime ijk 0.112964 seconds 
average runtime jik 0.111784 seconds 
average runtime kij 0.026593 seconds 
----------------------------------
512 
Vector to matrix 
average runtime ij 0.000037 seconds 
average runtime ji 0.000940 seconds 
----------------------------------
Matrix to matrix 
average runtime ijk 0.140280 seconds 
average runtime jik 0.146586 seconds 
average runtime kij 0.026500 seconds 
----------------------------------
1000 
Vector to matrix 
average runtime ij 0.000128 seconds 
average runtime ji 0.000443 seconds 
----------------------------------
Matrix to matrix 
average runtime ijk 0.910558 seconds 
average runtime jik 0.923641 seconds 
average runtime kij 0.252196 seconds 
----------------------------------
1024 
Vector to matrix 
average runtime ij 0.000141 seconds 
average runtime ji 0.004897 seconds 
----------------------------------
Matrix to matrix 
average runtime ijk 1.740733 seconds 
average runtime jik 1.800891 seconds 
average runtime kij 0.309521 seconds 
----------------------------------
2000 
Vector to matrix 
average runtime ij 0.000882 seconds 
average runtime ji 0.003454 seconds 
----------------------------------
Matrix to matrix 
average runtime ijk 8.550918 seconds 
average runtime jik 7.742696 seconds 
average runtime kij 2.028460 seconds 
----------------------------------
2048 
Vector to matrix 
average runtime ij 0.001234 seconds 
average runtime ji 0.025211 seconds 
----------------------------------
Matrix to matrix
average runtime kij 2.160248 seconds 
```
Для N=2048 удалось посчитать только kji порядок

4. И базовые скрипты баш +
Файлы находятся в папке /scripts
