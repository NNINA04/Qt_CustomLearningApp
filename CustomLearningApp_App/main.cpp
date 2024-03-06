//#include "EnglishLearning.h"
//#include "PhrasesManager_Lib/HandlersExecutioner.h"
//#include "PhrasesManager_Lib/WhiteSpacesRemover.h"
//#include "PhrasesManager_Lib/Trimmer.h"

#include "MainWindow.h"

/*
using namespace std;

static void PrintWrongAnsweredPhrases(const EnglishLearning::Enumerable& phrases)
{
    for (auto& item : phrases)
        cout << "En: " << item.first
        << "\tRu: " << item.second << endl;
}
*/

#pragma region MemoryAnalyzingArea
#pragma warning(push)
#pragma warning(disable: 28196)
#pragma warning(disable: 28251)
#pragma warning(disable: 6387)
size_t allocated = 0;

void* operator new(size_t _Size)
{
    allocated += _Size;
    return malloc(_Size);
}

void operator delete(void* obj, size_t size)
{
    allocated -= size;
    qDebug() << allocated;
    free(obj);
}
#pragma warning(pop)
#pragma endregion

int main(int argc, char* argv[]) // Make an insertion an image for learning (to be optional for user)
{
    /*
    setlocale(LC_ALL, "ru-RU");
    srand((unsigned int)time(NULL));
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    EnglishLearning::Enumerable phrases
    {
        {"I have a few ideas", "� ���� ���� ��������� ����"},
        {"She has lots of mistakes", "� �� ����� ������"},
        {"It's far more honest", "��� ������� �������"},
        {"For further information follow this link", "��� ���������� ���������� ����������� �� ���� ������"},
        {"I started making much fewer mistakes", "� ����� ������ ������� ������ ������"},
        {"He asked me what her job was", "�� ������� � ����, ����� � �� ������"},
        {"He asked me if I agreed", "�� ������� ����, ��� �� � ��������"},
        {"I want to speak English as well as you", "� ���� �������� �� ���������� ����� ������ ��� � ��"},
        {"His English level is lower than mine", "��� ������� ����������� ���� ��� ���"},
        {"He said that he'd done it the day before", "�� ������ ��� ������ ��� ����� (��� �����)"},
        {"", ""},
        {"", ""},
        {"", ""},
    };

    HandlersExecutioner<EnglishLearning::Enumerable> hExec;
    hExec.AddHandler(new Trimmer());
    hExec.AddHandler(new WhiteSpacesRemover());
    hExec.Handle(phrases);

    EnglishLearning en(phrases);
    en.AsksEnglish = false;

    while (en.empty() == false) // ���� �� ����������������, �� ���� �� ��������
    {
        en.AskPhrase();
        cout << endl;
    }

    auto& wrongAnswers = en.GetWrongAnsweredPhrases();
    if (wrongAnswers.empty() == false)
    {
        cout << "Press ENTER to see the wrong answers" << endl;
        cin.get();
        cout << "The wrong answers:" << endl;
    }
    PrintWrongAnsweredPhrases(wrongAnswers);
    */

    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}