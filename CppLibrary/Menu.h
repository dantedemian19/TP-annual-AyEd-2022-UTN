#pragma once
#include "consoleComands.h"
#include "dynamicTypes.h"
#include "include.h"

// keyboard id's
#define space 32
#define up 72
#define down 80
#define entr 13
#define esc 27
#define back 8


struct menuC {
    private:
        string name = "";
        int program = 0;
        bool enter = false;
        string namef = "";
        linkList<string> text;
        string exitText[2] = {
        " exit",
        " back"
        };
    public:
        int w = 1, exit = 0;
        void detection();
        void menu();
        void declare(string nameOfMenu, string menuText[], int numberOfOptions, int numberProgram = 1);
        void declare(string nameOfMenu, linkList<string> menuText, int numberOfOptions, int numberProgram = 1);
        void showGracia();
};

void advice() {
    //advice for users
    cout << " pulse W o UP para subir y S o DOWN para bajar \n";
    Sleep(1000);
    cout << " pulse ESC or DEL para salir \n";
    Sleep(1000);
    cout << " pulse F o ENTER para acceder o aceptar \n";
    Sleep(500);
    pause();
    cls();
    //advice
};

void menuC::detection() { // mueve el cursor dependiendo la decision del usuario
    int c = 0;
    // keyboard detection
    while (c != 's' && c != 'w' && c != 'f' && c != entr && c != up && c != down && c != esc && c != back) {
        c = _getch();
    }
    if (c == 'w' || c == up) {// if the user press up or W
        if (w > 1) {
            w = w - 1;
        }
        else {
            w = exit;
        }
    }
    if (c == 's' || c == down) {// if the user press down or S
        if (w < exit) {
            w = w + 1;
        }
        else {
            w = 1;
        }
    }
    if (c == 'f' || c == entr) {// if the user press enter or F
        enter = !enter;
    }
    if (c == back || c == esc) {// if the user press DELETE or ESC
        w = exit;
        enter = !enter;
    }
};

void menuC::menu() {// its a easy menu
        enter = false;
        int i = 1;
        while (!enter) {
            i = 1;
            cls();//cursor appears only in selected option 
            cout << " " << name << "  \n";
            while(i<=exit) {
                if (i != exit) {
                    if (w == i) { cout << "  >>"; } cout << "\t" << text[i]->data << "\n";
                }
                else { if (w == i) { cout << "  >>"; } cout << "\t" << exitText[program] << "\n"; }
                 i += 1;
            }
            //detection of the cursor
            detection();
            //detection of the cursor
        }
        cls();
}; 


void menuC::declare(string nameOfMenu, string menuText[], int numberOfOptions, int numberProgram) {
    int i = 0;
    while (numberOfOptions > i) {
        text.addToEnd((string)menuText[i]);
        i += 1;
    }
    exit    = numberOfOptions;
    program = numberProgram;
    name    = nameOfMenu;
};

void menuC::declare(string nameOfMenu, linkList<string> menuText, int numberOfOptions, int numberProgram) {
    text.addTofirst("enter");
    linkList<string>::node* temp = menuText.first;
    while (temp!=nullptr) {
        text.addToEnd(temp->data);
        temp = temp->next;
    }
    text.addToEnd("back");
    exit = numberOfOptions;
    program = numberProgram;
    name = nameOfMenu;
};


void menuC::showGracia() {
    cout << "error: pulse un numero valido\n  asi que se cree el gracisoso \n MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNMMMMMMNmyyyyyyyhdNMMNNNNNNNNNNNNNMMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNdyyyyyyyyhNMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMN-                            :NMMNy:`   .--.    --              `.                               .--.`   .+mMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMm-`yNNNNNNNNNNNNy`mNNNNNNNNNs -mMM/  .sdNMMMMNmy:`  :NNNNNNNNNmho.  :NNNNNNNNNN: yNNNNNNNNNs  :smNMMMMMNy+  -mMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMm- hMMMMMMMMMMMMh NMMMMMMMMMy -mMd  +NMMMMMNMMMMMh  /MMMMMMMMMMMMN. :MMMMMMMMMN: hMMMMMMMMMo :MMMMMMMMMMMMs  yMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMm- /osyNMMMMNyos/ NMMMMMhoso: -NMh `NMMMMM.`yMMMMM/ /MMMMMh-sMMMMMs :MMMMMNssso. hMMMMMhoss: yMMMMM/-mMMMMm- yMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMNo++: :NMMMMN: :  NMMMMM/     :NMh .MMMMMM  sMMMMMs /MMMMMh /MMMMMy :MMMMMd.     hMMMMM/     hMMMMMo`shhhdy. yMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMh -NMMMMN- h  NMMMMMo:::  /MMh .MMMMMM  sMMMMMy /MMMMMd:yMMMMMo :MMMMMm/::-  hMMMMMo:::` +MMMMMMho-` `  .hMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMh -NMMMMN- h  NMMMMMMMMM. /MMh .MMMMMM  -+++++: /MMMMMMMMMMMho` :MMMMMMMMMh` hMMMMMMMMN:  oNMMMMMMNd+`  :mMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMh -NMMMMN- h  NMMMMMMMMM. /MMh .MMMMMM          /MMMMMNhNMMMNy. :MMMMMMMMMh` hMMMMMMMMM:   `/yNMMMMMMN/  sMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMh -NMMMMN- h  NMMMMM+...  /MMh .MMMMMM  /hhhhd+ /MMMMMh`/MMMMMs :MMMMMm-..`  hMMMMM+...` .---:/+dMMMMMN: /MMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMh -NMMMMN- h  NMMMMM/ -+++omMh `MMMMMM  sMMMMMy /MMMMMh /MMMMMy :MMMMMd.`//` hMMMMM/ :+` yNNNNN:`hMMMMM/ /MMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMh -NMMMMN- h  NMMMMMs///:` yMs  MMMMMM  yMMMMM/ /MMMMMh /MMMMMy :MMMMMm+///- hMMMMMs///: sMMMMM/ yMMMMM+ /MMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMh -NMMMMN- h  NMMMMMMMMMd. +:`  sMMMMMddMMMMMd` /MMMMMh /MMMMMy :MMMMMMMMMMo hMMMMMMMMMN :MMMMMmdNMMMMN- /MMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMh :NMMMMN- h  NMMMMMMMMMd. `..  `/dNMMMMMMNd+.  /MMMMMy :NMMNMy :MMMMMMMMMMs hMMMMMMMMMM  :ymMMMMMMMmy-  sMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMh `------` h  .---------.  ...`   `.-:++/-.`    `-----. `.--.-. `----------. .----------    .-:+++:-. `.oNMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMNhhhhhhhhhhNhhhhhhhhhh/..```....-----------:/+osssooooo+++/::-.`````.+hhhhhhhhhhhhhhhhhhhhdho+++++++oydNMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN+......:+syhdddmmmmmmmmmmmmmddddhhhyso++/:-...``:mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm+..-../ydmmmmNNNNNNNNNNmmmmmmmdddhhhyso++//:--.```+mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm/..--.+dmmmmmmNNNNNNNNNNmmmmmmmmdddhhyso++////:.````:NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh-----+dmmmmmmNNNNNNNNNNNNNmmmmmmdddhhyso++/////:.````oNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/---.-dmmmmmmmNNNNNNNNNNNNNNmmmmmddhhhyso++++///:-..``-dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm.-..-ommmmmmmmNNNNNNNNNNNNNNmmmmmdddhhyyso++++//::-..``oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd....:smmmmmmmmNNNNNNNNNNNNNNmmmmmdddhhyysoooo++/:::-.``-NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh...-/sdmmmmmmmmNNNNNNNNNNNNNmmmmmmdddhhysssoo++/::::-.`.dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm..--/oddmmmmmmmmNNNNNNNNNNNNNmmmmmmdhhysoo+//:/:::////..yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:.-.:oddmmmmmmmmmmmmmNNNNNNmmmmmmmdhys/:-.````...-:/+o:-sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy-..-oddmddmmmddhhhhyyyhhddddddddhys/:.```........-/+o+:oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd-.`:sddddddhyoo+/:----:+ssyyyhhys+:...`..-::--.--.:+oo:+somMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/..+hddddho+//++oo++/////++oyddy+-.`.`---``.......:+oo/:./mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh..ohdddh++ooyyhhso+/////++ydmNds.`..-ss:--::.....-/oo+::+NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+./hddhs+ssyso+/.-.-os/+sydmNNmh+-:/oyyso+::-----:/+so:-/dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNm:-shdhsyhys+//s+/+oyyshdmmmmmmms/:/syhyysssooo++/:+ys-.-dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdds-+hddhhdhhhysssyyyyhdmmmmmmmNmh+::/oyyhhhyysso+/:oys:..+MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNhyho:yhddddmmddddddmdmmmmmmmmmmmNdy+::/osyyhhyso+/:/+hy-...MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdss/+hdhdmmmmmmmmmmmmNNmmmmdmmmNmmh+--osyyyyyso+::++hh:-/oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNhy//shdddddmmmmmmmmmNNmmmdmmmmmmdo/:-/sssyyso+/-:+oyy//smMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdhssoshdddddddmmmmmmNNmmdddyooso/...../ssssoo/:::+syhoyNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmmdmdyyhhhhdddmmmmmmmmmmmho:-:+/-.```..+ssso+/:://oshdMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmmdmdyhyyyhhhddmmmmmmmmmmmhhddyo+/----/oooo+/:://oyhdMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNhhhyhyyyhhhhdddmmmmmmmmmmmmdyyhhs+///+++/:::///+yhdMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmmmhyyhhyhhddmddmmmmmmmdddhhddhs//::::::--://+hhmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdhyyhhhhhdddddddhdddhyssso+:-..`.-::/::://ohhNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNhyhhhhhhhhhhysoooo+/+++///::-..-:///-::/+sydMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNyyyyhhyyyyyooosyyyysysoso+/--::::::-:/+so+oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNysyyyyyyyyyhhhhhyyso/::::-:/:::::--:+o/-.-mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNhsossssysyyhhhhyyysssyyyyss+//::-:/+:``.-sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdo+oooosssyhhhddmmmmmddhys++/::/+/.````./mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNho+/+oossyhhddddddddhhyo+/:--//-.````..:sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmso+//+ossyyhhhhhyyyso+/:-.....``````...:dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMhoso+:::/+oooooo++//:--...``````````.``-/hNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNyssoo/:----------.............``....``..:+odNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdssssso+//:-.........................``..:--:os++shmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMhsssssso+++/::--....................``.....`..--..:+oshdmNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmyssysssooo+++//:---......................``....``.-...--:+++oshhdmmNMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMhsyysssssooo+++/:----.....................`....``.......---.------:/oydmNNMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdyyyysssssooo++//:::---.......................```......--.-.----------:::+sydmNMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdhsyyyyyysssssoooo+++//::---..............---....`.......----..-----------::::-:/oyhmNMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmhso+//yyyhyyyysssssoooo++//::--------.....--------.........----...------------:::::::///+sdNN \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmhyo///+//oyyhhhyyysssssooo++//:::--:::------:::::/:-........------....-------..---::::---:::::/o \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmho++++///+/+//yshhhhhyyyyyssoo++//::::://::-:://+++++/-...-...---...--....--------------::------:::: \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNms+///////////+//+syhhhhhhyyyyso+++////://+++//++ooooo+:-.----..---------....------------------------:: \n";
    cout << "MMyooooooooooooooooooooooooooooooooooooooomNh+:..--......--.----.:os//+//////:o:-..--...--::--::::---.````..````..````..````..``.....`````.`....`..... \n";
    cout << "MM/ oooooo  ooooo/`+ooo.`+oos.oooo` +ooo- //  -+yhhyo-  .ooooooo:`   :oooooo` ` -+shhho:` .ooo+` `:oyhhy+.  `:oyhhyo-`  ./shhho:`  /ooo. /ooo. /ooo. . \n";
    cout << "MM/ MMMMMM`/MMMMMd.dMMM/-mMMM/sMMM+`MMMm  :. +MMMNNMMMo /MMMMNMMMm.  yMMMMMM/  /NMMNmMMMh./MMMm-`yMMMmNMMN/ hMMMNNMMMo :NMMNmMMMy. hMMM/ hMMM/ hMMM/ ` \n";
    cout << "MM/ MMMMMM/sMMMMMd.dMMM/-mMMM/-mMMhyMMN/ `+..dMMM/:NMMN-/MMMd-NMMMs .dMMMMMMy `dMMM+.mMMM//MMMm-:MMMm-/MMMh`MMMM/sNNNd yMMMo.dMMM/ hMMM/ hMMM/ hMMM/ . \n";
    cout << "MM/ MMMMMMhhMNMMMd.dMMM/-mMMM/ +MMNNMMh` ::`-NMMM:-ydhh-/MMMd-NMMMo :NMMddMMd..dMMM/.dNNN//MMMm-/MMMm-/MMMd.mMMMms/:-. hMMM+`hMMM/ hMMM/ hMMM/ hMMM/ - \n";
    cout << "MM/ MMMMmMMMMhMMMd.dMMM/-mMMM/  mMMMMM- .:-`-NMMM/+oooo./MMMMNMMNs  /MMMsyMMN:.dMMM/ -:::./MMMm-/MMMm-/MMMd..yNMMMMd/` hMMM+`hMMM/ hMMM/ hMMM/ hMMM/ . \n";
    cout << "MM/ MMMMoMMMMoMMMd.dMMM/-mMMM/  /MMMMy  -:-`-NMMM/mMMMM:/MMMd:NMMN: hMMM/yMMMo.dMMM/`:+++./MMMm-/MMMm-/MMMd.``-+hNMMMh hMMM+`hMMM/ hMMM/ hMMM/ hMMM/ . \n";
    cout << "MM/ MMMM:MMMm/MMMh.dMMM/-mMMM/  -NMMM/ .::-`-NMMM::NMMM:/MMMd`NMMMs NMMMmmMMMm.dMMM/.dMMM//MMMm-/MMMm-/MMMd.MMMM-:MMMM`hMMM+`hMMM/`yNNN: yNNN:`yNNN:   \n";
    cout << "MM/ MMMM-mMMh.MMMd`hMMMsoNMMN:  :NMMM: .::-``dMMMsoMMMM:/MMMh`NMMMs-MMMMddMMMM`yMMMy+NMMN:/MMMm--NMMN+yMMMy NMMMo+MMMM`sMMMy+mMMN: /oso. /sos- /sss-   \n";
    cout << "MM: MMMM yMMs.MMMh .hNMMMMMm/   -mMMN: .::-` -dNMMMmNMN:/MMMh`mMMMsoMMMM `MMMM+.hNMMMMNm/ /MMMm- :dNMMMMNy. :dNMMMMMm+ `yNMMMMMN/ `hMMM/ yMMM/ yMMM/ ` \n";
    cout << "MM/ ::/: -//.`:::-   `::::.  `.``::::` .::--`  .::-`-::``:::- -:::..::::  ::::.  `::::.   `:::-`   .::::`  `  `::::.     `::::.    -:::` -:::` -:::` ` \n";
    cout << "MMNmmmmmmmmmmmmmmmmNmh:...---:----------:-----....----...------------------------......----.....--........---.....``.---..............-.-.``......``.` \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMy:---:-::::-------::-------:::----------------::::----------------------------------..yooyss:hhooyy+ohss:yh/ysoo+y/d/sy++-.ys:y/  \n";
    cout << "MMMMMMMMMMMMMMMMMMMMm/------:::-----------------::::-------------------------------------------------------::-/:/-::--:/:s/-/--:.:-:`:/-/.:-:-:./::/`` \n";
    pause();
};