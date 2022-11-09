#include <iostream>
#include "tree.hpp"
#include <memory>

#define TEST_CASE(_TITLE, _CMD, _TEST, _MSG)  std::cout << "TEST : " << _TITLE << std::endl; _CMD ; if (_TEST) { std::cout << "\x1b[31m" << "ERROR : " << "\x1b[0m" << _MSG << std::endl; /* return ;*/ }
 
void  test ( )
{
 
    // Instanciation d'un ABR
    ft::Tree <int, std::allocator<int> > arbre;
    arbre.insert(40);
    arbre.insert(50);
    arbre.insert(14);
    arbre.insert(16);
    arbre.insert(5);
    arbre.insert(3);
    arbre.insert(7);
    arbre.insert(55);
    arbre.insert(45);
 
    std::cout << '\n';
    std::cout << "Le parcours infixe de cet arbre est : "<< std::endl;
    arbre.infix();
    std::cout << '\n';
 
    std::cout << '\n';
    std::cout << "Le parcours postfixe de cet arbre est : "<< std::endl;
    arbre.postfixe();
    std::cout << '\n';
 
    std::cout << '\n';
    std::cout << "Le parcours prefixe de cet arbre est : "<< std::endl;
    arbre.prefixe();
    std::cout << '\n';
 
    std::cout << '\n';
    if(arbre.search(3) != 0){
        std::cout << "Le noeud avec la cle 3 appartient a l'arbre" << std::endl;
    }
    else{
        std::cout << "Le noeud avec la cle 3 n'appartient pas a l'arbre" << std::endl;
    }
 
    if(arbre.search(60) != 0){
        std::cout << "Le noeud avec la cle 60 appartient a l'arbre" << std::endl;
    }
    else{
        std::cout << "Le noeud avec la cle 60 n'appartient pas a l'arbre" << std::endl;
    }
 
//   arbre.supprimer(3);
//   std::cout << '\n';
//   std::cout << "Le parcours infixe de l'arbre apres la suppression de 3 devient : "<< std::endl;
//   arbre.infixe();
//
//   arbre.supprimer(40); 
//   std::cout << '\n';
//   std::cout << "Le parcours infixe de l'arbre apres la suppression 40 devient : "<< std::endl;
//   arbre.infixe();
 
    return 0;

}

int main( void ) 
{
	test();

	return (0);
}
