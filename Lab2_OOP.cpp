#include <iostream>

using namespace std;

class Date {            //оголошенн€ класу дати
private:
    int* DATE;

public:
    Date()           //конструктор без параметр≥в
    {
        DATE = new int[3];
        for (int i = 0; i < 3; i++)
            DATE[i] = 0;
    }
    Date(int *DATE)          //конструктор з параметром
    {
        this->DATE = new int[3];
        for (int i = 0; i < 3; i++)
            this->DATE[i] = DATE[i];
    }
    Date(const Date& obj)       //конструктор коп≥юванн€
    {
        this->DATE = new int[3];
        for (int i = 0; i < 3; i++)
            this->DATE[i] = obj.DATE[i];
    }
    ~Date() { delete[] DATE; }          //деструктор

    // методи класу
    int SetDate(int *DATE)        //встановити нову дату
    {
        this->DATE = new int[3];
        if ((DATE[0] < 1 || DATE[0] > 31) || (DATE[1] < 1 || DATE[1] > 12))
        {
            cout << "Incorrectly entered date!!!" << endl;
            system("pause");
            return 0;
        }
        else
            for (int i = 0; i < 3; i++)
                this->DATE[i] = DATE[i];
    }

    void Print1()                           //вив≥д дати у формат≥ - d/m/y р. 
    {
        cout << "Date in format d/m/y: " << DATE[0] << "/" << DATE[1] << "/" << DATE[2] << " р." << endl;
    }
    void Print2()                           //вив≥д дати у формат≥ - y-m-d
    {
        cout << "Date in format y-m-d: " << DATE[2] << "-" << DATE[1] << "-" << DATE[0] << endl;
    }

    int Bissextile(int y)                   //перев≥рка чи Ї заданий р≥к високосним
    {
        return ((this->DATE[2] % 100 != 0) && (this->DATE[2] % 4 == 0)) || (this->DATE[2] % 400 == 0);
    }
    int DaysInMonth()          //к≥льк≥сть дн≥в у введеному м≥с€ц≥
    {
        int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (Bissextile(DATE[2]))
            arr[1] = 29;
        return arr[DATE[1]-1];
    }
    void DateNext()         //зб≥льшенн€ значенн€ дати на 1 день
    {
        DATE[0]++;
        if (DATE[0] > DaysInMonth())
        {
            DATE[0] = 1;
            DATE[1]++;
        }
        if (DATE[1] > 12)
        {
            DATE[1] = 1;
            DATE[2]++;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int* arr1;
    arr1 = new int[3];
    Date date;
    cout << "\n" << "Enter the day: ";
    cin >> arr1[0];
    cout << "Enter the month: ";
    cin >> arr1[1];
    cout << "Enter the year: ";
    cin >> arr1[2];
    date.SetDate(arr1);
    date.Print1();
    date.Print2();
    Date* obj1 = new Date;
    Date obj2(date);
    cout << "\n" << "Implementation of constructors:" << endl;
    obj1->Print1();
    obj1->Print2();
    cout << endl;
    obj2.Print1();
    obj2.Print2();
    cout << "\n" << "Increment a date by one day: " << endl;
    date.DateNext();
    date.Print1();
    date.Print2();
    system("pause");
    return 0;
}