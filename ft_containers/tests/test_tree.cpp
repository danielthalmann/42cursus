#include <iostream>
#include "tree.hpp"
#include <memory>

#define TEST_CASE(_TITLE, _CMD, _TEST, _MSG)  std::cout << "TEST : " << _TITLE << std::endl; _CMD ; if (_TEST) { std::cout << "\x1b[31m" << "ERROR : " << "\x1b[0m" << _MSG << std::endl; /* return ;*/ }
 

void printint(int &i, size_t level)
{
    std::cout << level << ":" << i << "\t" ;
}

void insert(int v, ft::Tree <int, std::allocator<int> > &arbre)
{
    arbre.insert(v);
    arbre.infix(&printint); std::cout << " " << arbre.size() << '\n';
}

void  test ( )
{
 
    // Instanciation d'un ABR
    ft::Tree <int, std::allocator<int> > arbre;
    arbre.infix(&printint); std::cout << " " << arbre.size() << '\n';
    insert(0, arbre);
    insert(1, arbre);
    insert(2, arbre);
    insert(3, arbre);
    insert(7, arbre);
    insert(14, arbre);
    insert(9, arbre);
    insert(19, arbre);
    insert(10, arbre);
    insert(17, arbre);
    insert(28, arbre);
    insert(54, arbre);
    insert(32, arbre);
    insert(29, arbre);
    insert(42, arbre);
    insert(44, arbre);
    insert(79, arbre);
    insert(76, arbre);
    insert(65, arbre);
    insert(77, arbre);
    insert(60, arbre);
    insert(78, arbre);
    insert(81, arbre);
    insert(80, arbre);
    insert(97, arbre);
    insert(82, arbre);
 /*
    std::cout << '\n';
    std::cout << "Le parcours infixe de cet arbre est : "<< std::endl;
    arbre.infix(&printint);
    std::cout << '\n';
 
    std::cout << '\n';
    std::cout << "Le parcours postfixe de cet arbre est : "<< std::endl;
    arbre.postfix(&printint);
    std::cout << '\n';
 
    std::cout << '\n';
    std::cout << "Le parcours prefixe de cet arbre est : "<< std::endl;
    arbre.prefix(&printint);
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

    for (size_t i = 0; i < 4; i++)
    {
        std::cout << i << " : ";
        arbre.drawTree (i);
        std::cout << '\n';
    } 

    arbre.remove(3);
    std::cout << '\n';
    std::cout << "Le parcours infixe de l'arbre apres la suppression de 3 devient : " << std::endl;
    arbre.infix(&printint);
    std::cout << std::endl;

    for (size_t i = 0; i < 6; i++)
    {
        std::cout << i << " : ";
        arbre.drawTree (i);
        std::cout << '\n';
    }

    arbre.remove(40); 
    std::cout << '\n';
    std::cout << "Le parcours infixe de l'arbre apres la suppression 40 devient : "<< std::endl;
    arbre.infix(&printint);
    std::cout << std::endl;

    for (size_t i = 0; i < 6; i++)
    {
        std::cout << i << " : ";
        arbre.drawTree (i);
        std::cout << '\n';
    }


    ft::Tree<int, std::allocator<int> >::tree_pointer p = arbre.search(14); 

    p = arbre.rotateRight(p);
    arbre.infix(&printint);
    std::cout << std::endl;


    for (size_t i = 0; i < 6; i++)
    {
        std::cout << i << " : ";
        arbre.drawTree (i);
        std::cout << '\n';
    }

    p = arbre.rotateLeft(p);
    arbre.infix(&printint);
    std::cout << std::endl;
  
*/

    for (size_t i = 0; i < 8; i++)
    {
        std::cout << i << " : ";
        arbre.drawTree (i);
        std::cout << '\n';
    }

    arbre.remove(14);

    for (size_t i = 0; i < 8; i++)
    {
        std::cout << i << " : ";
        arbre.drawTree (i);
        std::cout << '\n';
    }


}

int main( void ) 
{
	test();

	return (0);
}
