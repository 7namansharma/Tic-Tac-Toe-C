#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int num = 48;
void SetColor(int ForgC);
void disp_board();
int check_and_mark(int, int);
int check_status();
void reset_board();
int play_first();
int play_second();
int main()
{
    int choice, mark, check, first, res;
    int status = -1, turn = 1, player = 1;
    char esc;
    label_1:
    printf("Welcome to Tic Tac Toe\n");
    printf("1. Two Player\n");
    printf("2. One Player\n");
    printf("3. Exit\n");
    printf("Please enter the number corresponding to your choice\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Player 1 has 'X' and player 2 has 'O'\n");
            while(status == -1)
            {
                disp_board();
                player = (turn%2!=0) ? 1 : 2;
                label_2:
                printf("\nPlayer %d - Please enter your choice number.\n", player);
                fflush(stdin);
                scanf("%d", &mark);
                check = check_and_mark(mark, player);
                if(check==1)
                {
                    turn += 1;
                }
                else
                {
                    printf("Invalid choice\n");
                    goto label_2;
                }
                status = check_status();
                if(status == 1)
                {
                    turn -= 1;
                    player = (turn%2!=0) ? 1 : 2;
                    disp_board();
                    printf("Player %d wins\n", player);
                    reset_board();
                }
                else if(status == 0)
                {
                    disp_board();
                    printf("Draw\n");
                    reset_board();
                }
            }
            status = -1;
            break;
        case 2:
            label_234:
            printf("\n1. Let the Computer play first with X.\n");
            printf("2. You play first with X.\n");
            printf("Please enter the number corresponding to your choice.\n");
            scanf("%d", &first);
            if(first!=1 && first !=2)
            {
                printf("Invalid choice.\n");
                goto label_234;
            }
            if(first == 1)
            {
                res = play_first();
            }
            else if(first == 2)
            {
                res = play_second();
            }
            if(res==1)
            {
                printf("\nComputer Wins\n");
            }
            else if(res==0)
            {
                printf("\nDraw\n");
            }
            else
            {
                printf("\nPlayer Wins\n");
            }
            break;
        case 3:
            exit(0);
            break;
        default:;
            printf("Invalid Choice\n");
            goto label_1;
    }
    label_3:
    printf("\nDo you wish to play again? Type Y or N.\n");
    fflush(stdin);
    scanf("%c", &esc);
    if ((esc=='Y')||(esc=='N')||(esc=='y')||(esc=='n'))
    {
        if ((esc=='Y')||(esc=='y'))
        {
            goto label_1;
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        printf("Invalid Choice\n");
        goto label_3;
    }
    return 0;
}
void SetColor(int ForgC)
{
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void disp_board()
{
    printf("-------------\n");
    printf("|   |   |   |\n");
    if(board[1]=='X' ||  board[1]=='O')
    {
        if(board[1]=='X')
        {
            printf("| ");
            SetColor(100);
            printf("%c", board[1]);
            SetColor(255);
            printf(" |");
        }
        else
        {
            printf("| ");
            SetColor(9);
            printf("%c", board[1]);
            SetColor(255);
            printf(" |");
        }
    }
    else
    {
        printf("| ");
        SetColor(10);
        printf("%c", board[1]);
        SetColor(255);
        printf(" |");
    }
    if(board[2]=='X' ||  board[2]=='O')
    {
        if(board[2]=='X')
        {
            printf(" ");
            SetColor(100);
            printf("%c", board[2]);
            SetColor(255);
            printf(" ");
        }
        else
        {
            printf(" ");
            SetColor(9);
            printf("%c", board[2]);
            SetColor(255);
            printf(" ");
        }
    }
    else
    {
        printf(" ");
        SetColor(10);
        printf("%c", board[2]);
        SetColor(255);
        printf(" ");
    }
    if(board[3]=='X' ||  board[3]=='O')
    {
        if(board[3]=='X')
        {
            printf("| ");
            SetColor(100);
            printf("%c", board[3]);
            SetColor(255);
            printf(" |\n");
        }
        else
        {
            printf("| ");
            SetColor(9);
            printf("%c", board[3]);
            SetColor(255);
            printf(" |\n");
        }
    }
    else
    {
        printf("| ");
        SetColor(10);
        printf("%c", board[3]);
        SetColor(255);
        printf(" |\n");
    }
    printf("|   |   |   |\n");
    printf("|-----------|\n");
    printf("|   |   |   |\n");
    if(board[4]=='X' ||  board[4]=='O')
    {
        if(board[4]=='X')
        {
            printf("| ");
            SetColor(100);
            printf("%c", board[4]);
            SetColor(255);
            printf(" |");
        }
        else
        {
            printf("| ");
            SetColor(9);
            printf("%c", board[4]);
            SetColor(255);
            printf(" |");
        }
    }
    else
    {
        printf("| ");
        SetColor(10);
        printf("%c", board[4]);
        SetColor(255);
        printf(" |");
    }
    if(board[5]=='X' ||  board[5]=='O')
    {
        if(board[5]=='X')
        {
            printf(" ");
            SetColor(100);
            printf("%c", board[5]);
            SetColor(255);
            printf(" ");
        }
        else
        {
            printf(" ");
            SetColor(9);
            printf("%c", board[5]);
            SetColor(255);
            printf(" ");
        }
    }
    else
    {
        printf(" ");
        SetColor(10);
        printf("%c", board[5]);
        SetColor(255);
        printf(" ");
    }
    if(board[6]=='X' ||  board[6]=='O')
    {
        if(board[6]=='X')
        {
            printf("| ");
            SetColor(100);
            printf("%c", board[6]);
            SetColor(255);
            printf(" |\n");
        }
        else
        {
            printf("| ");
            SetColor(9);
            printf("%c", board[6]);
            SetColor(255);
            printf(" |\n");
        }
    }
    else
    {
        printf("| ");
        SetColor(10);
        printf("%c", board[6]);
        SetColor(255);
        printf(" |\n");
    }
    printf("|   |   |   |\n");
    printf("|-----------|\n");
    printf("|   |   |   |\n");
    if(board[7]=='X' ||  board[7]=='O')
    {
        if(board[7]=='X')
        {
            printf("| ");
            SetColor(100);
            printf("%c", board[7]);
            SetColor(255);
            printf(" |");
        }
        else
        {
            printf("| ");
            SetColor(9);
            printf("%c", board[7]);
            SetColor(255);
            printf(" |");
        }
    }
    else
    {
        printf("| ");
        SetColor(10);
        printf("%c", board[7]);
        SetColor(255);
        printf(" |");
    }
    if(board[8]=='X' ||  board[8]=='O')
    {
        if(board[8]=='X')
        {
            printf(" ");
            SetColor(100);
            printf("%c", board[8]);
            SetColor(255);
            printf(" ");
        }
        else
        {
            printf(" ");
            SetColor(9);
            printf("%c", board[8]);
            SetColor(255);
            printf(" ");
        }
    }
    else
    {
        printf(" ");
        SetColor(10);
        printf("%c", board[8]);
        SetColor(255);
        printf(" ");
    }
    if(board[9]=='X' ||  board[9]=='O')
    {
        if(board[9]=='X')
        {
            printf("| ");
            SetColor(100);
            printf("%c", board[9]);
            SetColor(255);
            printf(" |\n");
        }
        else
        {
            printf("| ");
            SetColor(9);
            printf("%c", board[9]);
            SetColor(255);
            printf(" |\n");
        }
    }
    else
    {
        printf("| ");
        SetColor(10);
        printf("%c", board[9]);
        SetColor(255);
        printf(" |\n");
    }
    printf("|   |   |   |\n");
    printf("-------------\n");
}
int check_and_mark(int mark, int player)
{
    char sym;
    sym = (player==1) ? 'X' : 'O';
    if((mark == 1)&&(board[1] == '1'))
    {
        board[1] = sym;
        return 1;
    }
    else if((mark == 2)&&(board[2] == '2'))
    {
        board[2] = sym;
        return 1;
    }
    else if((mark == 3)&&(board[3] == '3'))
    {
        board[3] = sym;
        return 1;
    }
    else if((mark == 4)&&(board[4] == '4'))
    {
        board[4] = sym;
        return 1;
    }
    else if((mark == 5)&&(board[5] == '5'))
    {
        board[5] = sym;
        return 1;
    }
    else if((mark == 6)&&(board[6] == '6'))
    {
        board[6] = sym;
        return 1;
    }
    else if((mark == 7)&&(board[7] == '7'))
    {
        board[7] = sym;
        return 1;
    }
    else if((mark == 8)&&(board[8] == '8'))
    {
        board[8] = sym;
        return 1;
    }
    else if((mark == 9)&&(board[9] == '9'))
    {
        board[9] = sym;
        return 1;
    }
    else
    {
        return 0;
    }
}
int check_status()
{
    if (board[1] == board[2] && board[2] == board[3])
        return 1;

    else if (board[4] == board[5] && board[5] == board[6])
        return 1;

    else if (board[7] == board[8] && board[8] == board[9])
        return 1;

    else if (board[1] == board[4] && board[4] == board[7])
        return 1;

    else if (board[2] == board[5] && board[5] == board[8])
        return 1;

    else if (board[3] == board[6] && board[6] == board[9])
        return 1;

    else if (board[1] == board[5] && board[5] == board[9])
        return 1;

    else if (board[3] == board[5] && board[5] == board[7])
        return 1;

    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' &&
        board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7]
        != '7' && board[8] != '8' && board[9] != '9')
        return 0;
    else
        return -1;
}
void reset_board()
{
    for(int i = 0; i <= 9; i++)
    {
        board[i] = num + i;
    }
}
int play_first()
{
    int player_choice, check_play_first;
    printf("Player 1 is Computer and has 'X' and Player 2 is You and have 'O'.\n");
    check_and_mark(7, 1);
    disp_board();
    printf("Player 1 has marked 'X' on 7.\n");
    label_4:
    printf("Player 2 - Please enter your choice number.\n");
    fflush(stdin);
    scanf("%d", &player_choice);
    check_play_first=check_and_mark(player_choice, 2);
    if(check_play_first==0)
    {
        printf("Invalid Choice.\n");
        goto label_4;
    }
    disp_board();
    printf("Player 2 has marked '0' on %d.\n", player_choice);
    if(player_choice == 5)
    {
        check_and_mark(3, 1);
        disp_board();
        printf("Player 1 has marked 'X' on 3.\n");
        label_5:
        printf("Player 2 - Please enter your choice number.\n");
        scanf("%d", &player_choice);
        check_play_first=check_and_mark(player_choice, 2);
        if(check_play_first==0)
        {
            printf("Invalid Choice.\n");
            goto label_5;
        }
        disp_board();
        printf("Player 2 has marked '0' on %d.\n", player_choice);
        if(player_choice == 1 || player_choice == 9)
        {
            if(player_choice == 1)
            {
                check_and_mark(9, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 9.\n");
                label_6:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_6;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice == 6)
                {
                    check_and_mark(8, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 8.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(6, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 6.\n");
                    reset_board();
                    return 1;
                }
            }
            else
            {
                check_and_mark(1, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 1.\n");
                label_7:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_7;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice == 2)
                {
                    check_and_mark(4, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 4.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(2, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 2.\n");
                    reset_board();
                    return 1;
                }
            }
        }
        else
        {
            if(player_choice == 2)
            {
                check_and_mark(8, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 8.\n");
                label_8:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_8;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice != 9)
                {
                    check_and_mark(9, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 9.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(1, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 1.\n");
                    label_9:
                    printf("Player 2 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_first=check_and_mark(player_choice, 2);
                    if(check_play_first==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_9;
                    }
                    disp_board();
                    printf("Player 2 has marked '0' on %d.\n", player_choice);
                    if(player_choice==4)
                    {
                        check_and_mark(6, 1);
                        disp_board();
                        printf("Player 1 has marked 'X' on 6.\n");
                        reset_board();
                        return 0;
                    }
                    else
                    {
                        check_and_mark(4, 1);
                        disp_board();
                        printf("Player 1 has marked 'X' on 4.\n");
                        reset_board();
                        return 1;
                    }
                }
            }
            else if(player_choice == 8)
            {
                check_and_mark(2, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 2.\n");
                label_228:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_228;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice != 1)
                {
                    check_and_mark(1, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 1.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(9, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 9.\n");
                    label_229:
                    printf("Player 2 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_first=check_and_mark(player_choice, 2);
                    if(check_play_first==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_229;
                    }
                    disp_board();
                    printf("Player 2 has marked '0' on %d.\n", player_choice);
                    if(player_choice==6)
                    {
                        check_and_mark(4, 1);
                        disp_board();
                        printf("Player 1 has marked 'X' on 4.\n");
                        reset_board();
                        return 0;
                    }
                    else
                    {
                        check_and_mark(6, 1);
                        disp_board();
                        printf("Player 1 has marked 'X' on 6.\n");
                        reset_board();
                        return 1;
                    }
                }
            }
            else if(player_choice == 4)
            {
                check_and_mark(6, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 6.\n");
                label_230:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_230;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice != 9)
                {
                    check_and_mark(9, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 9.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(1, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 1.\n");
                    label_231:
                    printf("Player 2 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_first=check_and_mark(player_choice, 2);
                    if(check_play_first==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_231;
                    }
                    disp_board();
                    printf("Player 2 has marked '0' on %d.\n", player_choice);
                    if(player_choice==2)
                    {
                        check_and_mark(8, 1);
                        disp_board();
                        printf("Player 1 has marked 'X' on 8.\n");
                        reset_board();
                        return 0;
                    }
                    else
                    {
                        check_and_mark(2, 1);
                        disp_board();
                        printf("Player 1 has marked 'X' on 2.\n");
                        reset_board();
                        return 1;
                    }
                }
            }
            else if(player_choice == 6)
            {
                check_and_mark(4, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 4.\n");
                label_232:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_232;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice != 1)
                {
                    check_and_mark(1, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 1.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(9, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 9.\n");
                    label_233:
                    printf("Player 2 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_first=check_and_mark(player_choice, 2);
                    if(check_play_first==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_233;
                    }
                    disp_board();
                    printf("Player 2 has marked '0' on %d.\n", player_choice);
                    if(player_choice==8)
                    {
                        check_and_mark(2, 1);
                        disp_board();
                        printf("Player 1 has marked 'X' on 2.\n");
                        reset_board();
                        return 0;
                    }
                    else
                    {
                        check_and_mark(8, 1);
                        disp_board();
                        printf("Player 1 has marked 'X' on 8.\n");
                        reset_board();
                        return 1;
                    }
                }
            }
        }
    }
    else
    {
        if(player_choice == 1 || player_choice == 4)
        {
            check_and_mark(9, 1);
            disp_board();
            printf("Player 1 has marked 'X' on 9.\n");
            label_10:
            printf("Player 2 - Please enter your choice number.\n");
            scanf("%d", &player_choice);
            check_play_first=check_and_mark(player_choice, 2);
            if(check_play_first==0)
            {
                printf("Invalid Choice.\n");
                goto label_10;
            }
            disp_board();
            printf("Player 2 has marked '0' on %d.\n", player_choice);
            if(player_choice != 8)
            {
                check_and_mark(8, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 8.\n");
                reset_board();
                return 1;
            }
            else
            {
                check_and_mark(3, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 3.\n");
                label_11:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_11;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice!=6)
                {
                    check_and_mark(6, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 6.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(5, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 5.\n");
                    reset_board();
                    return 1;
                }
            }
        }
        else if(player_choice == 3 || player_choice == 6)
        {
            check_and_mark(9, 1);
            disp_board();
            printf("Player 1 has marked 'X' on 9.\n");
            label_12:
            printf("Player 2 - Please enter your choice number.\n");
            scanf("%d", &player_choice);
            check_play_first=check_and_mark(player_choice, 2);
            if(check_play_first==0)
            {
                printf("Invalid Choice.\n");
                goto label_12;
            }
            disp_board();
            printf("Player 2 has marked '0' on %d.\n", player_choice);
            if(player_choice != 8)
            {
                check_and_mark(8, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 8.\n");
                reset_board();
                return 1;
            }
            else
            {
                check_and_mark(1, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 1.\n");
                label_13:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_13;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice!=4)
                {
                    check_and_mark(4, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 4.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(5, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 5.\n");
                    reset_board();
                    return 1;
                }
            }
        }
        else if(player_choice==2)
        {
            check_and_mark(9, 1);
            disp_board();
            printf("Player 1 has marked 'X' on 9.\n");
            label_14:
            printf("Player 2 - Please enter your choice number.\n");
            scanf("%d", &player_choice);
            check_play_first=check_and_mark(player_choice, 2);
            if(check_play_first==0)
            {
                printf("Invalid Choice.\n");
                goto label_14;
            }
            disp_board();
            printf("Player 2 has marked '0' on %d.\n", player_choice);
            if(player_choice != 8)
            {
                check_and_mark(8, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 8.\n");
                reset_board();
                return 1;
            }
            else
            {
                check_and_mark(5, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 5.\n");
                label_15:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_15;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice!=3)
                {
                    check_and_mark(3, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 3.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(1, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 1.\n");
                    reset_board();
                    return 1;
                }
            }
        }
        else
        {
            check_and_mark(1, 1);
            disp_board();
            printf("Player 1 has marked 'X' on 1.\n");
            label_16:
            printf("Player 2 - Please enter your choice number.\n");
            scanf("%d", &player_choice);
            check_play_first=check_and_mark(player_choice, 2);
            if(check_play_first==0)
            {
                printf("Invalid Choice.\n");
                goto label_16;
            }
            disp_board();
            printf("Player 2 has marked '0' on %d.\n", player_choice);
            if(player_choice!=4)
            {
                check_and_mark(4, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 4.\n");
                reset_board();
                return 1;
            }
            else
            {
                check_and_mark(3, 1);
                disp_board();
                printf("Player 1 has marked 'X' on 3.\n");
                label_17:
                printf("Player 2 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_first=check_and_mark(player_choice, 2);
                if(check_play_first==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_17;
                }
                disp_board();
                printf("Player 2 has marked '0' on %d.\n", player_choice);
                if(player_choice!=2)
                {
                    check_and_mark(2, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 2.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(5, 1);
                    disp_board();
                    printf("Player 1 has marked 'X' on 5.\n");
                    reset_board();
                    return 1;
                }
            }
        }
    }
    reset_board();
    return 0;
}
int play_second()
{
    int player_choice, check_play_second;
    printf("Player 1 is You and have 'X' and Player 2 is Computer and have 'O'.\n");
    disp_board();
    label_18:
    printf("Player 1 - Please enter your choice number.\n");
    fflush(stdin);
    scanf("%d", &player_choice);
    check_play_second=check_and_mark(player_choice, 1);
    if(check_play_second==0)
    {
        printf("Invalid Choice.\n");
        goto label_18;
    }
    disp_board();
    printf("Player 1 has marked 'X' on %d.\n", player_choice);
    if(player_choice == 5)
    {
        check_and_mark(9, 2);
        disp_board();
        printf("Player 2 has marked 'O' on 9.\n");
        label_19:
        printf("Player 1 - Please enter your choice number.\n");
        scanf("%d", &player_choice);
        check_play_second=check_and_mark(player_choice, 1);
        if(check_play_second==0)
        {
            printf("Invalid Choice.\n");
            goto label_19;
        }
        disp_board();
        printf("Player 1 has marked 'X' on %d.\n", player_choice);
        if(player_choice==1 || player_choice==3 || player_choice==7 || player_choice==9)
        {
            if(player_choice==1)
            {
                check_and_mark(7, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 7.\n");
                label_20:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_20;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice != 8)
                {
                    check_and_mark(8, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 8.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(2, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 2.\n");
                    label_21:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_21;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice==3 || player_choice==4)
                    {
                        check_and_mark(6, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 6.\n");
                        label_22:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_22;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        reset_board();
                        return 0;
                    }
                    else
                    {
                        check_and_mark(4, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 4.\n");
                        label_23:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_23;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        reset_board();
                        return 0;
                    }
                }
            }
            else if(player_choice==3)
            {
                check_and_mark(7, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 7.\n");
                label_235:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_235;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice != 8)
                {
                    check_and_mark(8, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 8.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(2, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 2.\n");
                    label_236:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_236;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice==1 || player_choice==4)
                    {
                        check_and_mark(6, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 6.\n");
                        label_237:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_237;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        reset_board();
                        return 0;
                    }
                    else
                    {
                        check_and_mark(4, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 4.\n");
                        label_238:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_238;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        reset_board();
                        return 0;
                    }
                }
            }
            else if(player_choice==7)
            {
                check_and_mark(3, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 3.\n");
                label_239:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_239;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice != 6)
                {
                    check_and_mark(6, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 6.\n");
                    reset_board();
                    return 1;
                }
                else
                {
                    check_and_mark(4, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 4.\n");
                    label_240:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_240;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice==1 || player_choice==2)
                    {
                        check_and_mark(8, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 8.\n");
                        label_241:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_241;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        reset_board();
                        return 0;
                    }
                    else
                    {
                        check_and_mark(2, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 2.\n");
                        label_242:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_242;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        reset_board();
                        return 0;
                    }
                }
            }
        }
        else
        {
            if(player_choice==2 || player_choice==8)
            {
                if(player_choice==2)
                {
                    check_and_mark(8, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 8.\n");
                    label_24:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_24;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=7)
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_25:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_25;
                        }
                        if(player_choice!=6)
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_26:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_26;
                            }
                            return 0;
                        }
                    }
                }
                else
                {
                    check_and_mark(2, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 2.\n");
                    label_27:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_27;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice==1)
                    {
                        check_and_mark(6, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 6.\n");
                        label_28:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_28;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            label_29:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_29;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            reset_board();
                            return 0;
                        }
                    }
                    else if(player_choice==4 || player_choice==6)
                    {
                        if(player_choice==4)
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            label_30:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_30;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=3)
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                label_31:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_31;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        if(player_choice==7)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            label_32:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_32;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=6)
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                reset_board();
                                return 1;
                            }
                        }
                        else
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            label_33:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_33;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice==1 || player_choice==6)
                            {
                                check_and_mark(4, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 4.\n");
                                label_34:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_34;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                            else
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                label_35:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_35;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
            }
            else if(player_choice==4 || player_choice==6)
            {
                if(player_choice==4)
                {
                    check_and_mark(6, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 6.\n");
                    label_36:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_36;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=3)
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_37:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_37;
                        }
                        if(player_choice!=8)
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_38:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_38;
                            }
                            return 0;
                        }
                    }
                }
                else
                {
                    check_and_mark(4, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 4.\n");
                    label_39:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_39;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice==1)
                    {
                        check_and_mark(8, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 8.\n");
                        label_40:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_40;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=7)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            label_41:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_41;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            reset_board();
                            return 0;
                        }
                    }
                    else if(player_choice==2 || player_choice==8)
                    {
                        if(player_choice==2)
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            label_42:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_42;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=7)
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_43:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_43;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        if(player_choice==3)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            label_44:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_44;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=8)
                            {
                                check_and_mark(8, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 8.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                reset_board();
                                return 1;
                            }
                        }
                        else
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            label_45:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_45;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice==1 || player_choice==8)
                            {
                                check_and_mark(2, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 2.\n");
                                label_46:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_46;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                            else
                            {
                                check_and_mark(8, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 8.\n");
                                label_47:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_47;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        if(player_choice==1 || player_choice==3 || player_choice==7 || player_choice==9)
        {
            if(player_choice==1)
            {
                check_and_mark(5, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 5.\n");
                label_48:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_48;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice==2 || player_choice==3 || player_choice==4 || player_choice==7)
                {
                    if(player_choice==2)
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_49:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_49;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=7)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_50:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_50;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=6)
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                label_51:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_51;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else if(player_choice==4)
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_52:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_52;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_53:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_53;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=8)
                            {
                                check_and_mark(8, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 8.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                label_54:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_54;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else if(player_choice==3)
                    {
                        check_and_mark(2, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 2.\n");
                        label_55:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_55;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=8)
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_56:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_56;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=6)
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                label_57:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_57;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(4, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 4.\n");
                        label_58:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_58;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=6)
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_59:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_59;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=8)
                            {
                                check_and_mark(8, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 8.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                label_60:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_60;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==6 || player_choice==8)
                {
                    if(player_choice==6)
                    {
                        check_and_mark(2, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 2.\n");
                        label_61:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_61;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=8)
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            label_62:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_62;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=3)
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                label_63:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_63;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(4, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 4.\n");
                        label_64:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_64;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=6)
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            label_65:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_65;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=7)
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                label_66:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_66;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else
                {
                    check_and_mark(6, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 6.\n");
                    label_67:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_67;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=4)
                    {
                        check_and_mark(4, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 4.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_68:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_68;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_69:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_69;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            reset_board();
                            return 0;
                        }
                    }
                }
            }
            else if(player_choice==3)
            {
                check_and_mark(5, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 5.\n");
                label_70:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_70;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice==1 || player_choice==2 || player_choice==6 || player_choice==9)
                {
                    if(player_choice==2)
                    {
                        check_and_mark(1, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 1.\n");
                        label_71:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_71;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=9)
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            label_72:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_72;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=4)
                            {
                                check_and_mark(4, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 4.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                label_73:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_73;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else if(player_choice==6)
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_74:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_74;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_75:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_75;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=8)
                            {
                                check_and_mark(8, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 8.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                label_76:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_76;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else if(player_choice==1)
                    {
                        check_and_mark(2, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 2.\n");
                        label_77:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_77;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=8)
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_78:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_78;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=6)
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                label_79:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_79;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(6, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 6.\n");
                        label_80:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_80;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=4)
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_81:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_81;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=8)
                            {
                                check_and_mark(8, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 8.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                label_82:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_82;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==4 || player_choice==8)
                {
                    if(player_choice==4)
                    {
                        check_and_mark(2, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 2.\n");
                        label_83:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_83;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=8)
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            label_84:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_84;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=1)
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                label_85:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_85;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(6, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 6.\n");
                        label_86:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_86;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=4)
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            label_87:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_87;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=9)
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                label_88:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_88;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else
                {
                    check_and_mark(4, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 4.\n");
                    label_89:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_89;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=6)
                    {
                        check_and_mark(6, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 6.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_90:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_90;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_91:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_91;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            reset_board();
                            return 0;
                        }
                    }
                }
            }
            else if(player_choice==7)
            {
                check_and_mark(5, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 5.\n");
                label_92:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_92;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice==1 || player_choice==4 || player_choice==8 || player_choice==9)
                {
                    if(player_choice==4)
                    {
                        check_and_mark(1, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 1.\n");
                        label_93:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_93;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=9)
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            label_94:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_94;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=2)
                            {
                                check_and_mark(2, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 2.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_95:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_95;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else if(player_choice==8)
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_96:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_96;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_97:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_97;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=6)
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_98:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_98;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else if(player_choice==1)
                    {
                        check_and_mark(4, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 4.\n");
                        label_99:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_99;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=6)
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            label_100:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_100;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=2)
                            {
                                check_and_mark(2, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 2.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_101:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_101;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(8, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 8.\n");
                        label_102:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_102;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=2)
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_103:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_103;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=6)
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_104:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_104;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==2 || player_choice==6)
                {
                    if(player_choice==6)
                    {
                        check_and_mark(8, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 8.\n");
                        label_105:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_105;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=2)
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            label_106:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_106;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=9)
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_107:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_107;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(4, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 4.\n");
                        label_108:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_108;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=6)
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            label_109:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_109;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=1)
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_110:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_110;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else
                {
                    check_and_mark(4, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 4.\n");
                    label_111:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_111;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=6)
                    {
                        check_and_mark(6, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 6.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_112:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_112;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_113:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_113;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            reset_board();
                            return 0;
                        }
                    }
                }
            }
            else
            {
                check_and_mark(5, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 5.\n");
                label_114:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_114;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice==3 || player_choice==6 || player_choice==7 || player_choice==8)
                {
                    if(player_choice==6)
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_115:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_115;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=7)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            label_116:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_116;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=2)
                            {
                                check_and_mark(2, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 2.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                label_117:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_117;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else if(player_choice==8)
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_118:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_118;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            label_119:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_119;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=4)
                            {
                                check_and_mark(4, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 4.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                label_120:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_120;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else if(player_choice==3)
                    {
                        check_and_mark(6, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 6.\n");
                        label_121:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_121;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=4)
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            label_122:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_122;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=2)
                            {
                                check_and_mark(2, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 2.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                label_123:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_123;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(8, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 8.\n");
                        label_124:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_124;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=2)
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_125:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_125;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=6)
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_126:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_126;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==2 || player_choice==4)
                {
                    if(player_choice==4)
                    {
                        check_and_mark(8, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 8.\n");
                        label_127:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_127;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=2)
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            label_128:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_128;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=7)
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                label_129:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_129;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(6, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 6.\n");
                        label_130:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_130;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=4)
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            label_131:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_131;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=3)
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                label_132:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_132;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else
                {
                    check_and_mark(6, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 6.\n");
                    label_133:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_133;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=4)
                    {
                        check_and_mark(4, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 4.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_134:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_134;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_135:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_135;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            reset_board();
                            return 0;
                        }
                    }
                }
            }
        }
        else
        {
            if(player_choice==2)
            {
                check_and_mark(5, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 5.\n");
                label_136:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_136;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice==1 || player_choice==3)
                {
                    if(player_choice==1)
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_137:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_137;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=7)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_138:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_138;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=6)
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                label_139:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_139;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(1, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 1.\n");
                        label_140:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_140;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=9)
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            label_141:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_141;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=4)
                            {
                                check_and_mark(4, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 4.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                label_142:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_142;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==4 || player_choice==6)
                {
                    if(player_choice==4)
                    {
                        check_and_mark(1, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 1.\n");
                        label_143:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_143;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=9)
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            label_144:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_144;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=3)
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                label_145:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_145;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_146:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_146;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=7)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            label_147:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_147;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=1)
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(4, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 4.\n");
                                label_148:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_148;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==7 || player_choice==9)
                {
                    if(player_choice==7)
                    {
                        check_and_mark(1, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 1.\n");
                        label_149:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_149;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=9)
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            label_150:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_150;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            {
                                if(player_choice!=3)
                                {
                                    check_and_mark(3, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 3.\n");
                                    label_151:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_151;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                                else
                                {
                                    check_and_mark(6, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 6.\n");
                                    label_152:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_152;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_153:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_153;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=7)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            label_154:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_154;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            {
                                if(player_choice!=1)
                                {
                                    check_and_mark(1, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 1.\n");
                                    label_155:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_155;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                                else
                                {
                                    check_and_mark(4, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 4.\n");
                                    label_156:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_156;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                            }
                        }
                    }
                }
                else
                {
                    check_and_mark(9, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 9.\n");
                    label_157:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_157;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=1)
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_158:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_158;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=6)
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            reset_board();
                            return 1;
                        }
                    }
                }
            }
            else if(player_choice==4)
            {
                check_and_mark(5, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 5.\n");
                label_159:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_159;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice==1 || player_choice==7)
                {
                    if(player_choice==1)
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_160:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_160;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_161:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_161;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=8)
                            {
                                check_and_mark(8, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 8.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                label_162:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_162;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(1, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 1.\n");
                        label_163:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_163;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=9)
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            label_164:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_164;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=2)
                            {
                                check_and_mark(2, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 2.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_165:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_165;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==2 || player_choice==8)
                {
                    if(player_choice==2)
                    {
                        check_and_mark(1, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 1.\n");
                        label_166:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_166;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=9)
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            label_167:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_167;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=3)
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                label_168:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_168;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_169:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_169;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            label_170:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_170;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=9)
                            {
                                check_and_mark(9, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 9.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                label_171:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_171;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==3 || player_choice==9)
                {
                    if(player_choice==3)
                    {
                        check_and_mark(1, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 1.\n");
                        label_172:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_172;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=9)
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            label_173:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_173;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            {
                                if(player_choice!=7)
                                {
                                    check_and_mark(7, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 7.\n");
                                    label_174:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_174;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                                else
                                {
                                    check_and_mark(8, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 8.\n");
                                    label_175:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_175;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_176:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_176;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            label_177:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_177;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            {
                                if(player_choice!=1)
                                {
                                    check_and_mark(1, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 1.\n");
                                    label_178:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_178;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                                else
                                {
                                    check_and_mark(2, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 2.\n");
                                    label_179:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_179;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                            }
                        }
                    }
                }
                else
                {
                    check_and_mark(3, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 3.\n");
                    label_180:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_180;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=7)
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(1, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 1.\n");
                        label_181:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_181;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=2)
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            reset_board();
                            return 1;
                        }
                    }
                }
            }
            else if(player_choice==6)
            {
                check_and_mark(5, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 5.\n");
                label_182:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_182;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice==3 || player_choice==9)
                {
                    if(player_choice==3)
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_183:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_183;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_184:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_184;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=8)
                            {
                                check_and_mark(8, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 8.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                label_185:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_185;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_186:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_186;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=7)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(8, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 8.\n");
                            label_187:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_187;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=2)
                            {
                                check_and_mark(2, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 2.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                label_188:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_188;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==2 || player_choice==8)
                {
                    if(player_choice==2)
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_189:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_189;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=7)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            label_190:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_190;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=1)
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(4, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 4.\n");
                                label_191:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_191;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_192:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_192;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            label_193:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_193;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=7)
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(4, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 4.\n");
                                label_194:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_194;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==1 || player_choice==7)
                {
                    if(player_choice==1)
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_195:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_195;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=7)
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_196:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_196;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            {
                                if(player_choice!=9)
                                {
                                    check_and_mark(9, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 9.\n");
                                    label_197:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_197;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                                else
                                {
                                    check_and_mark(8, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 8.\n");
                                    label_198:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_198;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_199:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_199;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_200:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_200;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            {
                                if(player_choice!=3)
                                {
                                    check_and_mark(3, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 3.\n");
                                    label_201:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_201;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                                else
                                {
                                    check_and_mark(2, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 2.\n");
                                    label_202:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_202;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                            }
                        }
                    }
                }
                else
                {
                    check_and_mark(1, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 1.\n");
                    label_203:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_203;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=9)
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(3, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 3.\n");
                        label_204:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_204;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=2)
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(7, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 7.\n");
                            reset_board();
                            return 1;
                        }
                    }
                }
            }
            else
            {
                check_and_mark(5, 2);
                disp_board();
                printf("Player 2 has marked 'O' on 5.\n");
                label_205:
                printf("Player 1 - Please enter your choice number.\n");
                scanf("%d", &player_choice);
                check_play_second=check_and_mark(player_choice, 1);
                if(check_play_second==0)
                {
                    printf("Invalid Choice.\n");
                    goto label_205;
                }
                disp_board();
                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                if(player_choice==7 || player_choice==9)
                {
                    if(player_choice==7)
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_206:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_206;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(4, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 4.\n");
                            label_207:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_207;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=6)
                            {
                                check_and_mark(6, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 6.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(3, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 3.\n");
                                label_208:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_208;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_209:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_209;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            label_210:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_210;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=4)
                            {
                                check_and_mark(4, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 4.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                label_211:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_211;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==4 || player_choice==6)
                {
                    if(player_choice==4)
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_212:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_212;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(9, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 9.\n");
                            label_213:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_213;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=1)
                            {
                                check_and_mark(1, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 1.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(2, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 2.\n");
                                label_214:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_214;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_215:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_215;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            label_216:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_216;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            if(player_choice!=7)
                            {
                                check_and_mark(7, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 7.\n");
                                reset_board();
                                return 1;
                            }
                            else
                            {
                                check_and_mark(4, 2);
                                disp_board();
                                printf("Player 2 has marked 'O' on 4.\n");
                                label_217:
                                printf("Player 1 - Please enter your choice number.\n");
                                scanf("%d", &player_choice);
                                check_play_second=check_and_mark(player_choice, 1);
                                if(check_play_second==0)
                                {
                                    printf("Invalid Choice.\n");
                                    goto label_217;
                                }
                                disp_board();
                                printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                reset_board();
                                return 0;
                            }
                        }
                    }
                }
                else if(player_choice==1 || player_choice==3)
                {
                    if(player_choice==1)
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        label_218:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_218;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=3)
                        {
                            check_and_mark(3, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 3.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_219:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_219;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            {
                                if(player_choice!=9)
                                {
                                    check_and_mark(9, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 9.\n");
                                    label_220:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_220;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                                else
                                {
                                    check_and_mark(6, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 6.\n");
                                    label_221:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_221;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_222:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_222;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=1)
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(2, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 2.\n");
                            label_223:
                            printf("Player 1 - Please enter your choice number.\n");
                            scanf("%d", &player_choice);
                            check_play_second=check_and_mark(player_choice, 1);
                            if(check_play_second==0)
                            {
                                printf("Invalid Choice.\n");
                                goto label_223;
                            }
                            disp_board();
                            printf("Player 1 has marked 'X' on %d.\n", player_choice);
                            {
                                if(player_choice!=7)
                                {
                                    check_and_mark(7, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 7.\n");
                                    label_224:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_224;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                                else
                                {
                                    check_and_mark(4, 2);
                                    disp_board();
                                    printf("Player 2 has marked 'O' on 4.\n");
                                    label_225:
                                    printf("Player 1 - Please enter your choice number.\n");
                                    scanf("%d", &player_choice);
                                    check_play_second=check_and_mark(player_choice, 1);
                                    if(check_play_second==0)
                                    {
                                        printf("Invalid Choice.\n");
                                        goto label_225;
                                    }
                                    disp_board();
                                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                                    reset_board();
                                    return 0;
                                }
                            }
                        }
                    }
                }
                else
                {
                    check_and_mark(3, 2);
                    disp_board();
                    printf("Player 2 has marked 'O' on 3.\n");
                    label_226:
                    printf("Player 1 - Please enter your choice number.\n");
                    scanf("%d", &player_choice);
                    check_play_second=check_and_mark(player_choice, 1);
                    if(check_play_second==0)
                    {
                        printf("Invalid Choice.\n");
                        goto label_226;
                    }
                    disp_board();
                    printf("Player 1 has marked 'X' on %d.\n", player_choice);
                    if(player_choice!=7)
                    {
                        check_and_mark(7, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 7.\n");
                        reset_board();
                        return 1;
                    }
                    else
                    {
                        check_and_mark(9, 2);
                        disp_board();
                        printf("Player 2 has marked 'O' on 9.\n");
                        label_227:
                        printf("Player 1 - Please enter your choice number.\n");
                        scanf("%d", &player_choice);
                        check_play_second=check_and_mark(player_choice, 1);
                        if(check_play_second==0)
                        {
                            printf("Invalid Choice.\n");
                            goto label_227;
                        }
                        disp_board();
                        printf("Player 1 has marked 'X' on %d.\n", player_choice);
                        if(player_choice!=6)
                        {
                            check_and_mark(6, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 6.\n");
                            reset_board();
                            return 1;
                        }
                        else
                        {
                            check_and_mark(1, 2);
                            disp_board();
                            printf("Player 2 has marked 'O' on 1.\n");
                            reset_board();
                            return 1;
                        }
                    }
                }
            }
        }
    }
    reset_board();
    return 0;
}
