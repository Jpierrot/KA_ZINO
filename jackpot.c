#include<stdio.h> 

#include<stdlib.h> 

#include <windows.h> 

#include"time.h"

void wait()
{
    Sleep(300);
    printf(".");
    
    Sleep(300);
    printf(".");
    
    Sleep(300);
    printf(".");
    
    Sleep(300);
    printf(".");
}

void clear()
{
    system("cls");
}

int main(void) {

    int static player_money = 1000000;

    int money = 0;

    int play[21] = { 0, };

    int playsum = 0;

    int deal[21] = { 0, };

    int dealsum = 0;

    int i = 2, j = 2, k = 0, n = 0;

    int draw = 0;

    int Ace = 0;

    int endn = 1;

    int ALL_IN = 0;

    int c_time = 0;

    int Card[53] = { 1,2,3,4,5,6,7,8,9,10,10,10,10,

    1,2,3,4,5,6,7,8,9,10,10,10,10,

    1,2,3,4,5,6,7,8,9,10,10,10,10,

    1,2,3,4,5,6,7,8,9,10,10,10,10 };


    while (1)
    {
        ALL_IN = 0;

        endn = 1;

        int Card[53] = { 1,2,3,4,5,6,7,8,9,10,10,10,10,

    1,2,3,4,5,6,7,8,9,10,10,10,10,

    1,2,3,4,5,6,7,8,9,10,10,10,10,

    1,2,3,4,5,6,7,8,9,10,10,10,10 };

        wait();

        clear();

        printf("  ♠♥♣◆\n");

        printf(" BLACK JACK \n");

        printf("  ♠♥♣◆\n");

        if(c_time != 0)
            printf("도전 횟수 : %d\n", c_time);

        printf("보유 금액 : %d", player_money);

    end:

        printf("\n∑배팅 금액을 입해주세요:");

        scanf_s("%d", &money);

        if (player_money - money == 0)
        {
            printf("ALL IN");
            ALL_IN = 1;
            Sleep(1000);
        }
        else if (player_money < money)
        {
            printf("보유한 금액이 부족합니다.");
            goto end;
        }
        else if (money < 100000)
        {
            printf("10만원 이상부터 베팅할 수 있습니다.");
            goto end;
        }


        clear();

        printf("\n BLACK JACK \n");

        wait();

        clear();

        srand(time(NULL));

        deal[0] = rand() % (52);



        do {

            deal[1] = rand() % (52) + 1;

        } while (deal[0] == deal[1]);

        do {

            play[0] = rand() % (52);

        } while (play[0] == deal[0] || play[0] == deal[1]);

        do {

            play[1] = rand() % (52);

        } while (play[1] == deal[0] || play[0] == deal[1] || play[1] == play[0]);





        dealsum = Card[deal[0]] + Card[deal[1]];

        playsum = Card[play[0]] + Card[play[1]];

        printf("∑딜러의 카드 : %d ??? \n", Card[deal[0]]);

        printf("∑플레이어의 카드 : %d %d \n", Card[play[0]], Card[play[1]]);



        for (;;) {

            do {

                printf("\n카드를 더 뽑으시겠습니까? (맞으면 1, 아니면 0 입력)");

                scanf_s("%d", &draw);

            } while (draw != 1 && draw != 0);

            if (draw == 1) {



                for (n = 0; n < i; n++) {

                    do {

                        play[i] = rand() % 52;

                    } while (play[i] == play[n]);

                }

                printf("\n카드를 한 장 더 뽑았습니다");

                if (Card[play[i]] == 1) {

                    printf("\n플레이어가 뽑은 카드 : A");

                    do {

                        printf("\nA를 1로 사용하시겠습니까? 11로 사용하시겠습니까?");

                        printf("\n(1로 사용하려면 1, 11로 사용하려면 0 입력)");

                        scanf_s("%d", &Ace);

                    } while (Ace != 1 && Ace != 0);

                    if (Ace == 1) {

                        Card[play[i]] = 1;

                    }

                    else if (Ace == 0) {

                        Card[play[i]] = 11;

                    }

                }

                else if (play[i] / 13 - 10 == 0)
                    printf("\n플레이어가 뽑은 카드 : J(10)");

                else if (play[i] / 13 - 11 == 0)
                    printf("\n플레이어가 뽑은 카드 : Q(10)");

                else if (play[i] / 13 - 12 == 0)
                    printf("\n플레이어가 뽑은 카드 : K(10)");


                else
                    printf("\n플레이어가 뽑은 카드 : %d\n", Card[play[i]]);

                playsum += Card[play[i]];

                i++;

                if (playsum >= 21) {

                    Sleep(3000);

                    break;

                }

            }

            else if (draw == 0)

                break;

        }



        clear();

        printf("∑딜러의 카드 : %d %d \n", Card[deal[0]], Card[deal[1]]);

        printf("∑플레이어의 카드 :");

        for (k = 0; k < i; k++) {

            printf(" %d", Card[play[k]]);

        }

        if (dealsum <= 16) {

            //

            do

            {

                for (n = 0; n < j; n++) {

                    do {

                        deal[j] = rand() % 52;

                    } while (deal[j] == deal[n]);

                }

                for (n = 0; n < i; n++) {

                    do {

                        deal[j] = rand() % 52;

                    } while (deal[j] == play[n]);

                }

                printf("\n\n딜러가 카드를 한 장 더 뽑았습니다");

                if (Card[deal[j]] == 1) {

                    printf("\n딜러가 뽑은 카드 : A");

                    if (dealsum + 11 > 21) {

                        Card[deal[j]] = 1;

                        printf("(1)");

                    }

                    else {

                        Card[deal[j]] = 11;

                        printf("(11)");

                    }

                }

                else if (deal[j] == 10 || deal[j] == 23 || deal[j] == 36 || deal[j] == 49)

                    printf("\n딜러가 뽑은 카드 : J(10)");

                else if (deal[j] == 11 || deal[j] == 24 || deal[j] == 37 || deal[j] == 50)

                    printf("\n딜러가 뽑은 카드 : Q(10)");

                else if (deal[j] == 12 || deal[j] == 13 || deal[j] == 38 || deal[j] == 51)

                    printf("\n딜러가 뽑은 카드 : K(10)");



                else

                    printf("\n딜러가 뽑은 카드 : %d", Card[deal[j]]);

                dealsum += Card[deal[j]];

                j++;

            } while (dealsum <= 16);

        }



        Sleep(5000);

        clear();

        printf("∑딜러의 카드 :");

        for (k = 0; k < j; k++) {

            printf(" %d", Card[deal[k]]);

        }

        printf("\n 딜러의 카드 합산 : %d\n", dealsum);

        printf("∑플레이어의 카드 :");

        for (k = 0; k < i; k++) {

            printf(" %d", Card[play[k]]);

        }

        printf("\n 플레이어의 카드 합산 : %d\n", playsum);

        if (playsum > 21) {

            printf("\n딜러 승리!\n");

            printf("%d원을 잃었습니다\n", money);

            if (ALL_IN == 1)
            {
                printf("모든 금액을 잃으셨습니다!");
                Sleep(1000);
                break;
            }
            else
                player_money -= money;

        }

        else if (dealsum > 21) {

            printf("\n플레이어 승리!\n");

            printf("%d원을 얻었습니다\n", 2 * money);


            if (ALL_IN == 1)
            {
                printf("system : ALL IN : 베팅 금액의 3배를 얻습니다.");
            }
            else
                player_money += money * 3;

        }

        else if (dealsum == playsum) {

            printf("\n무승부!\n");

        }

        else if (dealsum > playsum) {

            printf("\n딜러 승리!\n");

            printf("%d원을 잃었습니다\n", money);

            if (ALL_IN == 1)
            {
                printf("모든 금액을 잃으셨습니다!");
                Sleep(1000);
                break;
            }
            else
                player_money -= money;

        }

        else {

            printf("\n플레이어 승리!\n");

            printf("%d원을 얻었습니다\n", 2 * money);


            if (ALL_IN == 1)
            {
                printf("system : ALL IN : 베팅 금액의 3배를 얻습니다.");
                player_money += money * 3;
            }
            else
                player_money += money;

        }

        printf("게임을 끝내고 싶으면 0을 눌러주시고 아니면 1을 눌러주세요.");
        scanf("%d", &endn);

        if (endn == 0)
            break;

        c_time++;

        clear();
    }

    printf("\n");

    return 0;

}