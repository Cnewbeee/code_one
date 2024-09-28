for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] - a[j] == x && i != j){
                cout << "Yes" << endl;
                return ;
            }
        }
    }cout << "No" << endl;