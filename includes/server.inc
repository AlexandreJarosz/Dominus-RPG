#if defined _server_included
    #endinput
#endif
#define _server_included

stock ServerFormatMessages(playerid, const index[]){
    new msg[600], nickname[MAX_PLAYER_NAME];
    GetPlayerNickname(playerid, nickname);

    if (strcmp(index, "welcomePlayer", true) == 0) format(msg, sizeof(msg), "%s%s%s entrou no %sDominus %sRPG%s, bem-vindo!", C257, nickname, C1, C259, C258, C1);

    SendClientMessageToAll(-1, msg);
}