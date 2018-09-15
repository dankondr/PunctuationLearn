//
// Created by Даниил Кондратьев on 07.09.2018.
//

#ifndef PUNCTUATION_SENTENCES_H
#define PUNCTUATION_SENTENCES_H

#include "../main.h"

class Sentences {
private:
    std::string sentence;

    std::string sentenceRaw;

    size_t size;

    int serialNumber;

    bool replace(std::string& str, const std::string& from, const std::string& to);

public:
    const std::string &getSentence() const;

    size_t getSize() const;

    int getSerialNumber() const;

    Sentences(const std::string &sentence, size_t size, int serialNumber);

    const std::string &getSentenceRaw() const;
};


#endif //PUNCTUATION_SENTENCES_H
