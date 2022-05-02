#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct info
{
    int semnumber, sum, pdate, pmonth, pyear, bdate, bmonth, byear, date, month, year;
    float percentage, per1, per2, per3, per4, per5, per6, per7, per8, per9, per10;
    char name[20], fname[20];
    int CO, BOSS, DM, ESFP, DE;
    string address, fm_occupation, surname, enroll_number, cnumber;
} data[20];

class student
{
public:
    int i, m, j, count = 0, vowel = 0, year = 0, today = 0, highest = 0;
    void readdetails()
    {
    students:
        cout << "Enter Number Of Students:";
        cin >> m;
        if (m <= 1)
        {
            cout << "Minimum 2 Students Should Be Present." << endl;
            goto students;
        }
        for (i = 1; i <= m; i++)
        {
            ofstream obj;
            obj.open("PROJECT.txt", ios::app);
            //Student Name
            cout << "\nEnter Name Of Student " << i << ":";
            cin >> data[i].name >> data[i].surname;
            obj << "\nStudent " << i << " details" << endl
                << "Name:" << data[i].name << " " << data[i].surname << endl;

            //Enrollment Number
            cout << "Enter Enrollment Number Of Student " << i << ":";
            cin >> data[i].enroll_number;
            obj << "Enrollment Number:" << data[i].enroll_number << endl;

            //Contact Number
            cout << "Enter Contact Number Of Student " << i << ":";
            cin >> data[i].cnumber;
            obj << "Contact Number:" << data[i].cnumber << endl;

            //Father Name
            cout << "Enter Father Name Of Student " << i << ":";
            fflush(stdin);
            cin.getline(data[i].fname, 20);
            obj << "Father Name:" << data[i].fname << endl;

            //Occupation
            cout << "Enter Occupation Of Father/Mother Of Student " << i << ":";
            cin >> data[i].fm_occupation;
            obj << "Father Occupation:" << data[i].fm_occupation << endl;

            //Address
            cout << "Enter Address Of Student " << i << ":";
            fflush(stdin);
            cin >> data[i].address;
            obj << "Address:" << data[i].address << endl;

            //Sem Number
            cout << "Enter SEM Number Of Student " << i << ":";
            cin >> data[i].semnumber;
            obj << "SEM:" << data[i].semnumber << endl;

            //DOB
            cout << "Enter Date of Birth Related Details For Student " << i << ":" << endl;

            //Birth Date
            cout << "Enter Your Date Of Birth in DD MM YYYY form:";
            cin >> data[i].bdate >> data[i].bmonth >> data[i].byear;
            obj << "Birth Date:" << data[i].bdate << " Birth Month:" << data[i].bmonth << " Birth Year:" << data[i].byear << endl;

            //Present Date
            cout << "Enter Present Date in DD MM YYYY form:";
            cin >> data[i].pdate >> data[i].pmonth >> data[i].pyear;
            obj << "Present Date:" << data[i].pdate << " Present Date:" << data[i].pmonth << " Present Year:" << data[i].pyear << endl;

            //CO marks
        one:
            cout << "Enter Marks Of CO For Student " << i << ":";
            cin >> data[i].CO;
            if (data[i].CO > 100 || data[i].CO < 0)
            {
                cout << "Entered Marks Are Invalid So Enter Again." << endl;
                goto one;
            }
            obj << "CO Marks:" << data[i].CO << endl;

            //BOSS marks
        two:
            cout << "Enter Marks Of BOSS For Student " << i << ":";
            cin >> data[i].BOSS;
            if (data[i].BOSS > 100 || data[i].BOSS < 0)
            {
                cout << "Entered Marks Are Invalid So Enter Again." << endl;
                goto two;
            }
            obj << "BOSS Marks:" << data[i].BOSS << endl;

            //DM marks
        three:
            cout << "Enter Marks Of DM For Student " << i << ":";
            cin >> data[i].DM;
            if (data[i].DM > 100 || data[i].DM < 0)
            {
                cout << "Entered Marks Are Invalid So Enter Again." << endl;
                goto three;
            }
            obj << "DM Marks:" << data[i].DM << endl;

            //ESFP marks
        four:
            cout << "Enter Marks Of ESFP For Student " << i << ":";
            cin >> data[i].ESFP;
            if (data[i].ESFP > 100 || data[i].ESFP < 0)
            {
                cout << "Entered Marks Are Invalid So Enter Again." << endl;
                goto four;
            }
            obj << "ESFP Marks:" << data[i].ESFP << endl;

            //DE marks
        five:
            cout << "Enter Marks Of DE For Student " << i << ":";
            cin >> data[i].DE;
            if (data[i].DE > 100 || data[i].DE < 0)
            {
                cout << "Entered Marks Are Invalid So Enter Again." << endl;
                goto five;
            }
            obj << "DE Marks:" << data[i].DE << endl;
            obj.close();
        }
    }

    //Check Age
    void DOB()
    {

        int monthdate[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (i = 1; i <= m; i++)
        {
            data[i].year = data[i].pyear - data[i].byear;
            if (data[i].pmonth < data[i].bmonth)
            {
                data[i].year--;
                data[i].month = 12 - (data[i].bmonth - data[i].pmonth);
            }
            else if (data[i].pmonth <= data[i].bmonth && data[i].pdate < data[i].bdate)
            {
                data[i].year--;
                data[i].month = 12 - (data[i].bmonth - data[i].pmonth);
            }
            else
            {
                data[i].month = data[i].pmonth - data[i].bmonth;
            }
            if (data[i].pdate < data[i].bdate)
            {
                data[i].month--;
                data[i].date = monthdate[data[i].pmonth - 1] - (data[i].bdate - data[i].pdate);
            }
            else
            {
                data[i].date = data[i].pdate - data[i].bdate;
            }
        }
    }

    //Display all the students whose name starts with "s".
    void task11()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Name Of Student Whose Name Starts With 's':" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].name[0] == 's' || data[i].name[0] == 'S')
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "No Student Name Starts With s or S" << endl;
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students of semester 2,3 and 4.
    void task12()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Name Of Student Who Are From SEM 2,SEM 3 or SEM 4:" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].semnumber == 2 || data[i].semnumber == 3 || data[i].semnumber == 4)
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Student Is From SEM 2,SEM 3 or SEM 4" << endl;
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the name of studentswho are less than 20 years.
    void task13()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Name Of Student Who Are Less Than 20 Years:" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].year < 20)
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Student Is Of Age Less Than 20" << endl;
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students who are less than 20 years and lives in Ahmedabad.
    void task14()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Name Of Student Who Are Less Than 20 Years And Also Lives In Ahmedabad:" << endl;

        for (i = 1; i <= m; i++)
        {

            if (data[i].year < 20 && data[i].address == "Ahmedabad")
            {
                cout << data[i].name << endl;
                count++;
            }
            if (data[i].year < 20 && data[i].address == "ahmedabad")
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Student Is In Category Of Age Less Than 20 And Lives In Ahmedabad" << endl;
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students whose father’s name starts with the alphabet their students(child) name’s alphabet.
    void task15()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Name Of Student Whose Father's Name Starts With The Alphabet Their Students (Child) Name's Alphabet:" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].name[0] == data[i].fname[0])
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "No Student Name Starts With Their Father's Name's Alphabet" << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display allthe students who have cleared DE exam.
    void task21()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Name Of Student Who Cleared DE Exam" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].DE >= 40)
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Student Has Cleared DE's Exam\n"
                 << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students who have passed all the subjects.
    void task22()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Name Of Student Who Cleared All The Exam" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].DE >= 40 && data[i].CO >= 40 && data[i].BOSS >= 40 && data[i].DM >= 40 && data[i].ESFP >= 40)
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Student Has Cleared All Exam\n"
                 << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students who have Highest marks in DM in comparison to their individual marks in other subjects.
    void task23()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displyaing The Students Who Have Highest Marks In DM In Comparison To Their Individual Marks In Other Subjects" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].DM > data[i].CO && data[i].DM > data[i].BOSS && data[i].DM > data[i].ESFP && data[i].DM > data[i].DE)
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Student Has More Marks In DM Compared To Other Subjects In Exam" << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display  all  the  students  who  have  scored  less  than  60%  in  all  the  subjects together.
    void task24()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Students Who Have Scored Less Than 60% In All The Subjects Together" << endl;
        for (i = 1; i <= m; i++)
        {
            data[i].sum = data[i].CO + data[i].BOSS + data[i].DM + data[i].ESFP + data[i].DE;
            data[i].percentage = data[i].sum / 5;
            if (data[i].percentage < 60)
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Student Has Percentage Less Than 60" << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students who have scored more than 75% in three subjects.
    void task25()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Students Who Have Scored More Than 75% In Three Subjects" << endl;
        for (i = 1; i <= m; i++)
        {
            data[i].per1 = (data[i].CO + data[i].BOSS + data[i].DM) / 3;
            data[i].per2 = (data[i].CO + data[i].BOSS + data[i].ESFP) / 3;
            data[i].per3 = (data[i].CO + data[i].BOSS + data[i].DE) / 3;
            data[i].per4 = (data[i].CO + data[i].DM + data[i].ESFP) / 3;
            data[i].per5 = (data[i].CO + data[i].DM + data[i].DE) / 3;
            data[i].per6 = (data[i].CO + data[i].ESFP + data[i].DE) / 3;
            data[i].per7 = (data[i].BOSS + data[i].DM + data[i].ESFP) / 3;
            data[i].per8 = (data[i].BOSS + data[i].DM + data[i].DE) / 3;
            data[i].per9 = (data[i].BOSS + data[i].ESFP + data[i].DE) / 3;
            data[i].per10 = (data[i].DM + data[i].ESFP + data[i].DE) / 3;
            if (data[i].per1 > 75 || data[i].per2 > 75 || data[i].per3 > 75 || data[i].per4 > 75 || data[i].per5 > 75 || data[i].per6 > 75 || data[i].per7 > 75 || data[i].per8 > 75 || data[i].per9 > 75 || data[i].per10 > 75)
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Students Have Scored More Than 75% In Three Subjects" << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students who have two or more than 2 vowels in their name.
    void task31()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Students Who Have Two Or More Than 2 Vowels In Their Name" << endl;
        for (i = 1; i <= m; i++)
        {
            for (j = 0; j < strlen(data[i].name); j++)
            {
                if (data[i].name[j] == 'a' || data[i].name[j] == 'e' || data[i].name[j] == 'i' || data[i].name[j] == 'o' || data[i].name[j] == 'u')
                    vowel++;
            }
            if (vowel >= 2)
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Students Have Two Or More Than 2 Vowels In Their Name" << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students who have surname as patel or shah.
    void task32()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Name Of Student Who Have Their Surname As Patel And Shah" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].surname == "shah" || data[i].surname == "Shah" || data[i].surname == "patel" || data[i].surname == "Patel")
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Students Have Their Surname As Shah Or Patel\n"
                 << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students who have their entrepreneur parents.
    void task33()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying All The Students Who Have Their Entrepreneur Parents" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].fm_occupation == "entrepreneur" || data[i].fm_occupation == "Entrepreneur")
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Student Have Their Entrepreneur Parents\n"
                 << endl;
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the students who are 18 years and scored more than 70%.
    void task34()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Students Who Are 18 Years And Scored More Than 70%." << endl;
        for (i = 1; i <= m; i++)
        {
            data[i].sum = data[i].CO + data[i].BOSS + data[i].DM + data[i].ESFP + data[i].DE;
            data[i].percentage = data[i].sum / 5;
            if (data[i].year == 18 && data[i].percentage > 70)
            {
                cout << data[i].name << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "None Of The Students Are Of 18 Years And Scored More Than 70%" << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        count = 0;
    }

    //Display all the student/s who have scored highest in individual subjects.
    void task35()
    {
        cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Displaying The Student/s Who Have Scored Highest In Individual Subjects" << endl;
        cout << "Name Of Student Who Got Highest In CO:" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].CO >= highest)
            {
                highest = data[i].CO;
            }
        }
        for (i = 1; i <= m; i++)
        {
            if (data[i].CO == highest)
            {
                cout << data[i].name << endl;
            }
        }
        highest = 0;
        cout << "Name Of Student Who Got Highest In BOSS:" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].BOSS >= highest)
            {
                highest = data[i].BOSS;
            }
        }
        for (i = 1; i <= m; i++)
        {
            if (data[i].BOSS == highest)
            {
                cout << data[i].name << endl;
            }
        }
        highest = 0;
        cout << "Name Of Student Who Got Highest In DM:" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].DM >= highest)
            {
                highest = data[i].DM;
            }
        }
        for (i = 1; i <= m; i++)
        {
            if (data[i].DM == highest)
            {
                cout << data[i].name << endl;
            }
        }
        highest = 0;
        cout << "Name Of Student Who Got Highest In BOSS:" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].ESFP >= highest)
            {
                highest = data[i].ESFP;
            }
        }
        for (i = 1; i <= m; i++)
        {
            if (data[i].ESFP == highest)
            {
                cout << data[i].name << endl;
            }
        }
        highest = 0;
        cout << "Name Of Student Who Got Highest In DE:" << endl;
        for (i = 1; i <= m; i++)
        {
            if (data[i].DE >= highest)
            {
                highest = data[i].DE;
            }
        }
        for (i = 1; i <= m; i++)
        {
            if (data[i].DE == highest)
            {
                cout << data[i].name << endl;
            }
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        highest = 0;
    }
};

int main()
{
    student obj;
    obj.readdetails();
    obj.DOB();
    obj.task11();
    obj.task12();
    obj.task13();
    obj.task14();
    obj.task15();
    obj.task21();
    obj.task22();
    obj.task23();
    obj.task24();
    obj.task25();
    obj.task31();
    obj.task32();
    obj.task33();
    obj.task34();
    obj.task35();
    return 0;
}