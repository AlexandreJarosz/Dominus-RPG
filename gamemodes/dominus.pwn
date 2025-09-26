#include <a_samp>
#include <fixes>
#include <sscanf2>
#include <a_mysql>
#include <memory>

new MySQL:mysql_connection, Pointer:mainPlayer_ptr;

forward Pointer:GetEndList(Pointer:list_ptr, index);
forward Pointer:MEM_new_string(const str[]);
forward Pointer:GetElementList(Pointer:list_ptr, next, element1, element2, const option[]);

#include <color>
#include <player>
#include <server>
#include <useful>


main() {}

public OnGameModeInit() {
    mysql_connection = mysql_connect("localhost", "root", "", "dominus");
    if (mysql_errno() != 0) {
        print("Não foi possível conectar no banco de dados.");
        new rconCmd[] = "exit";
        SendRconCommand(rconCmd);
    }

    SetGameModeText("RPG");
    EnableStuntBonusForAll(false);
    return 1;
}