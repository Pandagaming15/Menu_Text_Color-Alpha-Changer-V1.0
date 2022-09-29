#include "mod/amlmod.h"
#include "mod/config.h"
#include "mod/logger.h"

#define sizeofA(__aVar)  ((int)(sizeof(__aVar)/sizeof(__aVar[0])))

MYMODCFG(net.pandagaming.NOP.menutextalphacolor, GTA:SA MenuTextAlphaColor, 1.0, Pandagaming&NOP);

#include "isautils.h"
ISAUtils* sautils = nullptr;

uintptr_t addr;

//config
ConfigEntry *menualpha;
ConfigEntry *menusmallr;
ConfigEntry *menusmallg;
ConfigEntry *menusmallb;
ConfigEntry *menuoutr;
ConfigEntry *menuoutg;
ConfigEntry *menuoutb;
ConfigEntry *menubigr;
ConfigEntry *menubigg;
ConfigEntry *menubigb;
ConfigEntry *bigoutr;
ConfigEntry *bigoutg;
ConfigEntry *bigoutb;

//Sautils Process
char szRetText[8];

/*menu alpha
menu_alpha_right = 0x2BAEA8 // 0xFF

    menu_alpha_left = 0x2BAEDC // 0x64
*/
void alpha(int oldVal, int newVal)
{
    menualpha->SetInt(newVal);
    *(char*)(addr +  0x2BAEA8) = newVal;
    *(char*)(addr + 0x2BAEDC) = newVal;;
    cfg->Save();
}
const char* alphadraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}

/*small
menu_small_textr = 0x2BB324 // 0xFF

    menu_small_textg = 0x2BB326 // 0xFF

    menu_small_textb = 0x2BB328 // 0xFF
*/
void smallr(int oldVal, int newVal)
{
    menusmallr->SetInt(newVal);
    *(char*)(addr +  0x2BB324) = newVal;
    cfg->Save();
}
const char* smallrdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void smallg(int oldVal, int newVal)
{
    menusmallg->SetInt(newVal);
    *(char*)(addr +  0x2BB326) = newVal;
    cfg->Save();
}
const char* smallgdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void smallb(int oldVal, int newVal)
{   
    menusmallb->SetInt(newVal);
    *(char*)(addr +  0x2BB328) = newVal;
    cfg->Save();
}
const char* smallbdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}

/*menu_outline
menu_small_outline_textr = 0x2BB350 // 0x0

    menu_small_outline_textg = 0x2BB352 // 0x0

    menu_small_outline_textb = 0x2BB354 // 0x0
*/
void moutr(int oldVal, int newVal)
{
    menuoutr->SetInt(newVal);
    *(char*)(addr + 0x2BB350) = newVal;
    cfg->Save();
}
const char* moutrdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void moutg(int oldVal, int newVal)
{
    menuoutg->SetInt(newVal);
    *(char*)(addr +  0x2BB352) = newVal;
    cfg->Save();
}
const char* moutgdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void moutb(int oldVal, int newVal)
{
    menuoutb->SetInt(newVal);
    *(char*)(addr +  0x2BB354) = newVal;
    cfg->Save();
}
const char* moutbdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}

/*big
menu_big_title_textr = 0x2BB538

    menu_big_title_textg = 0x2BB53A

    menu_big_title_textb = 0x2BB53C
*/
void bigr(int oldVal, int newVal)
{
    menubigr->SetInt(newVal);
    *(char*)(addr +  0x2BB538) = newVal;
    cfg->Save();
}
const char* bigrdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void bigg(int oldVal, int newVal)
{
    menubigg->SetInt(newVal);
    *(char*)(addr +  0x2BB53A) = newVal;
    cfg->Save();
}
const char* biggdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void bigb(int oldVal, int newVal)
{
    menubigb->SetInt(newVal);
    *(char*)(addr +  0x2BB53C) = newVal;
    cfg->Save();
}
const char* bigbdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}

/*big_outline
menu_big_title_outline_textr = 0x2BB54A
    menu_big_title_outline_textg = 0x2BB54C
    menu_big_title_outline_textb = 0x2BB54E
*/
void boutr(int oldVal, int newVal)
{
    bigoutr->SetInt(newVal);
    *(char*)(addr +  0x2BB54A) = newVal;
    cfg->Save();
}
const char* boutrdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void boutg(int oldVal, int newVal)
{
    bigoutg->SetInt(newVal);
    *(char*)(addr +  0x2BB54C) = newVal;
    cfg->Save();
}
const char* boutgdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void boutb(int oldVal, int newVal)
{
    bigoutb->SetInt(newVal);
    *(char*)(addr +  0x2BB54E) = newVal;
    cfg->Save();
}
const char* boutbdraw(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
//AML plugin entrance
extern "C" void OnModLoad()
{
	logger->SetTag("ColorMarker test plugin");
	addr = aml->GetLib("libGTASA.so");

/*menu alpha

menu_alpha_right = 0x2BAEA8 // 0xFF


    menu_alpha_left = 0x2BAEDC // 0x64
*/
aml->Unprot(addr + 0x2BAEA8, sizeof(char));
aml->Unprot(addr + 0x2BAEDC, sizeof(char));
/*small

menu_small_textr = 0x2BB324 // 0xFF


    menu_small_textg = 0x2BB326 // 0xFF

    menu_small_textb = 0x2BB328 // 0xFF
*/
aml->Unprot(addr + 0x2BB324, sizeof(char));
aml->Unprot(addr + 0x2BB326, sizeof(char));
aml->Unprot(addr + 0x2BB328, sizeof(char));
/*menu_outline

menu_small_outline_textr = 0x2BB350 // 0x0


    menu_small_outline_textg = 0x2BB352 // 0x0

    menu_small_outline_textb = 0x2BB354 // 0x0
*/
aml->Unprot(addr + 0x2BB350, sizeof(char));
aml->Unprot(addr + 0x2BB352, sizeof(char));
aml->Unprot(addr + 0x2BB354, sizeof(char));

/*big

menu_big_title_textr = 0x2BB538


    menu_big_title_textg = 0x2BB53A

    menu_big_title_textb = 0x2BB53C
*/
aml->Unprot(addr + 0x2BB538, sizeof(char));
aml->Unprot(addr + 0x2BB53A, sizeof(char));
aml->Unprot(addr + 0x2BB53C, sizeof(char));
    
/*big_outline

menu_big_title_outline_textr = 0x2BB54A

    menu_big_title_outline_textg = 0x2BB54C
    menu_big_title_outline_textb = 0x2BB54E
*/
aml->Unprot(addr + 0x2BB54A, sizeof(char));
aml->Unprot(addr + 0x2BB54C, sizeof(char));
aml->Unprot(addr + 0x2BB54E, sizeof(char)); 
    sautils = (ISAUtils*)GetInterface("SAUtils");
    if(sautils != nullptr)
    {
    sautils->AddSettingsTab("Menu_Text", "menu_mainsettings");

/*menu alpha



menu_alpha_right = 0x2BAEA8 // 0xFF


    menu_alpha_left = 0x2BAEDC // 0x64
*/
    	menualpha = cfg->Bind("Menu_Alpha", 0, "Menu");
        *(char*)(addr + 0x2BAEA8) = menualpha->GetInt();
        *(char*)(addr + 0x2BAEDC) = menualpha->GetInt();
        sautils->AddSliderItem(Menu, "Alpha", menualpha->GetInt(), 0, 255, alpha, alphadraw);
/*small



menu_small_textr = 0x2BB324 // 0xFF


    menu_small_textg = 0x2BB326 // 0xFF

    menu_small_textb = 0x2BB328 // 0xFF
*/
    	menusmallr = cfg->Bind("Small_Text_Red", 66, "Menu_Small_Text");
        *(char*)(addr + 0x2BB324) = menusmallr->GetInt();
        sautils->AddSliderItem(Menu, "Small_Text_Red", menusmallr->GetInt(), 0, 255, smallr, smallrdraw);
        
        menusmallg = cfg->Bind("Small_Text_Green", 245, "Menu_Small_Text");
        *(char*)(addr + 0x2BB326) = menusmallg->GetInt();
        sautils->AddSliderItem(Menu, "Small_Text_Green", menusmallg->GetInt(), 0, 255, smallg, smallgdraw);
        
        menusmallb = cfg->Bind("Small_Text_Blue", 155, "Menu_Small_Text");
        *(char*)(addr + 0x2BB328) = menusmallb->GetInt();
        sautils->AddSliderItem(Menu, "Small_Text_Blue", menusmallb->GetInt(), 0, 255, smallb, smallbdraw);
/*menu_outline



menu_small_outline_textr = 0x2BB350 // 0x0


    menu_small_outline_textg = 0x2BB352 // 0x0

    menu_small_outline_textb = 0x2BB354 // 0x0
*/
    	menuoutr = cfg->Bind("Menu_Small_Outline_Red", 104, "Menu_Outline");
        *(char*)(addr + 0x2BB350) = menuoutr->GetInt();
        sautils->AddSliderItem(Menu, "Menu_Small_Outline_Red", menuoutr->GetInt(), 0, 255, moutr, moutrdraw);
        
        menuoutg = cfg->Bind("Menu_Small_Outline_Green", 15, "Menu_Outline");
        *(char*)(addr + 0x2BB352) = menuoutg->GetInt();
        sautils->AddSliderItem(Menu, "Menu_Small_Outline_Green", menuoutg->GetInt(), 0, 255, moutg, moutgdraw);
        
        menuoutb = cfg->Bind("Menu_Small_Outline_Blue", 17, "Menu_Outline");
        *(char*)(addr + 0x2BB354) = menuoutb->GetInt();
        sautils->AddSliderItem(Menu, "Menu_Small_Outline_Blue", menuoutb->GetInt(), 0, 255, moutb, moutbdraw);
/*big



menu_big_title_textr = 0x2BB538


    menu_big_title_textg = 0x2BB53A

    menu_big_title_textb = 0x2BB53C
*/
        menubigr = cfg->Bind("Menu_Big_Title_Text_Red", 252, "Menu_Title");
        *(char*)(addr + 0x2BB538) = menubigr->GetInt();
        sautils->AddSliderItem(Menu, "Menu_Big_Title_Text_Red", menubigr->GetInt(), 0, 255, bigr, bigrdraw);
        
        menubigg = cfg->Bind("Menu_Big_Title_Text_Green", 165, "Menu_Title");
        *(char*)(addr + 0x2BB53A) = menubigg->GetInt();
        sautils->AddSliderItem(Menu, "Menu_Big_Title_Text_Green", menubigg->GetInt(), 0, 255, bigg, biggdraw);
        
        menubigb = cfg->Bind("Menu_Big_Title_Text_Blue", 3, "Menu_Title");
        *(char*)(addr + 0x2BB53C) = menubigb->GetInt();
        sautils->AddSliderItem(Menu, "Menu_Big_Title_Text_Blue", menubigb->GetInt(), 0, 255, bigb, bigbdraw);
/*big_outline



menu_big_title_outline_textr = 0x2BB54A

    menu_big_title_outline_textg = 0x2BB54C
    menu_big_title_outline_textb = 0x2BB54E
*/
        bigoutr = cfg->Bind("Menu_Big_Title_Outline_Text_Red", 123, "Menu_Big_Title_Outline");
        *(char*)(addr + 0x2BB54A) = bigoutr->GetInt();
        sautils->AddSliderItem(Menu, "Menu_Big_Title_Outline_Text_Red", bigoutr->GetInt(), 0, 255, boutr, boutrdraw);
        
        bigoutg = cfg->Bind("Menu_Big_Title_Outline_Text_Green", 3, "Menu_Big_Title_Outline");
        *(char*)(addr + 0x2BB54C) = bigoutg->GetInt();
        sautils->AddSliderItem(Menu, "Menu_Big_Title_Outline_Text_Green", bigoutg->GetInt(), 0, 255, boutg, boutgdraw);
        
        bigoutb = cfg->Bind("Menu_Big_Title_Outline_Text_Blue", 252, "Menu_Big_Title_Outline");
        *(char*)(addr + 0x2BB54C) = bigoutb->GetInt();
        sautils->AddSliderItem(Menu, "Menu_Big_Title_Outline_Text_Blue", bigoutb->GetInt(), 0, 255, boutb, boutbdraw);
    }
}