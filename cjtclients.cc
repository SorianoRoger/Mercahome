#include "cjtclients.hh"

cjtclients::cjtclients(){
	maxclients = 30;
	clients = vector<client>(maxclients);
	nclients = 0;
	
	
	
}
cjtclients::~cjtclients(){}

void cjtclients::afegir_client(client& c){
	if(nclients < maxclients){ // hi caben clients
		int i = nclients-1;
		bool b = false;
		int id = c.numero;
		while(i >= 0 and not b){
			if(id > clients[i].numero){
				b =  true; 
			}
			else{
				clients[i+1]= clients[i];
				i = i -1;
			}
		}	
		clients[i+1] = c;
		++nclients;
	}
	else{
		clients.push_back(c);
		++nclients;
		++maxclients;
	}

}
	
	
int cjtclients::nombre_clients(){
	return nclients;	
}

void cjtclients::llegir(int& L){
	
	for (int i = 0; i < L; ++i){
	int N,N1;
	string aux;
	int aux1;
	cin >> aux1 >> aux >> N1;
	if(aux.size() != 8 or aux1 <= 0 ){
		cout << "error" << endl;
		
	}
	else{
		
			
				N = N1;
				clients[i].instant = aux;
				clients[i].numero = aux1;
			
				
			for(int j = 0; j < N; ++j){
				cin >> clients[i].productes[j].quantitat >> clients[i].productes[j].nom;
			
	
		}
	}
	}
	
}