/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file or main.c
 * to avoid loosing it when reconfiguring.
 * https://cboard.cprogramming.com/c-programming/99735-embedded-menu-system.html
 * https://arstechnica.com/civis/viewtopic.php?f=20&t=240614
 */
#ifndef SEALHAT_MENU_H_
#define SEALHAT_MENU_H_

//#include "usb_start.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
/**
 * @brief A menu object
 *
 * A menu object used to create a menu structure.
 *     title: the text to display at the top of the menu
 *     command: the command associated with this menu. set to NULL if not used
 *     num_submenu: number of submenues in the submenu array
 *     submenu: array of submenu objects
 */
#define MAX_TITLE_LENGTH			(15)
#define MAX_SUBMENUS				(5)
typedef struct MENU_t MENU_t;
struct MENU_t{
    char title[MAX_TITLE_LENGTH];
    void (*command)();
    uint8_t num_submenus;
    const MENU_t* submenu[MAX_SUBMENUS];
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief print a menu
 */
void menu_display(const MENU_t* mnu);

/**
 * @brief print a random elephant seal fact
 */
const MENU_t *menu_navigate(const MENU_t* mnu, const uint32_t selection);

int menu_getinput(char* prompt, char* buf, size_t size);

int menu_getInt();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SEALHAT_MENU_H_
