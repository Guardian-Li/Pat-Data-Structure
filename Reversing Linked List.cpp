#include<cstdio>
#include<stack>
#define Null -1
using namespace std;
struct List{
    int Data;
    int address;
    int next;
}L[100010];
int main()
{
    int N,K,head;
    scanf("%d %d %d",&head,&N,&K);
    for(int i=0; i<N; i++){
        int address;
        scanf("%d",&address);
        scanf("%d %d",&L[address].Data,&L[address].next);
        L[address].address =address;
    }
    stack<List >sta;
    int last = head;
    int L2 = Null;
    int p;
    int correctn=0;
    while(last != Null){
        last = L[last].next;
        correctn++;
    }
    N = correctn;
    last = head;
    for(int i=0; i<N/K; i++){
        int cnt=0;
        while(cnt != K){
            sta.push(L[last]);
            last = L[last].next;
            cnt++;
        }
        while(cnt){
            if(L2 == Null){
                L2 = sta.top().address;
                sta.pop();
                p = L2;
            }
            else{
                L[p].next = sta.top().address;
                p = L[p].next;
                sta.pop();
            }
            cnt--;
        }
    }
    L[p].next = last;
    last = L2;
    while(last != -1){
        if(L[last].next ==Null)
            printf("%05d %d %d\n",L[last].address,L[last].Data,L[last].next);
        else
            printf("%05d %d %05d\n",L[last].address,L[last].Data,L[last].next);
        last =L[last].next;
    }
    return 0;

}
