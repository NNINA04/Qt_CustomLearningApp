//#include "EnglishLearning.h"
//#include "PhrasesManager_Lib/HandlersExecutioner.h"
//#include "PhrasesManager_Lib/WhiteSpacesRemover.h"
//#include "PhrasesManager_Lib/Trimmer.h"

#include "MainWindow.h"
#include "AddPhraseButton.h"

/*
using namespace std;

static void PrintWrongAnsweredPhrases(const EnglishLearning::Enumerable& phrases)
{
    for (auto& item : phrases)
        cout << "En: " << item.first
        << "\tRu: " << item.second << endl;
}
*/

size_t allocated = 0;

_NODISCARD _Ret_notnull_ _Post_writable_byte_size_(_Size) _VCRT_ALLOCATOR
void* __CRTDECL operator new(size_t _Size)
{
    allocated += _Size;
    return malloc(_Size);
}

void __CRTDECL operator delete(void* obj, size_t size)
{
    allocated -= size;
    qDebug() << allocated;
    free(obj);
}

int main(int argc, char* argv[])
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
        {"He said that he'd done it the day before", "�� ������ ��� ������ ��� ����� (���� �����)"},
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
    MainWindow englishLearning;
    englishLearning.show();
    return app.exec();
}