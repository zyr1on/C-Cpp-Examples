#include <poppler/cpp/poppler-document.h> // #include <poppler-document.h>
#include <poppler/cpp/poppler-page.h>     // #include <poppler-page.h>
#include <iostream>
#include <string>
bool isOnlySpace(const std::string& str) {
    for(char c:str)
        if(!std::isspace(c))
            return false;
    return true;
}
int main(int argc,char const *argv[]) {
    if(argc < 2) {
        std::cerr << "Enter PDF file > mypdfreader example.pdf" << std::endl;
        return 1;
    }
    std::string fileName = argv[1];
    poppler::document* document = poppler::document::load_from_file(fileName.c_str());
    if (!document) {
        std::cerr << "Error opening PDF file." << std::endl;
        return 1;
    }
    int numPages = document->pages();
    std::cout << numPages << "\n";
    for (int i = 0; i < numPages; ++i) {
        poppler::page* pdfPage = document->create_page(i);
        std::string textStr = pdfPage->text().to_utf8().data();
        if(!isOnlySpace(textStr))
            std::cout << "Page " << i + 1 << ":\n" << textStr << std::endl;
        delete pdfPage;
    }
    delete document;
    return 0;
}
