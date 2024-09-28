#include<bits/stdc++.h>

using namespace std;

const int N = 10010;

struct peo{
    int ho = 0;
    int sp = 0;
    int r = 0;
}all[10010];

struct ans{
    int id;
    int cnt;
    double h;
    double area;
};

int f[N], n;
set<int> st;
map<int, peo> a;
int find(int x){
    if(f[x] == x)return f[x];
    else return f[x] = find(f[x]);
}
void join(int x, int y){
    int tx = find(x), ty = find(y);
	if(tx != ty)
	{
		if(tx > ty) f[tx] = ty;
		else f[ty] = tx;
	}
}
bool cmp(ans a, ans b){
    if(a.area > b.area)return true;
    else if(a.area < b.area)return false;
    else{
        if(a.id > b.id)return false;
        else return true;
    }
}
int main(){
    cin >> n;
    int id, idf, idm;

    for(int i = 0; i < N; i++){
        f[i] = i;
    }
    int ids, k, t, sp;
    while(n--){
        cin >> id >> idf >> idm;
        st.insert(id);
        if(idf != -1){
            st.insert(idf);
            join(id, idf);
        }
        if(idm != -1){
            st.insert(idm);
            join(id, idm);
        }
        cin >> k;

        while(k--){
            cin >> ids;
            st.insert(ids);
            join(id, ids);
        }
        cin >> t;
        all[id].ho = t;
        cin >> sp;
        all[id].sp = sp;
    }
    for(auto i : st){
        int idd = find(i);
        a[idd].ho += all[i].ho, a[idd].sp += all[i].sp;
        a[idd].r++;
    }
    vector<ans> an;
    for(auto i : a){
        int id = i.first;
        int cnt = i.second.r;
        double h = (double)i.second.ho / cnt;
        double area = (double)i.second.sp / cnt;
        an.push_back({id, cnt, h, area});
    }
    sort(an.begin(), an.end(), cmp);
    //for(auto i : st) cout << i << endl;
    cout << an.size() << endl;
    for(auto i : an){
        printf("%04d %d %.3lf %.3lf\n", i.id, i.cnt, i.h, i.area);
    }
}