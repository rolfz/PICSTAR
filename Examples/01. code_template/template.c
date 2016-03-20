/*
   Title: template.c
   Purpose: example pour débuter un nouveau programme C18
   Version: 1.0
   Autor:
   Date:

   description:


   proposition pour organiser vos projets

	...../mes_projets
	...../mes_projets/shared  "contient tous les programs et routines partagées"
					par example driver
	...../mes_projets/projet1
	...../mes_projets/projet1/programme1.c  // mon program
	...../mes_projets/projet1/programme1.h  // mes définitions

	...../mes_projets/projet2

*/

// includes
// dans C:\MCC18\h, le projet MPLAB indique ou chercher les fichiers include
#include <p18f4550.h>   
// picstar.h contient toutes les variables et macros specifiques a picstar
#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"

// constants et définitions.

// variables globales


// notre programme débute ici.
void main()
{

// la procedure d'initialisation n'est pas toujours nécessaire.
// pour les programmers expérimentés, rempacer par les fonctions specifiques au programme.

	init_picstar();

// ajouter toutes les instructions d'initalisation ici.



// on va normallement dans une boucle infinie

	while(1)
	{

// ajouter le code qui tourne en boucle ici
// ...

	} // end of while


}
// fin du programme