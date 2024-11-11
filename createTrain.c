#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char destination[30];
    int trainNumber;
    int departureHour;
    int departureMinute;
} Train;

void writeTrainData(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Ошибка при открытии файла для записи.\n");
        return;
    }

    Train trains[8] = {
        {"Moscow", 101, 12, 30},
        {"Saint Petersburg", 102, 13, 45},
        {"Kazan", 103, 15, 00},
        {"Sochi", 104, 17, 15},
        {"Vladivostok", 105, 18, 00},
        {"Novosibirsk", 106, 19, 20},
        {"Ekaterinburg", 107, 20, 50},
        {"Krasnoyarsk", 108, 22, 10}
    };

    size_t writeCount = fwrite(trains, sizeof(Train), 8, file);
    if (writeCount != 8) {
        printf("Ошибка записи данных в файл.\n");
    } else {
        printf("Файл %s создан и данные успешно записаны.\n", filename);
    }

    fclose(file);
}

int main() {
    const char *filename = "traind.dat";
    writeTrainData(filename);
    return 0;
}

