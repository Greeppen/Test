#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char destination[30];
    int number;
    int departHour;
    int departMin;
} Train;

void searchTrains(const char *filename, int hour, int minute){
    FILE *file = fopen(filename,"rb");
    if (!file){
        printf("Error to open file! \n");
        return;
    }

    Train train;
    int found = 0;
    printf("Trains deparding after %02d:%02d \n", hour, minute);
    while (fread(&train, sizeof(Train),1,file)==1){
        if (train.departHour > hour || train.departHour == hour && train.departMin > minute){
            printf("Destination: %s Train number %d Departure Time: %02d:%02d\n", train.destination, train.number, train.departHour, train.departMin);
            found = 1;
        }
    }
    if (!found){
        printf("TThere are no trains leaving after %02d:%02d, \n", hour,minute);
    }
    fclose(file);
}

int main(){
    const char *filename = "traind.dat";
    int hour, minute;
    printf("Enter departure time (hours and minutes): \n");
    scanf("%d %d", &hour, &minute);

    searchTrains(filename,hour,minute);
    return 0;
}
