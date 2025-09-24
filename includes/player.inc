#if defined _player_included
    #endinput
#endif
#define _player_included

public OnPlayerConnect(playerid) {
    ClearChat(playerid);
    CreatePlayerNode(playerid);
    return 1;
}

stock CreatePlayerNode(playerid){
    new Pointer:pNode_ptr = MEM_new(13), Pointer:pRun_ptr;

    MEM_set_val(pNode_ptr, pInfoId("next"), _:Pointer:0);
    MEM_set_val(pNode_ptr, pInfoId("playerid"), playerid);
    MEM_set_val(pNode_ptr, pInfoId("nickname"), _:Pointer:0);
    MEM_set_val(pNode_ptr, pInfoId("isRegistered"), 0);
    MEM_set_val(pNode_ptr, pInfoId("isLogged"), 0);
    MEM_set_val(pNode_ptr, pInfoId("tempPassword"), _:Pointer:0);
    MEM_set_val(pNode_ptr, pInfoId("skin"), 0);
    MEM_set_val(pNode_ptr, pInfoId("score"), 0);
    MEM_set_val(pNode_ptr, pInfoId("money"), 0);
    MEM_set_val(pNode_ptr, pInfoId("itsInArea"), 0);
    MEM_set_val(pNode_ptr, pInfoId("lastDialog"), 0);
    MEM_set_val(pNode_ptr, pInfoId("tdLoginRegister"), _:Pointer:0);
    MEM_set_val(pNode_ptr, pInfoId("tdBikeInfo"), _:Pointer:0);

    if(mainPlayer_ptr == Pointer:0) mainPlayer_ptr = MEM_new(1);
    pRun_ptr = GetEndList(Pointer:mainPlayer_ptr, pInfoId("next"));
    MEM_set_val(pRun_ptr, pInfoId("next"), _:pNode_ptr);
}

stock pInfoId(const option[]){
    new i = 0;
    if (strcmp(option, "next", true) == 0) return i;
    i++;
    if (strcmp(option, "playerid", true) == 0) return i;
    i++;
    if (strcmp(option, "nickname", true) == 0) return i;
    i++;
    if (strcmp(option, "isRegistered", true) == 0) return i;
    i++;
    if (strcmp(option, "isLogged", true) == 0) return i;
    i++;
    if (strcmp(option, "tempPassword", true) == 0) return i;
    i++;
    if (strcmp(option, "skin", true) == 0) return i;
    i++;
    if (strcmp(option, "score", true) == 0) return i;
    i++;
    if (strcmp(option, "money", true) == 0) return i;
    i++;
    if (strcmp(option, "itsInArea", true) == 0) return i;
    i++;
    if (strcmp(option, "lastDialog", true) == 0) return i;
    i++;
    if (strcmp(option, "tdLoginRegister", true) == 0) return i;
    i++;
    if (strcmp(option, "tdBikeInfo", true) == 0) return i;

    printf("Algo errado na chamada da função pInfoId, tendo a opção %s", option);
    return -1;
}