#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

class sommet{
  int vals; // la valeur du sommet.
  sommet* suivant;//pointeur vers le sommet suivant.

public:
       void affichesomm(){
             cout<<vals;
            }
        friend class listevoisin;  //on est besoin d'acceder a ces attributs.
        friend sommet* cree_somm(int); //fonction global friend avec la class sommet pour acceder a ses membre privee.

};
sommet* cree_somm(int vals){
    sommet*neveau_som=new sommet;
    neveau_som->vals=vals;
    neveau_som->suivant=NULL;
    return neveau_som;
}

class listevoisin{
  sommet* head;
public:
  sommet* ajout_somm(int);
  void affiche_liste();

  friend class graph;
};

void listevoisin::affiche_liste(){
      sommet* tmp=new sommet;
      tmp=head;
      while (tmp->suivant!=NULL) {
          tmp->affichesomm();
          cout<<",";
          tmp=tmp->suivant;
      }
}

sommet* listevoisin::ajout_somm(int vals){
        sommet*tmp=cree_somm(vals);
        sommet*ntmp=head;
        while(ntmp->suivant!=NULL){
          ntmp=ntmp->suivant;
        }
        ntmp->suivant=tmp;
        return ntmp;

}


class graph{
      int nbsommet;

    public:
      vector<listevoisin> *gra;//notre  graph
        graph(int);
        void affiche_graph();


};

graph::graph(int nbsommet){
    this->nbsommet=nbsommet;
    gra=new vector<listevoisin> ;
    //gra->resize(nbsommet);

}

void graph::affiche_graph(){
      //vector<listevoisin>::iterator ptr;
      cout<<"the graph elements are:"<<endl;
      for(auto ptr=gra->begin();ptr < gra.end();ptr++){
          cout<<"hhhhhhh";
          ptr->affiche_liste();
      }
}

int main(){
      graph G(5);
      for(auto i=G.gra->begin();i<G.gra->end();i++){
          *i->ajout_somm(2);
          *i->ajout_somm(3);
          *i->ajout_somm(0);
      }

      G.affiche_graph();

}
