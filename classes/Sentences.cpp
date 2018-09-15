//
// Created by Даниил Кондратьев on 07.09.2018.
//

#include "Sentences.h"

const std::string &Sentences::getSentence() const {
    return sentence;
}

size_t Sentences::getSize() const {
    return size;
}

int Sentences::getSerialNumber() const {
    return serialNumber;
}

Sentences::Sentences(const std::string &sentence, size_t size, int serialNumber) : sentence(sentence), size(size),
                                                                                   serialNumber(serialNumber) {
    std::string insertString = "(";
    insertString += std::to_string(serialNumber);
    insertString += ")";
    this->sentence.insert(0, insertString);


    char prevCh = '\0';
    for (const auto &ch : sentence) {
        if (ch == ',' || ch == ':')
            continue;
        else if (ch == '-') {
            if (prevCh == ' ')
                continue;
        }
        sentenceRaw += ch;
        prevCh = ch;
    }
    replace(sentenceRaw, "  ", " ");
    sentenceRaw.insert(0, insertString);
}

const std::string &Sentences::getSentenceRaw() const {
    return sentenceRaw;
}

bool Sentences::replace(std::string &str, const std::string &from, const std::string &to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

