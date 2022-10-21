#include<bits/stdc++.h>
using namespace std;

const int n=26;

unordered_set<string> ans;




struct TrieNode{
	struct TrieNode* child[n];
	string str;
	bool added;
};

TrieNode* root;

struct TrieNode *getNode()
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->str = "";
    pNode->added=false;
 
    for(int i = 0; i < n; i++){
        pNode->child[i] = NULL;
    }
 
    return pNode;
}

void search(TrieNode* curr, TrieNode* nword){
	
	if(curr->str!="" && nword->str!=""){
		if(!curr->added){
	     ans.insert(curr->str);
	   }
	   curr->added=false;
	}
	
	if(nword->str!=""){
		search(curr,root);
	}
	
	
	for(int i=0;i<n;i++){
		if(curr->child[i]!=NULL && nword->child[i]!=NULL){
			search(curr->child[i],nword->child[i]);
		}
	}
}

void search1(TrieNode* curr){
	
	if(curr->str!=""){
		search(curr,root);
	}
	
	for(int i=0;i<n;i++){
		if(curr->child[i]!=NULL){
			search1(curr->child[i]);
		}
	}
	
}

void insert(TrieNode* curr,string s){
	
	for(int i=0;i<s.length();i++){
		if(curr->child[s[i]-'a']==NULL){
			curr->child[s[i]-'a']=getNode();
		}
		curr=curr->child[s[i]-'a'];
	}
	curr->str=s;
}

int main(){
	
	 clock_t Start;
    clock_t Finish;

    Start = clock();
	
	
	
	
	
	string st;
	ifstream in("Input_01.txt");
	vector<string> v;
	while(getline(in,st)){
		v.push_back(st);
	}
	
	
	
	
//    vector<string> st;
//    vector<string> final_ans;
//    int n;
//    cin>>n;
//
//    for(int i=0;i<n;i++){
//    	string s;
//	    cin>>s;
//	    st.push_back(s);
//    }
	
	root=getNode();
	
	for(auto x:v){
		insert(root,x);
	}
	search1(root);
	
	
	string first="",second="";
        
        for(string x:ans){
            if(x.length()>first.length()){
                second=first;
                first=x;
            }
           else if(x.length()>second.length()){
                    second=x;
                }
        }
        
        cout<<first<<"  "<<second<<endl;
	
	
	
	
	Finish = clock();

   double time_taken = double(Finish - Start) / double(CLOCKS_PER_SEC);

	cout << time_taken<<"sec"<<endl;;

    system("pause");
    
	
//	for(auto x:ans){
//		final_ans.push_back(x);
//        cout<<x<<" ";
//	}
	
//	   for(auto x:final_ans){
//	   	cout<<x<<" ";
//	   }
	return 0;
}
