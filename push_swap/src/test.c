
void ft_test()
{
	int	j;
	int	i;
	int N = 0;
	int	T[6];
	int	c;
	// Tri a bulle

	for(j=1;j<=N;j++) // pour faire l'operation N fois
		for(i=0; i < N-1; i++)
			if ( T[i] > T[i+1] ) {
					c = T[i];
					T[i] = T[i+1];
					T[i+1] = c;
			}

	// Tri par permutation
	//cet algorithme consiste a parcourir le tableau jusqu’à ce qu'il trouve un élément inférieur 
	// que le précédent ( mal placé ) , il prend cet élément et il le rang a sa place dans le tableau , 
	// et il continue le parcours jusqu’à la fin .
	// et affin de ne pas écraser les valeurs du tableau il faut réaliser une translation des valeurs a l'aide d'une boucle .

	int k;

	for(i=1;i<N;i++) {

		if ( T[i] < T[i-1] ) { // si l’élément est mal placé

			j = 0;

			while ( T[j] < T[i] ) j++; // cette boucle sort par j = la nouvelle position de l’élément
	
	c = T[i]; // ces 2 lignes servent a translater les cases en avant pour pouvoir insérer l’élément a sa nouvelle position
			for( k = i-1 ; k >= j ; k-- ) T[k+1] = T[k];
	T[j] = c; // l'insertion
		}
	}

}
