#pragma once
#ifndef _MAIN_WINDOW_MENU_
#define _MAIN_WINDOW_MENU_
#include "iup.h"
#include "project.h"

class Menu
{
public:
   Menu();
   ~Menu(void);

private:
   static Project *_project ;
};

#endif