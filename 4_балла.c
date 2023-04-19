#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <signal.h>
#define MAX_PAINTINGS 100
#define MAX_VISITORS 100
#define SIZE sizeof(int[MAX_PAINTINGS])

sem_t *sem_gallery;
int *shm_gallery;
int visitors, paintings;

void cleanup() {
    sem_close(sem_gallery);
    sem_unlink("/gallery_sem");
    munmap(shm_gallery, SIZE);
}

void sigint_handler(int signum) {
    cleanup();
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error line command arguments\n");
        return 1;
    }
  
    //Установка обработчика на сигнал SIGINT(при нажатии Ctrl+C), чтобы программа корректно завершила работу
    signal(SIGINT, sigint_handler);
    
    //Аргументы командной строки
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");
    if (!input_file || !output_file) {
        printf("Error opening files\n");
        return 1;
    }

    fscanf(input_file, "%d %d", &visitors, &paintings);
    printf("Number of visitors: %d\nNumber of paintings: %d\n", visitors, paintings);

    //Создание области разделяемой памяти
    shm_gallery = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shm_gallery == MAP_FAILED) {
        printf("Error mapping shared memory\n");
        return 1;
    }

    //Открытие/создание именованного семафора
    sem_gallery = sem_open("/gallery_sem", O_CREAT | O_EXCL, 0666, MAX_VISITORS);
    if (sem_gallery == SEM_FAILED) {
        printf("Error creating semaphore\n");
        return 1;
    }

    for (int i = 1; i <= paintings; i++) {
        shm_gallery[i] = 0;
    }

    pid_t pid;
    for (int i = 1; i <= visitors; i++) {
        pid = fork();
        if (pid < 0) {    //Дочерний процесс
            printf("Error creating child process\n");
            return 1;
        } else if (pid == 0) {    //Родительский процесс
            for (int j = 1; j <= paintings; j++) {
                usleep(rand() % 1000);    //Приостановка текущего процесса на заданное количество микросекунд
                sem_wait(sem_gallery);    //Выполнение операции блокировки семафора
                if (shm_gallery[j] >= MAX_VISITORS) {
                    printf("Visitor %d waiting for painting %d\n", i, j);
                    while (shm_gallery[j] >= MAX_VISITORS);
                }
                shm_gallery[j]++;
                printf("Visitor %d viewing painting %d (total viewers: %d)\n", i, j, shm_gallery[j]);
                fprintf(output_file, "Visitor %d viewed painting %d (total viewers: %d)\n", i, j, shm_gallery[j]);
                sem_post(sem_gallery);    //Освобождение семафора
            }
            exit(0);
        }
    }

    //Завершение всех дочерних процессов
    for (int i = 1; i <= visitors; i++) {
        wait(NULL);
    }

    //Освобождение ресурсов
    cleanup();
  
    //Закрытие файлов
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}
