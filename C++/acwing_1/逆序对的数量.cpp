#include<iostream>

using namespace std;

typedef long long ll;

const int N = 1e6+10;

int q[N], temp[N];
int n;

ll merge_sort(int l, int r){
    if(l >= r) return 0;

    int mid = l + r >> 1;
    ll res = merge_sort(l, mid) + merge_sort(mid+1, r);

    int i = l, j = mid+1;
    int k = 0;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else{
            temp[k++] = q[j++];
            res += mid + 1 - i;
        }
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];

    for(int i = l, j = 0; i <= r; i++, j++){
        q[i] = temp[j];
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> q[i];
    }

    cout << merge_sort(0, n - 1) << endl;
}