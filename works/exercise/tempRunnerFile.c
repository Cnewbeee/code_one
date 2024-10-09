if (ppp > 0 && w[pp][0] != '\0') {
        int ti = find(w[pp]);
        if (ti == -1) {
            mapstoi[p].c = (char*)malloc(strlen(w[pp]) + 1);
            strcpy(mapstoi[p].c, w[pp]);
            mapstoi[p++].count = 1;
        }else{
            mapstoi[ti].count++;
        }
        pp++;
        ppp = 0;
    }