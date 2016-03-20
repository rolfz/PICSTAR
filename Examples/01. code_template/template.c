/*
   Title: template.c
   Purpose: example pour d�buter un nouveau programme C18
   Version: 1.0
   Autor:
   Date:

   description:


   proposition pour organiser vos projets

	...../mes_projets
	...../mes_projets/shared  "contient tous les programs et routines partag�es"
					par example driver
	...../mes_projets/projet1
	...../mes_projets/projet1/programme1.c  // mon program
	...../mes_projets/projet1/programme1.h  // mes d�finitions

	...../mes_projets/projet2

*/

// includes
// dans C:\MCC18\h, le projet MPLAB indique ou chercher les fichiers include
#include <p18f4550.h>   
// picstar.h contient toutes les variables et macros specifiques a picstar
#include "..\shared\picstar_def.h"
#include "..\shared\picstar_ini.h"
#include "..\shared\picstar_delays.h"

// constants et d�finitions.

// variables globales


// notre programme d�bute ici.
void main()
{

// la procedure d'initialisation n'est pas toujours n�cessaire.
// pour les programmers exp�riment�s, rempacer par les fonctions specifiques au programme.

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