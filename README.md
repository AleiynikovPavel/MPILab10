# MPILab10

### Задание (вариант 6)
Реализовать сбор данных с n процессов с помощью двухточечных обменов (каждый процесс посылает заранее заданное количество значений).Эффективность реализации сравнить с функцией MPI_Gatherv(). 
## Двухточечных обменов 
### Сборка
`mpic++ -o main  main.cpp`
### Запуск
`pirun -np 10 --oversubscribe  main`
### Вывод программы

<details>
  
```
Result: Time=5.170876e-05
My rank 0
My rank 1
My rank 2
My rank 3
My rank 4
My rank 5
My rank 6
My rank 7
My rank 8
My rank 9

```
</details>

## Обменов через MPI_Gatherv 
### Сборка
`mpic++ -o main2  main2.cpp`
### Запуск
`pirun -np 10 --oversubscribe  main2`
### Вывод программы

<details>
  
```
Result: Time=4.576350e-06
My rank 0
My rank 1
My rank 2
My rank 3
My rank 4
My rank 5
My rank 6
My rank 7
My rank 8
My rank 9

```
</details>

