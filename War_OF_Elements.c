// MACHINE PROJECT, SALAZAR JACOB ISRAEL 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>      
#define MAX 70 
void StartGame();
void Earth();
void creature();
void human ();
void sword ();
typedef char string[100];

struct chartag {
	
	string name;
	int ID;
	int nElem;
	int HP;
	int PP;
	string stage;
	int currHP;
	int currPP;
	int lightA;
	int mediumA;
	int heavyA; 
	
};
typedef struct chartag characters;

struct Movetag {
	
	string name;
	string description;
	int ID;
	int attacktype;
	int element;
	
};
typedef struct Movetag attack;


struct Storytag {
	
	string title;
	int ID;
	string description;
	int numEnem;
	characters Enemy[MAX];
	characters protagonist;
	
	
};
typedef struct Storytag story;


void CheckList2 (attack move[MAX],int *nummove)
{
	FILE *pFileMove;
	int i;
	
	pFileMove = fopen("newfile.txt","rt"); // "RT = Read text"
	
	if (pFileMove != NULL) // file exists
	{
		
		fscanf(pFileMove,"%d ",nummove);
		for (i = 0;i < *nummove;i++)
		{
			
			fgets(move[i].name,300,pFileMove);
			fgets(move[i].description,300,pFileMove);
			fscanf(pFileMove,"%d",&move[i].ID);
			fscanf(pFileMove,"%d",&move[i].attacktype);
			fscanf(pFileMove,"%d",&move[i].element);
		}
		fclose(pFileMove);
	}
	else
		printf ("File does not exist.\n");
	
}

void CheckList(characters hero[MAX],int *numhero)
{
	FILE *pFile;
	int i;
	
	pFile = fopen("HEROLIST.txt","rt"); // "RT = Read text"
	
	if (pFile != NULL) // file exists
	{
		
		fscanf(pFile,"%d ",numhero);
		for (i = 0;i < *numhero;i++)
		{
			
			fgets(hero[i].name,200,pFile);
			fgets(hero[i].stage,200,pFile);
			fscanf(pFile,"%d",&hero[i].nElem);
			fscanf(pFile,"%d",&hero[i].HP);
			fscanf(pFile,"%d",&hero[i].PP);
			fscanf(pFile,"%d",&hero[i].ID);
			fscanf(pFile,"%d",&hero[i].lightA);
			fscanf(pFile,"%d",&hero[i].mediumA);
			fscanf(pFile,"%d",&hero[i].heavyA);
		
		}
		fclose(pFile);
	}
	else
		printf ("File does not exist.\n");
	
}
void CheckList3 (story story[MAX],int *numstory)
{
	FILE *pFile3;
	int i;
	int j;
	
	pFile3 = fopen("storyline.txt","rt"); // "RT = Read text"
	
	if (pFile3 != NULL) // file exists
	{
		
		fscanf(pFile3,"%d ",numstory);
		for (i = 0;i < *numstory;i++)
		{
			fscanf(pFile3,"%d ",&story[i].ID);
			fgets(story[i].title,300,pFile3);
			fgets(story[i].description,300,pFile3);
			fgets(story[i].protagonist.name,300,pFile3);
			fgets(story[i].protagonist.stage,300,pFile3);
			fscanf(pFile3,"%d",&story[i].protagonist.ID);
			fscanf(pFile3,"%d",&story[i].protagonist.HP);
			fscanf(pFile3,"%d",&story[i].protagonist.PP);
			fscanf(pFile3,"%d",&story[i].protagonist.nElem);
			fscanf(pFile3,"%d",&story[i].protagonist.lightA);
			fscanf(pFile3,"%d",&story[i].protagonist.mediumA);
			fscanf(pFile3,"%d",&story[i].protagonist.heavyA);
			
			
			fscanf(pFile3,"%d",&story[i].numEnem);
			for (j = 0;j < story[i].numEnem; j++)
			{
			fgets(story[i].Enemy[j].name,300,pFile3);
			fgets(story[i].Enemy[j].stage,300,pFile3);
			fscanf(pFile3,"%d",&story[i].Enemy[j].ID);
			fscanf(pFile3,"%d",&story[i].Enemy[j].HP);
			fscanf(pFile3,"%d",&story[i].Enemy[j].PP);
			fscanf(pFile3,"%d",&story[i].Enemy[j].nElem);
			fscanf(pFile3,"%d",&story[i].Enemy[j].lightA);
			fscanf(pFile3,"%d",&story[i].Enemy[j].mediumA);
			fscanf(pFile3,"%d",&story[i].Enemy[j].heavyA);

				
			}
			
		}
		fclose(pFile3);
	}
	else
		printf ("File does not exist.\n");
	
}







void displayContents (characters hero)
{
	
	printf("Hero Name: %s \n",hero.name);
	printf("Hero ID number: %d\n",hero.ID);
	printf("Location:  %s",hero.stage);
	if (hero.nElem == 1)
	printf ("Element: Fire\n");
	else if (hero.nElem ==  2)
	printf ("Element: Water\n");
	else if (hero.nElem ==  3)
	printf ("Element: Earth\n");	
	else if (hero.nElem ==4 )
	printf ("Element: Air\n");
	
	printf("Hitpoints: %d \n",hero.HP);
	printf("Powerpoints %d \n",hero.PP);
    printf("______________________");
	printf("\n");
	
	
}


void addHero (characters hero[MAX],int *numhero)
{
	int newID; 
	int secret;
	
	system ("cls");
	
	srand (time(NULL));
	secret = (rand() % (9999 - 1000 + 1)) + 99;
	
	
	printf("HERO ID number: %d \n",secret);
	hero[*numhero].ID = secret;
	
	
	printf ("Entering person information #%d \n",*numhero+1);
	getchar();
	printf ("Enter the Hero's name: \n");
	fgets(hero[*numhero].name,20,stdin);
	printf("Press anykey to continue.. \n");
	getch();
	printf ("Enter the Hero's location: ");
    fgets(hero[*numhero].stage,20,stdin);
    printf("\n");
    
    
	printf ("\nEnter [1] Fire    Enter [2] Water  Enter [3] Earth  Enter [4] - Air \n ");
	printf ("Enter Element number: \n ");
	
	do {
		scanf (" %d",&hero[*numhero].nElem);
		if ( hero[*numhero].nElem != 1 && hero[*numhero].nElem != 2 && hero[*numhero].nElem != 3 && hero[*numhero].nElem != 4)
			printf("enter values only from 1-4 try again pls \n");
		
	}while ( hero[*numhero].nElem != 1 && hero[*numhero].nElem != 2 && hero[*numhero].nElem != 3 && hero[*numhero].nElem != 4);
	
	
	
	printf ("Enter the Max hitpoints:\n ");
	scanf (" %d",&hero[*numhero].HP);
	printf ("Enter the Max powerpoints: \n ");
	scanf (" %d",&hero[*numhero].PP);
	hero[*numhero].lightA = 0;
	hero[*numhero].mediumA = 0;
    hero[*numhero].heavyA = 0;
    
    printf("%s successfully added to the hero pool!! \n",hero[*numhero].name);
    system("pause");
    
	(*numhero)++;
	
	
}

int getIndex(characters hero[MAX],int *numhero,int getID)
{
	int i;
	int Index;
	int found = 0;
	
	
	for (i=0;i<*numhero;i++)
	{
		if (hero[i].ID==getID)
		{
		Index = i;
		return Index;	 
	    }
	    else 
	    Index = 12345; // not found key number
	}
	return Index;

}





void delHero (characters hero[MAX],int *numhero)
{
		int nKey;
		int ID;
		int i;
		
		system ("cls");
		
		
		if (*numhero > 4)
		{
			
		for (i = 0;i <*numhero;i++)
		displayContents(hero[i]);
		
		
		do
		{
			printf("Enter which the ID number of the Hero you want to delete: ");
		scanf("%d",&ID);
		
				nKey = getIndex(hero,numhero,ID);
			
		}while( !(nKey != 12345));
		
		
		
	
	
		
		
		printf ("\n");
		printf ("Deleting element at index %d ",nKey);
		
		while (nKey < *numhero-1)
		{
				strcpy (hero[nKey].name, hero[nKey+1].name);
				strcpy(hero[nKey].stage, hero[nKey+1].stage);
				
				
				
				hero[nKey].nElem = hero[nKey+1].nElem;
				hero[nKey].HP = hero[nKey+1].HP;
			    hero[nKey].PP = hero[nKey+1].PP;
				hero[nKey].ID = hero[nKey+1].ID;
					
				nKey++;
		}		
				(*numhero)--;
		}
		else
		{
			printf("Minimum number of 4 heroes has been reached! \n");
			printf("Sorry! Cannot delete anymore hero \n\n\n\n\n\n\n\n\n");
			system("pause");
		}
		
		
	
}

void viewCharacters (characters hero[MAX],int *numhero)
{
	
	
	int i;
	
	system("cls");
	
	for (i=0;i<*numhero;i++)
	{
		displayContents(hero[i]);
	}
	
	
	system("pause");
	
	
	
	/*
	
	int index = 0, bReturn = 0;
	char ch;
	
	if (numhero <= 0)
		{
			system("cls");
			printf ("No available characters to show.\n");
			printf("Exiting now! \n");
			system("pause");
			
		}
		
	else
	{
		while (!bReturn)
		{
			system("cls");
			displayContents(hero[index]);
			printf ("\n");
			printf ("[N] - Next \n");
			printf ("[B] - Back \n");
			printf ("[E] - Exit \n");
			ch = getch();
			
			if (ch == 'n' || ch == 'N') // Next
			{
				index++;
				if (index == numhero)
					index = 0;
			}
			else if (ch == 'b' || ch == 'B') // Prev
			{
				index--;
				if (index < 0)
					index = numhero - 1;
			}
			else if (ch == 'E' || ch == 'e')
				bReturn = 1;
		}

	}
	
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}




void saveToFile(characters hero[MAX],int numhero)
{
	FILE *pFile;
	int i;
	
	pFile = fopen("HEROLIST.txt","wt"); // 1st parameter = filename, 2nd = mode.
	
	if (pFile != NULL) // File is generated successfully
	{
		fprintf (pFile,"%d  \n",numhero);
		for (i = 0;i < numhero;i++)
		{
			fputs(hero[i].name,pFile);
			fputs(hero[i].stage,pFile);
			fprintf(pFile,"%d ",hero[i].nElem);
			fprintf(pFile,"%d ",hero[i].HP);
			fprintf(pFile,"%d ",hero[i].PP);
			fprintf(pFile,"%d ",hero[i].ID);
			fprintf(pFile,"%d ",hero[i].lightA);
			fprintf(pFile,"%d ",hero[i].mediumA);
			fprintf(pFile,"%d ",hero[i].heavyA);
	
		}
		fclose(pFile);
		
	}
	else
		printf ("Error generating file. :(\n");
}









void modifyHero (characters hero[MAX],int *numhero)
{
	int nKey;
	int i;
	int nChoice;
	int bExit = 0;
	char newName[20];
	char newStage[20];
	int elem,HP,PP;
	int ID;
	int menu =0;
	
system("cls");

while (!menu)
{
	if (*numhero == 0)
	{	system("cls");
		printf("No Heroes in the hero pool yet!!!\n");
		system("pause");
		menu = 1;
	}	
	else
{
		system("cls");
	
	for (i = 0;i <* numhero;i++)
	displayContents(hero[i]);
	
	printf("\n \n");
	
	do{
			printf("Enter the Hero ID you want to modify: ");
	
	scanf("%d",&ID);
		
			nKey = getIndex(hero,numhero,ID);
	}while( !(nKey != 12345));

	printf("\n");
	

	
	
	
	displayContents(hero[nKey]);
	
	
	while (!bExit)
	{
		do
		{
			
			
	printf("[1] Modify Name \n");
	printf("[2] Modify Location \n");
	printf("[3] Modify element number \n");
	printf("[4] Modify Max Hitpoints \n");
	printf("[5] Modify Max Powerpoints \n");
	printf("[6] Exit \n");
			scanf (" %d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice != 4 &&nChoice != 5 && nChoice !=6);
		
		getchar();
	if (nChoice == 1)
	{
	printf("Enter New name:");
	fgets(newName,20,stdin);
	strcpy(hero[nKey].name,newName);
    }
	
	else if (nChoice == 2)
	{
		getchar();
	printf("Enter New Stage:");
	printf("\n");
	fgets(newStage,20,stdin);
	strcpy(hero[nKey].stage,newStage);

	
    }
	else if (nChoice == 3)
	{
	getchar();
	printf("Enter New element:");
	 scanf("%d",&elem);
	hero[nKey].nElem = elem;	
	}
	else if (nChoice == 4)
	{
	printf("Enter New Max HP:");
	scanf(" %d",&HP);
	hero[nKey].HP = HP;
    }  
    else if (nChoice == 5)
	{printf("Enter New Max PP:");
	scanf("%d",&PP);
	hero[nKey].PP = PP;
    }
	else if (nChoice == 6)
	{	
	bExit = 1;
	menu = 1;
	}

}


}
}
}

void EditHero(characters hero[MAX],int *numhero)
{
	
	int i;
	int bExit = 0;
	int nChoice;
	
	while (!bExit)
	{
		do
		{
			system ("cls");
			printf ("Hero List information: \n\n");
			for (i = 0;i < *numhero;i++)
				displayContents(hero[i]);
			printf ("Enter option: \n");
			printf ("[1] - Add new Hero\n");
			printf ("[2] - Delete a Hero\n");
			printf(" [3] - Modify a Hero \n");
			printf(" [4]  - Exit \n");
			scanf ("%d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice != 4);
		
		if (nChoice == 1)
			addHero(hero,numhero);
		else if (nChoice == 2)
			delHero(hero,numhero); 
		else if (nChoice == 3)
			modifyHero(hero,numhero); 
				
		else if (nChoice == 4)
			bExit = 1;
	}
	
	
}

void Configure(characters hero[MAX],int *numhero)
{
	
	int i;
	int bExit = 0;
	int nChoice;
	int fire =0;
	int water =0;
	int air = 0;
	int earth =0;
	
	while (!bExit)
	{
		do
		{
			system ("cls");
			
			human ();
			printf ("Enter option:\n");
			printf ("[1] - add hero\n");
			printf ("[2] - delete hero\n");
			printf("[3] - view hero\n");
			printf("[4] - modify hero\n");
			printf("[5] - Exit\n");
			scanf ("%d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice != 4 && nChoice !=5);
		
		if (nChoice == 1)
		addHero(hero,numhero);
		else if (nChoice == 2)
		delHero(hero,numhero); 
		else if (nChoice ==3)	
		viewCharacters(hero,numhero);
		else if (nChoice == 4)
			modifyHero(hero,numhero); 
				
		else if (nChoice == 5)
		{
				for (i=0;i<*numhero;i++)
	      {
		           
				if (hero[i].nElem == 1)
	             	fire++;
	             
	             
	            if (hero[i].nElem == 2)
	           	   water++;
	            
	            if (hero[i].nElem == 3 )
	           	   earth++;
	            
	            
	            if (hero[i].nElem == 4)
	           	   air++;
	       }
			
			if ( fire != 0 && water != 0 && earth != 0 && air != 0)
			
				
		
			bExit = 1;
			
			
			
			else
			{
			printf("\n\nYou are not allowed to exit the configure until there is atleast one hero per element! \n");
			
			system("pause");
			bExit = 0;
			}
			
			
		}
		
	}
	
}


void GamePlaySelect (characters hero[MAX],int numhero,attack move[MAX],int nummove)
{
	int i;
	int Index1;
	int Index2;
	int Player1;
	int Player2;
	int bExit = 0;
	int menu = 0;
	
	int nChoice;
	srand(time(NULL));
	

while(!menu)
{
		if (numhero < 2)
	{
		system("cls");
		printf("Add more heroes please! \n");
		system("pause");
		menu = 1;
	}
	else{
		system("cls");
	
	int allow1 = 0;
	int allow2 =0;
	
	
		for (i = 0;i < numhero;i++)
				displayContents(hero[i]);
				

	
	
	do{
		
	printf("Please select your character (Enter HERO ID) : ");			
	scanf("%d",&Index1);
	printf("\n");
	Player1 = getIndex(hero,&numhero,Index1);
	
	
	if ( Player1 != 12345)
	{
	if ((hero[Player1].lightA != 0) && (hero[Player1].mediumA != 0) && (hero[Player1].heavyA != 0))
	allow1 = 1;
	else 
	{
	printf("Hero doesn't have complete set of attacks! \n");
	allow1 =0;
	}
	
	}
	else if (Player1 == 12345)
	printf("hero doesnt exist! \n");
	
    }while ( !(Player1 != 12345) || !(allow1 != 0) );
	
	
	
	
	
	
	printf("Player 1 selected: %s \n", hero[Player1].name);
	
do{	
	printf("Please select your Enemy (Enter HERO ID) : ");
	scanf("%d",&Index2);
	printf("\n");
	Player2 = getIndex(hero,&numhero,Index2);
	
	
	if (Player2 != 12345)
	{
		
	if ((hero[Player2].lightA != 0) && (hero[Player2].mediumA != 0) && (hero[Player2].heavyA != 0))
	allow2 = 1;
	
	else 
	{
	printf("Hero doesn't have complete set of attacks! \n");
	allow2 =0;
	}
	
		
	}
	
    }while ( !(Player1 != 12345) || !(allow2 != 0));	
	
	
	
	
	
	
	
	
	
	
	printf("Player 2 selected: %s \n", hero[Player2].name);
	system("pause");
	
	while (!bExit)
	{
		do
		{
			system ("cls");
			printf("Player 1 selected: %s \n", hero[Player1].name);
			printf("Player 2 selected: %s \n", hero[Player2].name);
			
		
			printf ("Enter option: \n");
			printf ("[1] - Start the Game \n");
			printf ("[2] - Change Characters\n");
			 printf("[3] - Exit \n");
		
			scanf ("%d",&nChoice);
			system("pause");
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 );
		
		if (nChoice == 1)
			StartGame(Player1,Player2,hero,numhero,move,nummove);
		else if (nChoice == 2)
			GamePlaySelect(hero,numhero,move,nummove);
		else if (nChoice == 3)
			bExit = 1;
	
	
	
	


	
   }			
	menu = 1;			
	
	
		
	}
	
	
	
	
}


}
	
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		







void Compute(int nChoice,int *currHP1,int *currHP2, int *currPP1, int *currPP2,int turn,int maxHP1,int maxHP2,int maxPP1,int maxPP2,int *damage,int elem1,int elem2)
{
	int a;
	float i; 
	float multiplier1;
	float multiplier2;
	
	if (elem1 == elem2)
	{multiplier1 = 0.75; multiplier2  = 0.75;}
	else if (elem1 == 1 && elem2 == 2 )
{multiplier1 = 1.5; multiplier2  = 1;}
	else if (elem1 == 4 && elem2 == 1 )
{multiplier1 = 1.5; multiplier2  = 1;}
else if (elem1 == 3 && elem2 == 4 )
{multiplier1 = 1.5; multiplier2  = 1;}
else if (elem1 == 2 && elem2 == 4 )
{multiplier1 = 1.5; multiplier2  = 3;}

else if (elem2 == 1 && elem1 == 2 )
{multiplier2 = 1.5; multiplier1  = 1;}
else if (elem2 == 4 && elem1 == 1 )
{multiplier2 = 1.5; multiplier1  = 1;}
else if (elem2 == 3 && elem1 == 4 )
{multiplier1 = 1.5; multiplier2  = 1;}
else if (elem1 == 3 && elem2 == 4 )
{multiplier1 = 1.5; multiplier2  = 1;}





	
	srand(time(NULL));
	
	int miss;
	*damage = 0;
	if(nChoice == 1 && (turn % 2) == 0)
	{
		*currPP1 += 3;

		
	}
	else if(nChoice == 1 && (turn % 2) == 1)
	{
		
		*currPP2 += 3;
	
	}
	
	
	
	if (nChoice ==2 &&  (turn % 2) == 0 )
	{

		
		miss = (rand() % (5-1))+1;
		if (miss > 1)
		{
		a = (rand() % (15-5+1))+5;
		i =  maxHP2*((float)a/100);
		i = i*multiplier2;
		*damage = i;
		*currHP2 = *currHP2 - *damage;
		}
		else if (miss == 1)
		*damage = 0;
		
		
		
}
	else if (nChoice ==2 &&  (turn % 2) == 1)
	{
		
		miss = (rand() % (5-1))+1;
		if (miss > 1)
		{
		a = (rand() % (15-5+1))+5;
		i =  maxHP1*((float)a/100);
		i = i*multiplier1;
		*damage = i;
		*currHP1 = *currHP1 - *damage;
		}
		else if (miss == 1)
		{
		*damage = 0;	
		}
		
	}
		
/////////////////////////////////////		
		
		if (nChoice ==3  &&  (turn % 2) == 0 )
	{
		miss = (rand() % (11-1))+1;
		if (miss >1)
		{
		a = (rand() % (30-20+1))+20;
		i = maxHP2*((float)a/100);
		
		i = i*multiplier2;
	
		*damage = i;
		*currHP2 = *currHP2 - *damage;
		}
		else if (miss ==1 )
		*damage = 0;
		
		
		}
	else if (nChoice ==3 &&  (turn % 2) == 1)
	{
		miss = (rand() % (11 -1))+1;
		
		if (miss >1)
		{
		a = (rand() % (30-20+1))+20;
		i =  maxHP1*((float)a/100);
		i = i*multiplier1;
		*damage = i;
		*currHP1 = *currHP1 - *damage;
		}
		else if (miss ==1)
		*damage = 0;
	}	
		
	
	if (nChoice ==4  &&  (turn % 2) == 0 )
	{
		a = (rand() % (50-40+1))+40;
		i = maxHP2*((float)a/100);
		i = i*multiplier2;
		*damage = i;
		*currHP2 = *currHP2 - *damage;
		}
	else if (nChoice ==4 &&  (turn % 2) == 1)
	{
		a = (rand() % (50-40+1))+40;
		i = maxHP1*((float)a/100);
		i = i*multiplier1;
		*damage = i;
		*currHP1 = *currHP1 - *damage; 	
	}		
		
			
}









void StartGame(int Player1, int Player2,characters hero[MAX],int numhero,attack move[MAX],int nummove)
{
	

		srand(time(NULL));
	int turn;
	int nChoice;
	int location;
	char stage[MAX];
	int bExit =0;
	int index;
	float j,k;
	int i,a;
	int costL1, costM1, costH1, costL2, costM2, costH2;
	

	int maxHP1 = hero[Player1].HP;
	int maxHP2 = hero[Player2].HP;
	int damage = 0;
	int maxPP1 = hero[Player1].PP;
	int maxPP2 = hero[Player2].PP;
	int currHP1 = hero[Player1].HP;
	int currHP2 = hero[Player2].HP;
	int currPP1 = 0;
	int currPP2 = 0;
	float multi;
	int elem1 = hero[Player1].nElem;
    int elem2 = hero[Player2].nElem;
    
int J;
	
    char light_move1[300];
	char light_move2[300];
	char medium_move1[300];
	char medium_move2[300];
	char heavy_move1[300];
	char heavy_move2[300]; 
	
 int lightmove1 = hero[Player1].lightA;
 int lightmove2  = hero[Player2].lightA;
	
	


 int mediummove1 = hero[Player1].mediumA;
 int mediummove2 = hero[Player2].mediumA;
 int heavymove1 = hero[Player1].heavyA;
 int heavymove2 = hero[Player2].heavyA;
	
	lightmove1 = getIndexMove(move,&nummove,lightmove1);
	lightmove2 = getIndexMove(move,&nummove,lightmove2);
	
	mediummove1 = getIndexMove(move,&nummove,mediummove1);
	mediummove2 = getIndexMove(move,&nummove,mediummove2);
	
	
	
	heavymove1 = getIndexMove(move,&nummove,heavymove1);
	heavymove2 = getIndexMove(move,&nummove,heavymove2);
	

	strcpy(light_move1,move[lightmove1].name);
	
	strcpy(light_move2,move[lightmove2].name);	 
	strcpy(medium_move1,move[mediummove1].name); 
	strcpy(medium_move2,move[mediummove2].name);
	strcpy(heavy_move1,move[heavymove1].name);
	strcpy(heavy_move2,move[heavymove2].name);


	
	
	
	a = (rand() % (20-10+1))+10;
	i = maxPP1*((float)a/100);
    costL1 = i;
    
    a = (rand() % (50-30+1))+30;
	i = maxPP1*((float)a/100);
    costM1 = i;
    
    a = (rand() % (80-60+1))+60;
	i = maxPP1*((float)a/100);
    costH1 = i;
    
    
    a = (rand() % (20-10+1))+10;
	i = maxPP2*((float)a/100);
    costL2 = i;
    
    a = (rand() % (50-30+1))+30;
	i = maxPP2*((float)a/100);
    costM2 = i;
    
    a = (rand() % (80-60+1))+60;
	i = maxPP2*((float)a/100);
    costH2 = i;

	
	
	
	turn = (rand ()%(3-1))+1;
	

	
	
	strcpy(stage,hero[Player2].stage);
	
	
	i = 0;

	while (!bExit)
	{
		
		do
		{
			
			system("cls");
		printf("%s",stage);
		printf("\n\n");
		
		Earth();
		
		printf("%s",hero[Player1].name);
		printf("\t\t\t\t\t\t\t\t\t%s",hero[Player2].name);
		printf("\n");
	if (hero[Player1].nElem == 1)
	printf ("\t\t\tFire\t\t");
	else if (hero[Player1].nElem ==  2)
		printf ("\t\t\tWater\t\t");
	else if (hero[Player1].nElem ==  3)
	printf ("\t\t\tEarth\t\t");	
	else if (hero[Player1].nElem ==4 )
	printf ("\t\t\tAir\t\t");
	printf(" vs \t\t\t ");
	if (hero[Player2].nElem == 1)
	printf ("Fire\n");
	else if (hero[Player2].nElem ==  2)
		printf ("Water\n");
	else if (hero[Player2].nElem ==  3)
	printf ("Earth\n");	
	else if (hero[Player2].nElem ==4 )
	printf ("Air\n");
	
	printf("\t\t\tHP: %d / %d \t\t\t\t\t",currHP1,maxHP1);
	printf("HP: %d / %d \n",currHP2,maxHP2);			
		
	printf("\t\t\tPP: %d / %d \t\t\t\t\t",currPP1,maxPP1);
	
	printf("PP: %d / %d \n",currPP2,maxPP2);
	nChoice = 0;	
	

	
	if (turn % 2 == 0)
	{

	printf("Player's Turn!\n\n");
	printf("Select Move:\n");
	printf("[1] Charge \n");
	printf("[2] %s ",light_move1);
	printf("(Required PP: %d) %s",costL1,move[lightmove1].description);
	printf("[3] %s ",medium_move1);
	printf("(Required PP: %d) %s",costM1,move[mediummove1].description);
	printf("[4] %s ",heavy_move1);
	printf("(Required PP: %d) %s",costH1,move[heavymove1].description);	

	
while(!i)
	{
		
	do {
	printf("enter choice: \n");
	scanf(" %d",&nChoice);
	
		
	}while(nChoice != 1 && nChoice != 2 && nChoice != 3 && nChoice !=4); 
	
	
	if (nChoice == 1)
	{
	Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
	 i = 1;
	 turn++;
   }
	
	
	if (nChoice == 2 && currPP1 >= costL1 )
	{

		currPP1 -= costL1;
		Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
		i =1;
		currPP1 += 2;
		turn++;
	}
	else if (nChoice == 2 && currPP1 < costL1 )
	printf("insufficient PP!!! TRY AGAIN! \n");
		

	if (nChoice == 3 && currPP1 >= costM1 )
	{
		currPP1 -= costM1;
		Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
		currPP1 += 2;
		i =1;
		turn++;
	}
	else if (nChoice == 3 && currPP1 < costM1 )
	printf("insufficient PP!!!TRY AGAIN! \n");	
	
	if (nChoice == 4 && currPP1 >= costH1 )
	{
		currPP1 -= costH1;
		Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
		currPP1 += 2;
		i =1;
		turn++;
	}		
	else if (nChoice == 4 && currPP1 < costH1 )
	printf("insufficient PP!!!TRY AGAIN! \n");	
	
	}
	
	if (currPP1 > maxPP1)
	currPP1 = maxPP1;
	
	
	
}



	else if (turn % 2 == 1)
	{
		printf("enemy's turn: \n");
	
	printf("Enemy choosing a move:\n");
	printf("[1] Charge \n");
	printf("[2] %s (Required PP: %d) \n",light_move2,costL2);
	printf("[3] %s (Required PP: %d) \n",medium_move2,costM2);
	printf("[4] %s (Required PP: %d) \n",heavy_move2,costH2);
		
		
do{
		srand(time(NULL));
	 int k;
	 
	 for (k=0;k<100;k++)
	 {
	 	 J = (rand()%(10-1))+1;
	 }
	
	 
	
	
	
	if (J == 1 || J == 2 || J ==3 || J == 4)
	{
		     nChoice =1;
		     
	
			Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
			printf("\n \t\t\t\t\t\t\t%s \t\t\t\t\t\t\tused charged!!! \n",hero[Player2].name);
		i =0;
		turn++;
	}
	else if (J == 5 || J == 6 || J==7 || J ==8 || J == 9 ||J ==10)
	{
		
		if (currPP2 >= (k = (float)maxPP2*0.20) && currPP2 < (k = (float)maxPP2*0.35) )
		{
			nChoice = 2;
			currPP2 -= costL2;
			Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
			currPP2 += 2;
			printf("\n \t\t\t\t\t\t\t%s \t\t\t\t\t\ttused %s!!! \n",hero[Player2].name,light_move2);
			
			i =0;
			turn++;
		}
	else if (currPP2 >= (k = (float)maxPP2*0.35) && currPP2 < (k = (float)maxPP2*0.70) )
		{
			nChoice = 3;
			currPP2 -= costM2;
			Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
			currPP2 += 2;
			printf(" \n \t\t\t\t\t\t\t%s \t\t\t\t\t\t\tused %s!!! \n",hero[Player2].name,medium_move2);
			turn++;
			i =0;
		}
	else if (currPP2 >= (k = (float)maxPP2*0.70) && currPP2 <= (k = (float)maxPP2*0.100) )
		{
			nChoice = 4;
			currPP2 -= costH2;
			Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
			currPP2 += 2;
			printf(" \n \t\t\t\t\t\t\t%s \t\t\t\t\t\t\tused %s!!! \n",hero[Player2].name,heavy_move2);
			turn++;
			i =0;
		}

		
	}
	

	if (currPP2 > maxPP2)
	currPP2 = maxPP2;


		
	}while( !(turn % 2 == 0) );
}



	if ((turn % 2 == 1 && (nChoice >=2 && nChoice <=4 ) ) && damage > 0 )
		printf("\n \t\t\t\t\t\t\tEnemy received %d damage!!! \n",damage);
		else if ((turn % 2 == 1 && (nChoice >=2 && nChoice <=4 )) && damage == 0 )
		printf("\n \t\t\t\t\t\t\t\tYOU ATTACK MISSED! \n ");
		
		
		else if ((turn % 2 == 0 && (nChoice >=2 && nChoice <=4 ) ) && damage >0  )
		printf("\n \t\t\t\t\tYou received %d damage! \n",damage);
		else if ((turn % 2 ==  0&& (nChoice >=2 && nChoice <=4 )) && damage == 0 )
		printf("\n \t\t\t\t\t\t\t\tEnemy ATTACK MISSED!!! \n ");



	system("pause");
		
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice !=4 );
		
		if (currHP1 <= 0  )
			{
				system("cls");
				printf("\n\n\t\t\t\t%s WON THE BATTLE!!!!\n\n",hero[Player2].name);
				system("pause");
				bExit = 1;
			}
			
		else if	(currHP2 <= 0 )
		{
			system("cls");
			printf("\n\n\n\t\t\t\t %s HAS WON THE BATTLE!!!!\n\n",hero[Player1].name);
			system("pause");
				bExit = 1;
		}
		else if (currHP1 > 0 )
			bExit = 0;
	}
	
		
	



	
}





void displayContentsMove(attack move)
{

	printf("Move Name:%s",move.name);
	printf("Description:%s",move.description);
	printf("MOVE ID: %d\n",move.ID);
	
	if (move.attacktype == 1)
	printf ("AttackType: Light Attack");
	else if (move.attacktype ==  2)
		printf ("AttackType: Medium Attack");
	else if (move.attacktype ==  3)
	printf ("AttackType: Heavy Attack");	
	printf("\n");
	
	if (move.element == 1)
		printf ("Element: Fire\n");
	else if (move.element ==  2)
		printf ("Element: Water\n");
	else if (move.element ==  3)
	printf ("Element: Earth\n");	
	else if (move.element == 4 )
	printf ("Element: Air\n");
	
	
	printf("\n");
	
	
}






void saveToFileMove(attack move[MAX],int nummove)
{
	FILE *pFile;
	int i;
	
	pFile = fopen("newfile.txt","wt"); // 1st parameter = filename, 2nd = mode.
	
	if (pFile != NULL) // File is generated successfully
	{
		fprintf (pFile,"%d\n",nummove);
		for (i = 0;i < nummove;i++)
		{
			fputs(move[i].name,pFile);
			fputs(move[i].description,pFile);
			fprintf(pFile,"%d ",move[i].ID);
			fprintf(pFile,"%d ",move[i].attacktype);
			fprintf(pFile,"%d ",move[i].element);
		
		}
		fclose(pFile);
		
	}
	else
		printf ("Error generating file. :(\n");
}






void addMove (attack move[MAX],int *nummove)
{
	int newID; 
	int secret;
	
	system ("cls");
	
	srand (time(NULL));
	secret = (rand() % (9999 - 1000 + 1)) + 99;
	
	
	printf("MOVE ID number: %d \n",secret);
	move[*nummove].ID = secret;
	
	
	printf ("Entering MOVE information #%d \n",*nummove+1);
	getchar();
	printf ("Enter the Move's name: ");
	fgets(move[*nummove].name,20,stdin);
	printf("Enter any key to continue....\n");
	getch();
	printf ("Enter the Move's description: ");
    fgets(move[*nummove].description,300,stdin);
    printf("\n");

    
    
	printf ("Enter [1] Light Attack    Enter [2] Medium Attack Enter [3] Heavy Attack: \n ");
	printf ("Enter Move attacktype number: \n ");
	
	
	do {
		 scanf ("%d",&move[*nummove].attacktype);
		if (move[*nummove].attacktype != 1 || move[*nummove].attacktype != 2 || move[*nummove].attacktype != 3 )
		printf("Enter only integer values from 1 - 3 \n");
		
	}while ( move[*nummove].attacktype != 1 && move[*nummove].attacktype != 2 && move[*nummove].attacktype !=3  );
	
	
	printf ("Enter [1] Fire    Enter [2] Water  Enter [3] Earth  Enter [4] - Air \n ");
	printf ("Enter The Element Number:\n ");
	
	
	
		do {
				scanf ("%d",&move[*nummove].element);
		
	}while ( move[*nummove].element != 1 && move[*nummove].element != 2 && move[*nummove].element !=3 && move[*nummove].element !=4 );
	

	
	
		saveToFileMove(move,*nummove);
	
	 


	(*nummove)++;
}





void delMove (attack move[MAX],int *nummove,characters hero[MAX],int *numhero)
{
		int nKey;
		int ID;
		int i;
		int menu = 0;
		
		system("cls");
		while (!menu)
		{
			
			if (*nummove == 0)
			{
				printf("No moves to destroy!!! \n");
				printf("Exiting now \n\n\n\n");
				system("pause");
				menu = 1;
			}
			else
			{
				system ("cls");
		
		for (i = 0;i <*nummove;i++)
		displayContentsMove(move[i]);
		
		do{
				printf("Enter which the ID number of the Move you want to delete: ");
		scanf("%d",&ID);
		nKey = getIndexMove(move,nummove,ID);
			
		}while ( !(nKey != 12345 ));
	
		
		
		
	
		
		
		printf ("\n");
		printf ("Deleting element at index %d ",nKey);
		
		
		if (move[nKey].attacktype == 1)		
		{
			for (i = 0;i<*numhero;i++)
		{
			
			if (hero[i].lightA == move[nKey].ID)
			hero[i].lightA = 0;
	    }			
		}		
		else if (move[nKey].attacktype == 2)
		{
			for (i=0;i<*numhero;i++)
			{
			if (hero[i].mediumA == move[nKey].ID)
			hero[i].mediumA = 0;
			}		
		}	
		else if (move[nKey].attacktype == 2)
		{
			for (i=0;i<*numhero;i++)
			{
			if (hero[i].heavyA == move[nKey].ID)
			hero[i].heavyA = 0;
			}	
		}
		

		
		while (nKey < *nummove-1)
		{
				strcpy (move[nKey].name, move[nKey+1].name);
				strcpy(	move[nKey].description, move[nKey+1].description);
				
				
				
				move[nKey].ID = move[nKey+1].ID;
				move[nKey].attacktype = move[nKey+1].attacktype;
			    move[nKey].element = move[nKey+1].element;
				

				nKey++;
		}		
				(*nummove)--;
				
		
				
				
			system("pause");
			menu = 1;	
			}
			
			
		}
		saveToFileMove(move,*nummove);
}


int getIndexMove(attack move[MAX],int *nummove,int getID)
{
	int i;
	int Index;
	
	
	for (i=0;i<*nummove;i++)
	{
		if (move[i].ID==getID)
		{
		Index = i;
		return Index;	 
	    }
	    else 
	    Index = 12345;
	}
	
	return Index;
}


void modifyMove (attack move[MAX],int *nummove)
{
	int nKey;
	int i;
	int nChoice;
	int bExit = 0;
	char newName[20];
	char newDescription[200];
	int attacktype, element;
	int ID;
	int menu = 0;

system("cls");

while (!menu)
{
	if (*nummove == 0)
	{	
		printf("No available moves yet!!!\n");
		system("pause");
		menu = 1;
	}
	else
	{
		system("cls");
	
	for (i = 0;i <* nummove;i++)
	displayContentsMove(move[i]);
	
	printf("\n \n");
	
	do {
		
		printf("Enter the MOVE ID you want to modify: ");
	scanf("%d",&ID);
		nKey = getIndexMove(move,nummove,ID);
	}while (!(nKey != 12345));
	
	printf("\n");
	

	
	
	
	displayContentsMove(move[nKey]);
	
	
	while (!bExit)
	{
		do
		{
			
			printf("\n");
	printf("[1] Modify Name \n");
	printf("[2] Modify Description \n");
	printf("[3] Modify Attacktype \n");
	printf("[4] Modify Element \n");
	printf("[5] Exit \n");
			scanf (" %d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice != 4 &&nChoice != 5);
		
		system("pause");
	if (nChoice == 1)
	{
		getch();
	printf("Enter New name: \n");
	fgets(newName,sizeof(newName),stdin);
	strcpy(move[nKey].name,newName);
	printf("new name entered: %s",move[nKey].name);
    }
	
	else if (nChoice == 2)
	{
	getch();
	printf("Enter Description:");
	fgets(newDescription,sizeof(newDescription),stdin);
	strcpy(move[nKey].description,newDescription);	
	printf("new description entered: %s",move[nKey].description);
}
	else if (nChoice == 3)
	{printf("Enter New AttackType:");
	 scanf(" %d",&attacktype);
	move[nKey].attacktype = attacktype;	
	printf("new attacktype entered: %d",move[nKey].attacktype);
	}
	else if (nChoice == 4)
	{printf("Enter New element:");
	 scanf(" %d",&move);
	move[nKey].element = element;	
	printf("new element entered: %d",move[nKey].element);
	}
	
	
	else if (nChoice == 5)
	bExit = 1;
		menu = 1;
	}
	

}///while
	
	
	
	
}
	
	saveToFileMove(move,*nummove);
}

void viewmove(attack move[MAX],int *nummove)
{	
	int i;
	int menu = 0;
	system("cls");

	while (!menu)
	{
		if (*nummove == 0)
		{
			printf("no moves to view here\n!!!");
			printf("exiting now \n\n\n\n");
			menu = 1;
			system("pause");
		}
		else
		{
			
	printf ("Move List information: \n\n");	
			
			for (i = 0;i < *nummove;i++)
				displayContentsMove(move[i]);
		system("pause");
		menu = 1;	
			
		}
		
		
	}
	
		
}

void assignMove (attack move[MAX],int *nummove,characters hero[MAX],int *numhero)
{
	int nKeyhero;
	int nKeymove;
	int i;
	int nChoice;
	
	char newName[20];
	char newDescription[200];
	int attacktype, element;
	int IDhero, IDmove;
	int menu = 0;
	int allow1 = 0;
	system("cls");
	
	printf("total moves %d \n",*nummove);
	
	while (!menu)
	{
		if (*nummove == 0)
		{
			printf("No moves to assign with\n");
			printf("Exiting now!!\n\n");
			menu = 1;
			system("pause");
		}
		else
		{
			system("cls");
		
		for (i = 0;i < *nummove;i++)
				displayContentsMove(move[i]);
		
		do{
		printf("Enter the ID number of the move you want to assign: ");
		scanf("%d",&IDmove);
		IDmove = getIndexMove(move,nummove,IDmove);
	
	if ( IDmove != 12345)
	{
		printf("%s move Selected! \n",move[IDmove].name);
	}
	else if  (IDmove == 12345)
	printf("move ID doesnt exist! \n");
	
    }while ( !(IDmove != 12345) );
			
		
		
		
		

		system("pause");
		
		system("cls");
		
			for (i = 0;i < *numhero;i++)
				displayContents(hero[i]);
	
		
	do{
		
		printf("Enter which the ID number of hero ");
		scanf("%d",&IDhero);
		nKeyhero = getIndex(hero,numhero,IDhero);
	
	printf("%d \n",IDmove);


	if ( nKeyhero != 12345)
	{

		
			if (hero[nKeyhero].nElem == move[IDmove].element)
		{
			if (move[IDmove].attacktype == 1)
			hero[nKeyhero].lightA = move[IDmove].ID;
			
			else if (move[IDmove].attacktype == 2)
			hero[nKeyhero].mediumA = move[IDmove].ID;
			
			else if (move[IDmove].attacktype == 3)
			hero[nKeyhero].heavyA = move[IDmove].ID;
			 allow1 = 1;
			printf("new attack added! \n");
			system("pause");
		
		}
		else
		printf("Elements not compatible\n\n");	
	}	
	else if (nKeyhero == 12345)
	printf("hero doesnt exist! \n");
	
    }while ( !(nKeyhero != 12345) || !(allow1 != 0 ));
	
	menu = 1;


		
			
		}
		
		
		
	}
		saveToFileMove(move,*nummove);
}



void savetofile3 (story story[MAX], int numstory)
{
	FILE *pFile3;
	int i;
	int j=0;
	pFile3 = fopen("storyline.txt","wt"); // "RT = Read text"
	
	if (pFile3 != NULL) // file exists
	{
		
		fprintf(pFile3,"%d \n",numstory);
		for (i = 0;i < numstory;i++)
		{
			fprintf(pFile3,"%d \n",story[i].ID);
			fputs(story[i].title,pFile3);
			fputs(story[i].description,pFile3);
			fputs(story[i].protagonist.name,pFile3);
			fputs(story[i].protagonist.stage,pFile3);
			fprintf(pFile3," %d ",story[i].protagonist.ID);
			fprintf(pFile3," %d ",story[i].protagonist.HP);
			fprintf(pFile3," %d ",story[i].protagonist.PP);
			fprintf(pFile3," %d ",story[i].protagonist.nElem);
			fprintf(pFile3," %d ",story[i].protagonist.lightA);
			fprintf(pFile3," %d ",story[i].protagonist.mediumA);
			fprintf(pFile3," %d ",story[i].protagonist.heavyA);
			
			
			fprintf(pFile3,"%d",story[i].numEnem);
			for (j = 0;j < story[i].numEnem; j++)
			{
			fputs(story[i].Enemy[j].name,pFile3);
			fputs(story[i].Enemy[j].stage,pFile3);
			fprintf(pFile3," %d ",story[i].Enemy[j].ID);
			fprintf(pFile3," %d ",story[i].Enemy[j].HP);
			fprintf(pFile3," %d ",story[i].Enemy[j].PP);
			fprintf(pFile3," %d ",story[i].Enemy[j].nElem);
			fprintf(pFile3," %d ",story[i].Enemy[j].lightA);
			fprintf(pFile3," %d ",story[i].Enemy[j].mediumA);
			fprintf(pFile3," %d ",story[i].Enemy[j].heavyA);

				
			}
			
		}
		fclose(pFile3);
	}
	else
		printf ("File does not exist.\n");
	
}





ConfigureMove (attack move[MAX],int *nummove,characters hero[MAX],int *numhero)
{
	
	int i, nChoice, bExit = 0;
 	CheckList2(move,nummove);
	
		while (!bExit)
	{
		do
		{
			system ("cls");
			printf ("Enter option: \n");
			printf ("[1] - Add new move\n");
			printf ("[2] - Delete a move \n");
			printf("[3] - Modify a move \n");
			printf("[4] - view moves \n");
			printf("[5] - assign moves \n");
			printf("[6] - Exit \n");
		
			scanf (" %d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice != 4 && nChoice !=5 && nChoice != 6);
		
		if (nChoice == 1)
			addMove(move,nummove);
		else if (nChoice == 2)
			delMove(move,nummove,hero,numhero); 
		else if (nChoice == 3)
			modifyMove(move,nummove); 
		else if (nChoice == 4)	
			viewmove(move,nummove);
		else if (nChoice == 5)
			assignMove(move,nummove,hero,numhero);	
		else if (nChoice == 6)
			bExit = 1;
	
}
	saveToFileMove(move,*nummove);

}

void displayContentsStory(story story)
{

	
	int i = 0;
	printf("================================================\n");
	printf("Storyline title:%s",story.title);
	printf("Storyline ID number: %d\n",story.ID);
	printf("Description:%s",story.description);
	
	printf("Protagonist : %s",story.protagonist);
	
	if (story.protagonist.nElem == 1)
	printf ("Element: Fire\n");
	else if (story.protagonist.nElem  ==  2)
	printf ("Element: Water\n");
	else if (story.protagonist.nElem ==  3)
	printf ("Element: Earth\n");	
	else if (story.protagonist.nElem  == 4 )
	printf ("Element: Air\n");
	
	printf("Enemies: %d \n",story.numEnem);
	for (i = 0; i < story.numEnem;i++)
	{
	printf("Enemy #%d : %s",i+1,story.Enemy[i].name);
	printf("Enemy ID number: %d \n",story.Enemy[i].ID);
	
	if (story.Enemy[i].nElem == 1)
	printf ("Element: Fire\n");
	else if ( story.Enemy[i].nElem ==  2)
	printf ("Element: Water\n");
	else if ( story.Enemy[i].nElem ==  3)
	printf ("Element: Earth\n");	
	else if (story.Enemy[i].nElem  == 4 )
	printf ("Element: Air\n");
	
		
	}
	printf("================================================\n");
	
	
	
}






void addStory (story story[MAX],int *numstory,characters hero[MAX],int *numhero)
{
	int newID; 
	int secret;
	int i;
	int nkey;	
	int protaID=0;
	system ("cls");
	int numEnem;
	int enemID;
	int allow1 = 0;
	int ctr =0;
	int Ekey = 0;
	int nKey =0;
		for (i = 0;i <*numhero;i++)
	{
		if (hero[i].lightA != 0 && hero[i].mediumA !=0 && hero[i].heavyA != 0 )
		ctr++;
	}
	
	
	if (ctr<4)
	{
		printf("Not enough heroes to create a story!\n");
		system("pause");
	}
	else 
	{
		ctr =0;
		
			printf("List of available heroes: \n");
	
	for (i = 0;i <*numhero;i++)
	{
		if (hero[i].lightA != 0 && hero[i].mediumA !=0 && hero[i].heavyA != 0 )
		{
			displayContents(hero[i]);
			ctr++;
		}
		
	}
	
	
	
	srand (time(NULL));
	secret = (rand() % (9999 - 1000 + 1)) + 99;
	
	
	printf("Storyline ID number: %d \n",secret);
	story[*numstory].ID = secret;
	
	
	printf ("Entering Story information #%d \n", *numstory+1);
	getchar();
	printf ("Enter the Storyline's Title: ");
	fgets(story[*numstory].title,sizeof(story[*numstory].title),stdin);
	printf("press anykey to continue....\n");
	getch();
	printf ("Enter the Storyline's description: ");
    fgets(story[*numstory].description,sizeof(story[*numstory].description),stdin);
    printf("\n");
    
    
    
    
	do{
		
	printf("Enter the ID number of the protagonist! \n");
    scanf(" %d",&protaID);
	printf("\n");
	
	int nKey;
	 nKey = getIndex(hero,numhero,protaID);
	
	
	
	
	
	if ( protaID != 12345)
	{
		
		
		
	if ((hero[nKey].lightA != 0) && (hero[nKey].mediumA != 0) && (hero[nKey].heavyA != 0))
	{
	
	allow1 = 1;	
	}
	else if (((hero[nKey].lightA == 0) && (hero[nKey].mediumA == 0) && (hero[nKey].heavyA == 0)))
	{
	        printf("Hero doesn't have complete set of attacks! \n");
          	allow1 =0;	}
	
	}
	else
	printf("hero does not exist!! \n");
	
    }while ( !(protaID != 12345) || !(allow1 != 0) );
    
    


    story[*numstory].protagonist.ID = protaID;
    
    
    
    
    strcpy(story[*numstory].protagonist.name,hero[nKey].name);
    strcpy(story[*numstory].protagonist.stage,hero[nKey].stage);
    
   story[*numstory].protagonist.HP = hero[nKey].HP;
    story[*numstory].protagonist.PP = hero[nKey].PP;
    story[*numstory].protagonist.nElem = hero[nKey].nElem;
    
    story[*numstory].protagonist.lightA = hero[nKey].lightA;
    story[*numstory].protagonist.mediumA = hero[nKey].mediumA;
    story[*numstory].protagonist.heavyA = hero[nKey].heavyA;
    
       
       
       
       
printf("number of heros in the pool: %d \n",*numhero);

do {
	
	printf("enter number of enemies that the protagonist will fight: \n");
    scanf(" %d",&numEnem);
	if (numEnem < 3)
	printf("Stories require greater than or equal to 3 enemies! \n");
	
	
}while ( !(numEnem >= 3) );
		
	
    
    
    
    
     story[*numstory].numEnem = numEnem;
    
    
 allow1 = 0;
    
    for (i = 0;i < ctr-1;i++)
    {

    	
    	do{
		
	printf("Enter the ID number of the Enemy! \n");
    scanf("%d",&enemID);
	printf("\n");
	
	

	
	
	
	
	if ( Ekey != 12345)
	{
		
		
		if (enemID == protaID)
		printf("The protagonist cannot fight himself!\n");
		else 
		{
	if ((hero[Ekey].lightA != 0) && (hero[Ekey].mediumA != 0) && (hero[Ekey].heavyA != 0))
	allow1 = 1;
	else 
	{
	printf("Hero doesn't have complete set of attacks! \n");
	allow1 =0;
	}
	
	}

	}
	else if (enemID == 12345)
	printf("hero does not exist!! \n");
	
	
    }while ( !(enemID != 12345) || !(allow1 != 0) );
    
    	
int Ekey = getIndex(hero,numhero,enemID);
    
    
    story[*numstory].Enemy[i].ID = enemID;
    
    
    strcpy(story[*numstory].Enemy[i].name,hero[Ekey].name);
    strcpy(story[*numstory].Enemy[i].stage,hero[Ekey].stage);
    
    story[*numstory].Enemy[i].HP = hero[Ekey].HP;
    story[*numstory].Enemy[i].PP = hero[Ekey].PP;
    story[*numstory].Enemy[i].nElem = hero[Ekey].nElem;
    
    story[*numstory].Enemy[i].lightA = hero[Ekey].lightA;
    story[*numstory].Enemy[i].mediumA = hero[Ekey].mediumA;
    story[*numstory].Enemy[i].heavyA = hero[Ekey].heavyA;
    	
    printf("enemy %s added!\n",story[*numstory].Enemy[i].name);	
    	
    	
    	
	}
	printf("New story line saved!! \n");

    system("pause");
    
    
    
    


	(*numstory)++;
		
		
	}
	
	savetofile3(story, *numstory);

}




void delStoryline (story story[MAX],int *numstory)
{
int nKey;
int i = 0, menu = 0, bSelect = 0;
	char ch;
	
	if (*numstory <= 0)
		printf ("No characters to display.\n");
	else
	{
		while (!menu)
		{
			system("cls");
			displayContentsStory(story[i]);
			printf ("\n");
			printf ("[N]ext [B]ack [S]elect [E] - Exit");
			ch = getch();
			
			switch(ch)
			{
				case 'n':
				case 'N':
				{
					i++;
					if (i == *numstory)
					i = 0;
					break;
				}	
				case 'B':
				case 'b':
				{
					i--;
					if (i < 0)
					i = *numstory - 1;
					break;
				}	
				case 'E':
				case 'e':
					{   menu = 1;
				     	break;
					}
				case 'S':
				case 's':
				{
					bSelect = 0;
				while (!bSelect)
				{
						do
					{
						system("cls");
						displayContentsStory(story[i]);
						printf ("\n");
						printf ("you choose to destory this story?");
						printf ("[D] - Destory  [S] - Spare");
						ch = getch();
					} while (ch != 'D' && ch != 'd' && ch != 'S' && ch != 's');
					if (ch == 'd' || ch == 'D')
					{
						
						nKey = i;
						
					while (nKey < *numstory-1)
	           	{
				strcpy (story[nKey].title, story[nKey+1].title);
				strcpy(	story[nKey].description, story[nKey+1].description);
				story[nKey].ID = story[nKey+1].ID;
				story[nKey].numEnem = story[nKey+1].numEnem;
			    strcpy(story[nKey].protagonist.name,story[nKey+1].protagonist.name);
			    strcpy(story[nKey].protagonist.stage,story[nKey+1].protagonist.stage);
			    story[nKey].protagonist.ID = story[nKey+1].protagonist.ID;
			    story[nKey].protagonist.HP = story[nKey+1].protagonist.HP;
			    story[nKey].protagonist.PP = story[nKey+1].protagonist.PP;
			    story[nKey].protagonist.nElem = story[nKey+1].protagonist.nElem;
			    story[nKey].protagonist.lightA = story[nKey+1].protagonist.lightA;
			    story[nKey].protagonist.mediumA = story[nKey+1].protagonist.mediumA;
			    story[nKey].protagonist.heavyA = story[nKey+1].protagonist.heavyA;
			    
			    for (i=0;i<story[nKey+1].numEnem;i++)
			    {
			    	strcpy(story[nKey].Enemy[i].name,story[nKey+1].Enemy[i].name);
			    	strcpy(story[nKey].Enemy[i].stage,story[nKey+1].Enemy[i].stage);
			    	story[nKey].Enemy[i].ID = story[nKey+1].Enemy[i].ID;
			    	story[nKey].Enemy[i].HP = story[nKey+1].Enemy[i].HP;
			    	story[nKey].Enemy[i].PP = story[nKey+1].Enemy[i].PP;
			    	story[nKey].Enemy[i].nElem = story[nKey+1].Enemy[i].nElem;
			    	story[nKey].Enemy[i].lightA = story[nKey+1].Enemy[i].lightA;
			        story[nKey].Enemy[i].mediumA = story[nKey+1].Enemy[i].mediumA;
			    	story[nKey].Enemy[i].heavyA = story[nKey+1].Enemy[i].heavyA;
				}
			    
				
					
				nKey++;
	            }	
						
				(*numstory)--;	
				
				printf ("\nStory destoryed!\n");
						system("pause");
						bSelect = 1;
				
				
				     }	
				    else
				    bSelect = 1;
					
					
				}	
				
				
				
				break;
			
			}

}
}
}
savetofile3(story, *numstory);
}




void modifyStory (story story[MAX],int numstory,characters hero[MAX],int *numhero)
{
	int nChoice;
	int enemID;
	int bExit = 0;
	char newTitle[20];
	char newDescription[200];
	int numEnem;
	int attacktype, element;
	int ID;
	int enemIndex;
	int nKey;
    int i = 0, j=0, menu = 0, bSelect = 0;
	char ch;
	
	if (numstory <= 0)
		printf ("No Storyline....\n");
	else
	{
		while (!menu)
		{
			system("cls");
			displayContentsStory(story[i]);
			printf ("\n");
			printf ("[N]ext [B]ack [S]elect [E] - Exit");
			ch = getch();
			
			switch(ch)
			{
				case 'n':
				case 'N':
				{
					i++;
					if (i == numstory)
					i = 0;
					break;
				}	
				case 'B':
				case 'b':
				{
					i--;
					if (i < 0)
					i = numstory - 1;
					break;
				}	
				case 'E':
				case 'e':
					{   menu = 1;
				     	break;
					}
				case 'S':
				case 's':
					{
					bSelect = 0;
				while (!bSelect)
				{
						do
					{
						system("cls");
						displayContentsStory(story[i]);
						printf ("\n");
						printf ("you choose to Change this story?");
						printf ("[C] - Change  [S] - Spare");
						ch = getch();
					} while (ch != 'C' && ch != 'c' && ch != 'S' && ch != 's');
					if (ch == 'C' || ch == 'c')
					{
				     	nKey = i;
					while (!bExit)
	{
		do
		{
			
	system("cls");
	displayContentsStory(story[i]);		
	printf("\n");
	printf("[1] Modify Title \n");
	printf("[2] Modify Description \n");
	printf("[3] Modify Protagonist \n");
	printf("[4] Modify Enemies \n");
	printf("[5] Exit \n");
			scanf (" %d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice != 4 &&nChoice != 5);
		
		system("pause");
	if (nChoice == 1)
	{
		getchar();
	printf("Enter New Title: \n");
	fgets(newTitle,sizeof(newTitle),stdin);
	strcpy(story[nKey].title,newTitle);
	printf("new name entered: %s",story[nKey].title);
    }
	
	else if (nChoice == 2)
	{
	getchar();
	printf("Enter Description:");
	fgets(newDescription,sizeof(newDescription),stdin);
	strcpy(story[nKey].description,newDescription);	
	printf("new description entered: %s",story[nKey].description);
}
	else if (nChoice == 3)
	{
	
	int index = 0, bReturn = 0;
	char ch;
	
	if (numhero <= 0)
		printf ("No characters to display.\n");
	else
	{
		while (!bReturn)
		{
			system("cls");
			displayContents(hero[index]);
			printf ("\n");
			printf ("[N]ext [B]ack [S]elect [E]xit");
			ch = getch();
			
			
			switch(ch)
			{
			case 'n':
			case  'N':
			{
				index++;
				if (index == *numhero)
				index = 0;
				break;
				
			}	
				
			case 'B':
			case 'b':
			{
				index--;
				if (index < 0)
					index = numstory - 1;
				break;
			}	
			case 'E':
			case 'e':	
				{
					bReturn = 1;
					break;
				}
			case  'S':
			case  's':
			{
		
				int	bSelect2 = 0;
				while (!bSelect2)
				{
						do
					{
						system("cls");
						displayContents(hero[index]);
						printf ("\n");
						printf ("you choose to Change this hero?");
						printf ("[C] - Choose  [B] - Back ");
						ch = getch();
					} while (ch != 'C' && ch != 'c' && ch != 'B' && ch != 'b');
					if (ch == 'C' || ch == 'c')
					{
						
				strcpy(story[nKey].protagonist.name,hero[index].name);
			    strcpy(story[nKey].protagonist.stage,hero[index].stage);
			    story[nKey].protagonist.ID = hero[index].ID;
			    story[nKey].protagonist.HP = hero[index].HP;
			    story[nKey].protagonist.PP = hero[index].PP;
			    story[nKey].protagonist.nElem = hero[index].nElem;
			    story[nKey].protagonist.lightA = hero[index].lightA;
			    story[nKey].protagonist.mediumA = hero[index].mediumA;
			    story[nKey].protagonist.heavyA = hero[index].heavyA;
		
						printf("New Protagonist added!!! \n");
						system("pause");
						bSelect2 = 1;
		          	}	
					else
					bSelect2 = 1;
				
		      }
		      
		      break;
			}
				
		
		
		

	         }
	
	
	
            }
}
}
else if (nChoice == 4)
			{
	printf("enter number of enemies that the protagonist will fight: \n");
	printf("number of heros in the pool: %d \n",numhero);
    scanf("%d",&numEnem);
     story[nKey].numEnem = numEnem;
    
    for (j = 0;j < numEnem;j++)
    {
    	
    printf("Enter the ID number of the Enemy #%d! \n",j+1);
    scanf("%d",&enemID);
    
    story[nKey].Enemy[j].ID = enemID;
    
    enemIndex = getIndex(hero,numhero,enemID);
    
    strcpy(story[nKey].Enemy[j].name,hero[enemIndex].name);
    strcpy(story[nKey].Enemy[j].stage,hero[enemIndex].stage);
    
    story[nKey].Enemy[j].HP = hero[enemIndex].HP;
    story[nKey].Enemy[j].PP = hero[enemIndex].PP;
    story[nKey].Enemy[j].nElem = hero[enemIndex].nElem;
    
    story[nKey].Enemy[j].lightA = hero[enemIndex].lightA;
    story[nKey].Enemy[j].mediumA = hero[enemIndex].mediumA;
    story[nKey].Enemy[j].heavyA = hero[enemIndex].heavyA;
    	
    printf("enemy %s added!\n",story[nKey].Enemy[j].name);	
		
			}
		}
   else if (nChoice ==5)
   {
   	bExit = 1;
   	bSelect = 0;
			   }			
       }
					}	
					else 
					bSelect = 1;
					
					}
					
	
	
}
}
}
}
savetofile3(story, numstory);
}





void viewStory (story story[MAX],int numstory)
{
	int bExit = 0;
	int bView = 0;
	int i;
	int position = 0,nChoice =0, bExit2 =0;
	char ch; 
		int menu =0;
	
system("cls");

  while (!menu)
{ 
	if (numstory == 0)
	{	system("cls");
		printf("No Stories in the story pool yet!!!\n");
		system("pause");
		menu = 1;
	}	
	else
	{
		while (!bExit)
	{
		do
		{
			system ("cls");
			printf ("Enter VIEW MODE OPTION: \n");
			printf ("[1] - view list mode\n");
			printf ("[2] - view Protagonist mode \n");
			printf("[3] - Exit \n");
			scanf (" %d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3);
		
		if (nChoice == 1)
		{
			while (!bView)
		{
				system("cls");
				printf("STORY LINE LIST: \n");
				for (i = 0;i < numstory;i++)
				displayContentsStory(story[i]);
		
			    printf("[B] - Back \n");
			    ch = getch();
			    if (ch == 'b' || ch == 'B')
			    bView = 1;
			    else 
			    bView = 0;
			    
			    
		}
		
		
			
		}
		else if (nChoice == 2)
		{
			bExit = 0;
			
		if (numstory <= 0)
	printf ("No Stories to display.\n");
	else
	{
		while (!bExit2)
		{
			system("cls");
			displayContentsStory(story[position]);
			printf ("\n");
			printf ("[N]ext [B]ack [E]xit");
			ch = getch();
			
			
			switch(ch)
			{
			case  'n':
			case  'N':
			{
				position++;
				if (position == numstory)
				position = 0;
				break;
				
			}	
				
			case 'B':
			case 'b':
			{
				position--;
				if (position < 0)
					position = numstory - 1;
				break;
			}	
			case 'E':
			case 'e':	
				{
					bExit2 = 1;
					break;
				}
			
			
	        	}
		
	  }
			
     }///else end bracket
	
        }//else if end bracket
        
        else if (nChoice == 3)
        {
        bExit = 1;	
		menu =1;
        	
		}
        
        
} //while end bracket
		
}
		
		
	}
	
	
}//function end bracket































int StartStoryGame (int Player1, int Player2,characters hero[MAX],int numhero,attack move[MAX],int nummove)
{
	

int result = 5;


		srand(time(NULL));
	int turn;
	int nChoice;
	int location;
	char stage[MAX];
	int bExit =0;
	int index;
	float j,k;
	int i,a;
	int costL1, costM1, costH1, costL2, costM2, costH2;
	

	int maxHP1 = hero[Player1].HP;
	int maxHP2 = hero[Player2].HP;
	int damage = 0;
	int maxPP1 = hero[Player1].PP;
	int maxPP2 = hero[Player2].PP;
	int currHP1 = hero[Player1].HP;
	int currHP2 = hero[Player2].HP;
	int currPP1 = 0;
	int currPP2 = 0;
	float multi;
	int elem1 = hero[Player1].nElem;
    int elem2 = hero[Player2].nElem;
    
int J;
	
    char light_move1[300];
	char light_move2[300];
	char medium_move1[300];
	char medium_move2[300];
	char heavy_move1[300];
	char heavy_move2[300]; 
	
 int lightmove1 = hero[Player1].lightA;
 int lightmove2  = hero[Player2].lightA;
	
	

 int mediummove1 = hero[Player1].mediumA;
 int mediummove2 = hero[Player2].mediumA;
 int heavymove1 = hero[Player1].heavyA;
 int heavymove2 = hero[Player2].heavyA;
	
	lightmove1 = getIndexMove(move,&nummove,lightmove1);
	lightmove2 = getIndexMove(move,&nummove,lightmove2);
	
	mediummove1 = getIndexMove(move,&nummove,mediummove1);
	mediummove2 = getIndexMove(move,&nummove,mediummove2);
	
	
	
	heavymove1 = getIndexMove(move,&nummove,heavymove1);
	heavymove2 = getIndexMove(move,&nummove,heavymove2);
	


		
	strcpy(light_move1,move[lightmove1].name);
	
	strcpy(light_move2,move[lightmove2].name);	 
	strcpy(medium_move1,move[mediummove1].name); 
	strcpy(medium_move2,move[mediummove2].name);
	strcpy(heavy_move1,move[heavymove1].name);
	strcpy(heavy_move2,move[heavymove2].name);



	
	
	a = (rand() % (20-10+1))+10;
	i = maxPP1*((float)a/100);
    costL1 = i;
    
    a = (rand() % (50-30+1))+30;
	i = maxPP1*((float)a/100);
    costM1 = i;
    
    a = (rand() % (80-60+1))+60;
	i = maxPP1*((float)a/100);
    costH1 = i;
    
    
    a = (rand() % (20-10+1))+10;
	i = maxPP2*((float)a/100);
    costL2 = i;
    
    a = (rand() % (50-30+1))+30;
	i = maxPP2*((float)a/100);
    costM2 = i;
    
    a = (rand() % (80-60+1))+60;
	i = maxPP2*((float)a/100);
    costH2 = i;

	
	
	
	turn = (rand ()%(3-1))+1;
	


	
	strcpy(stage,hero[Player2].stage);
	i = 0;


	bExit = 0;

	while (!bExit)
	{
		
	
		
		
		
		do
		{
			
				
			
			system("cls");
		printf("%s",stage);
		printf("\n\n");
		
		Earth();
		
		printf("%s",hero[Player1].name);
		printf("\t\t\t\t\t\t\t\t\t%s",hero[Player2].name);
		printf("\n");
	if (hero[Player1].nElem == 1)
	printf ("\t\t\tFire\t\t");
	else if (hero[Player1].nElem ==  2)
		printf ("\t\t\tWater\t\t");
	else if (hero[Player1].nElem ==  3)
	printf ("\t\t\tEarth\t\t");	
	else if (hero[Player1].nElem ==4 )
	printf ("\t\t\tAir\t\t");
	printf(" vs \t\t\t ");
	if (hero[Player2].nElem == 1)
	printf ("Fire\n");
	else if (hero[Player2].nElem ==  2)
		printf ("Water\n");
	else if (hero[Player2].nElem ==  3)
	printf ("Earth\n");	
	else if (hero[Player2].nElem ==4 )
	printf ("Air\n");
	
	printf("\t\t\tHP: %d / %d \t\t\t\t\t",currHP1,maxHP1);
	printf("HP: %d / %d \n",currHP2,maxHP2);			
		
	printf("\t\t\tPP: %d / %d \t\t\t\t\t",currPP1,maxPP1);
	
	printf("PP: %d / %d \n",currPP2,maxPP2);
	nChoice = 0;	
	

	
	if (turn % 2 == 0)
	{

	printf("Player's Turn!\n\n");
	printf("Select Move:\n");
	printf("[1] Charge \n");
	printf("[2] %s ",light_move1);
	printf("(Required PP: %d) %s",costL1,move[lightmove1].description);
	printf("[3] %s ",medium_move1);
	printf("(Required PP: %d) %s",costM1,move[mediummove1].description);
	printf("[4] %s ",heavy_move1);
	printf("(Required PP: %d) %s",costH1,move[heavymove1].description);	

	
while(!i)
	{
		
	do {
	printf("enter choice: \n");
	scanf(" %d",&nChoice);
	
		
	}while(nChoice != 1 && nChoice != 2 && nChoice != 3 && nChoice !=4); 
	
	
	if (nChoice == 1)
	{
	Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
	 i = 1;
	 turn++;
   }
	
	
	if (nChoice == 2 && currPP1 >= costL1 )
	{

		currPP1 -= costL1;
		Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
		i =1;
		currPP1 += 2;
		turn++;
	}
	else if (nChoice == 2 && currPP1 < costL1 )
	printf("insufficient PP!!! TRY AGAIN! \n");
		

	if (nChoice == 3 && currPP1 >= costM1 )
	{
		currPP1 -= costM1;
		Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
		currPP1 += 2;
		i =1;
		turn++;
	}
	else if (nChoice == 3 && currPP1 < costM1 )
	printf("insufficient PP!!!TRY AGAIN! \n");	
	
	if (nChoice == 4 && currPP1 >= costH1 )
	{
		currPP1 -= costH1;
		Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
		currPP1 += 2;
		i =1;
		turn++;
	}		
	else if (nChoice == 4 && currPP1 < costH1 )
	printf("insufficient PP!!!TRY AGAIN! \n");	
	
	}
	
	if (currPP1 > maxPP1)
	currPP1 = maxPP1;
	
	
	
}



	else if (turn % 2 == 1)
	{
		printf("enemy's turn: \n");
	
	printf("Enemy choosing a move:\n");
	printf("[1] Charge \n");
	printf("[2] %s (Required PP: %d) \n",light_move2,costL2);
	printf("[3] %s (Required PP: %d) \n",medium_move2,costM2);
	printf("[4] %s (Required PP: %d) \n",heavy_move2,costH2);
		
		
do{
	
	 int k;
	 
	 for (k=0;k<100;k++)
	 J = (rand()%(10-1))+1;
	 
	 
	
	
	if (J == 1 || J == 2 || J ==3 || J == 4)
	{
		     nChoice =1;
			
			Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
			printf("\n \t\t\t\t\t\t\t%s \t\t\t\t\t\t\tused charged!!! \n",hero[Player2].name);
		i =0;
		turn++;
	}
	else if (J == 5 || J == 6 || J==7 || J ==8 || J == 9 ||J ==10)
	{
		
		if (currPP2 >= (k = (float)maxPP2*0.20) && currPP2 < (k = (float)maxPP2*0.35) )
		{
			nChoice = 2;
			currPP2 -= costL2;
			Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
			currPP2 += 2;
			printf("\n \t\t\t\t\t\t\t%s \t\t\t\t\t\ttused %s!!! \n",hero[Player2].name,light_move2);
			
			i =0;
			turn++;
		}
	else if (currPP2 >= (k = (float)maxPP2*0.35) && currPP2 < (k = (float)maxPP2*0.70) )
		{
			nChoice = 3;
			currPP2 -= costM2;
			Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
			currPP2 += 2;
			printf(" \n \t\t\t\t\t\t\t%s \t\t\t\t\t\t\tused %s!!! \n",hero[Player2].name,medium_move2);
			turn++;
			i =0;
		}
	else if (currPP2 >= (k = (float)maxPP2*0.70) && currPP2 <= (k = (float)maxPP2*0.100) )
		{
			nChoice = 4;
			currPP2 -= costH2;
			Compute(nChoice,&currHP1,&currHP2,&currPP1,&currPP2,turn,maxHP1,maxHP2,maxPP1,maxPP2,&damage,elem1,elem2);
			currPP2 += 2;
			printf(" \n \t\t\t\t\t\t\t%s \t\t\t\t\t\t\tused %s!!! \n",hero[Player2].name,heavy_move2);
			turn++;
			i =0;
		}

		
	}
	

	if (currPP2 > maxPP2)
	currPP2 = maxPP2;


		
	}while( !(turn % 2 == 0) );
}



	if ((turn % 2 == 1 && (nChoice >=2 && nChoice <=4 ) ) && damage > 0 )
		printf("\n \t\t\t\t\t\t\tEnemy received %d damage!!! \n",damage);
		else if ((turn % 2 == 1 && (nChoice >=2 && nChoice <=4 )) && damage == 0 )
		printf("\n \t\t\t\t\t\t\t\tYOU ATTACK MISSED! \n ");
		
		
		else if ((turn % 2 == 0 && (nChoice >=2 && nChoice <=4 ) ) && damage >0  )
		printf("\n \t\t\t\t\tYou received %d damage! \n",damage);
		else if ((turn % 2 ==  0&& (nChoice >=2 && nChoice <=4 )) && damage == 0 )
		printf("\n \t\t\t\t\t\t\t\tEnemy ATTACK MISSED!!! \n ");



	system("pause");
		
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice !=4 );
		
		if (currHP1 <= 0  )
			{
				system("cls");
				printf("\n\n\t\t\t\t%s WON THE BATTLE!!!!\n\n",hero[Player2].name);
				system("pause");
				bExit = 1;
				result = 0;
			}
			
		else if	(currHP2 <= 0 )
		{
			system("cls");
			printf("\n\n\n\t\t\t\t %s HAS WON THE BATTLE!!!!\n\n",hero[Player1].name);
			system("pause");
				bExit = 1;
				result = 1;
		}
		else if (currHP1 > 0 )
			bExit = 0;
	}
	
		
	

return result;

	
}


void StartStory(story story,characters hero[MAX],int numhero,attack move[MAX],int nummove)
{
	
	int i = 0;
	int bExit = 0, nChoice = 0, Player1 = 0, Player2 = 0;
	 Player1 = story.protagonist.ID;
	 int result =10;
	 
	 int P2index;
	 
	 Player1 = getIndex(hero,&numhero,Player1);
	 
	 system("cls");
	 printf("\t\t\t\t\t\t%s\t\t\t\t\t\t\t\n",story.title);
	 printf("\t\t\t\t\t\t%s\t\t\t\t\t\t",story.description);
	 system("pause");
	
	while (!bExit)
	{
		do
		{
			P2index = getIndex(hero,&numhero,story.Enemy[Player2].ID);
			
			
			system ("cls");
			printf("Protagonist selected: %s \n", hero[Player1].name);
			printf("Enemy Facing!!!: %s \n", story.Enemy[Player2].name);
			
		
			printf ("Do you wish to fight this enemy? \n");
			printf ("[1] - Yes! Let's Start the Battle!!!! \n");
			printf("[2] - No! Run!! \n");
		
			scanf ("%d",&nChoice);
			printf("nChoice = %d",nChoice);
			system("pause");
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 );
		
		if (nChoice == 1)
			{
				result = StartStoryGame(Player1,P2index,hero,numhero,move,nummove);
				if (result == 1)
				{
					printf("Congratulations!!! You Won against:\n");
					system("pause");
					printf("\t\t\t\t%s",story.Enemy[Player2].name);
					Player2++;
					bExit = 0;
				}
				else if (result == 0)
				{
					printf("You Lost, its okay you can train again!!! You lost against:\n");
					printf("\t\t\t\t%s",story.Enemy[Player2].name);
					bExit = 1;
				}
			}
		else if (nChoice == 2)
			bExit = 1;
	
    }
	
}









void StorylineSelect (characters hero[MAX],int numhero,attack move[MAX],int nummove,story story[MAX],int numstory)
{
	int i =0;
	int bSelect;
	
	int position = 0;
		int	bExit = 0;
	char ch;	
			
		if (numstory <= 0)
		{
			printf ("No Stories to display.\n");
			system("pause");
			
		}
	
	else
	{
		while (!bExit)
		{
			printf("Select your Storyline: \n");
			system("cls");
			displayContentsStory(story[position]);
			printf ("\n");
			printf ("[N]- Next [B]-Back [S]-Select [E]- Exit ");
			ch = getch();
			
			
			switch(ch)
			{
			case  'n':
			case  'N':
			{
				position++;
				if (position == numstory)
				position = 0;
				break;
				
			}	
				
			case 'B':
			case 'b':
			{
				position--;
				if (position < 0)
					position = numstory - 1;
				break;
			}	
			case 'S':
			case 's':
			{
				bSelect = 0;
				while (!bSelect)
				{
						do
					{
						system("cls");
						displayContentsStory(story[position]);
						printf ("\n");
						printf ("you choose this story?");
						printf ("[C] - Choose  [B] - back ");
						ch = getch();
					} while (ch != 'C' && ch != 'c' && ch != 'S' && ch != 's');
					if (ch == 'C' || ch == 'c')
					{
						StartStory(story[position],hero,numhero,move,nummove);
						bSelect = 1;
					}
					else 
					bSelect = 1;
				
			     }  
				
				
				
				
				
				}	
			case 'E':
			case 'e':	
				{
					bExit = 1;
					break;
				}
			
			
	    } // switch bracket
		
	  }
			
     }
		
		
		
	
	
	
	
}



void playtheGame(characters hero[MAX],int numhero,attack move[MAX],int nummove,story story[MAX],int numstory)
{
	int i, nChoice, bExit = 0;
		
	while (!bExit)
	{
		do
		{
			system ("cls");
			printf ("Enter option: \n");
			printf ("[1] - Free mode \n");
			printf("[2] - Storyline mode \n");
			printf("[3] - Exit \n");
		
			scanf (" %d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 );
		
		if (nChoice == 1)
		GamePlaySelect(hero,numhero,move,nummove);
		else if (nChoice == 2)
		StorylineSelect (hero,numhero,move,nummove,story,numstory);
		else if (nChoice ==3 )
		bExit  = 1;
	
}
}



ConfigureStory(characters hero[MAX],int *numhero,attack move[MAX],int *nummove,story story[MAX],int *numstory)
{
	
	int i, nChoice, bExit = 0;
		
while (!bExit)
	{
		do
		{
			system ("cls");
			printf (": Storyboard contents: \n\n");
			for (i = 0;i < *numstory;i++)
				displayContentsStory(story[i]);
			printf ("Enter option: \n");
			printf ("[1] - Add story\n");
			printf ("[2] - Delete a Story \n");
			printf("[3] - Modify a Story \n");
			printf("[4] - view a story \n");
			printf("[5] - Exit \n");
		
			scanf (" %d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice != 4 && nChoice != 5);
		
		if (nChoice == 1)
			addStory(story,numstory,hero,numhero);
		else if (nChoice == 2)
			delStoryline (story,numstory);
		else if (nChoice == 3)
			modifyStory(story,*numstory,hero,numhero); 
		else if (nChoice == 4)
			viewStory(story,*numstory);
		else if (nChoice == 5)
			bExit = 1;
	}
	
	
	
	
}










void Settings(characters hero[MAX],int *numhero,attack move[MAX],int *nummove,story story[MAX],int *numstory)
{
	int i, nChoice, bExit = 0;
		
	while (!bExit)
	{
		do
		{
			system ("cls");
			sword ();
			printf ("Enter Settings options: \n");
			printf ("[1] - Configure Characters \n");
			printf("[2] - Configure Moves \n");
			printf("[3] - Configure Story line \n");
			printf("[4] - Exit\n");
		
			scanf (" %d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 &&nChoice != 3 && nChoice != 4);
		
		if (nChoice == 1)
		Configure(hero,numhero);
		else if (nChoice == 2)
		ConfigureMove(move,nummove,hero,numhero);
		else if (nChoice ==3)
		ConfigureStory(hero,numhero,move,nummove,story,numstory);
		else if (nChoice == 4)
		bExit = 1;
	
}
}



void Title()
{
	

printf("              _______  __     ______  __    __	 ___________  \n");
printf("             |   ____||  |  /  _____||  |  |  | |           | \n");                                                
printf("             |  |__   |  | |  |  __  |  |__|  | `---|  |----` \n");                                                
printf("             |   __|  |  | |  | |_ | |   __   |     |  | \n");                                                     
printf("             |  |     |  | |  |__| | |  |  |  |     |  | \n");                                                     
printf("             |__|     |__|  |______| |__|  |__|     |__| \n");                                                     
printf("                                                                                                               \n");
printf("       ______    _______     _______  __       _______ .___  ___.  _______ .__   __. .___________.    _______. \n");
printf("      /  __  |  |   ____|   |   ____||  |     |   ____||   ||   | |   ____||  |  |  | |           |   /       | \n");
printf("     |  |  |  | |  |__      |  |__   |  |     |  |__   |   __   | |  |__   |  |  |  |  `--|  |----`  |   (----` \n");
printf("     |  |  |  | |   __|     |   __|  |  |     |   __|  |  |  |  | |   __|  |   | |  |     |  |        |   | \n");    
printf("     |  `--'  | |  |        |  |____ |  `----.|  |____ |  |  |  | |  |____ |  | ||  |     |  |    .----)   | \n");   
printf("      |______|  |__|        |_______||_______||_______||__|  |__| |_______||__|  |__|     |__|    |_______| \n");


}
	
	
	




int main ()
{
	
	
	
	
	characters hero[100]; 
	attack move[100]; 
	story story[100];

	int i, nChoice, bExit = 0;
	
	int numhero = 0;
		int nummove =0;
		int numstory =0;
			
	CheckList(hero,&numhero); 
	CheckList2(move,&nummove);
	CheckList3(story,&numstory);
	
	while (!bExit)
	{
		do
		{
			system ("cls");
			system("COLOR 1E");
		//	printf ("Hero List information: \n\n");
		//	for (i = 0;i < numhero;i++)
		//	displayContents(hero[i]);
			creature();
			Title();
			
			printf ("Enter option: \n");
			printf ("[1] - Play the Game \n");
			printf("[2] - Configure \n");
			printf("[3] - Exit \n");
			

			scanf (" %d",&nChoice);
		} while (nChoice != 1 && nChoice != 2 && nChoice != 3 );
		
		
		
		
		
		if (nChoice == 1)
			playtheGame(hero,numhero,move,nummove,story,numstory);
		else if (nChoice == 2)
			Settings(hero,&numhero,move,&nummove,story,&numstory);
		else if (nChoice ==3)
			bExit = 1;
	}
	
	
		
	saveToFile(hero,numhero);
	saveToFileMove(move,nummove);
	savetofile3 (story,numstory);
	
	
	return 0;
	
}


void Earth()
{
	
	char slash = 92;
	
printf("\t\t*                    /   %c              /'%c       _                              * \n",slash,slash);
printf("\t\t*%c_..           /'.,/     %c_         .,'   %c     / %c_                            * \n",slash,slash,slash,slash);
printf("\t\t*    %c         /            %c      _/       %c_  /    %c     _                     * \n",slash,slash,slash,slash);
printf("\t\t*     %c__,.   /              %c    /           %c/.,   _|  _/ %c                    * \n",slash,slash,slash,slash);
printf("\t\t*          %c_/                %c  /',.,''%c      %c_ %c_/  %c/    %c                   * \n",slash,slash,slash,slash,slash,slash,slash);
printf("\t\t*                           _  %c/   /    ',../',.%c    _/      %c                  * \n",slash,slash,slash);
printf("\t\t*             /           _/m%c  %c  /    |         %c  /.,/'%c   _%c                 * \n",slash,slash,slash,slash,slash);
printf("\t\t*           _/           /MMmm%c  %c_     |          %c/      %c_/  %c                * \n",slash,slash,slash,slash);
printf("\t\t*          /      %c     |MMMMmm|   %c__   %c          %c_       %c   %c_              * \n",slash,slash,slash,slash,slash,slash);
printf("\t\t*                  %c   /MMMMMMm|      %c   %c           %c       %c    %c             * \n",slash,slash,slash,slash,slash,slash);
printf("\t\t*                   %c  |MMMMMMmm%c      %c___            %c_      %c_   %c            * \n",slash,slash,slash,slash,slash,slash);
printf("\t\t*                    %c|MMMMMMMMmm|____.'  %c_            %c       %c   %c_          * \n",slash,slash,slash,slash,slash);
printf("\t\t*                    /'.,___________...,,'   %c            %c   %c        %c         * \n",slash,slash,slash,slash);
printf("\t\t*                   /       %c          |      %c    |__     %c   %c_       %c        * \n",slash,slash,slash,slash,slash);
printf("\t\t*                 _/        |           %c      %c_     %c     %c    %c       %c_      * \n",slash,slash,slash,slash,slash,slash);
printf("\t\t*                /                               %c     %c     %c_   %c        %c     * \n",slash,slash,slash,slash,slash);
printf("\t\t*                                                 %c     %c      %c   %c__      %c    * \n",slash,slash,slash,slash,slash);
printf("\t\t*                                                  %c     %c_     %c     %c      %c   * \n",slash,slash,slash,slash,slash);
printf("\t\t*                                                   |      %c     %c     %c      %c  * \n",slash,slash,slash,slash);
printf("\t\t*                                                    %c          |            %c * \n",slash,slash);
printf("\t\t ******************************************************************************** \n");	

}


void creature()
{
	
	char c = 92;
	
	
printf("                    ___====-_  _-====___                                   \n");
printf("              _--^^^#####//      %c%c#####^^^--                             \n",c,c);
printf("           _-^##########//  (   ) %c%c##########^-_                             \n",c,c);
printf("          -############//   |%c %c|  %c%c############-                     \n",c,c,c);
printf("        _/############//   (@: :@)    %c%c############%c_                  \n",c,c,c);
printf("       /#############((    %c%c  //     ))#############                     \n",c,c);
printf("       ###############%c%c    (oo)    %c##############                    \n",c,c,c);
printf("     -#################%c   / VV %c  %c%c#################-        - WELCOME TRAVELER!!!        \n",c,c,c,c);
printf("    -###################\%c /      %c%c%c###################-              \n",c,c,c,c);
printf("   _#/|##########/%c######(   /%c   )######/%c##########|%c#_               \n",c,c,c,c); 
printf("   |/ |#/%c#/%c#/%c/  %c#/%c##%c  |  |  /##/#/  %c/%c#/%c#/%c#| %c|           \n",c,c,c,c,c,c,c,c,c,c,c);
printf("   `  |/  V  V  `   V  %c#%c| |  | |/#/  V   '  V  V  |  ' \n",c,c);
printf("      `   `  `      `   %c | |  | | %c   '      '  '   ' \n",c,c);
printf("                       (  | |  | |  ) \n");
printf("                      __%c | |  | | /__ \n",c);
printf("                     (vvv(VVV)(VVV)vvv) \n");
}

void human ()
{

     
	 
char c = 92;
	     
printf("        /n n%c        /%c  - make your character \n",c,c);
printf("        |/^%c|       /  %c \n",c,c); 
printf("        | , |       ^||^\n");
printf("         %c_%c         || \n",c,c); 
printf("         _U_         || \n");
printf("       /`   `''-----'P3 \n");
printf("      / |. .|''----- || \n");
printf("      %c'|   |        || \n",c);
printf("       %c|   |        || \n",c);
printf("        E   |        || \n");
printf("       /#####%c      || \n",c);
printf("       /#####%c	     || \n",c);
printf("         |||         || \n");
printf("         |||         || \n");
printf("         |||         || \n");
printf("         |||         || \n");
printf("        molom        Ll \n");
	
}




void sword ()
{
	
	char c = 92;
	
	
printf("            	/%c \n",c);                            
printf("               /  %c \n",c);
printf("              /    %c \n",c);
printf("              | vv | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | !! | \n");
printf("              | ^^ | \n");
printf(" |%c          /  __  %c           /| \n",c,c);
printf(" |'%c________/  /  %c  %c_________/ | \n",c,c,c);
printf(" |    []      | /%c |      []     |  \n",c);
printf(" |. ________  | %c/ |  _________ .|  \n",c);
printf(" %c_/        %c  %c__/  /         %c_/ \n",c,c,c,c);
printf("             %c      / \n",c);
printf("              |XXXX| \n"); 
printf("              |XXXX| \n");  
printf("              |XXXX| \n");  
printf("              |XXXX| \n");   
printf("              |XXXX| \n");   
printf("              |XXXX| \n");  
printf("              |XXXX| \n");  
printf("              |XXXX| \n");  
printf("             /  /%c  %c \n",c,c);
printf("            /   --   %c \n",c);
printf("            %c________/ \n",c);
	
	
	
	
	
	
	
	
	
	
	
}
