#pragma once

/*
class EnglishLearning
{
public:
    using Enumerable = std::set<std::pair<std::string, std::string>>;
private:
    Enumerable _phrases;
    Enumerable _wrongAnsweredPhrases;
    Enumerable::iterator _akedPhrase;
public:
    bool AsksEnglish = true;

    EnglishLearning(Enumerable _phrases) 
        : _phrases(_phrases)
    {
    }

    void AskPhrase()
    {
        SetAskedPhrase();

        std::string askedPhrase = AsksEnglish
            ? (*_akedPhrase).first
            : (*_akedPhrase).second;

        std::cout << askedPhrase << std::endl;
        Answer();
        _phrases.erase(_akedPhrase);
    }

    bool empty()
    {
        return _phrases.empty();
    }

    const Enumerable& GetWrongAnsweredPhrases() const
    {
        return _wrongAnsweredPhrases;
    }
private:
    void SetAskedPhrase()
    {
        int randomNumber = rand() % _phrases.size();
        auto beginIter = begin(_phrases);
        _akedPhrase = next(beginIter, randomNumber);
    }

    void Answer()
    {
        std::cout << "Your answer: ";

        std::string clientAnswer;
        getline(std::cin, clientAnswer);

        const std::string& enPhrase = (*_akedPhrase).first;
        const std::string& ruPhrase = (*_akedPhrase).second;
        const std::string& correctAnswer = AsksEnglish ? ruPhrase : enPhrase;

        const size_t clientAnswerLength = clientAnswer.size();
        const size_t correctAnswerLength = correctAnswer.size();

        const std::string& shortestAnswer = clientAnswerLength > correctAnswerLength
            ? correctAnswer : clientAnswer;

        const std::string& longestAnswer = clientAnswerLength > correctAnswerLength
            ? clientAnswer : correctAnswer;

        const size_t shortestLength = shortestAnswer.size();
        const size_t longestLength = longestAnswer.size();
        int match = 0;
        for(size_t i = 0; i < shortestLength; i++)
        {
            if(shortestAnswer[i] == longestAnswer[i])
                ++match;
        }

        int answerCorrectness = (int)((100.0 / longestLength) * match);
        std::cout << "You answered " << answerCorrectness << "%" << std::endl;

        if(answerCorrectness < 100)
        {
            std::cout << "The correct answer is: " << correctAnswer << std::endl;
            _wrongAnsweredPhrases.emplace(enPhrase, ruPhrase);
        }
    }
};
*/