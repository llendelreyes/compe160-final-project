//
//  main.c
//  Final Project 2
//
//  Created by Llendel Reyes on 4/25/16.
//  Copyright © 2016 Llendel Reyes. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pointsTouchdowns(int numTD) {  //Calculates fantasy points for rushing and recieving touchdowns
    int pointsTouchdown = 0;
    
    pointsTouchdown = 6 * numTD;
    
    return pointsTouchdown;
}


int pointsYards(int numYards) {
    int i;                        //Calculates amount of fantasy points for rushing yards and recieving yards
    int pointsYards = 0;
    
    for (i = 0; i <= numYards; i++) {
        if(i % 10 == 0) {
            pointsYards = 1 + pointsYards;
        }
        else if (numYards <= 9) {
            pointsYards = 0;
        }
    }
    int* temp = &pointsYards;
    //return pointsYards;
    return *temp;
}

int pointsConversions(int numConversions) {
    //Calculates fantasy points from 2-point conversions
    int pointsConversions = 0;
    
    
    pointsConversions = numConversions * 2;
    
    return pointsConversions;
}

int pointsTDpass(int numTDpass) {
    //Calculates fantasy points from TD passes
    int pointsTDpass = 0;
    
    pointsTDpass = numTDpass * 4;
    
    return pointsTDpass;
}

int pointsPassYards(int numPassYards) {    //Calculates fantasy points from passing yards
    int i;
    int pointsPassYards = 0;
    
    for (i = 0; i <= numPassYards; i++) {
        if (i % 25 == 0) {
            pointsPassYards = 1 + pointsPassYards;
        }
        else if (numPassYards <= 24) {
            pointsPassYards = 0;
        }
    };
    
    return pointsPassYards;
}

int pointsTurnovers(int numTurnovers) {     //Calculates fantasy points from turnovers
    int pointsTurnovers = 0;
    
    pointsTurnovers = numTurnovers * -2;
    
    return pointsTurnovers;
}


int main(int argc, char** argv) {
    char userPosition[50];
    char userPlayer[50];
    
    char* position[4];
    position[0] = "Quarterback\n";
    position[1] = "Running Back\n";
    position[2] = "Wide Receiver\n";
    position[3] = "Tight End\n";
    
    char userPosition1[] = "Quarterback\n";
    char userPosition2[] = "Running Back\n";
    char userPosition3[] = "Wide Reciever\n";
    char userPosition4[] = "Tight End\n";
    
    FILE* in = fopen(argv[1], "r");
    
    /*if(in != 0)
     {
     printf("Invalid file name\n");
     exit(0);
     }*/
    
    //fgets(userPosition, 64, in);
    
    //printf("Enter Player Position:");
    fgets(userPosition, 50, in);
    //printf("Enter Player Name:");
    fgets(userPlayer, 50, in);
    int numPassYards, numPassTD, numRushYards, numRushTD, numRecYards, numRecTDs, numTurnovers, numConversions, totalPoints = 0;
    
    if(strcmp(userPosition, position[0]) == 0) {
        printf("Enter passing yards:\n");
        fscanf(in, "%d", &numPassYards);
        printf("Enter passing touchdowns:\n");
        fscanf(in, "%d", &numPassTD);
        printf("Enter rushing yards:\n");
        fscanf(in, "%d", &numRushYards);
        printf("Enter rushing touchdowns:\n");
        fscanf(in, "%d", &numRushTD);
        printf("Enter number of turnovers:\n");
        fscanf(in, "%d", &numTurnovers);
        printf("Enter number of 2-pt Conversions:\n");
        fscanf(in, "%d", &numConversions);
        printf("\n");
        
        printf("PassYards PassTD RushYards RushTD TOs 2-pt\n");
        printf("--------- ------ --------- ------ --- ----\n");
        printf("%d        %d      %d       %d     %d  %d\n", numPassYards, numPassTD, numRushYards, numRushTD, numTurnovers, numConversions);
        
        printf("\n");
        
        totalPoints = pointsPassYards(numPassYards) + pointsTDpass(numPassTD) + pointsYards(numRushYards) + pointsTouchdowns(numRushTD) + pointsTurnovers(numTurnovers) + pointsConversions(numConversions);
        
        printf("%s has scored %d fantasy points.\n", userPlayer, totalPoints);
        
        
    }
    else if(strcmp(userPosition, position[1]) == 0) {
        
        printf("Enter rushing yards:\n");
        scanf("%d", &numRushYards);
        printf("Enter rushing touchdowns:\n");
        scanf("%d", &numRushTD);
        printf("Enter recieving yards:\n");
        scanf("%d", &numRecYards);
        printf("Enter recieving touchdowns:\n");
        scanf("%d", &numRecTDs);
        printf("Enter number of turnovers:\n");
        scanf("%d", &numTurnovers);
        printf("Enter number of 2-pt Conversions:\n");
        scanf("%d", &numConversions);
        printf("\n");
        
        printf("RushYards RushTD RecYards RecTD TOs 2-pt\n");
        printf("--------- ------ -------- ----- --- ----\n");
        printf("%d        %d     %d       %d    %d   %d\n", numRushYards, numRushTD, numRecYards, numRecTDs, numTurnovers, numConversions);
        
        printf("\n");
        
        totalPoints = pointsYards(numRushYards) + pointsTouchdowns(numRushTD) + pointsYards(numRecYards) + pointsTouchdowns(numRecYards) + pointsTurnovers(numTurnovers) + pointsConversions(numConversions);
        printf("%s has scored %d fantasy points.\n", userPlayer, totalPoints);
        
    }
    
    else if((strcmp(userPosition, position[2]) == 0) || (strcmp(userPosition, userPosition4) == 0)) {
        
        printf("Enter recieving yards:\n");
        scanf("%d", &numRecYards);
        printf("Enter recieving touchdowns:\n");
        scanf("%d", &numRecTDs);
        printf("Enter number of turnovers:\n");
        scanf("%d", &numTurnovers);
        printf("Enter number of 2-pt Conversions:\n");
        scanf("%d", &numConversions);
        printf("\n");
        
        printf("RecYards RecTD TOs 2-pt\n");
        printf("-------- ----- --- ----\n");
        printf("%d       %d    %d  %d\n", numRecYards, numRecTDs, numTurnovers, numConversions);
        printf("\n");
        
        totalPoints = pointsYards(numRecYards) + pointsTouchdowns(numRecTDs) + pointsTurnovers(numTurnovers) + pointsConversions(numConversions);
        
        printf("%s has scored %d fantasy points.\n", userPlayer, totalPoints);
        
    }
    else if(strcmp(userPosition, userPosition1) || strcmp(userPosition, userPosition2) || strcmp(userPosition, userPosition3) || strcmp(userPosition, position[3]) != 0) {
        printf("Invalid Position. Enter 'Quarterback','Running Back','Wide Reciever', or 'Tight End' only.\n");
    }
    
    
    return 0;
}
