#if defined _useful_included
    #endinput
#endif
#define _useful_included

stock ClearChat(playerid) {
    for (new i = 0; i < 20; i++) SendClientMessage(playerid, -1, " ");
}

stock Pointer:GetElementList(Pointer:list_ptr, next, element1, element2, const option[]) {
    new Pointer:run_ptr = list_ptr;

    if (strcmp(option, "end", true) == 0) while (Pointer:MEM_get_val(run_ptr, next) != Pointer:0) run_ptr = Pointer:MEM_get_val(run_ptr, next);
    else if (strcmp(option, "player", true) == 0) while (MEM_get_val(run_ptr, element1) != element2) run_ptr = Pointer:MEM_get_val(run_ptr, next);

    return run_ptr;
}

stock Pointer:MEM_new_string(const str[]) {
    new size = strlen(str), Pointer:gStr_ptr = MEM_new(size + 1);
    for (new i = 0; i <= size; i++) MEM_set_val(gStr_ptr, i, str[i]);
    return gStr_ptr;
}

stock MEM_get_string(Pointer:gStr_ptr, dest[], size) {
    for (new i = 0; i < size - 1; i++) {
        dest[i] = MEM_get_val(gStr_ptr, i);
        if (dest[i] == '\0') break;
    }
    dest[size - 1] = '\0';
}