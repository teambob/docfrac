//---------------------------------------------------------------------------
#ifndef tdoxH
#define tdoxH


class TDox
{
public:
    TDox();
    ~TDox();

    void SetInFileName(const std::string &Filename);
    void SetOutFileName(const std::string &Filename);
    bool FileConvert();



    void SetInString(const std::string &in);
    std::string StringConvert(void);

    void SetInFormat(const std::string &Extension);
    void SetOutFormat(const std::string &Extension);

    int DebugOn;

private:
    std::string inBuffer;
    std::string outBuffer;

    int inFormat;  /* Automatic or RTF to HTML */
    int outFormat; /* Automatic or RTF to HTML */

    int Ext2For(const char *Extension);

    bool UseInString;
};

//---------------------------------------------------------------------------
#endif
