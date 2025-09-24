#if defined _useful_included
    #endinput
#endif
#define _useful_included

stock ClearChat(playerid) {
    for (new i = 0; i < 20; i++) SendClientMessage(playerid, -1, " ");
}

stock Pointer:GetEndList(Pointer:list_ptr, index){
    new Pointer:run_ptr = list_ptr;
    while(Pointer:MEM_get_val(run_ptr, index) != Pointer:0) run_ptr = Pointer:MEM_get_val(run_ptr, index);
    return run_ptr;
}