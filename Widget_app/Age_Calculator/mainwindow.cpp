#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

struct Age
{
    int Day ;
    int Month ;
    int Year ;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Calculate_clicked()
{
    // -------------------------------------

    struct Age Born ;
    struct Age Today ;
    struct Age Difference ;

    // -------------------------------------

    int flag = -1 , flag_2 = -1 , flag_3 = -1 ;

    // flag   -> Leap Year Control
    // flag_2 -> Loop Control
    // flag_3 -> Leap Year Control ( Born Day , Next Born Day )

    // -------------------------------------

    int Change = -1 ; // Year control

    // -------------------------------------

    Born.Year = ui->Born_Year->text().toInt() ;

    if(Born.Year<1)
    {
        QMessageBox::information(this,"Syntax Error","Please enter Born Year again ") ;
        Born.Year = 1 ;
        ui->Born_Year->clear() ;
        ui->Born_Year->setText(QString::number(Born.Year)) ;
    }

    // -------------------------------------

    if((Born.Year)%4 == 0) // Leap Year Control
    {
        if(((Born.Year)%100 == 0)&&((Born.Year)%400 == 0))
        {
            flag = 1 ;
        }
        else if((Born.Year)%100 != 0)
        {
            flag = 1 ;
        }
    }

    else {

        flag = 0 ;
    }


    // -------------------------------------

    Born.Month = ui->Born_Month->text().toInt() ;

    if(( Born.Month < 1)||(Born.Month > 12))
    {
        QMessageBox::information(this,"Syntax Error","Please Enter Born Month again") ;
        Born.Month = 1 ;
        ui->Born_Month->clear() ;
        ui->Born_Month->setText(QString::number(Born.Month)) ;
        flag_2 = 0 ;
    }

    // -------------------------------------

    Born.Day   = ui->Born_Day->text().toInt() ;

    if(flag_2 != 0 )
    {
        if(Born.Month == 2) // February
        {
            if(flag == 0)
            {
                if(Born.Day<29) // Leap Year -> False (28)
                {
                    flag_2 = 1 ;

                }

                else {
                    flag_2 = 0 ;
                }
            }

            else if (flag == 1) // Leap Year -> True ( 29 )
            {
                if(Born.Day<30)
                {
                    flag_2 = 1 ;

                }

                else {
                    flag_2 = 0 ;
                }
            }
        }


        else if ((Born.Month == 4)||(Born.Month == 6)||(Born.Month == 9)||(Born.Month == 11)) // April ,June ,September,November
        {
            if(Born.Day < 31 )
            {
                flag_2 = 1 ;

            }
            else {
                flag_2 = 0 ;
            }
        }

        else if ((Born.Month == 1)||(Born.Month == 3)||(Born.Month == 5)||(Born.Month == 7)||(Born.Month == 8)||(Born.Month == 10)||(Born.Month == 12))
        {
            if(Born.Day < 32) // January,March,May,July,August,October,December
            {
                flag_2 = 1 ;
            }

            else {
                flag_2 = 0 ;
            }

        }
    }

    // -------------------------------------


    else {


        if(flag_2 == 0)
        {
            QMessageBox::information(this,"Syntax Error","Please enter Born Day again") ;
            Born.Day = 1 ;
            ui->Born_Day->clear() ;
            ui->Born_Day->setText(QString::number(Born.Day)) ;
        }
    }
    // -------------------------------------

    int Control = -1 ;

    Today.Year = ui->Today_Year->text().toInt() ;

    if((Today.Year<1)||(Today.Year < Born.Year ))
    {
        QMessageBox::information(this,"Syntax Error","Please enter Today Year again") ;
        Today.Year = 1 ;
        ui->Today_Year->clear() ;
        ui->Today_Year->setText(QString::number(Today.Year));
        Control = 1 ; // True
    }

    // -------------------------------------

    if((Today.Year)%4 == 0) // Leap Year Control
    {
        if(((Today.Year)%100 == 0)&&((Today.Year)%400 == 0))
        {
            flag = 1 ;
        }
        else if((Today.Year)%100 != 0)
        {
            flag = 1 ;
        }
    }

    else {

        flag = 0 ;
    }

    // -------------------------------------

    Today.Month = ui->Today_Month->text().toInt() ;

    if(( Today.Month < 1)||(Today.Month > 12))
    {
        QMessageBox::information(this,"Syntax Error","Please enter Today Month again") ;
        Today.Month = 1 ;
        ui->Today_Month->clear() ;
        ui->Today_Month->setText(QString::number(Today.Month)) ;
        flag_2 = 0 ;
    }

    // -------------------------------------

    Today.Day   = ui->Today_Day->text().toInt() ;

    if(flag_2 != 0 )
    {
        if(Today.Month == 2)
        {
            if(flag == 0) // February
            {
                if(Today.Day<29) // Leap Year -> false ( 28 )
                {
                    flag_2 = 1 ;

                }

                else {
                    flag_2 = 0 ;
                }
            }

            else if (flag == 1) // Leap Year -> true ( 29 )
            {
                if(Today.Day<30)
                {
                    flag_2 = 1 ;

                }

                else {
                    flag_2 = 0 ;
                }
            }
        }


        else if ((Today.Month == 4)||(Today.Month == 6)||(Today.Month == 9)||(Today.Month == 11))
        {
            if(Today.Day < 31 ) // April ,June ,September,November
            {
                flag_2 = 1 ;

            }

            else {
                flag_2 = 0 ;
            }
        }

        else if ((Today.Month == 1)||(Today.Month == 3)||(Today.Month == 5)||(Today.Month == 7)||(Today.Month == 8)||(Today.Month == 10)||(Today.Month == 12))
        {
            if(Today.Day < 32) // January,March,May,July,August,October,December
            {
                flag_2 = 1 ;
            }

            else {
                flag_2 = 0 ;
            }
        }
    }

    else {

        if(flag_2 == 0 )
        {
            QMessageBox::information(this,"Syntax Error","Please enter Today Day again") ;
            Today.Day = 1 ;
            ui->Today_Day->clear() ;
            ui->Today_Day->setText(QString::number(Today.Day)) ;
        }
    }
    // -------------------------------------

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

           else {
               Control = 1 ;
           }
       }

    }



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

    // -------------------------------------

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

    // -------------------------------------

    Difference.Year = Today.Year  - Born.Year ;

    ui->Age->setText(QString::number(Difference.Year)) ;
    ui->Different_Year->setText(QString::number(Difference.Year))  ;
    ui->Different_Month->setText(QString::number(Difference.Month))  ;
    ui->Different_Day->setText(QString::number(Difference.Day));

    // -------------------------------------

    int Result = 0 , Result_2 = 0 , Counter = 1 ;

    // Result   -> Last Year Total Day
    // Result_2 -> Total Day
    // Counter

    int i = 0; // Loop variable

    // -------------------------------------

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

    ui->Total_Hour->setText(QString::number(Result_2*24)) ;
    ui->Total_Minute->setText(QString::number((Result_2*24)*60)) ;
    ui->Total_Second->setText(QString::number(((Result_2*24)*60)*60)) ;
    ui->Total_Days->setText(QString::number(Result_2)) ;
    ui->Total_Weeks->setText(QString::number(Result_2/7)) ;
    ui->Total_Months->setText(QString::number((Difference.Year*12)+Difference.Month)) ;


    // -------------------------------------

    int BirthDay_Day = -1 ;

    int YearCode = -1 ;
    int Ref_Yea_Day = -1 ; // Reference Year Code
    int Ref_Day = -1 ; // Reference Day
    int Ref_Day_Res = -1 ; // Reference Day Res
    int T_Div = -1 ; // Division
    int T_Mod = -1 ; // Module
    int T_Lea = -1 ;
    int G = -1 ; // Formula
    int Last_Ref = -1  ; // Last Reference

    int Tod_YearCode = -1 ; // Today Year Code

    // -------------------------------------

    YearCode = Born.Year % 1000 ;
    YearCode = YearCode % 100 ;

    // -------------------------------------

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

    Ref_Day_Res = Born.Day - Ref_Day ;

    while(Ref_Day_Res > 7 )
    {
        Ref_Day_Res = Ref_Day_Res - 7 ;
    }

    T_Div = YearCode/12 ;
    T_Mod = YearCode%12 ;

    T_Lea = T_Mod/4 ;

    G = (YearCode + (YearCode/4))%7 ;

    Last_Ref = (Ref_Yea_Day + ((T_Div + T_Mod + T_Lea + Ref_Day_Res)%7))%7 ;

    // -------------------------------------

    switch(Last_Ref)
    {
    case 0 :
        ui->Res_Born_Day->setText("Sunday") ;
        break ;
    case 1 :
        ui->Res_Born_Day->setText("Monday") ;
        break ;

    case 2 :
        ui->Res_Born_Day->setText("Tuesday") ;
        break ;

    case 3 :
        ui->Res_Born_Day->setText("Wednesday") ;
        break ;

    case 4 :
        ui->Res_Born_Day->setText("Thursday") ;
        break ;

    case 5 :
        ui->Res_Born_Day->setText("Friday") ;
        break ;

    case 6 :
        ui->Res_Born_Day->setText("Saturday") ;
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
        ui->Next_BirthDay->setText(QString::number(365-(Difference.Day+Result))) ;

    }

    else if(flag_3 == 1)
    {
        ui->Next_BirthDay->setText(QString::number(366-(Difference.Day+Result))) ;

    }



    // -------------------------------------


    if(Change == 1)
    {
        Today.Year++ ;
    }

    for( i=0 ; i<2 ; i++)
    {


        Tod_YearCode = (Today.Year) % 1000 ;
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

        if(i==0)
        {
            switch(Last_Ref)
            {
            case 0 :
                ui->Next_Born_Day->setText("Sunday") ;
                ui->Today_Year_info->setText(QString::number(Today.Year)) ;
                break ;
            case 1 :
                ui->Next_Born_Day->setText("Monday") ;
                ui->Today_Year_info->setText(QString::number(Today.Year)) ;
                break ;

            case 2 :
                ui->Next_Born_Day->setText("Tuesday") ;
                ui->Today_Year_info->setText(QString::number(Today.Year)) ;
                break ;

            case 3 :
                ui->Next_Born_Day->setText("Wednesday") ;
                ui->Today_Year_info->setText(QString::number(Today.Year)) ;
                break ;

            case 4 :
                ui->Next_Born_Day->setText("Thursday ") ;
                ui->Today_Year_info->setText(QString::number(Today.Year)) ;
                break ;
            case 5 :
                ui->Next_Born_Day->setText("Friday") ;
                ui->Today_Year_info->setText(QString::number(Today.Year)) ;
                break ;

            case 6 :
                ui->Next_Born_Day->setText("Saturday") ;
                ui->Today_Year_info->setText(QString::number(Today.Year)) ;
                break ;
            }
        }

        else if(i==1){

            switch(Last_Ref)
            {
            case 0 :
                ui->Next_Born_Day_2->setText("Sunday") ;
                ui->Next_Year_info->setText(QString::number(Today.Year)) ;
                break ;
            case 1 :
                ui->Next_Born_Day_2->setText("Monday") ;
                ui->Next_Year_info->setText(QString::number(Today.Year)) ;
                break ;

            case 2 :
                ui->Next_Born_Day_2->setText("Tuesday") ;
                ui->Next_Year_info->setText(QString::number(Today.Year)) ;
                break ;

            case 3 :
                ui->Next_Born_Day_2->setText("Wednesday") ;
                ui->Next_Year_info->setText(QString::number(Today.Year)) ;
                break ;

            case 4 :
                ui->Next_Born_Day_2->setText("Thursday ") ;
                ui->Next_Year_info->setText(QString::number(Today.Year)) ;
                break ;
            case 5 :
                ui->Next_Born_Day_2->setText("Friday") ;
                ui->Next_Year_info->setText(QString::number(Today.Year)) ;
                break ;

            case 6 :
                ui->Next_Born_Day_2->setText("Saturday") ;
                ui->Next_Year_info->setText(QString::number(Today.Year)) ;
                break ;
            }
        }

        Today.Year++ ;
    }

  }

}


