/*
 *
 */
#include "sealhat_menu.h"

static inline void menu_cursorTop() {
    printf("\e[H");
}

static inline void menu_clearScreen() {
    printf("\e[2J");
}

static inline void menu_eraseAbove() {
    printf("\e[1J");
}

void menu_display(const MENU_t *mnu)
{
    int i;
    menu_cursorTop();
    printf("** %s **\n", mnu->title);
    for(i = 0; i < mnu->num_submenus; i++) {
        printf("%d: %s\n", i+1, mnu->submenu[i]->title);
    }
}

const MENU_t* menu_navigate(const MENU_t* mnu, const uint32_t selection)
{
    const MENU_t* nextMnu;				// variable to hold the selected menu

    menu_clearScreen();
    // if a valid submenu is chosen return its pointer, otherwise return the same one
    if ((selection > 0) && (selection <= mnu->num_submenus)) {
        // 0 index so subtract 1 and get its pointer from the array
        nextMnu = mnu->submenu[selection-1];

        // if the menu chosen has no submenus, then it is a command
        // execute the command and return the origional menu.
        if(nextMnu->num_submenus == 0 && nextMnu->command != NULL) {
            nextMnu->command();
        }
        else {
            mnu = nextMnu;
        }
    }
    else {
        printf("Error: %d is not a valid option.\n\n", selection);
    }

    return mnu;
}

int menu_getinput(char* prompt, char* buf, size_t size) {
    int retval = 0;      // flag to return if there was extra data not captured

    if (prompt != NULL) {
        printf("%s", prompt);
        fflush(stdout);
    }

    if(fgets(buf, size, stdin) == NULL) {
        return 0;
    }

    if(buf[strlen(buf)-1] != '\n') {
        int c;  // character to catch getc returns
        while(( (c = getchar()) != '\n') && (c != EOF) ) {
            retval--;
        }
    }
    else {
        buf[strlen(buf)-1] = '\0';
        retval = strlen(buf);
    }

    printf("\n");
    return retval;
}

int menu_getInt() {
    static const int BUF_SIZE = 5;
    char buf[BUF_SIZE];    // to hold the user input
    char* endptr;   // for comparing conversion ptr to detect errors
    int retVal = -1;
    menu_getinput("Choice: ", buf, BUF_SIZE);
    retVal = strtol(buf, &endptr, 10);
    return retVal;
}
