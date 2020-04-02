#include <iostream> 
#include <vector> 

using namespace std;



class sommet {
	int val1;     //identificateur du sommet.
	vector<sommet>* listvoisin;      //liste des voising du sommet
public:
	sommet();     //constructeur d'un sommet par default.
	sommet(int); //constructeur d'un sommet.
	void ajouterunsommet(sommet&);
	void afficherS();
};
sommet::sommet() {
	val1 = NULL;
	listvoisin = new vector<sommet>[] ;
}
sommet::sommet(int val1) {
	this->val1 = val1;
	listvoisin = new vector<sommet>[];
}
void sommet::ajouterunsommet(sommet& Sapasser) {
	listvoisin->push_back(Sapasser);  //insirer un sommet a la liste des voisines d'un autre sommet.

}
void sommet::afficherS() {
	cout << "liste des voising du" << val1 << ":" << endl;
	for (auto i = listvoisin->begin(); i != listvoisin->end(); i++) {
		cout << listvoisin[i].val1;
	}
}


class Graph {
	vector<sommet> *somdugraph; //la liste des sommet du graph.
public:
	Graph();//constructor du graph.
	void ajo_som_graph(sommet&);//ajouter un sommet au graph.
	void afficher();
};


Graph::Graph() {
	somdugraph = new vector<sommet>[];
}



void Graph::ajo_som_graph(sommet& s) {
	//s est le sommet a ajouter a notre graph
	somdugraph->push_back(s);
}
void Graph::afficher() {
	for (auto i = somdugraph->begin(); i < somdugraph->end(); i++) {
		somdugraph[i].afficheS();
		cout << endl;
	}
}

int main() {
	
	Graph A;
	sommet a(1);
	sommet b(3);
	sommet c(2);
	a.ajouterunsommet(b);
	b.ajouterunsommet(a);
	b.ajouterunsommet(c);
	A.ajo_som_graph(a);
	A.ajo_som_graph(b);
	A.ajo_som_graph(c);
	A.afficher();
	return 0;

}