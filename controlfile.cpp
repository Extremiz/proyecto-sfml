#include "controlfile.h"

controlfile:: controlfile(){
	ifstream archi("hi-score.txt");
	if(!archi.is_open()){
		cout<<"error";
	}
	string x;
	while(getline(archi,x)){
		aux.name=x;
		archi.eof();
		archi>>aux.points;
		archi.ignore();
		v.push_back(aux);}
	archi.close();
	
}

bool controlfile::entreeneltop(int p){
	int cont=0;
	auxi.points=p;
	vector<input>::iterator it;
	for(int i=0;i<v.size();i++){
		if(v[i].points<auxi.points){
			cont++;
		}
	}
	if(cont==0){
		return false;
	}else return true;
	//	for(int i=0;i<v.size();i++) {
	//		cout<<v[i].name<<"-- "<<v[i].points<<endl;}		
	//	ofstream write("high.txt",ios::trunc);
	//	for(int i=0;i<v.size();i++) {
	//		write<<v[i].name<<endl;
	//		write<<v[i].points<<endl;
	//	}	
}

void controlfile::editlist(string a,int b){
	auxi.name=a;
	auxi.points=b;
	input auxi2;
	for(int i=0;i<v.size();i++){
		if(v[i].points<auxi.points){
			auxi2=v[i];
			v[i]=auxi;
			auxi=auxi2;}
	}
	ofstream write("hi-score.txt",ios::trunc);
	for(int i=0;i<v.size();i++) {
		write<<v[i].name<<endl;
		write<<v[i].points<<endl;
	}	
	write.close();
}
int controlfile::max_point(){
	return v[0].points;
}
string controlfile::get_name(int x){
	return v[x].name;
}
int controlfile::get_point(int x){
	return v[x].points;
}
