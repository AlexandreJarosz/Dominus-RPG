#include <a_samp>
#include <a_mysql>

#define db_host "localhost"
#define db_username "root"
#define db_password ""
#define db_name "dominus"

new MySQL:mysql_connection;

main() {}

public OnGameModeInit() {
    mysql_connection = mysql_connect(db_host, db_username, db_password, db_name);
    if (mysql_errno() != 0) {
        print("Não foi possível conectar no banco de dados.");
        new rconCmd[] = "exit";
        SendRconCommand(rconCmd);
    }
    
    SetGameModeText("RPG");
    return 1;
}