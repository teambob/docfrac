#include <stdio.h>

int MonthLengths[] =     {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int LeapMonthLengths[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int MonthStarts[] =      {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
int LeapMonthStarts[] =  {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336};

int Int2Mime(long Value);
int IsLeapYear(int Year);
int DMY2Jul(int Day, int Month, int Year);

main()
{
int Year, Month, Day, Count;
unsigned long Jul, InvJul;
char Buffer[255];

printf("Year:");
scanf("%i", &Year);

printf("Month:");
scanf("%i", &Month);

printf("Date of month:");
scanf("%i", &Day);

Day = DMY2Jul(Day, Month, Year);

printf("Julian day: %i\n", Day);

Year -= 1900;
Jul = 1000*(long)Year + (long)Day;
InvJul = ~Jul;

printf("\n%li\n", Jul);

for (Count=0;Count<=5;Count++)
        {
        Buffer[Count] = Int2Mime(Jul>>((5-Count)*5));
        Buffer[Count+6] = Int2Mime(InvJul>>((5-Count)*5));
        }
Buffer[Count<<1]=0;
printf("\n%s\n", Buffer);
}

int Int2Mime(long Value)
{
Value &= 0x1F;
if ((Value>=0)&&(Value<=9))
        return Value + '0';
else if ((Value>=10)&&(Value<=35))
        return Value + 'a' - 10;
else if ((Value>=36)&&(Value<=62))
        return Value + 'A' - 36;
else return '(';
}

int DMY2Jul(int Day, int Month, int Year)
{
if (IsLeapYear(Year))
        return LeapMonthStarts[Month-1] + Day - 1;
else
        return MonthStarts[Month-1] + Day - 1;
}

int IsLeapYear(int Year)
{
int LeapYear = 0;
if (!(Year%4))
        {
        if (!(Year%100))
                {
                if (!(Year%400))
                        LeapYear = 1;
                }
        else
                LeapYear = 1;
        }

return LeapYear;
}

	
