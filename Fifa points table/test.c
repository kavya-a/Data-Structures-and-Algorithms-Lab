/* Program to replicate the FIFA world cup points table */
#include<stdio.h>
#include<math.h>
#include<string.h>

#include<ctype.h>

/*Declaring all user defined functions */
void input(int , int);
void display(int);
void populate(int);
void sort(int);
void exchange(int , int);

/*Defining the structure */
struct team
{
    char name[50];
    int teamno;
    int played;
    int won;
    int lost;
    int draw;
    int points;
    int goaldiff;

}teams[10];

main()
{
    int choice,count,Team1,Team2,team_num = -1 ,i, populate_check = -1, populate_flag;

    printf("Group D FIFA world cup 2014");

    do
    {
        printf("\n\n1.Enter team details\n2.Enter match details\n3.Display group table\n4.Exit\n\n");
        printf("\nEnter choice:  ");
        scanf("%d",&choice);
        printf("\n\n\n");

        switch(choice)
        {

            case 1: if(populate_check == 0)
                       {
                           printf("Are you sure you want to overwrite all values in existing table?\n\n1.Yes\n2.No\n\n");
                           scanf("%d", &populate_flag);


                       }

                    if(populate_flag == 2)
                        break;

                    printf("\n\nEnter the number of teams you wish to add:  ");
                    scanf("%d",&team_num);
                    populate_check = 0;
                    populate(team_num);
                    break;


            case 2: if(team_num == -1)
                       printf("\n\nFirst enter team details.\n\n");


                    else
                    {
                        printf("\n\n\n");
                    for(i=0;i<team_num;i++)
                        printf("%d.%s \n",(i+1),teams[i].name );
                    printf("\n\n");
                    printf("\n Which teams played?\n\n");
                    printf("Team 1:  ");
                    scanf("%d",&Team1);

                    if(Team1 > team_num)
                    {

                        printf("\n\nInvalid Input\n\n");
                        break;

                    }
                    printf("\nTeam 2:  ");
                    scanf("%d",&Team2);

                    if((Team2 == Team1)||(Team2 > team_num))
                    {
                        printf("\n\nInvalid Input\n\n");
                        break;

                    }



                    input((Team1-1) , (Team2-1));

                    }


                    break;

            case 3: if(team_num == -1)
                       printf("\n\nFirst enter team details.\n\n");
                    else
                       display(team_num);
                    break;

            case 4: printf("\n\n\n Exited. \n\n\n\n\n");
                    break;

            default: printf("\n\n\n Invalid option. \n\n\n");


        }
    }while(choice!=4);

}


void input(int team1 , int team2)
{
    int choice,result,goals1,goals2;

    printf("\n\nGoals scored by %s :  ",teams[(team1)].name);
    scanf("%d",&goals1);
    printf("\n\nGoals scored by %s :  ",teams[(team2)].name);
    scanf("%d", &goals2);

    if(goals1 == goals2)
    {
        teams[(team1)].played++;
        teams[(team1)].draw++;
        teams[(team2)].played++;
        teams[(team2)].draw++;
        teams[(team1)].points++;
        teams[(team2)].points++;

    }

    else
    {

        if(goals1>goals2)
            result = 1;
        else
            result = 2;

        if(result == 1)
        {
            teams[(team1)].played++;
            teams[(team2)].played++;
            teams[(team1)].won++;
            teams[(team2)].lost++;
            teams[(team1)].points += 3;
            teams[(team1)].goaldiff += (goals1 - goals2);
            teams[(team2)].goaldiff -= (goals1 - goals2);

        }

        else
        {
            teams[(team1)].played++;
            teams[(team2)].played++;
            teams[(team2)].won++;
            teams[(team1)].lost++;
            teams[(team2)].points += 3;
            teams[(team1)].goaldiff -= (goals2 - goals1);
            teams[(team2)].goaldiff += (goals2 - goals1);
        }

    }

}

void display(int team_num)
{
    int i;
    printf("\n\n\n\n\n");

    sort(team_num);

    printf("  Team\t\t      Team No.\tPlayed\tWon\tLost\tDraw\tGD\tPoints\n\n");

    for(i=0;i< team_num;i++)
    printf("\n\n  %-8s\t\t%d\t %d\t %d\t %d\t %d\t %d\t %d",teams[i].name,teams[i].teamno,teams[i].played,teams[i].won,teams[i].lost,teams[i].draw,teams[i].goaldiff,teams[i].points);

    printf("\n\n\n");


}

void populate(int team_num)
{
    int i;

    for(i=0; i < team_num;i++)
    {
        printf("\n\nEnter the team number of the %d team:  ",(i+1));
        scanf("%d",&teams[i].teamno);
        printf("\n\nEnter team name:  ");
        getchar();
        gets(teams[i].name);

    }
}

void sort(int team_num)
{
    int i,j;

    for(i=0;i<team_num;i++)
        for(j=i;j>0;j--)
            if(teams[j].points>teams[j-1].points)
               exchange(j , (j-1));
            else
               break;
}

void exchange(int num1 , int num2)
{
    int temp;
    char name_temp[50];

    /*swapping names */
    strcpy(name_temp,teams[num1].name);
    strcpy(teams[num1].name,teams[num2].name);
    strcpy(teams[num2].name,name_temp);

    /*swapping team number */
    temp = teams[num1].teamno;
    teams[num1].teamno = teams[num2].teamno;
    teams[num2].teamno = temp;

    /*Swapping number of matches played */
    temp = teams[num1].played;
    teams[num1].played = teams[num2].played;
    teams[num2].played = temp;

    /*swapping number of wins */
    temp = teams[num1].won;
    teams[num1].won = teams[num2].won;
    teams[num2].won = temp;

    /*swapping number of losses */
    temp = teams[num1].lost;
    teams[num1].lost = teams[num2].lost;
    teams[num2].lost = temp;

    /*swapping number of draws */
    temp = teams[num1].draw;
    teams[num1].draw = teams[num2].draw;
    teams[num2].draw = temp;

    /*Swapping goal difference */
    temp = teams[num1].goaldiff;
    teams[num1].goaldiff = teams[num2].goaldiff;
    teams[num2].goaldiff = temp;


    /*swapping points */
    temp = teams[num1].points;
    teams[num1].points = teams[num2].points;
    teams[num2].points = temp;



}

