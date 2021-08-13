#pragma once

#include "..//inode.h"

// text collection
class CXI_STRCOLLECTION : public CINODE
{
  public:
    CXI_STRCOLLECTION(CXI_STRCOLLECTION &&) = delete;
    CXI_STRCOLLECTION(const CXI_STRCOLLECTION &) = delete;
    CXI_STRCOLLECTION();
    ~CXI_STRCOLLECTION() override;

    void Draw(bool bSelected, uint32_t Delta_Time) override;
    bool Init(INIFILE *ini1, const char *name1, INIFILE *ini2, const char *name2, VDX9RENDER *rs, XYRECT &hostRect,
              XYPOINT &ScreenSize) override;
    void ReleaseAll() override;
    int CommandExecute(int wActCode) override;
    bool IsClick(int buttonID, long xPos, long yPos) override;

    void MouseThis(float fX, float fY) override
    {
    }

    bool GetInternalNameList(std::vector<std::string> &aStr) override;
    void SetInternalName(std::string &sName) override;
    void ChangePosition(XYRECT &rNewPos) override;
    void SaveParametersToIni() override;
    uint32_t MessageProc(long msgcode, MESSAGE &message) override;

    void ChangeString(long num, const char *sValue) const;
    void ChangeStringColor(long num, uint32_t dwColor) const;
    void ChangeStringPos(long num, XYPOINT &pntNewPos) const;

  protected:
    struct STRINGDESCR
    {
        char *sFontName;
        int nFontNum;
        long strNum;
        char *strStr;
        char *strID;
        XYPOINT scrPos;     // screen position for string show
        uint32_t foreColor; // color of font
        uint32_t backColor; // color of the font background
        int wAlignment;     // print text alignment
        bool bShadow;       // do shadow
        float fScale;       // scale for string out
    };

  protected:
    void LoadIni(INIFILE *ini1, const char *name1, INIFILE *ini2, const char *name2) override;
    STRINGDESCR *CreateNewDinamicString(const char *strID, const char *strStr);

  protected:
    int m_nStr;               // string quantity
    STRINGDESCR *m_pStrDescr; // pointer to array of the string descriptors
    long m_nEditIndex;
};