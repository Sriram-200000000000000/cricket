#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum length {yorker, full_length, medium_length, short_length, out1, out2, out3, out4} length;
length pickinglength(int shot, length preferredlength, int *a);
typedef enum shot {cut, straight_drive, pull_shot, sweep, out5, out6, out7, out8} shot;
shot pickingshot(int length, shot preferredShot,int *b);
 
const char *team_APlayers[] = {"Virat","Rohith","Bumrah","Jadeja","Ashwin","RKRahul","HardikPandya","ShubmanGill","Siraj","SuryakumarYadav","IshanKishan"};


const char *team_BPlayers[] = 
{"Chris gayle","Brian lara","Kieron pollard","Russel","Shaihope","Nicholas","Sunilnarine","Jason","Dwayne","Shannon Gabriel","Shimron"};

void displayPlayers(const char *teamName, const char *players[]) {
    printf("Players in %s:\n", teamName);
    for (int i = 0; i < 11; i++) {
        printf("  %d. %s\n", i + 1, players[i]);
    }
}

int main() 
{
    int p=0, score1=0, score2=0, overs, n, w1=0, w2=0,t,k,a=0,b=0,i,j;
    printf("Enter no.of overs :\n");
    scanf("%d", &overs);
    char Team_A,Team_B;
    char *teams[]={"Team_A","Team_B"};
    srand(time(0)); // Seed for random number generator

    int computerTeam = rand() % 2; // 0 for Team A, 1 for Team B
    int userTeam = 1 - computerTeam;

    const char *computerTeamName = computerTeam == 0 ? "Team_A" : "Team_B";
    const char *userTeamName = userTeam == 0 ? "Team_A" : "Team_B";
    const char **computerPlayers = computerTeam == 0 ? team_APlayers : team_BPlayers;
    const char **userPlayers = userTeam == 0 ? team_APlayers : team_BPlayers;

    printf("Computer chose: %s\n", computerTeamName);
    printf("Your team is: %s\n\n", userTeamName);

    displayPlayers(computerTeamName, computerPlayers);
    displayPlayers(userTeamName, userPlayers);

    printf("\nComputer's selected players:\n");
    int computerSelected[4];
    for (int i = 0; i < 4; i++) {
        int randomIndex;
        do {
            randomIndex = rand() % 11;
        } while (memchr(computerSelected, randomIndex, i * sizeof(int)) != NULL); // Avoid duplicate selections
        computerSelected[i] = randomIndex;
        printf("  %s\n", computerPlayers[randomIndex]);
    }

    printf("\nSelect 4 players from your team by entering their numbers (1-11):\n");
    int userSelected[4];
    for (int i = 0; i < 4; i++) {
        int choice;
        do {
 	    scanf("%d",&choice);
            printf("Player %d: ", i + 1);
        } while (choice < 1 || choice > 11 || memchr(userSelected, choice - 1, i * sizeof(int)) != NULL);
        userSelected[i] = choice - 1; // Convert to zero-based index
        printf("%s\n", userPlayers[userSelected[i]]);
    }

    printf("\nTeam selection completed!\n");
    int TeamA, tossResult, decision;
    srand(time(0)); 
    printf("Choose Heads (0) or Tails (1): ");
    scanf("%d", &TeamA);

    tossResult = rand() % 2; 
    printf("Toss result: %s\n", tossResult == 0 ? "Heads" : "Tails");

    switch (tossResult == TeamA) {
        case 1: 
            printf("Team_A won the toss! Choose to Bat (0) or Bowl (1): ");
            scanf("%d", &decision);
            switch (decision) {
                case 0:
                    printf("Team_A chose to Bat first. Good luck!\n");
                    p++;
                    break;
                case 1:
                    printf("Team_A chose to Bowl first. Good luck!\n");
                    break;
                default:
                    printf("Invalid choice!\n");
            }
            

        case 0: 
            decision = rand() % 2; 
            switch (decision) {
                case 0:
                    printf("Team B won the toss and chose to Bat first.\n");
                    break;
                case 1:
                    printf("Team B won the toss and chose to Bowl first.\n");
                    p++;
                    break;
            }
            break;
    }
    for(int z=0; z<2;z++) 
    {
        if(p==1)
        {
            length lengths[] = {yorker, full_length, medium_length, short_length};
    int numlengths = sizeof(lengths) / sizeof(lengths[0]);

    for (int i = 0; i < overs; i++) 
    {
        printf("Score / Wickets : %d / %d\n\n", score1,w1);
        for (int j = 1; j <= 6; j++)  
        {
            if(w1==4)
            {
               printf("All Out");
               break;
            }
            length preferredlength = lengths[rand() % numlengths];
            length currentlength = pickinglength(t, preferredlength, &a);  // Get updated 'a' from pickinglength
            score1=score1+a;
            if (preferredlength == yorker) {
                printf("Bowler bowls yorker\n");
            }
            else if (preferredlength == full_length) {
                printf("Bowler bowls full_length\n");
            }
            else if (preferredlength == medium_length) {
                printf("Bowler bowls medium_length\n");
            }
            else if (preferredlength == short_length){
                printf("Bowler bowls short_length\n");
            }

            printf("Choose the batting shot:\n1.Cut\n2.Straight drive\n3.Pull shot\n4.Sweep\n");
            scanf("%d", &t);

            if (j == 6) {
                printf("overs %d.0: ", i + 1);
                
            } else {
                printf("overs %d.%d: ", i, j);
            }
            

            switch (t) {
                case 1:
                    switch (currentlength) {
                        case yorker:
                            printf("batsman hits a cut shot for yorker\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case full_length:
                            printf("batsman hits a cut shot for full length \n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case medium_length:
                            printf("He hits a cut for medium length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case short_length:
                            printf("he cuts for a short length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case out1:
                            printf("out for a yorker as he tried to cut it.\n");
                            w1++;
                            break;
                        case out2:
                            printf("out for a full length as he tried to cut it.\n");
                            w1++;
                            break;
                        case out3:
                            printf("out for a medium length as he tried to cut it.\n");
                            w1++;
                            break;
                        case out4:
                            printf("out for a short length as he tried to cut it.\n");
                            w1++;
                            break;
                        default:
                            printf("defended it well\n");
                             printf("runs scored on this ball : 0\n");
                            break;
                    }
                    break;

                case 2:
                    switch (currentlength) {
                        case yorker:
                            printf("batsman hits a straight drive for yorker\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case full_length:
                            printf("batsman hits a straight drive for full length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case medium_length:
                            printf("He drives it for medium length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case short_length:
                            printf("drives well for a short length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case out1:
                            printf("out for a yorker as he tried to drive it.\n");
                            w1++;
                            break;
                        case out2:
                            printf("out for a full length as he tried to drive it.\n");
                            w1++;
                            break;
                        case out3:
                            printf("out for a medium length as he tried to drive it.\n");
                            w1++;
                            break;
                        case out4:
                            printf("out for a short length as he tried to drive it.\n");
                            w1++;
                            break;
                        default:
                            printf("defended it well\n");
                             printf("runs scored on this ball : 0\n");
                            break;
                    }
                    break;

                case 3:
                    switch (currentlength) {
                        case yorker:
                            printf("batsman hits a pull shot for a yorker\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case full_length:
                            printf("batsman hits a pull shot for a full length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case medium_length:
                            printf("He pulls it for a medium length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case short_length:
                            printf("he pulls it well for a short length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case out1:
                            printf("out for a yorker as he tried to pull it.\n");
                            w1++;
                            break;
                        case out2:
                            printf("out for a full length as he tried to pull it.\n");
                            w1++;
                            break;
                        case out3:
                            printf("out for a medium_length as he tried to pull it.\n");
                            w1++;
                            break;
                        case out4:
                            printf("out for a short_length as he tried to pull it.\n");
                            w1++;
                            break;
                        default:
                            printf("defended it well\n");
                             printf("runs scored on this ball : 0\n");
                            break;
                    }
                    break;

                case 4:
                    switch (currentlength) {
                        case yorker:
                            printf("batsman hits a sweep shot for a yorker\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case full_length:
                            printf("batsman hits a sweep shot for full length \n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case medium_length:
                            printf("He sweeps for a medium length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case short_length:
                            printf("swept well for a short length\n");
                            printf("runs scored on this ball : %d\n", a);
                            break;
                        case out1:
                            printf("out for a yorker as he tried to sweep.\n");
                            w1++;
                            break;
                        case out2:
                            printf("out for a full length as he tried to sweep it.\n");
                            w1++;
                            break;
                        case out3:
                            printf("out for a medium_length as he tried to sweep it.\n");
                            w1++;
                            break;
                        case out4:
                            printf("out for a short_length as he tried to sweep it.\n");
                            w1++;
                            break;

                        default:
                            printf("defended it well\n");
                            printf("runs scored on this ball : 0\n");
                            break;
                    }
                    break;

                default:
                    printf("defended it well\n");
                     printf("runs scored on this ball : 0\n");
                    break;
            }
        }
        if(w1==4)
            {
               printf("All Out\n");
               break;
            }
    }

    printf("Total Score / Wickets : %d / %d \n\n", score1,w1);
    if(w1==4)
            {
               printf("All Out\n");
            }
            printf("Innings Completed\n");
            p=0;
        }
         if(p==0)
     {
          shot shots[] = {cut, straight_drive, pull_shot, sweep};
    int numShots = sizeof(shots) / sizeof(shots[0]);

    for (int i = 0; i < overs; i++) 
    {
        printf("Score / Wickets : %d / %d\n\n", score2,w2);
        for (int j = 1; j <= 6; j++) 
        {
             if(w2==4)
            {
               printf("All Out \n");
               break;
            }
            printf("Choose the bowling length:\n1.Yorker\n2.Full\n3.Medium\n4.Short\n ");
            scanf("%d",&k);
             shot preferredShot = shots[rand() % numShots];
            shot currentShot = pickingshot(k, preferredShot,&b);
             score2=score2+b;
            if(j==6)
            {
                printf("overs %d.0: ",i+1);
            }
            else
            {
            printf("overs %d.%d: ", i, j);
            }
            switch(k)
            {
            case 1:
                switch (currentShot)
                {
                case cut:
                    printf("batsman hits a cut shot for a yorker\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case straight_drive:
                    printf("batsman hits a straight drive for a yorker\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case pull_shot:
                    printf("He pulls it for a yorker and scored \n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case sweep:
                    printf("swept well for a yorker\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case out5:
                    printf("out for a yorker cause he tried to pull it.\n");
                    w2++;
                    break;
                case out6:
                    printf("out for a yorker as he tried to cut it.\n");
                    w2++;
                    break;
                case out7:
                    printf("out for a yorker as he tried to drive it straight.\n");
                    w2++;
                    break;
                case out8:
                    printf("out for a yorker as he tried to sweep it.\n");
                    w2++;
                    break;
                default:
                    printf("defended it well for a yorker\n");
                    printf("runs scored on this ball : 0\n");
                    break;
                }
                break;

            case 2:
                switch (currentShot)
                {
                case cut:
                    printf("batsman hits a cut shot for a full length ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case straight_drive:
                    printf("batsman hits a straight drive for a full length ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case pull_shot:
                    printf("He pulls it for a full length ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case sweep:
                    printf("swept well for a full length ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case out5:
                    printf("out for a full length ball cause he tried to pull it.\n");
                    w2++;
                    break;
                case out6:
                    printf("out for a full length ball as he tried to cut it.\n");
                    w2++;
                    break;
                case out7:
                    printf("out for a full length ball as he tried to drive it straight.\n");
                    w2++;
                    break;
                case out8:
                    printf("out for a full length ball as he tried to sweep it.\n");
                    w2++;
                    break;
                default:
                    printf("defended it well for a full length ball\n");
                     printf("runs scored on this ball : 0\n");
                    break;
                }
                break;

            case 3:
                switch (currentShot)
                {
                case cut:
                    printf("batsman hits a cut shot for a length ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case straight_drive:
                    printf("batsman hits a straight drive for a length ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case pull_shot:
                    printf("He pulls it for a length ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case sweep:
                    printf("swept well for a length ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case out5:
                    printf("out for a medium length ball as he tried to pull it.\n");
                    w2++;
                    break;
                case out6:
                    printf("out for a medium length ball as he tried to cut it.\n");
                    w2++;
                    break;
                case out7:
                    printf("out for a medium length ball as he tried to drive it straight.\n");
                    w2++;
                    break;
                case out8:
                    printf("out for a medium length ball as he tried to sweep it.\n");
                    w2++;
                    break;
                default:
                    printf("defended it well for a length ball\n");
                     printf("runs scored on this ball : 0\n");
                    break;
                }
                break;

            case 4:
                switch (currentShot)
                {
                case cut:
                    printf("batsman hits a cut shot for a short ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case straight_drive:
                    printf("batsman hits a straight drive for a short ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case pull_shot:
                    printf("He pulls it for a short ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case sweep:
                    printf("swept well for a short ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case out5:
                    printf("out for a short ball as he tried to pull it.\n");
                    w2++;
                    break;
                case out6:
                    printf("out for a short ball as he tried to cut it.\n");
                    w2++;
                    break;
                case out7:
                    printf("out for a short ball as he tried to drive it straight.\n");
                    w2++;
                    break;
                case out8:
                    printf("out for a short ball as he tried to sweep it.\n");
                    w2++;
                    break;
                default:
                    printf("defended it well for a short ball\n");
                     printf("runs scored on this ball : 0\n");
                    break;
                }
                break;

            default:
                switch (currentShot)
                {
                case cut:
                    printf("batsman hits a cut shot for a full length ball\n");
                    printf("runs scored on this ball : %d\n", b);
                    break;
                case straight_drive:
                    printf("batsman hits a straight drive for a full length ball\n");
                     printf("runs scored on this ball : %d\n", b);
                    break;
                case pull_shot:
                    printf("He pulls it for a full length ball\n");
                     printf("runs scored on this ball : %d\n", b);
                    break;
                case sweep:
                    printf("swept well for a full length ball\n");
                     printf("runs scored on this ball : %d\n", b);
                    break;
                case out5:
                    printf("out for a full length ball cause he tried to pull it.\n");
                    w2++;
                    break;
                case out6:
                    printf("out for a full length ball as he tried to cut it.\n");
                    w2++;
                    break;
                case out7:
                    printf("out for a full length ball as he tried to drive it straight.\n");
                    w2++;
                    break;
                case out8:
                    printf("out for a full length ball as he tried to sweep it.\n");
                    w2++;
                    break;
                default:
                    printf("defended it well for a full length ball\n");
                     printf("runs scored on this ball : 0\n");
                    break;
                }
                break;
            }
        }
        if(w2==4)
            {
               printf("All Out\n");
               break;
            }
    }
    
    printf("Total Score / Wickets %d / %d\n", score2, w2);
            if(w2==4)
            {
               printf(" All Out\n");
            }
            printf("Innings Completed\n");
        }
    }
    if(score1<score2)
    {
        printf("won");
    }
    else if (score1>score2)
    {
        printf("lost");

    }
    else
    {
        printf("tie");
    }
    
return 0;
}

length pickinglength(int shot, length preferredlength, int *a) 
{
    int randNum = rand() % 10;

    // Example logic for handling different shots and lengths
    if ((shot == 1 && preferredlength == yorker)) {
        if (randNum < 2)
         {
            *a=0;
            return out1; // 50% chance of getting out
            
        }
        else
        *a = rand() % 3;  // Update 'a' and return the new value
    }
    else if ((shot == 2 && preferredlength == yorker)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 40% chance of getting out
            
        }
        else
        *a = rand() % 2;  // Update 'a' and return the new value
    }
    else if ((shot == 3 && preferredlength == yorker)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 40% chance of getting out
            
        }
        else
        *a = rand() % 2;  // Update 'a' and return the new value
    }
    else if ((shot == 4 && preferredlength == yorker)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 40% chance of getting out
        }
        else
        *a = rand() % 3;  // Update 'a' and return the new value
    }


    if ((shot == 1 && preferredlength == full_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 30% chance of getting out
        }
        else
        *a = rand() % 4;  // Update 'a' and return the new value
    }
    else if ((shot == 2 && preferredlength == full_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 20% chance of getting out
        }
        else
        *a = rand() % 6;  // Update 'a' and return the new value
    }
    else if ((shot == 3 && preferredlength == full_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 20% chance of getting out
        }
        else
        *a = rand() % 2;  // Update 'a' and return the new value
    }
    else if ((shot == 4 && preferredlength == full_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 20% chance of getting out
        }
        else
        *a = rand() % 6;  // Update 'a' and return the new value
    }
    
    if ((shot == 1 && preferredlength == medium_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 10% chance of getting out
        }
        else
        *a = rand() % 4;  // Update 'a' and return the new value
    }
    else if ((shot == 2 && preferredlength == medium_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 5% chance of getting out
        }
        else
        *a = rand() % 4;  // Update 'a' and return the new value
    }
    else if ((shot == 3 && preferredlength == medium_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 5% chance of getting out
        }
        else
        *a = rand() % 6;  // Update 'a' and return the new value
    }
    else if ((shot == 4 && preferredlength == medium_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 5% chance of getting out
        }
        else
       *a = rand() % 3;  // Update 'a' and return the new value
    }


    if ((shot == 1 && preferredlength == short_length)) {
        if (randNum < 2) {
            *a=0;
            return out1; // 10% chance of getting out
        }
        else
        *a = rand() % 3;  // Update 'a' and return the new value
    }
    else if ((shot == 2 && preferredlength == short_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 5% chance of getting out
        }
        else
        *a = rand() % 2;  // Update 'a' and return the new value
    }
    else if ((shot == 3 && preferredlength == short_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 5% chance of getting out
             
        }
        else
        *a = rand() % 6;  // Update 'a' and return the new value
    }
    else if ((shot == 4 && preferredlength == short_length)) {
        if (randNum < 2) {
             *a=0;
            return out1; // 5% chance of getting out
        }
        else
        *a = rand() % 3;  // Update 'a' and return the new value
    }
    return preferredlength;
    
}


shot pickingshot(int length, shot preferredShot,int  *b)
{
    

    if ((length == 1 && preferredShot == pull_shot))
    {
        int randNum = rand() % 10;
        if (randNum < 5)
        {
            *b=0;
            return out5; // 50% chance of getting out

        }
        else
        *b = rand() % 2;
    }
    else if ((length == 2 && preferredShot == pull_shot))
    {
        int randNum = rand() % 10;
        if (randNum < 4)
        {
            *b=0;
            return out5; // 40% chance of getting out
        }
        else
        *b = rand() % 2;
        
    }
    else if ((length == 3 && preferredShot == pull_shot))
    {
        int randNum = rand() % 10;
        if (randNum < 2)
        {
            *b=0;
            return out5; // 20% chance of getting out
        }
        else
        *b = rand() % 5; 
    }
    else if ((length == 4 && preferredShot == pull_shot))
    {
        int randNum = rand() % 10;
        if (randNum < 1)
        {
            *b=0;
            return out5; // 10% chance of getting out
        }
        else
        *b = rand() % 6;
    }


    if ((length == 1 && preferredShot == cut))
    {
        int randNum = rand() % 10;
        if (randNum < 2)
        {
            *b=0;
            return out6; // 20% chance of getting out
        }
        else
        *b = rand() % 2; 
    }
    else if ((length == 2 && preferredShot == cut))
    {
        int randNum = rand() % 10;
        if (randNum < 3)
        {
            *b=0;
            return out6; // 30% chance of getting out
        }
        else
        *b = rand() % 4;
    }
    else if ((length == 3 && preferredShot == cut))
    {
        int randNum = rand() % 10;
        if (randNum < 1)
        {
            *b=0;
            return out6; // 10% chance of getting out
        }
        else
        *b = rand() % 4;
    }
    else if ((length == 4 && preferredShot == cut))
    {
        int randNum = rand() % 10;
        if (randNum < 1)
        {
            *b=0;
            return out6; // 10% chance of getting out
        }
        else
        *b = rand() % 3;
    }
    if ((length == 1 && preferredShot == straight_drive))
    {
        int randNum = rand() % 10;
        if (randNum < 5)
        {
            *b=0;
            return out7; // 50% chance of getting out
        }
        else
        *b = rand() % 2;    
    }
    else if ((length == 2 && preferredShot == straight_drive))
    {
        int randNum = rand() % 10;
        if (randNum < 4)
        {
            *b=0;
            return out7; // 40% chance of getting out
        }
        else
        *b = rand() % 6;
        
    }
    else if ((length == 3 && preferredShot == straight_drive))
    {
        int randNum = rand() % 10;
        if (randNum < 2)
        {
            *b=0;
            return out7; // 20% chance of getting out
        }
        else
        *b = rand() % 4; 
    }
    else if ((length == 4 && preferredShot == straight_drive))
    {
        int randNum = rand() % 10;
        if (randNum < 1)
        {
            *b=0;
            return out7; // 10% chance of getting out
        }
        else
        *b = rand() % 2;
    } 

    if ((length == 1 && preferredShot == sweep))
    {
        int randNum = rand() % 10;
        if (randNum < 5)
        {
            *b=0;
            return out8; // 50% chance of getting out
        }
        else
        *b = rand() % 4;    
    }
    else if ((length == 2 && preferredShot == sweep))
    {
        int randNum = rand() % 10;
        if (randNum < 4)
        {
            *b=0;
            return out8; // 40% chance of getting out
        }
        else
        *b = rand() % 6;
        
    }
    else if ((length == 3 && preferredShot == sweep))
    {
        int randNum = rand() % 10;
        if (randNum < 2)
        {
            *b=0;
            return out8; // 20% chance of getting out
        }
        else
        *b = rand() % 3; 
    }
    else if ((length == 4 && preferredShot == sweep))
    {
        int randNum = rand() % 10;
        if (randNum < 1)
        {
            *b=0;
            return out8; // 10% chance of getting out
        }
        else
        *b = rand() % 2;
    }
    return preferredShot; // Default: return the preferred shot
}

    
