#include <stdio.h>
#include "sealhat_menu.h"

#define NUMBER_OF_FACTS				(5)
const char* const facts[] = {
    "From end to end, large elephant seal males can grow to lengths of 20 feet and weigh up to 8800 pounds.\n",
    "In The Lord of the Rings, scrawny, cave-dwelling Moria orcs emit an eerie battle screech created from elephant seal pup calls.\n",
    "Once the lactation process starts, these pups grow up fast: In just 30 days, an average pup will go from weighing 75 to 300 pounds.\n",
    "Elephant seals can dive up to a depth of 5788 feet and hold their breath for up to two hours.\n",
    "By 1892, many people thought the northern elephant seal was extinct due to hunting. They were hunted to harvest blubber for oil.\n",
    NULL};

void printchar();
void printint();
void sealfact();

const MENU_t main_m;
const MENU_t printchar_m = {"print character", &printchar, 0, NULL};
const MENU_t printint_m  = {"print integer", &printint, 0, NULL};
const MENU_t sealfact_m  = {"Seal Fact!", &sealfact, 0, NULL};
const MENU_t exit_m  = {"EXIT", NULL, 0, NULL};
const MENU_t print_m = {"Print Things", NULL, 4, {&main_m, &printchar_m, &printint_m, &sealfact_m}};
const MENU_t main_m = {"Main Menu", NULL, 2, {&exit_m, &print_m}};

int main()
{
    const MENU_t* curMenu = &main_m;
    uint32_t choice;

    do {
        menu_display(curMenu);
        choice  = menu_getInt();
        curMenu = menu_navigate(curMenu, choice);
    } while(curMenu != &exit_m);

    return 0;
}

void printchar() {
    char c = 'f';
    printf("%c\n", c);
}

void printint() {
    int i = 34734;
    printf("%d\n", i);
}

void sealfact() {
    int i = rand() % NUMBER_OF_FACTS;
    printf("%s\n", facts[i]);
}
