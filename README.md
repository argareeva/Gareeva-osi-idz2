# Gareeva-osi-idz2

## Гареева Альбина БПИ218, Вариант 18
Задача о картинной галерее.  
Вахтер–процесс следит за тем, чтобы в картинной галерее одновременно было не более 50 процессов–посетителей.  
Для обозрения представлены 5 картин. Посетитель случайным образом ходит от картины к картине, и если на картину любуются более чем десять посетителей, он стоит в стороне и ждет, пока число желающих увидеть картину не станет меньше.
Посетитель может покинуть галерею, когда просмотрит все картины. В галерею также пытаются постоянно зайти новые посетители, которые ожидают своей очереди, если та заполнена. Создать приложение, моделирующее однодневную работу картинной галереи.  
Время нахождения возле картины для каждого посетителя является случайной величиной в некотором диапазоне.
Для задания имен входного и выходного файлов используются аргументы командной строки.  
Все тестовые файлы находятся в папке [tests](https://github.com/argareeva/Gareeva-osi-idz2/tree/main/tests)


## 4 балла
Разработано консольное приложение, в котором единый родительский процесс запускает требуемое число дочерних процессов.  
Множество процессов взаимодействуют с использованием именованных POSIX семафоров.  
Обмен данными ведется через разделяемую память в стандарте POSIX.

Код находится в [4_балла.c](https://github.com/argareeva/Gareeva-osi-idz2/blob/main/4_%D0%B1%D0%B0%D0%BB%D0%BB%D0%B0.c)   
В примечаниях описана схема решаемой задачи

## 5 баллов
Разработано консольное приложение, в котором единый родительский процесс запускает требуемое число дочерних процессов.  
Множество процессов взаимодействуют с использованием неименованных POSIX семафоров расположенных в разделяемой памяти.  
Обмен данными также ведется через разделяемую память в стандарте POSIX

Код находится в [5_баллов.c](https://github.com/argareeva/Gareeva-osi-idz2/blob/main/5_%D0%B1%D0%B0%D0%BB%D0%BB%D0%BE%D0%B2.c)  
В примечаниях описана схема решаемой задачи

## 6 баллов
Разработано консольное приложение, в котором единый родительский процесс запускает требуемое число дочерних процессов.  
Множество процессов взаимодействуют с использованием семафоров в стандарте UNIX SYSTEM V.  
Обмен данными ведется через разделяемую память в стандарте UNIX SYSTEM V.  

Код находится в [6_баллов.c](https://github.com/argareeva/Gareeva-osi-idz2/blob/main/6_%D0%B1%D0%B0%D0%BB%D0%BB%D0%BE%D0%B2.c)  
В примечаниях описана схема решаемой задачи

## 7 баллов
Разработано приложение, состоящее из отдельных программ–процессов, запускаемых независимо друг от друга.  
С использованием семафоров и разделяемой памяти организовать между ними взаимодействие.  
Множество независимых процессов взаимодействуют с использованием именованных POSIX семафоров.  
Обмен данными ведется через разделяемую память в стандарте POSIX.

Код находится в [7_баллов.c](https://github.com/argareeva/Gareeva-osi-idz1/blob/43c6e2b619b523f0a33f071eb50376ea8058ab96/7_%D0%B1%D0%B0%D0%BB%D0%BB%D0%BE%D0%B2.c)  
В примечаниях описана схема решаемой задачи

## 8 баллов
Разработано приложение, состоящее из отдельных программ–процессов, запускаемых независимо друг от друга.  
С использованием семафоров и разделяемой памяти организовать между ними взаимодействие.  
Множество независимых процессов взаимодействуют с использованием семафоров в стандарте UNIX SYSTEM V.  
Обмен данными ведется через разделяемую память в стандарте UNIX SYSTEM V.  

Код находится в [8_баллов.c](https://github.com/argareeva/Gareeva-osi-idz1/blob/43c6e2b619b523f0a33f071eb50376ea8058ab96/8_%D0%B1%D0%B0%D0%BB%D0%BB%D0%BE%D0%B2.c)  
В примечаниях описана схема решаемой задачи
