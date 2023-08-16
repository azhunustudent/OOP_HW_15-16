#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// Реализуйте класс "Член Семьи".
// В классе заведите переменные : "Название члена семьи", "Текущий расход", "Суммарный расход" и пр.
// Реализуйте конструкторы, деструкторы, методы класса для доступа к переменным класса.
// В классе описать статическую переменную - "Бюджет семьи".
// Реализуйте статическую функцию установки исходного значения бюджета.
// Реализуйте метод класса - "расход из бюджета".Расход можно представить, как уменьшение бюджета на случайную ограниченную величину.
// 
// В программе объявить членов семьи, например: Мама, Папа, Дочь, Сын.
// Задать исходное значение бюджета.
// Каждый член такой семьи будет случайным образом расходовать бюджет до его обнуления.
// В итоге вывести общий расход каждого члена семьи.


class FamilyMember
{
private:
    static int FamBudget;
    string Name;
    int CurSpend;
    int TotalSpend;
public:
    FamilyMember() : Name(), CurSpend(), TotalSpend() {}
    FamilyMember(string name) : Name(name), CurSpend(), TotalSpend() {}
    FamilyMember(string name, int cur, int total) : Name(name), CurSpend(cur), TotalSpend(total) {}
    ~FamilyMember() {}

    string GetName()    { return Name; }
    int GetCurSpend()   { return CurSpend; }
    int GetTotalSpend() { return TotalSpend; }
     
    static void SetFamBudget(int val) { FamBudget = val; }
    static int GetFamBudget()         { return FamBudget; }

    void SpendFromBudget()
    {
        CurSpend = RAND(10, 100);
        if (CurSpend > FamBudget)
        {
            CurSpend = FamBudget;
        }
        FamBudget -= CurSpend;
        TotalSpend += CurSpend;
    }

};

int FamilyMember::FamBudget = 0;

int main() {
    FamilyMember mom("Mom");
    FamilyMember dad("Dad");
    FamilyMember daughter("Daughter");
    FamilyMember son("Son");

    int budget;
    cout << "Enter Budget of family: ";
    cin >> budget;
    FamilyMember::SetFamBudget(budget);

    while (FamilyMember::GetFamBudget() > 0)
    {
        mom.SpendFromBudget();
        dad.SpendFromBudget();
        daughter.SpendFromBudget();
        son.SpendFromBudget();
    }

    cout << "\nTotal Family Spends:\n";
    cout << mom.GetName() << "\t:" << mom.GetTotalSpend() << endl;
    cout << dad.GetName() << "\t:" << dad.GetTotalSpend() << endl;
    cout << daughter.GetName() << ":" << daughter.GetTotalSpend() << endl;
    cout << son.GetName() << "\t:" << son.GetTotalSpend() << endl;
}