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

        printf("  ��������\n");

        printf(" BLACK JACK \n");

        printf("  ��������\n");

        if(c_time != 0)
            printf("���� Ƚ�� : %d\n", c_time);

        printf("���� �ݾ� : %d", player_money);

    end:

        printf("\n������ �ݾ��� �����ּ���:");

        scanf_s("%d", &money);

        if (player_money - money == 0)
        {
            printf("ALL IN");
            ALL_IN = 1;
            Sleep(1000);
        }
        else if (player_money < money)
        {
            printf("������ �ݾ��� �����մϴ�.");
            goto end;
        }
        else if (money < 100000)
        {
            printf("10���� �̻���� ������ �� �ֽ��ϴ�.");
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

        printf("�������� ī�� : %d ??? \n", Card[deal[0]]);

        printf("���÷��̾��� ī�� : %d %d \n", Card[play[0]], Card[play[1]]);



        for (;;) {

            do {

                printf("\nī�带 �� �����ðڽ��ϱ�? (������ 1, �ƴϸ� 0 �Է�)");

                scanf_s("%d", &draw);

            } while (draw != 1 && draw != 0);

            if (draw == 1) {



                for (n = 0; n < i; n++) {

                    do {

                        play[i] = rand() % 52;

                    } while (play[i] == play[n]);

                }

                printf("\nī�带 �� �� �� �̾ҽ��ϴ�");

                if (Card[play[i]] == 1) {

                    printf("\n�÷��̾ ���� ī�� : A");

                    do {

                        printf("\nA�� 1�� ����Ͻðڽ��ϱ�? 11�� ����Ͻðڽ��ϱ�?");

                        printf("\n(1�� ����Ϸ��� 1, 11�� ����Ϸ��� 0 �Է�)");

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
                    printf("\n�÷��̾ ���� ī�� : J(10)");

                else if (play[i] / 13 - 11 == 0)
                    printf("\n�÷��̾ ���� ī�� : Q(10)");

                else if (play[i] / 13 - 12 == 0)
                    printf("\n�÷��̾ ���� ī�� : K(10)");


                else
                    printf("\n�÷��̾ ���� ī�� : %d\n", Card[play[i]]);

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

        printf("�������� ī�� : %d %d \n", Card[deal[0]], Card[deal[1]]);

        printf("���÷��̾��� ī�� :");

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

                printf("\n\n������ ī�带 �� �� �� �̾ҽ��ϴ�");

                if (Card[deal[j]] == 1) {

                    printf("\n������ ���� ī�� : A");

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

                    printf("\n������ ���� ī�� : J(10)");

                else if (deal[j] == 11 || deal[j] == 24 || deal[j] == 37 || deal[j] == 50)

                    printf("\n������ ���� ī�� : Q(10)");

                else if (deal[j] == 12 || deal[j] == 13 || deal[j] == 38 || deal[j] == 51)

                    printf("\n������ ���� ī�� : K(10)");



                else

                    printf("\n������ ���� ī�� : %d", Card[deal[j]]);

                dealsum += Card[deal[j]];

                j++;

            } while (dealsum <= 16);

        }



        Sleep(5000);

        clear();

        printf("�������� ī�� :");

        for (k = 0; k < j; k++) {

            printf(" %d", Card[deal[k]]);

        }

        printf("\n ������ ī�� �ջ� : %d\n", dealsum);

        printf("���÷��̾��� ī�� :");

        for (k = 0; k < i; k++) {

            printf(" %d", Card[play[k]]);

        }

        printf("\n �÷��̾��� ī�� �ջ� : %d\n", playsum);

        if (playsum > 21) {

            printf("\n���� �¸�!\n");

            printf("%d���� �Ҿ����ϴ�\n", money);

            if (ALL_IN == 1)
            {
                printf("��� �ݾ��� �����̽��ϴ�!");
                Sleep(1000);
                break;
            }
            else
                player_money -= money;

        }

        else if (dealsum > 21) {

            printf("\n�÷��̾� �¸�!\n");

            printf("%d���� ������ϴ�\n", 2 * money);


            if (ALL_IN == 1)
            {
                printf("system : ALL IN : ���� �ݾ��� 3�踦 ����ϴ�.");
            }
            else
                player_money += money * 3;

        }

        else if (dealsum == playsum) {

            printf("\n���º�!\n");

        }

        else if (dealsum > playsum) {

            printf("\n���� �¸�!\n");

            printf("%d���� �Ҿ����ϴ�\n", money);

            if (ALL_IN == 1)
            {
                printf("��� �ݾ��� �����̽��ϴ�!");
                Sleep(1000);
                break;
            }
            else
                player_money -= money;

        }

        else {

            printf("\n�÷��̾� �¸�!\n");

            printf("%d���� ������ϴ�\n", 2 * money);


            if (ALL_IN == 1)
            {
                printf("system : ALL IN : ���� �ݾ��� 3�踦 ����ϴ�.");
                player_money += money * 3;
            }
            else
                player_money += money;

        }

        printf("������ ������ ������ 0�� �����ֽð� �ƴϸ� 1�� �����ּ���.");
        scanf("%d", &endn);

        if (endn == 0)
            break;

        c_time++;

        clear();
    }

    printf("\n");

    return 0;

}