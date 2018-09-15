#include "main.h"
#include "classes/Sentences.h"

void loadTextFromFile();
void createFile(std::ifstream &fileInput, std::ofstream &fileOutput, std::ofstream &fileOutputUser);
void checkTextFromFile();

int main() {
    std::cout << "Welcome to punctuation training program.\nChoose your variant:\n"
              << "1) Load text from file\n"
              << "2) Check edited file\n"
              << "3) Exit\n";
    char userMenuInput = 0;
    std::cin >> userMenuInput;
    switch (userMenuInput) {
        case '1':
            loadTextFromFile();
            break;
        case '2':
            checkTextFromFile();
            break;
        case '3':
            break;
        default:break;
    }
    return 0;
}

void loadTextFromFile() {
    // Input object creation
    std::string fileName = "/Users/dankondr/CLionProjects/Punctuation/files/";
    std::cout << "Enter the file name: ";
    std::string input;
    std::cin >> input;
    fileName += input;
    std::ifstream fileInput(fileName);
    if (!fileInput.is_open()) {
        std::cout << "File isn't found\n";
        return;
    }
    fileInput >> std::noskipws;
    // Output objects creation
    size_t lastIndex = fileName.find_last_of('.');
    std::string outputFileName = fileName.substr(0, lastIndex) + "_comp.txt";
    std::ofstream fileOutput(outputFileName);

    outputFileName = fileName.substr(0, lastIndex) + "_user.txt";
    std::ofstream fileOutputUser(outputFileName);
    // Creation of file which contains text without punctuation marks
    createFile(fileInput, fileOutput, fileOutputUser);

    fileOutput.close();
    fileOutputUser.close();
    fileInput.close();
}

void createFile(std::ifstream &fileInput, std::ofstream &fileOutput, std::ofstream &fileOutputUser) {
    std::string tmpLine;
    size_t size = 0;
    int serialNumber = 0;
    char ch;
    char prevCh = '\0';
    while (fileInput >> ch) {
        size++;
        if (ch == '\n' || (ch == ' ' && prevCh == '.'))
            continue;
        tmpLine += ch;
        if (tmpLine.back() == '.') {
            serialNumber++;
            Sentences sentence1(tmpLine, size, serialNumber);
            fileOutput << sentence1.getSentence() << std::endl;
            fileOutputUser << sentence1.getSentenceRaw() << std::endl;
            size = 0;
            tmpLine.clear();
        }
        prevCh = ch;
    }
}

void checkTextFromFile() {
    std::string fileName = "/Users/dankondr/CLionProjects/Punctuation/files/";
    std::cout << "Enter the file name: ";
    std::string input;
    std::cin >> input;
    fileName += input;
    size_t lastIndex = fileName.find_last_of('.');
    fileName = fileName.substr(0, lastIndex) + "_comp.txt";
    std::ifstream fileComp(fileName);
    fileName = fileName.substr(0, lastIndex) + "_user.txt";
    std::ifstream fileUser(fileName);
    fileName = fileName.substr(0, lastIndex) + "_mistakes.txt";
    std::ofstream fileMistakes(fileName);
    // Check for mistakes
    while (!fileComp.eof()) {
        std::string lineComp;
        std::string lineUser;
        getline(fileComp, lineComp);
        getline(fileUser, lineUser);
        if (lineComp != lineUser) {
            fileMistakes << lineUser << std::endl << lineComp << std::endl;
            fileMistakes << "Amount of mistakes: " << lineComp.size() - lineUser.size() << std::endl << std::endl;
        }
    }
}



