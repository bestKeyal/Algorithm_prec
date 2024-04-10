#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int T;
struct SAM {
	//edited by piaoyun from some other's code 
	//����#define int long long 
	 
	static const int MAXN=1000010,MAXS=28;
    
    int tot=1,last=1,link[MAXN << 1],ch[MAXN << 1][MAXS],len[MAXN << 1],endpos[MAXN << 1];
	//�ܵ���tot�����index����[1-tot]���մ�/��Ϊ1 
	//lastΪ��һ�β���ĵ�
	//linkΪ���parent�����ڵ� / � ����λ�����Լ���ͬ �ĺ�׺
	//ch[n][s] ָ�ڵ�nĩβ���ַ�s��ת�Ƶ��ĵ�
	//lenָ�ýڵ�Ĵ��� ����ȣ�ע�⵽ ��̳��� ���� len[link[n]] + 1 �����ڵ�� + 1
	//endpos[n] �ο�get_endpos()��ע�� 
	void clear(){
        for(int i = 0; i <= tot; i++){
            link[i] = len[i] = endpos[i] = 0;
            for(int k = 0; k < MAXS; k++) ch[i][k] = 0;
        }
        tot=1;last=1;
    }
    
    //�ӳ�һ���ַ���ͨ��Ϊ[1-26] 
    void extend(int w){
        int p=++tot,x=last,r,q;
        //TODO
        
        endpos[p] = ;
        
        //END
		for(len[last=p]=len[x]+1; x&&!ch[x][w]; x=link[x]) ch[x][w]=p;
        if(!x)link[p]=1;
        else if(len[x]+1==len[q=ch[x][w]]) link[p]=q;
        else {
            link[r=++tot]=link[q];
            memcpy(ch[r],ch[q],sizeof ch[r]);
            len[r]=len[x]+1;
            link[p]=link[q]=r;
            for(; x&&ch[x][w]==q; x=link[x])ch[x][w]=r;
        }
    }
    
    //*ע��vectorռ�õĿռ� 
    vector<int> p[MAXN << 1]; //����parent�����Ա���ϵ���dfs 
    void dfs(int u){
    	int v;
    	for(int i=0;i<p[u].size();i++){
        	v=p[u][i];
        	dfs(v);
        	endpos[u]+=endpos[v];
   		}
	}
    
    //ע�⣡��ʹ�ø÷���ǰ��endpos[]����ÿ������Ϊ���ս�㡱�Ĵ���
	//ʹ�ø÷�����endpos[]ָ�ڴ��г����ܴ�������ԭ������������
    void get_endpos(){
    	for(int i = 1;i <= tot; i++) p[i].clear();
    	for(int i = 2;i <= tot; i++){
        	p[link[i]].push_back(i); //����parent�����Ա���ϵ���dfs 
   		}
   		dfs(1);
   		for(int i = 1;i <= tot; i++) p[i].clear();
	}
    
    
    //*������ȷ���Ƿ��г�д����ʱ��ʹ�ø÷��� 
    //*�����������κ�����ǰ�Լ죬��ǰ�����ݻᱻ��� 
    static const int STC = 998244353;
    void self_test(){
		clear();
		for(int i = 1;i <= 1000; i++) extend(i * i % 26 + 1);
		int tmp = 107 * last + 301 * tot;
		for(int i = 1;i <= tot; i++){
			tmp = (tmp * 33 + link[i] * 101 + len[i] * 97) % STC;
			for(int k = 1; k < MAXS; k++) tmp = (tmp + k * ch[i][k]) % STC;
		}
		assert("stage 1" && tmp == 393281314); // stage1 : ��齨���Ƿ���ȷ
		tmp = 0;
		get_endpos();
		for(int i = 1;i <= tot; i++) tmp = (tmp * 33 + endpos[i]) % STC;
		assert("stage 2" && tmp == 178417668); // stage2 : ���endpos�����Ƿ���ȷ��������޸���endpos[]�ĺ�����ᱨ��
		cout<<"Self Test Passed.Remember to delete this function's use."<<endl;
		clear();
	}
	
	//����ʱ�ɵ��� 
	void debug_print(){
		for(int i = 1;i <= tot; i++){
			cout<<"node:"<<i<<" father:"<<link[i]<<" endpos:"<<endpos[i]<<" len:"<<len[i]<<endl;
		}
	} 
	
	string str; 
	
	void solve(){
		//TODO
		
		//END
	}
}sam;

string tmp;

void prepare() {
	sam.solve();
}

signed main() {
    T=1;
    while(T--) {
        prepare();
    }
    return 0;
}
