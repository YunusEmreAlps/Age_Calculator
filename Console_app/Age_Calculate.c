// Structure

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Age
{
    int Day ;
    int Month ;
    int Year ;

} Born, Today, Difference ;

void Birth(int Birt) ; // Next Birthday Day
void Driver_Licence(int Age) ; // Driver License
void Horoscopes(int B_Day,int B_Month) ; // Horoscopes

int Born_Leap(int B_Year) ; // Calculate Born Leap Year
int Today_Leap(int T_Year) ; // Calculate Today Leap Year

int main()
{
    while(1)
    {

        int flag = -1, flag_2 = -1 ;

        // flag -> Leap Year Control
        // flag_2 -> Loop Control

        printf("\n ---------- \n\n") ;

        printf(" Please enter a Born Year : ") ;

        while(1) // Born Year Control
        {
            scanf("%d",&Born.Year) ;

            if(Born.Year > 0)
            {
                break ;
            }
            while(getchar() != '\n') ; // Control Char
            printf(" Please try again : ") ;


        }

        // -------------------------------------

        flag = Born_Leap(Born.Year) ;

        // -------------------------------------

        printf("\n ---------- \n\n") ;

        printf(" Please enter a Born month : ") ;

        while(1) // Born Month Control
        {
            scanf("%d",&Born.Month) ;

            if(( Born.Month > 0)&&(Born.Month < 13))
            {
                break ;
            }
            while(getchar() != '\n') ; // Control Char
            printf(" Please try again : ") ;

        }

        // -------------------------------------

        printf("\n ---------- \n\n") ;

        printf(" Please enter a Born day : ") ;

        while(1) // Born Day Control
        {
            scanf("%d",&Born.Day) ;

            if(Born.Month == 2) // February
            {
                if(flag == 0)
                {
                    if(Born.Day<29) // Leap Year -> False (28)
                    {
                        flag_2 = 1 ;

                    }
                }

                else if (flag == 1) // Leap Year -> True ( 29 )
                {
                    if(Born.Day<30)
                    {
                        flag_2 = 1 ;

                    }
                }
            }


            else if ((Born.Month == 4)||(Born.Month == 6)||(Born.Month == 9)||(Born.Month == 11)) // April ,June ,September,November
            {
                if(Born.Day < 31 )
                {
                    flag_2 = 1 ;

                }
            }

            else if ((Born.Month == 1)||(Born.Month == 3)||(Born.Month == 5)||(Born.Month == 7)||(Born.Month == 8)||(Born.Month == 10)||(Born.Month == 12))
            {
                if(Born.Day < 32) // January,March,May,July,August,October,December
                {
                    flag_2 = 1 ;

                }
            }

            if(flag_2 == 1)
            {
                break ;
            }
            while(getchar() != '\n') ; // Control Char
            printf(" Please try again : ") ;


        }

        // -------------------------------------

        printf("\n ---------- \n\n") ;

        flag = -1, flag_2 = -1 ;

        // flag -> Leap Year Control
        // flag_2 -> Loop Control

        printf(" Please enter a This Year : ") ;

        while(1) // Today Year Control
        {
            scanf("%d",&Today.Year) ;

            if(( Today.Year > 0 )&&(Today.Year >= Born.Year ))
            {
                break ;
            }
            while(getchar() != '\n') ; // Control Char
            printf(" Please try again : ") ;


        }

        // -------------------------------------

        flag = Today_Leap(Today.Year) ;

        // -------------------------------------

        printf("\n ---------- \n\n") ;

        printf(" Please enter a This month : ") ;

        while(1) // Today Month Control
        {
            scanf("%d",&Today.Month) ;

            if(( Today.Month > 0)&&(Today.Month < 13))
            {
                break ;
            }

            while(getchar() != '\n') ; // Control Char
            printf(" Please try again : ") ;
        }

        // -------------------------------------

        printf("\n ---------- \n\n") ;

        printf(" Please enter a This day : ") ;

        while(1) // Today Day Control
        {
            scanf("%d",&Today.Day) ;

            if(Today.Month == 2)
            {
                if(flag == 0) // February
                {
                    if(Today.Day<29) // Leap Year -> false ( 28 )
                    {
                        flag_2 = 1 ;

                    }
                }

                else if (flag == 1) // Leap Year -> true ( 29 )
                {
                    if(Today.Day<30)
                    {
                        flag_2 = 1 ;

                    }
                }
            }


            else if ((Today.Month == 4)||(Today.Month == 6)||(Today.Month == 9)||(Today.Month == 11))
            {
                if(Today.Day < 31 ) // April ,June ,September,November
                {
                    flag_2 = 1 ;

                }
            }

            else if ((Today.Month == 1)||(Today.Month == 3)||(Today.Month == 5)||(Today.Month == 7)||(Today.Month == 8)||(Today.Month == 10)||(Today.Month == 12))
            {
                if(Today.Day < 32) // January,March,May,July,August,October,December
                {
                    flag_2 = 1 ;
                }
            }

            if(flag_2 == 1)
            {
                break ;
            }
            while(getchar() != '\n') ; // Control Char
            printf(" Please try again : ") ;

        }

        printf("\n ---------- \n\n") ;

        int Control = -1 ;

        if(Born.Year == Today.Year)
        {
            if(Born.Month>Today.Month)
            {
                Control = 1 ;
            }

            else if (Born.Month==Today.Month)
            {
                if(Today.Day>Born.Day)
                {
                    Control = 0 ;
                }

                else
                {
                    Control = 1 ;
                }
            }

        }


        printf("\n ---------- \n\n") ;

        // -------------------------------------

        // Age Calculator

        if(Control != 1)
        {

            Difference.Day = Today.Day - Born.Day ;

            if(Difference.Day < 0 )
            {
                Today.Month-- ;

                if(Today.Month == 2)
                {
                    if(flag == 0)
                    {
                        Difference.Day = 28 + Difference.Day ;
                    }

                    else if (flag == 1)
                    {
                        Difference.Day = 29 + Difference.Day ;
                    }
                }


                else if ((Today.Month == 4)||(Today.Month == 6)||(Today.Month == 9)||(Today.Month == 11))
                {
                    Difference.Day = 30 + Difference.Day ;
                }

                else if ((Today.Month == 1)||(Today.Month == 3)||(Today.Month == 5)||(Today.Month == 7)||(Today.Month == 8)||(Today.Month == 10)||(Today.Month == 12))
                {
                    Difference.Day = 31 + Difference.Day ;
                }
            }

            int Change ;

            if(Born.Month > Today.Month)
            {
                Change = 1 ; // Today Year Control

                // For Example -> 2019

                Difference.Month = Today.Month - Born .Month ;
                Difference.Month = 12 + Difference.Month ;
                Today.Year-- ; // -> 2018

                // We need this variable Calculate Next Born Day
            }

            else
            {
                Difference.Month = Today.Month - Born .Month ;

            }

            Difference.Year = Today.Year  - Born.Year ;

            printf("\n ---------- \n\n") ;

            printf(" Your Age : %d \n",Difference.Year) ;
            printf(" Year : %d , Month : %d , Days : %d \n",Difference.Year,Difference.Month,Difference.Day) ;

            printf("\n ---------- \n\n") ;

            // -------------------------------------

            int Result = 0,Result_2 = 0, Counter = 1 ;

            int i ; // Loop variable

            // Result -> Last Year Total Day
            // Result_2 -> Total Day
            // Counter ->

            while(1) // Calculate Last One Year Total Days
            {
                if(Difference.Month == 0)
                {
                    break ;
                }


                if( Counter == 2)
                {
                    if (flag == 0)
                    {
                        Result = Result + 28 ;

                    }

                    else if (flag == 1)
                    {
                        Result = Result + 29 ;

                    }
                }

                if ((Counter == 4)||(Counter  == 6)||(Counter  == 9)||(Counter  == 11))
                {
                    Result = Result + 30 ;

                }

                if ((Counter == 1)||(Counter  == 3)||(Counter  == 5)||(Counter== 7)||(Counter == 8)||(Counter  == 10)||(Counter == 12))
                {
                    Result = Result + 31 ;


                }

                if(Counter == Difference.Month)
                {
                    printf("%d Month + %d Days : %d Total Days \n",Difference.Month,Difference.Day,Result+Difference.Day) ;
                    break ;
                }
                Counter++ ;
            }


            // -------------------------------------

            for( i=Born.Year ; i<Today.Year+1 ; i++ ) // Total Leap Day
            {
                if(i%4 == 0)
                {
                    if((i%100 == 0)&&(i%400 == 0))
                    {
                        Result_2++ ;
                    }
                    else if(i%100 != 0)
                    {
                        Result_2++ ;
                    }
                }

            }

            // -------------------------------------


            Result_2 += Difference.Day+Result + ((Difference.Year)*365) ; // Total Days


            printf("\n ---------- \n\n") ;

            printf(" Total Hour : %ld  \n",Result_2*24) ;
            printf(" Total Minute : %ld \n",(Result_2*24)*60) ;
            printf(" Total Second : %ld \n",((Result_2*24)*60)*60) ;
            printf(" Total Days : %d \n",Result_2) ;
            printf(" Total Week : %ld \n",Result_2/7) ;
            printf(" Total Month : %ld \n",(Difference.Year*12)+Difference.Month) ;

            // -------------------------------------


            int BirthDay_Day ;


            int YearCode = Born.Year % 1000 ;
            YearCode = YearCode % 100 ;

            // -------------------------------------


            int Ref_Yea_Day ;
            int Ref_Day ;

            // Reference Year Day -> Ref_Yea_Day

            /*
                 1600  2
                 1700  0
                 1800  5
                 1900  3
                 2000  2
                 2100  0
                 2200  3
                 2300  5


            */

            int flag_3 ; // Control 3

            if(Born.Year%4 == 0) // Leap Year Control
            {
                if((Born.Year%100 == 0)&&(Born.Year%400 == 0))
                {
                    flag_3 = 1 ;
                }
                else if(Born.Year%100 != 0)
                {
                    flag_3 = 1 ;
                }
            }

            else
            {
                flag_3 = 0 ;
            }



            if(( Born.Year - YearCode)%400 == 0)
            {
                Ref_Yea_Day = 2 ;

            }

            else if (( Born.Year - YearCode)%400 != 0)
            {
                if(( Born.Year - YearCode-100)%400 == 0)
                {
                    Ref_Yea_Day = 0 ;
                }

                else if(( Born.Year - YearCode-200)%400 == 0)
                {
                    Ref_Yea_Day = 5 ;
                }

                else if (( Born.Year - YearCode-300)%400 == 0)
                {
                    Ref_Yea_Day = 3 ;
                }
            }


            // Reference Day -> Ref Day

            if((Born.Month == 4)||(Born.Month == 6)||(Born.Month == 8)||(Born.Month == 10)||(Born.Month == 12))
            {
                Ref_Day = Born.Month ;
            }

            else if (Born.Month == 5)
            {
                Ref_Day = 9 ;
            }

            else if (Born.Month == 9)
            {
                Ref_Day = 5 ;
            }

            else if (Born.Month == 7)
            {
                Ref_Day = 11 ;
            }

            else if (Born.Month == 11)
            {
                Ref_Day = 7 ;
            }

            else if (Born.Month == 1)
            {
                if(flag_3 == 0)
                {
                    Ref_Day = 3 ;
                }

                else
                {
                    Ref_Day = 4 ;
                }
            }

            else if ((Born.Month == 2)||(Born.Month == 3))
            {
                if(flag_3 == 0)
                {
                    Ref_Day = 28%7 ;
                }

                else
                {
                    Ref_Day = 29%7 ;
                }
            }

            int Ref_Day_Res ;

            Ref_Day_Res = Born.Day - Ref_Day ;

            while(Ref_Day_Res > 7 )
            {
                Ref_Day_Res = Ref_Day_Res - 7 ;
            }

            int T_Div = YearCode/12 ;
            int T_Mod = YearCode%12 ;

            int T_Lea = T_Mod/4 ;

            int G = (YearCode + (YearCode/4))%7 ;

            int Last_Ref = (Ref_Yea_Day + ((T_Div + T_Mod + T_Lea + Ref_Day_Res)%7))%7 ;

// -------------------------------------

            switch(Last_Ref)
            {
            case 0 :
                printf(" Which were your born day : Sunday \n") ;
                break ;
            case 1 :
                printf(" Which were your born day : Monday \n") ;
                break ;

            case 2 :
                printf(" Which were your born day : Tuesday \n") ;
                break ;

            case 3 :
                printf(" Which were your born day : Wednesday \n") ;
                break ;

            case 4 :
                printf(" Which were your born day : Thursday \n") ;
                break ;

            case 5 :
                printf(" Which were your born day : Friday \n") ;
                break ;

            case 6 :
                printf(" Which were your born day : Saturday \n") ;
                break ;


            }

            // -------------------------------------


            if((Today.Year)%4 == 0) // Leap Year Control
            {
                if((((Today.Year+1)%100)== 0)&&(((Today.Year)%400)== 0))
                {
                    flag_3 = 1 ;
                }
                else if(((Today.Year)%100) != 0)
                {
                    flag_3 = 1 ;
                }
            }



            if(flag_3 == 0)
            {
                printf(" Next Birthday : %d Day \n",365-(Difference.Day+Result)) ;

            }

            else if(flag_3 == 1)
            {
                printf(" Next Birthday : %d Day \n",366-(Difference.Day+Result)) ;

            }



            // -------------------------------------

            if(Change == 1)
            {
                Today.Year++ ;
            }

            for( i=0 ; i<2 ; i++)
            {


                int Tod_YearCode = (Today.Year) % 1000 ;
                Tod_YearCode = (Today.Year)% 100 ;

                // -------------------------------------

                Ref_Yea_Day = -1 ;
                Ref_Day = -1 ;
                flag_3 = -1 ;


                // Reference Year Day -> Ref_Yea_Day

                /*
                     1600  2
                     1700  0
                     1800  5
                     1900  3
                     2000  2
                     2100  0
                     2200  5
                     2300  3

                */

                if((Today.Year)%4 == 0) // Leap Year Control
                {
                    if((((Today.Year+1)%100)== 0)&&(((Today.Year)%400)== 0))
                    {
                        flag_3 = 1 ;
                    }
                    else if(((Today.Year)%100) != 0)
                    {
                        flag_3 = 1 ;
                    }
                }

                else
                {
                    flag_3 =  0 ;
                }




                if(( Today.Year - Tod_YearCode)%400 == 0)
                {
                    Ref_Yea_Day = 2 ;

                }

                else if (( Today.Year - Tod_YearCode)%400 != 0)
                {
                    if(( Today.Year - Tod_YearCode-100)%400 == 0)
                    {
                        Ref_Yea_Day = 0 ;
                        //flag_3 = 0 ;
                    }

                    else if(( Today.Year - Tod_YearCode-200)%400 == 0)
                    {
                        Ref_Yea_Day = 5 ;
                        // flag_3 = 0 ;
                    }

                    else if (( Today.Year - Tod_YearCode-300)%400 == 0)
                    {
                        Ref_Yea_Day = 3 ;
                        //  flag_3 = 0 ;
                    }
                }


                // Reference Day -> Ref Day

                if((Born.Month == 4)||(Born.Month == 6)||(Born.Month == 8)||(Born.Month == 10)||(Born.Month == 12))
                {
                    Ref_Day = Born.Month ;
                }

                else if (Born.Month == 5)
                {
                    Ref_Day = 9 ;
                }

                else if (Born.Month == 9)
                {
                    Ref_Day = 5 ;
                }

                else if (Born.Month == 7)
                {
                    Ref_Day = 11 ;
                }

                else if (Born.Month == 11)
                {
                    Ref_Day = 7 ;
                }

                else if (Born.Month == 1)
                {
                    if(flag_3 == 0)
                    {
                        Ref_Day = 3 ;
                    }

                    else
                    {
                        Ref_Day = 4 ;
                    }
                }

                else if ((Born.Month == 2)||(Born.Month == 3))
                {
                    if(flag_3 == 0)
                    {
                        Ref_Day = 28%7 ;
                    }

                    else
                    {
                        Ref_Day = 29%7 ;
                    }
                }

                // 2019 -> 2019 - 19 = 2000 % 400 == 0
                // Ref_Yea_Day = 2
                // flag_3 = 1 ;
                // Ref_Day = 9 ;
                // Ref_Day_Res = 8 - 9 ; -1


                // T_Div = 1 ;
                // T_Mod = 7 ;
                // T_Lea = 1 ;
                // G = (19 + 4)%7 = 2

                // (1+7+1-1)%7 = 1+19 = 20%7 = 6 ;

                Ref_Day_Res = Born.Day - Ref_Day ;

                while(Ref_Day_Res > 7 )
                {
                    Ref_Day_Res = Ref_Day_Res - 7 ;
                }

                T_Div = 0, T_Mod = 0, T_Lea = 0, G = 0, Last_Ref = 0 ;

                T_Div = Tod_YearCode/12 ;
                T_Mod = Tod_YearCode%12 ;

                T_Lea = T_Mod/4 ;

                G = (Tod_YearCode + (Tod_YearCode/4))%7 ;

                Last_Ref = (Ref_Yea_Day + ((T_Div + T_Mod + T_Lea + Ref_Day_Res)%7))%7 ;

                Birth(Last_Ref) ;

                Today.Year++ ;
            }

            // -------------------------------------


            printf("\n ---------- \n\n") ;

            Driver_Licence(Difference.Year) ;

            // -------------------------------------

            printf("\n ---------- \n\n") ;

            Horoscopes(Born.Day,Born.Month) ;

        }

        if(Control == 1)
        {
            printf(" Error -> Born Date > Today Date ") ;
        }
        getch() ;

        system("CLS") ;

    }

    return 0 ;

}

int Born_Leap(int B_Year)
{
    if((B_Year)%4 == 0) // Leap Year Control
    {
        if(((B_Year)%100 == 0)&&((B_Year)%400 == 0))
        {
            return 1 ;
        }
        else if((B_Year)%100 != 0)
        {
            return 1 ;
        }
    }

    else
    {
        return 0 ;
    }
}

int Today_Leap(int T_Year)
{
    if((T_Year)%4 == 0) // Leap Year Control
    {
        if(((T_Year)%100 == 0)&&((T_Year)%400 == 0))
        {
            return 1 ;
        }
        else if((T_Year)%100 != 0)
        {
            return 1 ;
        }
    }

    else
    {
        return 0 ;
    }

}


void Birth(int Birt)
{

    switch(Birt)
    {
    case 0 :
        printf(" Next born day (%d): Sunday \n",Today.Year) ;
        break ;
    case 1 :
        printf(" Next born day (%d): Monday \n",Today.Year) ;
        break ;

    case 2 :
        printf(" Next born day (%d) : Tuesday \n",Today.Year) ;
        break ;

    case 3 :
        printf(" Next born day (%d): Wednesday \n",Today.Year) ;
        break ;

    case 4 :
        printf(" Next born day (%d): Thursday \n",Today.Year) ;
        break ;
    case 5 :
        printf(" Next born day (%d): Friday \n",Today.Year) ;
        break ;

    case 6 :
        printf(" Next born day (%d): Saturday \n",Today.Year) ;
        break ;


    }

}

void Driver_Licence(int Age)
{
    printf(" Driver Licence : ( TURKEY ) \n") ;

    if(Difference.Year > 15)
    {
        printf(" M \n B1 \n A1 \n") ;
    }

    if (Difference.Year > 18)
    {
        printf(" A2 \n B \n BE \n C1 \n C1E \n F \n G \n") ;
    }

    if(Difference.Year > 21 )
    {
        printf(" C \n CE \n D1 \n D1E \n") ;
    }

    if(Difference.Year > 24)
    {
        printf(" D \n DE \n") ;
    }

}



void Horoscopes(int B_Day,int B_Month)
{
    printf(" Horoscopes :  \n") ;

    if(((B_Month == 3)&&(B_Day>20))||((B_Month == 4)&&(B_Day<21)))
    {
        printf("\n Your Horoscopes : Aries (Koc)\n") ;
    }

    else if(((B_Month == 4)&&(B_Day>20))||((B_Month == 5)&&(B_Day<22)))
    {
        printf("\n Your Horoscopes : Taurus (Boga)") ;
    }

    else if(((B_Month == 5)&&(B_Day>21))||((B_Month == 6)&&(B_Day<23)))
    {
        printf("\n Your Horoscopes : Gemini (ikizler)") ;
    }

    else if(((B_Month == 6)&&(B_Day>22))||((B_Month == 7)&&(B_Day<23)))
    {
        printf("\n Your Horoscopes : Cancer (Yengec)") ;
    }

    else if(((B_Month == 7)&&(B_Day>22))||((B_Month == 8)&&(B_Day<23)))
    {
        printf("\n Your Horoscopes : Leo (Aslan)") ;
    }

    else if(((B_Month == 8)&&(B_Day>22))||((B_Month == 9)&&(B_Day<23)))
    {
        printf("\n Your Horoscopes : Virgo (Basak)") ;
    }

    else  if(((B_Month == 9)&&(B_Day>22))||((B_Month == 10)&&(B_Day<23)))
    {
        printf("\n Your Horoscopes : Libra (Terazi)") ;
    }

    else  if(((B_Month == 10)&&(B_Day>22))||((B_Month == 11)&&(B_Day<22)))
    {
        printf("\n Your Horoscopes : Scorpio (Akrep)") ;
    }

    else  if(((B_Month == 11)&&(B_Day>21))||((B_Month == 12)&&(B_Day<22)))
    {
        printf("\n Your Horoscopes : Sagittarius (Yay)") ;
    }
    else  if(((B_Month == 12)&&(B_Day>21))||((B_Month == 1)&&(B_Day<21)))
    {
        printf("\n Your Horoscopes : Capricorn (Oglak)") ;
    }
    else  if(((B_Month == 1)&&(B_Day>20))||((B_Month == 2)&&(B_Day<19)))
    {
        printf("\n Your Horoscopes : Aquarius (Kova)") ;
    }
    else  if(((B_Month == 2)&&(B_Day>18))||((B_Month == 3)&&(B_Day<21)))
    {
        printf("\n Your Horoscopes : Pisces (Balik)") ;
    }
}


