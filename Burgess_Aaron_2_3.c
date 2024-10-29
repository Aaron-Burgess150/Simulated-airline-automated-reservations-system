/*
COP3223 Fall 2024 Assignment 2.3
Copyright 2024 Burgess Aaron
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int search_seat(int section, int seats[]);
void print_boarding_pass(int section, int seat_number);

int main(){
    //variables
    int seats[6] = {0};
    int section, boarded, seat_number, change = 0;
    bool all_boarded_first = false;
    bool all_boarded_econ = false;
    bool run_switch = true;

    do{
        srand(time(NULL));

        if (seats[0] == 1 && seats[1] == 1 && seats[2] == 1){
            all_boarded_first = true;
        }

        if (seats[3] == 1 && seats[4] == 1 && seats[5] == 1){
            all_boarded_econ = true;
        }

        printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"\n");
        scanf("%d", &section);

        //checking whether there are seats
        if (all_boarded_first && all_boarded_econ){
            printf("Next flight leaves in 3 hours\n");
            run_switch = false;
        }

        //running function to assign seats
        if (run_switch){
            switch (section){
            case 1:
                int change = 0;
                if (all_boarded_first && all_boarded_econ){
                    printf("Next flight leaves in 3 hours\n");
                    break;
                }
                else if (all_boarded_first){
                    printf("no seat available in first class, do you want a seat in economy? ");
                    scanf("%d", &change);
                    if (change == 1){
                        section = 2;
                        seat_number = search_seat(section, seats);
                        print_boarding_pass(section, seat_number);
                        break;
                    }
                    else if (change == 0){
                        printf("Next flight leaves in 3 hours\n");
                        break;
                    }
                    else{
                        printf("");
                        break;
                    }
                }
                seat_number = search_seat(section, seats);
                print_boarding_pass(section, seat_number);
                break;
            case 2:
                change = 0;
                if (all_boarded_econ && all_boarded_first){
                    printf("Next flight leaves in 3 hours\n");
                    break;
                }
                else if (all_boarded_econ){
                    printf("no seat available in economy, do you want a seat in first class? ");
                    scanf("%d", &change);
                    if (change == 1){
                        section = 1;
                        seat_number = search_seat(section, seats);
                        print_boarding_pass(section, seat_number);
                        break;
                    }
                    else if (change == 0){
                        printf("Next flight leaves in 3 hours\n");
                        break;
                    }
                    else{
                        printf("");
                        break;
                    }
                }
                seat_number = search_seat(section, seats);
                print_boarding_pass(section, seat_number);
                break;
            default:
                printf("");
            }
        }

        //asking if everyone is boarded to see if the program needs to be run again
        printf("Is everyone boarded? ");
        scanf("%d", &boarded);
    }while (boarded == 0);
}

int search_seat(int section, int seats[]){ //returns seat number
        int r_index = 0;
        if (section == 1){
            r_index = rand() % 3; //0-2

            //randomizing seat number to available seat
            if (seats[r_index] == 1){
                do{
                    r_index = rand() % 3;
                } while (seats[r_index] == 1);
            }
            seats[r_index] = 1;
            return r_index + 1;
        }
        else if (section == 2){
            r_index = rand() % 3 + 3; //3-5

            //randomizing seat number to available seat
            if (seats[r_index] == 1){
                do {
                    r_index = rand() % 3 + 3;
                } while (seats[r_index] == 1);
            }
            seats[r_index] = 1;
            return r_index + 1;
        }
        else{
            return -1;
        }

}

void print_boarding_pass(int section, int seat_number){
    if (section == 1){
        printf("Your seat is assigned to first class %d\n", seat_number);
    }
    else if (section == 2){
        printf("Your seat is assigned to economy %d\n", seat_number);
    }
    else{
        printf("");
    }
}
