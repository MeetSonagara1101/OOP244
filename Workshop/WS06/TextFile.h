#pragma once
#ifndef SENECA_TEXTFILE_H__
#define SENECA_TEXTFILE_H__
#include <iostream>

namespace seneca {
    const char m_prefix[3] = "C_";
    class Text;
    class Line
    {
        char* m_value{ nullptr };

        operator const char* () const;

        Line() {}
        ~Line();
        Line& operator=(const char*);

        friend class TextFile;
        // copy and copy assignment prevention goes here
    };

    class TextFile
    {

        Line* m_textLines{ nullptr };
        char* m_filename{ nullptr };
        unsigned m_noOfLines;
        unsigned m_pageSize;

        void setEmpty();
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName) const;


    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile& _copy_Obj);
        TextFile& operator=(const TextFile& _copy_Obj);
        ~TextFile();

        unsigned lines() const;
        const char* name() const;
        std::ostream& view(std::ostream& ostr) const;
        std::istream& getFile(std::istream& istr);
        const char* operator[](unsigned index) const;
        operator bool() const;
    };

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);
}
#endif // !SENECA_TEXTFILE_H_